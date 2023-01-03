//Dado um tabuleiro e um cavalo quantos caminhos são possíveis de forma que o cavalo passe por todas as casas?
#include <iostream>
#include <cstring>  //para usar memset

using namespace std;

#define N 10

long int np = 0;

int const nummov = 8;

bool existeMovimento;

//agora em sentido horário
int movimentos[nummov][2] = {1, 2,
                            2, 1,
                            2, -1,
                            1, -2,
                            -1, -2,
                            -2, -1,
                            -2, 1,
                            -1, 2};

void ImprimeTab(int mat[N][N])
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

bool Valido(int tab[N][N], int lin, int col)
{
    return ((lin >= 0) && (lin < N) && (col >= 0) && (col < N) && tab[lin][col] == -1);
}

int CalcGrau(int tab[N][N], int x, int y)
{
    int qnt = 0;
    for (int i = 0; i < nummov; i++)
    {
        if (Valido(tab, x + movimentos[i][0], y + movimentos[i][1]))
        {
            qnt++;
        }
    }
    return qnt;
}

bool MenorGrau(int tab[N][N], int lin, int col, int* l, int* c)
{
    int x;
    int y;
    int menorGrau = nummov;
    int grau;

    for (int i = 0; i < nummov; i++)
    {
        x = lin + movimentos[i][0];
        y = col + movimentos[i][1];
        if (Valido(tab, x, y))
        {
            grau = CalcGrau(tab, x, y);
            if (grau < menorGrau)
            {
                menorGrau = grau;
                *l = x;
                *c = y;
            }
        }
    }

    if (menorGrau == nummov)
    {
        return false;
    }
    
    return true;
}

bool Backtracking(int tab[N][N], int lin, int col, int count)
{
    int c;
    int l;

    if (count == (N * N))
    {
        np++;
        cout << "Caminho encontrado." << endl;
        ImprimeTab(tab);
        return true;
    }
    
    existeMovimento = MenorGrau(tab, lin, col, &l, &c);
    if (existeMovimento)
    {
        tab[l][c] = count + 1;
        if(Backtracking(tab, l, c, count + 1))
            return true;
        tab[l][c] = -1; //esse cara nunca é executado, aqui temos O(n^2), ele sempre encontra solução na primeira tentativa
    }

    return false;   
}

void Iterativo(int tab[N][N], int lin, int col, int count)
{
    int c = col;
    int l = lin;

    for (int i = 0; i < N * N; i++)
    {
        existeMovimento = MenorGrau(tab, l, c, &l, &c);
        if (existeMovimento)
        {
            count++;
            tab[l][c] = count;
        }
    }

    ImprimeTab(tab);
    return;
}

int main(int argc, char const *argv[])
{
    int tab[N][N];

    memset(tab, -1, sizeof(tab));
    tab[0][0] = 1;   //começa com o cavalo no (0, 0)
    //Backtracking(tab, 0, 0, 1); //como a solução virou iterativa podemos fazer em apenas um for
    Iterativo(tab, 0, 0, 1);
    return 0;
}