#include <bits/stdc++.h>

using namespace std;

int dirx[4] = {0, 0, 1, -1};
int diry[4] = {1, -1, 0, 0};

int c, l;
int x, y, n, old = -1;
int ma[1005][1005];

bool verifica(int x, int y)
{
    return x >= 0 and x < c and y >= 0 and y < l;
}

void bfs(int x, int y)
{
    queue<pair<int, int>> fila;

    old = ma[x][y];

    fila.push({x, y});

    ma[x][y] = n;

    while (!fila.empty())
    {
        x = fila.front().first;
        y = fila.front().second;

        fila.pop();

        for (int k = 0; k < 4; k++)
        {
            int xi = x + dirx[k];
            int xj = y + diry[k];

            if (!verifica(xi, xj))
                continue;

            if (ma[xi][xj] == old)
            {
                ma[xi][xj] = n;
                fila.push({xi, xj});
            }
        }
    }
}

int main(void)
{
    cin >> c >> l;

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < l; j++)
        {
            cin >> ma[i][j];
        }
    }

    cin >> x >> y >> n;

    bfs(x - 1, y - 1);

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < l; j++)
        {
            cout << ma[i][j];
            if (j != l - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}