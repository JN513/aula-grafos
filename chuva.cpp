#include <bits/stdc++.h>

#define ll long long int
#define nl endl

using namespace std;

int n, m;
char matriz[505][505];

void dfs(int i, int j)
{
    if (matriz[i + 1][j] == '.')
    {
        matriz[i + 1][j] = 'o';
        dfs(i + 1, j);
    }
    else if (matriz[i + 1][j] == '#')
    {
        if (matriz[i][j - 1] == '.')
        {
            matriz[i][j - 1] = 'o';
            dfs(i, j - 1);
        }
        if (matriz[i][j + 1] == '.')
        {
            matriz[i][j + 1] = 'o';
            dfs(i, j + 1);
        }
    }
}

int main(void)
{
    cin >> n >> m;
    int w;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matriz[i][j];
        }
    }

    for (int i = 0; i < m; i++)
        if (matriz[0][i] == 'o')
        {
            w = i;
            break;
        }

    dfs(0, w);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matriz[i][j];
        }
        cout << nl;
    }

    return 0;
}