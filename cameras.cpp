#include "bits/stdc++.h"

using namespace std;

int n, m, k;

int dirx[4] = {1, -1, 0, 0};
int diry[4] = {0, 0, 1, -1};

int ma[32][32];

bool verifica(int x, int y)
{
    return x > 0 and y > 0 and x <= m and y <= n;
}

void dfs(int i, int j)
{
    if (ma[i][j] != 0)
        return;

    ma[i][j] = 2;

    for (int k = 0; k < 4; k++)
    {
        int xi = i + dirx[k];
        int xj = j + diry[k];

        if (!verifica(xi, xj))
            continue;

        if (ma[xi][xj] == 0)
            dfs(xi, xj);
    }
}

void print()
{
    cout << endl
         << endl;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << ma[i][j] << " ";
        }

        cout << endl;
    }
    cout << endl
         << endl;
}

int main(void)
{

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++)
    {
        int a, b;
        char c;

        cin >> a >> b >> c;

        if (c == 'N')
        {
            for (int j = b; j > 0; j--)
                ma[j][a] = 1;
        }
        else if (c == 'S')
        {
            for (int j = b; j <= m; j++)
                ma[j][a] = 1;
        }
        else if (c == 'L')
        {
            for (int j = a; j <= n; j++)
                ma[b][j] = 1;
        }
        else if (c == 'O')
        {
            for (int j = a; j > 0; j--)
                ma[b][j] = 1;
        }
    }

    dfs(1, 1);

    if (ma[m][n] == 0 or ma[m][n] == 1)
        cout << "N\n";
    else if (ma[m][n] == 2)
        cout << "S\n";

    return 0;
}