#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    long long n;
    cin >> n;

    for (long long i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
    cout << n << endl;
    
    return 0;
}