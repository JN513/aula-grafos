#include <bits/stdc++.h>

#define ll long long int
#define nl endl

using namespace std;

int grafo[100][100];
int grafo3[100][100];

vector<int> grafo2[100];

int main(void)
{
    grafo[1][2] = 1;
    grafo[2][1] = 1;

    grafo2[1].push_back(2);
    grafo2[2].push_back(1);

    return 0;
}