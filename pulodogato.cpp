/*********************************/
/*     questão: Pulo do gato     */
/*          OBI - 2018           */
/*     nivel: 1 Terceira fase    */
/*  Solução de Julio Nunes Avelar*/
/*********************************/

#include <bits/stdc++.h> // impremento a minha biblioteca

using namespace std; // uso espaço de nome padrão

#define oo 10000000 // defino infinito como 10 elevado a 7, para que nem valor alcance ele

int grid[505][505]; // crio minha matriz grid grid
int dist[505][505]; // crio minha  matriz de marcação

int n, m, r; // crio minhas variaveis n, m e a de resposta(r)

bool verifica(int i, int j)
{                                              // crio minha função para verificar os limites
    return i < n && i >= 0 && j < m && j >= 0; // retorno i e j edentro dos limites
}

void bfs(int x, int y)
{                               // crio minha função bfs
    queue<pair<int, int>> fila; // crio minha fila de pair com a posição i e j

    fila.push({x, y}); // adiciono i e j na fila

    while (!fila.empty())
    { // olho se tem alguem na fila

        x = fila.front().first;  // coloco x como o primeiro numero (i)
        y = fila.front().second; // coloco y como o segundo numero (j)

        fila.pop(); // limpo a fila

        for (int i = -2; i <= 2; i++) // percorro todos os vizinhos
            for (int j = -2; j <= 2; j++)
            {
                int xi = x + i; // crio xi como uma posição i vizinha
                int xj = y + j; // crio xj como uma posição j vizinha
                if (verifica(xi, xj) && dist[xi][xj] == oo && grid[xi][xj] == 1)
                {                                  // verifico xi e xj ta nos limites, olho se a posição ja não foi visitada, e olho se i e j e uma lajota preto
                    dist[xi][xj] = dist[x][y] + 1; // falo que a distancia de xi e xj , e igual a distancia da lajota anterior mais um
                    fila.push({xi, xj});           // adiciono xi e xj na fila
                }
            }
    }
}

int main()
{                  // inicio minha função inicial{
    cin >> n >> m; // pego os valores de n e m

    for (int i = 0; i < n; i++) // pego os valores da matriz
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j]; // coleto o valor da posição i e j e coloco na minha matriz grid
            dist[i][j] = oo;   // seto o dist dessa posição como infinito
        }

    dist[0][0] = 0; // falo que a distancia inicial e igual a 0

    bfs(0, 0); // chamo a bfs na posição inicial

    if (dist[n - 1][m - 1] == oo)
        cout << "-1"; // verifico se a ultima lajota for igual a infinito falo que e impossivel chegar nela, se for impossivel imprimo -1
    else
        cout << dist[n - 1][m - 1]; // caso contrario imprimo o valor nela

    return 0; // termino meu codigo
}
