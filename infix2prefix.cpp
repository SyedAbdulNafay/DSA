#include <iostream>
using namespace std;
#include <math.h>
#include <algorithm>

struct Node
{
    char value;
    Node *next;

    Node(char input)
    {
        value = input;
    }
};

struct ENode
{
    double value;
    ENode *next;

    ENode(double input)
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

void EPush(ENode **top, double c)
{
    ENode *ptr = new ENode(c);

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

void EPop(ENode **top)
{
    if (*top == NULL)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        ENode *temp = *top;
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

string infixToPrefix(Node *top, string Infix)
{
    reverse(Infix.begin(), Infix.end());
    string Prefix = "";

    for (int i = 0; i < Infix.length(); i++)
    {
        if ((Infix[i] >= 'a' && Infix[i] <= 'z') || (Infix[i] >= 'A' && Infix[i] <= 'Z'))
        {
            Prefix += Infix[i];
        }
        else if (Infix[i] == ')')
        {
            Push(&top, Infix[i]);
        }
        else if (Infix[i] == '(')
        {
            while (top && (top->value != ')'))
            {
                Prefix += top->value;
                Pop(&top);
            }
            Pop(&top);
        }
        else
        {
            while ((top != nullptr) && (getPrecedence(Infix[i]) < getPrecedence(top->value)) && (top->value != '('))
            {
                Prefix += top->value;
                Pop(&top);
            }
            Push(&top, Infix[i]);
        }
    }

    while (top)
    {
        Prefix += top->value;
        Pop(&top);
    }

    reverse(Prefix.begin(), Prefix.end());
    return Prefix;
}

int PrefixEvaluation(ENode *top, string Prefix)
{
    reverse(Prefix.begin(), Prefix.end());
    for (int i = 0; i < Prefix.length(); i++)
    {
        if ((Prefix[i] >= 'a' && Prefix[i] <= 'z') || (Prefix[i] >= 'A' && Prefix[i] <= 'Z'))
        {
            cout << "Enter a value for " << Prefix[i] << " : ";
            double value;
            cin >> value;
            EPush(&top, value);
        }
        else if (Prefix[i] >= '0' && Prefix[i] <= '9')
        {
            EPush(&top, Prefix[i] - '0');
        }
        else
        {
            double op2 = top->value;
            EPop(&top);
            double op1 = top->value;
            EPop(&top);

            double result = ApplyOperator(Prefix[i], op1, op2);
            EPush(&top, result);
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

void CreateEvaluationTree(string Prefix, STNode **stop)
{
    reverse(Prefix.begin(), Prefix.end());
    for (int i = 0; i < Prefix.length(); i++)
    {
        ExNode *ptr = new ExNode(Prefix[i]);

        if ((Prefix[i] >= 'a' && Prefix[i] <= 'z') || (Prefix[i] >= 'A' && Prefix[i] <= 'Z') || (Prefix[i] >= '0' && Prefix[i] <= '9'))
        {
            STPush(stop, ptr);
        }
        else
        {
            ptr->left = (*stop)->entry;
            STPop(stop);
            ptr->right = (*stop)->entry;
            STPop(stop);

            STPush(stop, ptr);
        }
    }
}

int main()
{
    Node *top = nullptr;
    ENode *etop = nullptr;
    STNode *stop = nullptr;
    string Infix = "a+b*c/d*x-f*d";

    string Prefix = infixToPrefix(top, Infix);
    cout << "Prefix Expression: " << Prefix << endl;

    double Evaluation = PrefixEvaluation(etop, Prefix);
    cout << "Prefix Evaluation: " << Evaluation << endl;

    CreateEvaluationTree(Prefix, &stop);
    Display(stop->entry);

    return 0;
}