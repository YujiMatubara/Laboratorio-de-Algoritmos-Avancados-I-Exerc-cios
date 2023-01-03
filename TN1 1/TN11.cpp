#include <iostream>
#include <math.h>

using namespace std;

void CrivoEratostenes(long long n)
{
    if (n <= 1)
    {
        cout << "NO" << endl;
        return;
    }
    
    int raiz = sqrt(n);
    
    int vetprimos[10000];
    for (int i = 0; i < 10000; i++)
    {
        vetprimos[i] = -1;
    }
    
    bool flag = false;
    int count = 0;
    //pegar todos os numeros primos até n
    for (int i = 2; i <= raiz; i++)
    {
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {   
                flag = true;
            }
        }
        if (!flag)
        {
            vetprimos[count] = i;
            count++;
        }
        flag = false;
    }

    for (int i = 0; i < count; i++)
    {
        if (n % vetprimos[i] == 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    
    cout << "YES" << endl;
}

int main(int argc, char const *argv[])
{
    long long primo;
    cin >> primo;

    CrivoEratostenes(primo);
    return 0;
}
