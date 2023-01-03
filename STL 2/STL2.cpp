#include <iostream>
#include <map>

using namespace std;

void Job()
{
    int n;
    int m;

    cin >> n >> m;

    if (n < 1 || n > 100 || m < 0 || m > n - 1)
    {
        cout << "valores inválidos." << endl;
        return;
    }

    int vet[n];

    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
    }
    
    int highPrior = 1;

    //encontrar o segundo maior
    int secondHigherPos = -1;
    int secondHigherValue = 0x7FFFFFFF;

    for (int i = 0; i < n; i++)
    {
        if (vet[i] > vet[m] && secondHigherValue > vet[i])
        {
            secondHigherValue = vet[i];
            secondHigherPos = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i == m)
        {
            //skip
        }
        else if (vet[i] > vet[m])    //no caso vet[m] > vet[m] ele não somará!
        {
            highPrior++;
        }
        else if (vet[i] == vet[m])
        {
            highPrior++;
        }
    }
    
    int i = secondHigherPos;
    do
    {
        i--;
        if (i == m)
        {
            //skip
        }
        else if (vet[i] == vet[m])
        {
            highPrior--;
        }

    } while (secondHigherValue > vet[i] && i > 0);

    cout << highPrior << endl;

    return;
}

int main()
{
    int numCases;

    cin >> numCases;

    for (int i = 0; i < numCases; i++)
    {
        Job();
    }

    return 0;
}