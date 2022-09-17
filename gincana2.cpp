#include <bits/stdc++.h>

#define ll long long int
#define nl endl

using namespace std;

int n, m, r;

vector<int> grafo[1002];
int visitados[1002];

void bfs(int i)
{
    queue<int> fila;

    fila.push(i);

    while (!fila.empty())
    {
        int u = fila.front();
        fila.pop();

        visitados[u] = 1;

        for (int j = 0; j < grafo[u].size(); j++)
        {
            int v = grafo[u][j];

            if (visitados[v] == 0)
            {
                fila.push(v);
            }
        }
    }
}

int main(void)
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;

        cin >> a >> b;

        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (visitados[i] == 0)
        {
            r++;
            bfs(i);
        }
    }

    cout << r << nl;

    return 0;
}