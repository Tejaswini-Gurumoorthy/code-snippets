#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter number of vertices and edges : " << endl;
    cin >> n >> m;
    vector<int> g[n];
    cout << "Enter the graph : " << endl;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    for (int j = 0; j < n; j++)
    {
        for (auto i : g[j])
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
