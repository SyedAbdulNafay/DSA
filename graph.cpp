#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        adj[u].push_back(v);

        if (!direction)
        {
            adj[v].push_back(u);
        }
    }

    void bfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans, int node)
    {
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);

            for (auto i : adj[frontNode])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    void BFS(int vertex)
    {
        unordered_map<int, bool> visited;
        vector<int> ans;
        for (int i = 0; i < vertex; i++)
        {
            if (!visited[i])
            {
                bfs(adj, visited, ans, i);
            }
        }
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, vector<int> component)
    {
        component.push_back(node);
        visited[node] = true;

        for (auto i : adj[node])
        {
            if (!visited[node])
            {
                dfs(i, visited, adj, component);
            }
        }

        for (int i = 0; i < component.size(); i++)
        {
            cout << component[i] << " ";
        }
        cout << endl;
    }

    void DFS(int vertex)
    {
        unordered_map<int, bool> visited;
        vector<vector<int>> ans;
        for (int i = 0; i < vertex; i++)
        {
            if (!visited[i])
            {
                vector<int> component;
                dfs(i, visited, adj, component);
                ans.push_back(component);
            }
        }
    }

    bool CycleBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
    {
        unordered_map<int, int> parent;
        parent[src] = -1;
        visited[src] = 1;
        queue<int> q;
        q.push(src);

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (auto neighbour : adj[front])
            {
                if (visited[neighbour] == true && neighbour != parent[front])
                {
                    return true;
                }
                else if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = 1;
                    parent[neighbour] = front;
                }
            }
        }
        return false;
    }

    string CycleDet(int vertex)
    {
        unordered_map<int, bool> visited;
        for (int i = 0; i < vertex; i++)
        {
            if (!visited[i])
            {
                bool ans = CycleBFS(i, visited, adj);
                if (ans == 1)
                {
                    return "Yes";
                }
            }
        }
        return "No";
    }

    void shortestPath(int start, int end)
    {
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        queue<int> q;
        q.push(start);
        parent[start] = -1;
        visited[start] = true;

        while (!q.empty())
        {
            int front = q.front();
            q.pop()

                for (auto i : adj[front])
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    parent[i] = front;
                    q.push(i);
                }
            }
        }

        vector<int> ans;
        int currentNode = end;
        ans.push_back(t);

        while (currentNode != start)
        {
            currentNode = parent[currentNode];
            ans.push_back(currentNode);
        }

        reverse(ans.begin(), ans.end());

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    void print()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int m;
    cout << "Enter number of edges: ";
    cin >> m;

    graph g;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        g.addEdge(u, v, false);
    }

    g.print();

    // g.BFS(n);

    // g.DFS(n);
    g.CecleDet(n);

    return 0;
}