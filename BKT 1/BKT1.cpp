#include <iostream>

using namespace std;

int sumSubsetXOR = 0;

int BitwiseXOR(int a, int b)
{
    return (a ^ b);
}

int SumXOR(int n, int* vet, bool* vetb)
{
    int sum = 0;
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (flag && vetb[i])
        {
            flag = false;
            sum = vet[i];
        }
        else if (vetb[i])
        {
            sum = BitwiseXOR(sum, vet[i]);
        }
    }
    if (flag)
    {
        sum = 0;
    }
    
    return sum;
}

void SumSubset(int n, int* vet, bool* vetb, int iterator)
{
    if (iterator == n)
    {
        sumSubsetXOR += SumXOR(n, vet, vetb);
        return;
    }
    
    vetb[iterator] = true;
    SumSubset(n, vet, vetb, iterator + 1);
    vetb[iterator] = false;
    SumSubset(n, vet, vetb, iterator + 1);
    return;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    int vet[n];
    bool vetb[n];
    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
    }
    
    SumSubset(n, vet, vetb, 0);
    cout << sumSubsetXOR;
    return 0;
}
