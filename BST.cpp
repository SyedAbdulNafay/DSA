#include <iostream>
using namespace std;

struct BSTNode
{
    int data;
    BSTNode * left;
    BSTNode * right;

    BSTNode()
    {
        data = 0;
        left = nullptr;
        right = nullptr;
    }

    BSTNode(int d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

void Insert(BSTNode ** root)
{
    cout << "Enter value: ";
    int value;
    cin >> value;

    BSTNode * node = new BSTNode(value);

    if (*root == nullptr)
    {
        *root = node;
        return;
    }
    BSTNode * curr = *root;

    while (curr != nullptr)
    {
        if (curr->data < value)
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

void Search(BSTNode * root)
{
    if (root == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }

    cout << "Enter value: ";
    int toSearch;
    cin >> toSearch;

    BSTNode * curr = root;

    while (curr != nullptr)
    {
        if (curr->data == toSearch)
        {
            cout << "Found" << endl;
            return;
        }
        else if (curr->data < toSearch)
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

void Display(BSTNode * root)
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
    BSTNode * root = nullptr;
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
            Insert(&root);
            break;
        case 2:
            Search(root);
            break;
        case 3:
            Display(root);
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