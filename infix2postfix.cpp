#include <iostream>
using namespace std;
#include <cstdlib>
#include <math.h>
#include <unordered_map>

struct Node
{
    char value;
    Node *next;

    Node(char input)
    {
        value = input;
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

double ApplyOperator(char op, double a, double b)
{
    switch (op)
    {
    case '+': return a + b;

        case '-': return a - b;

        case '*': return a * b;

        case '/': return a / b;

        case '%': return fmod(a, b);

        case '&': return (a != 0) && (b != 0);

        case '|': return (a != 0) || (b != 0);

        case '>': return a > b;

        case '<': return a < b;

        default:
        return -1;
    }
}

string InfixToPostfix(Node *top, string Infix)
{
    string Postfix = "";

    for (int i = 0; i < Infix.length(); i++)
    {
        if ((Infix[i] >= 'a' && Infix[i] <= 'z') || (Infix[i] >= 'A' && Infix[i] <= 'Z'))
        {
            Postfix += Infix[i];
        }
        // if stack is empty, the precedence of the top operator is lower or there is an open bracket at the top, push the operator
        else if (top == NULL || (getPrecedence(top->value) < getPrecedence(Infix[i])) || (top->value == '('))
        {
            Push(&top, Infix[i]);
        }
        // if the precedence of the top operator is higher or equal
        else if (getPrecedence(top->value) >= getPrecedence(Infix[i]) && top->value != '(')
        {
            while (top && (!(getPrecedence(top->value) < getPrecedence(Infix[i]))))
            {
                Postfix += top->value;
                Pop(&top);
            }
            Push(&top, Infix[i]);
        }
        else if (Infix[i] == ')')
        {
            do
            {
                Postfix += top->value;
                Pop(&top);
            } while (top && (top->value != '('));
        }
    }

    if (top)
    {
        while (top)
        {
            Postfix += top->value;
            Pop(&top);
        }
    }
    return Postfix;
}

int PostfixEvaluation(Node *top, string Postfix)
{
    unordered_map<char, int> varValues;
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
            Push(&top, Postfix[i]-'0');
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

int main()
{
    Node *top = NULL; //top for conversion stack
    Node *etop = NULL; // top for evaluation stack
    string Infix = "a+b*c/d*x-f*d";

    string Postfix = InfixToPostfix(top, Infix);
    cout << "Postfix: " << Postfix << endl;

    int Evaluation = PostfixEvaluation(etop, Postfix);
    cout << "Postfix Evaluation: " << PostfixEvaluation;

    return 0;
}