//encontrar um elemento em um vetor
//retorna o índice
//recursivo

#include <iostream>

using namespace std;

#define MAX 5

int Find(int* vet, int k, int i)
{
    //condição de parada    
    if (i == MAX)
    {
        return -1;
    }

    if (k == vet[i])
    {
        return i;
    }
    else
    {
        return Find(vet, k, i + 1);
    }
    
}

int main(int argc, char const* argv[])
{
    int vet[MAX] = {4, 7, 2, 5, 9};

    cout << "Elemento encontrado no índice " << Find(vet, 9, 0) << "." << endl;
}