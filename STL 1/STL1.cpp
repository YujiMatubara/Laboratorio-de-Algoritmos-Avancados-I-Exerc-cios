#include <iostream>
#include <map>

using namespace std;

void inverter()
{
    int tam;
    cin >> tam;

    int vet[tam];
    for (int i = tam - 1; i >= 0; i--)
    {
        cin >> vet[i];
    }

    for (int i = 0; i < tam; i++)
    {
        cout << vet[i] << endl;
    }
}

int main()
{
    int ncases;
    cin >> ncases;

    for (int i = 0; i < ncases; i++)
    {
        inverter();
        if (i != ncases -1)
        {
            cout << endl;
        }
        
    }

    return 0;
}