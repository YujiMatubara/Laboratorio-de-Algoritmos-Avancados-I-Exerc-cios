#include <iostream>

using namespace std;

int Lis(int* v, int n)
{
    int* lis;
    int max = 0;
    lis = (int*)malloc(sizeof(int) * n);
 
    for (int i = 0; i < n; i++)
    {
        lis[i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
            }
        }
    }
        
    for (int i = 0; i < n; i++)
    {
        if (max < lis[i])
        {
            max = lis[i];
        }
    }

    free(lis);
    return max;
}
 
/* Driver program to test above function */
int main()
{
    int n;
    cin >> n;
    
    int v[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int k = sizeof(v) / sizeof(v[0]);

    cout << Lis(v, k);

    return 0;
}