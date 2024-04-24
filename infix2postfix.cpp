#include <iostream>
using namespace std;
#include <cstdlib>
#include <math.h>

struct Node
{
    char value;
    Node *next;

    Node(char input)
    {
        value = input;
    }
};

struct ExNode
{
    char value;
    ExNode *right;
    ExNode *left;

    ExNode(char input)
    {
        value = input;
        right = nullptr;
        left = nullptr;
    }
};

struct STNode
{
    ExNode *entry;
    STNode *next;

    STNode(ExNode *value)
    {
        entry = value;
        next = nullptr;
    }
};

int getPrecedence(char op)
{
    if (op == '|')
    {
        return 0;
    }
    else if (op == '&')
    {
        return 1;
    }
    else if (op == '<' || op == '>')
    {
        return 2;
    }
    else if (op == '+' || op == '-')
    {
        return 3;
    }
    else if (op == '*' || op == '/' || op == '%')
    {
        return 4;
    }
    else if (op == '(')
    {
        return 5;
    }
    else
    {
        return -1;
    }
}

void Push(Node **top, char c)
{
    Node *ptr = new Node(c);

    ptr->next = *top;
    *top = ptr;
}

void STPush(STNode **stop, ExNode *c)
{
    STNode *ptr = new STNode(c);

    ptr->next = *stop;
    *stop = ptr;
}

void Pop(Node **top)
{
    if (*top == NULL)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        Node *temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

void STPop(STNode **stop)
{
    if (*stop == NULL)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        STNode *temp = *stop;
        *stop = (*stop)->next;
        delete temp;
    }
}

double ApplyOperator(char op, double a, double b)
{
    switch (op)
    {
    case '+':
        return a + b;

    case '-':
        return a - b;

    case '*':
        return a * b;

    case '/':
        return a / b;

    case '%':
        return fmod(a, b);

    case '&':
        return (a != 0) && (b != 0);

    case '|':
        return (a != 0) || (b != 0);

    case '>':
        return a > b;

    case '<':
        return a < b;

    default:
        return -1;
    }
}

string InfixToPostfix(Node *top, string Infix)
{
    string Postfix;

    for (int i = 0; i < Infix.length(); i++)
    {
        if ((Infix[i] >= 'a' && Infix[i] <= 'z') || (Infix[i] >= 'A' && Infix[i] <= 'Z'))
        {
            Postfix += Infix[i];
        }
        else if (Infix[i] == '(')
        {
            Push(&top, Infix[i]);
        }
        else if (Infix[i] == ')')
        {
            while ((top != nullptr) && (top->value != '('))
            {
                Postfix += top->value;
                Pop(&top);
            }
            if (top != nullptr)
            {
                Pop(&top);
            }
        }
        else
        {
            while ((top != nullptr) && (getPrecedence(top->value) > getPrecedence(Infix[i])) && (top->value != '('))
            {
                Postfix += top->value;
                Pop(&top);
            }
            Push(&top, Infix[i]);
        }
    }
    while (top != nullptr)
    {
        Postfix += top->value;
        Pop(&top);
    }

    return Postfix;
}

int PostfixEvaluation(Node *top, string Postfix)
{
    for (int i = 0; i < Postfix.length(); i++)
    {
        if ((Postfix[i] >= 'a' && Postfix[i] <= 'z') || (Postfix[i] >= 'A' && Postfix[i] <= 'Z'))
        {
            cout << "Enter a value for " << Postfix[i] << " : ";
            double value;
            cin >> value;
            Push(&top, value);
        }
        else if (Postfix[i] >= '0' && Postfix[i] <= '9')
        {
            Push(&top, Postfix[i] - '0');
        }
        else
        {
            int op2 = top->value;
            Pop(&top);
            int op1 = top->value;
            Pop(&top);

            int result = ApplyOperator(Postfix[i], op1, op2);
            Push(&top, result);
        }
    }
    return top->value;
}

void Display(ExNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    Display(root->left);
    cout << root->value << " ";
    Display(root->right);
}

void CreateEvaluationTree(string Postfix, STNode **stop)
{
    for (int i = 0; i < Postfix.length(); i++)
    {
        ExNode *ptr = new ExNode(Postfix[i]);

        if ((Postfix[i] >= 'a' && Postfix[i] <= 'z') || (Postfix[i] >= 'A' && Postfix[i] <= 'Z') || (Postfix[i] >= '0' && Postfix[i] <= '9'))
        {
            STPush(stop, ptr);
        }
        else
        {
            ptr->right = (*stop)->entry;
            STPop(stop);
            ptr->left = (*stop)->entry;
            STPop(stop);

            STPush(stop, ptr);
        }
    }
}

int main()
{
    Node *top = NULL;    // top for conversion stack
    Node *etop = NULL;   // top for evaluation stack
    STNode *stop = NULL; // top for tree stack
    string Infix = "(a-b/c)*(a/k-l)";

    string Postfix = InfixToPostfix(top, Infix);
    cout << "Postfix: " << Postfix << endl;

    int Evaluation = PostfixEvaluation(etop, Postfix);
    cout << "Postfix Evaluation: " << PostfixEvaluation << endl;

    CreateEvaluationTree(Postfix, &stop);
    Display(stop->entry);

    return 0;
}
