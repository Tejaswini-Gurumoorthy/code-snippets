#include <bits/stdc++.h>
using namespace std;
const int N = 100;
vector<pair<int, int>> g[N];
bool vis[N] = {0};
vector<int> wt(N,INFINITY);

void dijkstra(int start)
{
    bool enqueued[N] = {0}; // to keep track if the element s enqueued or not
    queue<int> q;
    q.push(start);       // pushing the starting vertex inside queue
    enqueued[start] = 1; // starting vertex now inside the queue
    wt[start] = 0;

    while (!q.empty())
    {
        for (auto child : g[q.front()]) // front= whichever came first
        {
            if (vis[child.first] == 0)
            {
                if (enqueued[child.first] == 0)
                {
                    q.push(child.first);
                    enqueued[child.first] = true;
                }
                if (wt[q.front()] + child.second < wt[child.first])
                {
                    wt[child.first] = wt[q.front()] + child.second;
                }
            }
        }
        vis[q.front()] = true; // marking visited when all its children are enqueued
        q.pop();               // and finally popping it out
    }
    return;
}

void print(int start, int n)
{
    cout<<"Minimum distance of : "<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" from "<<start<<" is : "<<wt[i]<<endl;
    }

}

int main()
{
    int n, m, vert;
    cout << "Enter number of vertices and edges : " << endl;
    cin >> n >> m;

    cout << "Enter the graph : " << endl;
    for (int i = 0; i < m; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        g[v1].push_back({v2, wt});
        g[v2].push_back({v1,wt}); //for directed, comment out this line
    }
    cout << "Enter starting vertex : " << endl;
    cin >> vert;
    dijkstra(vert);
    print(vert,n);
}
