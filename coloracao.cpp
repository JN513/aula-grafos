#include <bits/stdc++.h>

#define ll long long int
#define nl endl

using namespace std;

int n, m, r;

char mat[1026][1026];

int dirx[4] = {0, 0, 1, -1};
int diry[4] = {1, -1, 0, 0};

bool verifica(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(int i, int j)
{
    queue<pair<int, int>> fila;

    fila.push(make_pair(i, j));

    mat[i][j] = 'o';

    while (!fila.empty())
    {
        i = fila.front().first;
        j = fila.front().second;

        fila.pop();

        for (int k = 0; k < 4; k++)
        {
            int xi = i + dirx[k];
            int xj = j + diry[k];

            if (verifica(xi, xj) && mat[xi][xj] == '.')
            {
                mat[xi][xj] = 'o';
                fila.push(make_pair(xi, xj));
            }
        }
    }
}

int main(void)
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == '.')
            {
                bfs(i, j);
                r++;
            }
        }
    }

    cout << r << nl;

    return 0;
}