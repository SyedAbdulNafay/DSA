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
        right = NULL;
        left = NULL;
    }
};

int height(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }

    int lt = height(root->left);
    int rt = height(root->right);
    return lt > rt ? lt + 1 : rt + 1;
}

Node *RightRotate(Node *root)
{
    Node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}

Node *LeftRotate(Node *root)
{
    Node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}

Node *RInsert(Node *root, int value)
{
    if (root == NULL)
    {
        Node *node = new Node(value);
        root = node;
        return root;
    }
    if (root->value > value)
    {
        root->left = RInsert(root->left, value);
        if ((height(root->left) - height(root->right)) > 1 || (height(root->left) - height(root->right)) < -1)
        {
            if (value < root->left->value)
            {
                root = RightRotate(root);
            }
            else
            {
                root->left = LeftRotate(root->left);
                root = RightRotate(root);
            }
        }
    }
    else
    {
        root->right = RInsert(root->right, value);
        if ((height(root->left) - height(root->right)) < -1)
        {
            // check if it needs single rotation or double rotation
            if (value > root->right->value)
            {
                root = LeftRotate(root);
            }
            else
            {
                root->right = RightRotate(root->right);
                root = LeftRotate(root);
            }
        }
    }
    return root;
}

bool Search(Node *root, int toSearch)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->value == toSearch)
    {
        return true;
    }

    if (toSearch > root->value)
    {
        return Search(root->right, toSearch);
    }
    else
    {
        return Search(root->left, toSearch);
    }
}

void Display(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Display(root->left);
    cout << root->value << " ";
    Display(root->right);
}

int main()
{
    Node *root = NULL;
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
            cout << "Enter value: ";
            int value;
            cin >> value;
            root = RInsert(root, value);
            break;
        case 2:
            cout << "Enter value: ";
            int toSearch;
            cin >> toSearch;

            bool isFound;
            isFound = Search(root, toSearch);
            isFound ? cout << "Found" << endl : cout << "Not Found" << endl;
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
