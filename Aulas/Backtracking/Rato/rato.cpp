//temos um rato no labirinto, começando em (0, 0) quer ir até (n-1, n-1), e o tabuleiro tem barreiras, 1 é livre, 0 é obstáculo
#include <iostream>
#include <cstring>

using namespace std;

#define N 100

int tab[N][N];
bool solucao[N][N];

int n;

int const numMov = 4;

int movimentos[numMov][2] = {0, 1,
                            1, 0,
                            0, -1,
                            -1, 0};

void ImprimeTab(bool mat[N][N])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool Valido(int lin, int col)
{
    return ((lin >= 0) && (lin < n) && (col >= 0) && (col < n) && (solucao[lin][col] != 1) && (tab[lin][col] == 1));
}

bool Caminho(int lin, int col)
{
    int x;
    int y;

    //caminho encontrado
    if (x == n - 1 && y == n - 1 && tab[n - 1][n - 1] == 1)
    {
        solucao[x][y] = true;
        return true;
    }
    
    for (int i = 0; i < numMov; i++)
    {
        x = lin + movimentos[i][0];
        y = col + movimentos[i][1];
        if (Valido(x, y))
        {
            solucao[x][y] = true;
            if (Caminho(x, y))
            {
                return true;
            }
            solucao[x][y] = false;
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    memset(solucao, false, sizeof(solucao));

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> tab[i][j];
        }
    }
    
    solucao[0][0] = true;
    if (Caminho(0, 0))
    {
        cout << "Caminho encontrado" << endl;
    }
    else
    {
        cout << "Caminho não encontrado" << endl;
    }

    ImprimeTab(solucao);
    
    return 0;
}