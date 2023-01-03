#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    while (true)
    {
        cin >> n;
        if (n == 0)
        {
            break;
        }

        vector<int> v;
        int aux;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            v.push_back(aux);
        }
        
        sort(v.begin(), v.end());
        int soma = 0;
        int total = 0;
        while ((int)v.size() != 1)
        {
            soma = v[0] + v[1];
            total += soma;
            v.erase(v.begin());
            v.erase(v.begin());
            v.push_back(soma);
            sort(v.begin(), v.end());
        }
        cout << total << endl;
        v.clear();
    }
    return 0;
}
