//Dado um tabuleiro e um cavalo quantos caminhos são possíveis de forma que o cavalo passe por todas as casas?
#include <iostream>
#include <cstring>  //para usar memset

using namespace std;

#define N 5

long int np = 0;

int const nummov = 8;

int movimentos[nummov][2] = {-1, 2,
                            -2, 1,
                            -2, -1,
                            -1, -2,
                            1, -2,
                            2, -1,
                            2, 1,
                            1, 2};

void ImprimeTab(bool mat[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool Valido(bool tab[N][N], int lin, int col)
{
    return ((lin >= 0) && (lin < N) && (col >= 0) && (col < N) && !tab[lin][col]);
}

void Backtracking(bool tab[N][N], int lin, int col, int count)
{
    int c;
    int l;

    if (count == (N * N))
    {
        np++;
        return;
    }
    
    for (int i = 0; i < nummov; i++)
    {
        l = lin + movimentos[i][0];
        c = col + movimentos[i][1];
        if (Valido(tab, l, c))
        {
            tab[l][c] = true;
            Backtracking(tab, l, c, count + 1);
            tab[l][c] = false;
        }
        
    }
    
}

int main(int argc, char const *argv[])
{
    bool tab[N][N];

    memset(tab, false, sizeof(tab));
    tab[0][0] = true;   //começa com o cavalo no (0, 0)
    Backtracking(tab, 0, 0, 1);
    cout << "Existem " << np << " caminhos possíveis." << endl;
    return 0;
}