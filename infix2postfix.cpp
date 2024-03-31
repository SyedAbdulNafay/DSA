#include <iostream>
using namespace std;
#include <cstdlib>

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

        case '%': return a;

        case '&': return (a != 0) && (b != 0);

        case '|': return (a != 0) || (b != 0);

        case '>': return a > b;

        case '<': return a < b;

        default:
        return -1;
    }
}

int main()
{
    Node *top = NULL;
    string Infix = "a+b*c/d*x-f*d";
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

    cout << "Postfix: " << Postfix << endl;

    return 0;
}