/* 	Questão Toca do Saci neps academy
 */

#include <bits/stdc++.h> //incluo minha biblioteca

using namespace std; // uso o namespace standard

int dirx[4] = {0, 0, 1, -1}; // crio meus vetores de coordenadas
int diry[4] = {1, -1, 0, 0};

int n, m, r = 2, id = false; // crio minhas variaveis de limite e a de resposta com valor inicial igual a 2 por causa do ponto de inicio e o ponto final
int matriz[1005][1005];      // crio minha matriz

bool ver(int x, int y)
{                                              // crio minha variavel para verificar os limites
    return x >= 0 && x < n && y >= 0 && y < m; // verifico os limites e retorno verdadeiro ou falso
}

void dfs(int i, int j)
{                     // crio minha função de busca
    matriz[i][j] = 0; // marco a posição como ja visitada

    for (int k = 0; k < 4 && !id; ++k)
    {                         // percorro todos os vizinhos
        int xi = i + dirx[k]; // crio o xi para facilitar
        int xj = j + diry[k]; // crio o xj também para facilitar, pois não precisarei usar todo o conjunto toda vez atenas o xj, o mesmo vale pro xi

        if (!ver(xi, xj))
            continue; // verifico xi e xj usando minh função ver

        if (matriz[xi][xj] == 2)
        { // verifico se a posição tiver valor igual a 2 termino minha função
            id = true;
            return; // termino a função
        }
        else // caso contrario
            if (matriz[xi][xj] == 1)
            {                // se a posição tiver valor igual a 1 , aplico a função no xi, xj
                r++;         // aumento meu r com mais um
                dfs(xi, xj); // aplico a função no xi e xj
            }
    }
}

int main() // abro minha função principal
{
    cin >> n >> m; // pego o valor de m e n

    for (int i = 0; i < n; ++i) // percorro todas as posições da matriz e pegos os valores de cada posição
        for (int j = 0; j < m; ++j)
            cin >> matriz[i][j]; // pego o valor da posição

    for (int i = 0; i < n; ++i) // percorro toda matriz fazendo a busca
        for (int j = 0; j < m; ++j)
            if (matriz[i][j] == 3)
                dfs(i, j); //  verifico se a posição i e j e igual a 3 e aplico a função se for verdadeiro

    cout << r; // imprimo minha resposta

    return 0; // termino meu codigo
}
