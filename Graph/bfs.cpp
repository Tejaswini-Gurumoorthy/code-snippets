#include <bits/stdc++.h>
using namespace std;
const int N = 100;
vector<int> g[N];
bool vis[N] = {0};

void bfs(int start)
{
    bool enqueued[N] = {0}; //to keep track if the element s enqueued or not
    queue<int> q; 
    q.push(start);//pushing the starting vertex inside queue
    enqueued[start] = 1; //starting vertex now inside the queue
    cout << q.back(); //printing the stating vertex

    while (!q.empty())
    {
        for (auto child : g[q.front()]) //front= whichever came first
        {
            if (enqueued[child] == 0)
            {
                q.push(child);
                enqueued[child] = true;
                cout << q.back()<<" ";//printing the order in which it is enqueued
            }
        }
        vis[q.front()] = true;//marking visited when all its children are enqueued
        q.pop();//and finally popping it out
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
