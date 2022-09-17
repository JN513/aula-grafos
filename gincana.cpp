#include <bits/stdc++.h>

#define ll long long int
#define nl endl

using namespace std;

int n, m;

int v[1005];
vector<int> grafo[5005];

void bfs(int u)
{
    queue<int> q;

    q.push(u);

    while (!q.empty())
    {
        int u = q.front();

        q.pop();

        for (int i = 0; i < grafo[u].size(); i++)
        {
            int am = grafo[u][i];

            if (v[am] == -1)
            {
                v[am] = v[u];

                q.push(am);
            }
        }
    }
}

int main(void)
{

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        v[i] = -1;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;

        cin >> a >> b;

        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    int n_ti = 0;

    for (int i = 1; i <= n; i++)
    {
        if (v[i] == -1)
        {
            n_ti++;

            v[i] = n_ti;
            bfs(i);
        }
    }

    cout << n_ti << nl;

    return 0;
}