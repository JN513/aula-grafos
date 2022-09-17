#include <bits/stdc++.h>

using namespace std;

int s, t, p, r = 0, v[201], vi[201];
vector<int> m[201];

void dfs(int x)
{
    for (int i = 0; i < m[x].size(); i++)
    {
        int k = m[x][i];

        if (vi[k] == 0 and v[k - 1] < v[x - 1])
        {
            vi[k] = 1;
            r++;
            dfs(k);
        }
    }
}

int main()
{
    cin >> s >> t >> p;

    for (int i = 0; i < s; i++)
        cin >> v[i];

    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;
        m[b].push_back(a);
        m[a].push_back(b);
    }

    dfs(p);

    cout << r << endl;

    return 0;
}
