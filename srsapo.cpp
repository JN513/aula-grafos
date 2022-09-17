#include <bits/stdc++.h>

#define ll long long int
#define nl endl
//#define oo 10000000

using namespace std;

int n, m, p, spi, spj, npi, npj;

int matriz[101][101];
int dist[101][101];

int dirx[] = {0, 0, 0, 0, 0, 0, 1, 2, 3, -1, -2, -3};
int diry[] = {1, 2, 3, -1, -2, -3, 0, 0, 0, 0, 0, 0};

bool verifica(int x, int y)
{
    return x > 0 && x <= n && y > 0 && y <= m;
}

void dfs(int i, int j)
{
    dist[i][j] = 1;

    for (int k = 0; k < 12; k++)
    {
        int x = i + dirx[k];
        int y = j + diry[k];

        if (verifica(x, y) && matriz[x][y] == 1 && dist[x][y] == 0)
        {
            dfs(x, y);
        }
    }
}

int main(void)
{
    cin >> n >> m;

    cin >> p;

    for (int i = 0; i < p; i++)
    {
        int a, b;

        cin >> a >> b;

        matriz[a][b] = 1;
    }

    cin >> spi >> spj >> npi >> npj;

    dfs(spi, spj);

    if (dist[npi][npj] == 0)
    {
        cout << "N" << nl;
    }
    else
    {
        cout << "S" << nl;
    }
}