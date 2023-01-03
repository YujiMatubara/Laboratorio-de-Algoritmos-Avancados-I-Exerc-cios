#include <iostream>

using namespace std;

long int escada = 0;

long int Maximo(long int a, long int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
    
}

void BuscaBinaria(long int esq, long int dir, long int n)
{
    long int meio = (esq + dir) / 2;
    long int moedas = (meio / 2) * (meio * 1);

    if (esq > dir)
    {
        escada--;
        cout << escada;
        return;
    }
    
    if (moedas > n)
    {
        dir = meio - 1;
    }
    else
    {
        esq = meio + 1;
        escada = Maximo(meio, escada);
    }

    return BuscaBinaria(esq, dir, n);
}

int main(int argc, char const *argv[])
{
    long int n;
    cin >> n;

    BuscaBinaria(0, n, n);
    
    return 0;
}
