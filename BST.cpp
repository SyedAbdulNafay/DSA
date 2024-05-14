#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node *Insert(Node *root, int value)
{
    if (root == NULL)
    {
        Node *node = new Node(value);
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

void Search(Node *root, int value)
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

void InOrderTraversal(Node *head)
{
    if (head == nullptr)
        return;
    InOrderTraversal(head->left);
    cout << head->data << " ";
    InOrderTraversal(head->right);
}

void PreOrderTraversal(Node *head)
{
    if (head == nullptr)
        return;
    cout << head->data << " ";
    PreOrderTraversal(head->left);
    PreOrderTraversal(head->right);
}

void PostOrderTraversal(Node *head)
{
    if (head == nullptr)
        return;
    PostOrderTraversal(head->left);
    PostOrderTraversal(head->right);
    cout << head->data << " ";
}

Node *FindMin(Node* head){
    while (head->left != nullptr) head = head->left;
    return head;
}

Node *Delete(Node *head, int value)
{
    if (head == nullptr)
        return head;

    if (value > head->data)
        head->right = Delete(head->right, value);
    else if (value < head->data)
        head->left = Delete(head->left, value);
    else
    {
        // 0 children
        if (head->right == nullptr && head->left == nullptr)
        {
            delete head;
            head = nullptr;
        }
        // 1 right child
        else if (head->left == nullptr)
        {
            Node *temp = head;
            head = head->right;
            delete temp;
        }
        // 1 left child
        else if (head->right == nullptr)
        {
            Node *temp = head;
            head = head->left;
            delete temp;
        }
        // 2 children
        else {
            Node *temp = FindMin(head->right);
            head->data = temp->data;
            head->right = Delete(head->right, temp->data);
        }
    }
    return head;
}

int main()
{
    Node *head = nullptr;

    while (true)
    {
        cout << "Press" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Delete" << endl;
        cout << "4. In Order Traversal" << endl;
        cout << "5. Pre Order Traversal" << endl;
        cout << "6. Post Order Traversal" << endl;
        cout << "0. Exit" << endl;

        int option;
        cin >> option;

        if (option == 1)
        {
            int value;
            cout << "Enter value: ";
            cin >> value;
            head = Insert(head, value);
        }
        else if (option == 2)
        {
            int value;
            cout << "Enter value: ";
            cin >> value;
            Search(head, value);
        }
        else if (option == 3)
        {
            int value;
            cout << "Enter value: ";
            cin >> value;
            head = Delete(head, value);
        }
        else if (option == 4)
        {
            InOrderTraversal(head);
        }
        else if (option == 5)
        {
            PreOrderTraversal(head);
        }
        else if (option == 6)
        {
            PostOrderTraversal(head);
        }
        else if (option == 0)
        {
            break;
        }
        else
        {
            cout << "Enter valid option" << endl;
        }
    }

    return 0;
}