#include <bits/stdc++.h>

using namespace std;

int diri[4] = {1, -1, 0, 0};
int dirj[4] = {0, 0, -1, 1};

int matriz[1005][1005];
int n, m, r;

bool verifica(int i, int j)
{
    return i < n && j < m && i >= 0 && j >= 0;
}

void dfs(int i, int j)
{
    matriz[i][j] == 2;

    for (int k = 0; k < 4; k++)
    {
        int xi = i + diri[k];
        int xj = j + dirj[k];

        if (!verifica(xi, xj))
            continue;
        if (matriz[xi][xj] == 1)
            dfs(xi, xj);
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matriz[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (matriz[i][j] == 1)
            {
                dfs(i, j);
                r++;
            }

    cout << r << endl;

    return 0;
}
