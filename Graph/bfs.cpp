#include <bits/stdc++.h>
using namespace std;
const int N = 100;
vector<int> g[N];
bool vis[N] = {0};

void bfs(int start)
{
    bool enqueued[N] = {0};
    queue<int> q;
    q.push(start);
    enqueued[start] = 1;
    cout << q.back();

    while (!q.empty())
    {
        for (auto child : g[q.front()])
        {
            if (enqueued[child] == 0)
            {
                q.push(child);
                enqueued[child] = true;
                cout << q.back()<<" ";
            }
        }
        vis[q.front()] = true;
        q.pop();
    }
    return;
}

int main()
{
    int n, m, vert;
    cout << "Enter number of vertices and edges : " << endl;
    cin >> n >> m;

    cout << "Enter the graph : " << endl;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    cout << "Enter starting vertex : " << endl;
    cin >> vert;
    bfs(vert);
}
