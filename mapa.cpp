#include <bits/stdc++.h>

#define ll long long int
#define nl endl

using namespace std;

int dirx[4] = {0, 0, 1, -1};
int diry[4] = {1, -1, 0, 0};

int n, m, xi, yi, xf, yf;
vector<string> grid;

bool verifica(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(int x, int y)
{
    queue<pair<int, int>> fila;

    fila.push({x, y});

    while (!fila.empty())
    {
        int x = fila.front().first;
        int y = fila.front().second;

        fila.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dirx[i];
            int ny = y + diry[i];

            if (verifica(nx, ny) and grid[nx][ny] == 'H')
            {
                xf = nx;
                yf = ny;

                fila.push({nx, ny});

                grid[nx][ny] = '.';
            }
        }
    }
}

int main(void)
{

    cin >> n >> m;

    grid.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    bool ok = true;

    for (int i = 0; i < n and ok; i++)
    {
        for (int j = 0; j < m and ok; j++)
        {
            if (grid[i][j] == 'o')
            {
                xi = i;
                yi = j;

                ok = false;

                break;
            }
        }
    }

    bfs(xi, yi);

    cout << xf + 1 << " " << yf + 1 << nl;

    return 0;
}