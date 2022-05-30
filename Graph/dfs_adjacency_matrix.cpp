#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int g[N][N];
bool vis[N] = {0};

void dfs(int start, int n)
{
    cout << start << " ";
    vis[start] = true;
    for (int i = 1; i <= n; i++)
    {
        if (g[start][i] == 1)
        {
            if (vis[i])
            {
                continue;
            }
            else
            {
                dfs(i, n);
            }
        }
    }
    return;
}

int main()
{
    int n, m, vert;
    cout << "Enter number of vertices : " << endl;
    cin >> n;

    cout << "Enter the graph : " << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> g[i][j];
        }
    }
    cout << "Enter starting vertex : " << endl;
    cin >> vert;
    dfs(vert, n);
}
