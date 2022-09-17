#include <bits/stdc++.h>

using namespace std;

int m, n, in, r1, r = 1;

vector<int> v[1000];
int amig[1000];

void dfs(int k)
{
    for (int i = 0; i < (int)v[k].size(); i++)
    {
        int w = v[k][i];
        if (amig[w] == 0)
        {
            amig[w] = 2;
            r++;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);

    scanf("%d%d", &in, &r1);

    amig[in] = 2;

    for (int i = 1; i <= m; i++)
    {
        int a;
        scanf("%d", &a);
        for (int j = 0; j < a; j++)
        {
            int x;
            scanf("%x", &x);
            v[i].push_back(x);
        }
    }

    for (int i = r1 - 1; i <= m; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            int y = v[i][j];
            if (amig[y] == 2)
                dfs(i);
        }
    }

    printf("%d\n", r);

    return 0;
}