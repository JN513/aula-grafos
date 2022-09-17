#include <bits/stdc++.h>

using namespace std;

vector<string> v;
int ma[505][505];
int m, f;

int dirx[4] = {0, 0, 1, -1};
int diry[4] = {1, -1, 0, 0};

bool ver(int x, int y)
{
    return x >= 0 && x < m && y >= 0 && y < v[x].size();
}

void dfs(int i, int j)
{
    int az = v[i][j] - '0';
    ma[i][j] = 1;

    if (az <= f)
    {
        v[i][j] = '*';

        for (int k = 0; k < 4; k++)
        {
            int xi = i + dirx[k];
            int xj = j + diry[k];

            if (!ver(xi, xj))
                continue;
            if (ma[xi][xj] == 0)
                dfs(xi, xj);
        }
    }
}

int main()
{
    cin >> m >> f;

    for (int i = 0; i < m; i++)
    {
        string st;
        cin >> st;
        v.push_back(st);
    }

    dfs(0, 0);

    for (int i = 0; i < m; i++)
        cout << v[i] << endl;

    return 0;
}
