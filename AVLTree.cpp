#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *right;
    Node *left;

    Node(int c)
    {
        value = c;
        right = nullptr;
        left = nullptr;
    }
};

int height(Node *root)
{
    if (root == nullptr)
    {
        return -1;
    }

    int lt = height(root->left);
    int rt = height(root->right);
    return lt > rt ? lt + 1 : rt + 1;
}

void Insert(Node **root)
{
    cout << "Enter value: ";
    int value;
    cin >> value;

    Node *node = new Node(value);

    if (*root == nullptr)
    {
        *root = node;
        return;
    }
    Node *curr = *root;

    while (curr != nullptr)
    {
        if (curr->value < value)
        {
            if (curr->right == nullptr)
            {
                curr->right = node;
                return;
            }

            curr = curr->right;
        }
        else
        {
            if (curr->left == nullptr)
            {
                curr->left = node;
                return;
            }

            curr = curr->left;
        }
    }
}

void Search(Node *root)
{
    if (root == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }

    cout << "Enter value: ";
    int toSearch;
    cin >> toSearch;

    Node *curr = root;

    while (curr != nullptr)
    {
        if (curr->value == toSearch)
        {
            cout << "Found" << endl;
            return;
        }
        else if (curr->value < toSearch)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }

    cout << "Not found" << endl;
}

void Display(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    Display(root->left);
    cout << root->value << " ";
    Display(root->right);
}

int main()
{
    Node *root = nullptr;
    bool loop = true;

    while (loop)
    {
        cout << "Press" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Display" << endl;
        cout << "4. Height of tree" << endl;
        cout << "0. Exit" << endl;

        int option;
        cin >> option;

        switch (option)
        {
        case 1:
            Insert(&root);
            break;
        case 2:
            Search(root);
            break;
        case 3:
            Display(root);
            break;
        case 4:
            cout << "Height of tree: " << height(root) << endl;
            break;
        case 0:
            loop = false;
            break;

        default:
            break;
        }
    }

    return 0;
}