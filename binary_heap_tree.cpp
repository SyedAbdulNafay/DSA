#include <iostream>
using namespace std;
#include <queue>

struct HeapNode
{
    string data;
    HeapNode *left;
    HeapNode *right;

    HeapNode(string d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

HeapNode *BinaryHeapTree(HeapNode *head, string value)
{
    HeapNode *node = new HeapNode(value);
    if (head == nullptr)
    {
        return node;
    }

    queue<HeapNode *> q;
    q.push(head);

    while (!q.empty())
    {
        HeapNode *front = q.front();
        q.pop();

        if (front->left == nullptr)
        {
            front->left = node;
            return head;
        }
        if (front->right == nullptr)
        {
            front->right = node;
            return head;
        }

        q.push(head->left);
        q.push(head->right);
    }

    return head;
}

void PrintTree(HeapNode *head)
{
    if (head == nullptr)
        return;

    PrintTree(head->left);
    cout << head->data << " ";
    PrintTree(head->right);
}

HeapNode *Mirror(HeapNode *head)
{
    if (head == nullptr)
        return head;

    HeapNode *rc = Mirror(head->right);
    HeapNode *lc = Mirror(head->left);

    head->right = lc;
    head->left = rc;

    return head;
}

bool Family(HeapNode *head, string value, bool check)
{
    if (head == nullptr)
        return check;

    if (head->data == value)
    {
        check = true;
    }

    bool check1 = Family(head->left, value, check);
    bool check2 = Family(head->right, value, check);

    if (check1 || check2)
    {
        check = true;
        if (head->data != value)
        {
            cout << head->data << " ";
        }
    }

    return check;
}

int LevelOfNode(HeapNode *head, string value, int level)
{
    if (head == nullptr)
        return -1;

    if (head->data == value)
        return level;

    int l = LevelOfNode(head->left, value, level + 1);

    if (l != -1)
        return l;

    return LevelOfNode(head->right, value, level + 1);
}

int main()
{
    HeapNode *head = nullptr;

    while (true)
    {
        cout << "Print" << endl;
        cout << "1. Insert into binary heap" << endl;
        cout << "2. Print binary heap" << endl;
        cout << "3. Mirror" << endl;
        cout << "4. Find Predecessors and successors" << endl;
        cout << "5. Level of node" << endl;
        cout << "0. Exit" << endl;

        int opt;
        cin >> opt;

        if (opt == 1)
        {
            string value;
            cout << "Enter string: ";
            cin >> value;

            head = BinaryHeapTree(head, value);
        }
        else if (opt == 2)
        {
            PrintTree(head);
            cout << endl;
        }
        else if (opt == 3)
        {
            head = Mirror(head);
        }
        else if (opt == 4)
        {
            string value;
            cout << "Enter value: ";
            cin >> value;
            Family(head, value, false);
        }
        else if (opt == 5)
        {
            string value;
            cout << "Enter string: ";
            cin >> value;

            int i = LevelOfNode(head, value, 0);

            if (i != -1)
            {
                cout << "Level: " << i << endl;
            }
            else
            {
                cout << "Not found" << endl;
            }
        }
        else if (opt == 0)
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