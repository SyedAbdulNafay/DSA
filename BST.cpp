#include <iostream>
using namespace std;

struct BSTNode
{
    int data;
    BSTNode *left;
    BSTNode *right;

    BSTNode(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

BSTNode *Insert(BSTNode *root, int value)
{
    if (root == NULL)
    {
        BSTNode *node = new BSTNode(value);
        root = node;
        return root;
    }
    if (value > root->data)
    {
        root->right = Insert(root->right, value);
    }
    else
    {
        root->left = Insert(root->left, value);
    }
    return root;
}

void Search(BSTNode *root, int value)
{
    if (root == NULL)
    {
        cout << "Not Found" << endl;
        return;
    }
    if (root->data == value)
    {
        cout << "Found" << endl;
    }
    else if (value > root->data)
    {
        Search(root->right, value);
    }
    else
    {
        Search(root->left, value);
    }
}

void Display(BSTNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    Display(root->left);
    cout << root->data << " ";
    Display(root->right);
}

int main()
{
    BSTNode *root = nullptr;
    bool loop = true;

    while (loop)
    {
        cout << "Press" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Display" << endl;
        cout << "0. Exit" << endl;

        int option;
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter value: ";
            int value;
            cin >> value;
            root = Insert(root, value);
            break;
        case 2:
            cout << "Enter value: ";
            int toSearch;
            cin >> toSearch;
            Search(root, toSearch);
            break;
        case 3:
            Display(root);
            cout << endl;
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