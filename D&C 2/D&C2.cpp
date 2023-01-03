#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void DivideAndSummarize(vector<long long> vet, unordered_set<long long> &possibilidades)
{
    long long sum = 0;
    for (int i = 0; i < (int)vet.size(); i++)
    {
        sum += vet[i];
    }
    possibilidades.insert(sum);

    long long min = *min_element(vet.begin(), vet.end());
    long long max = *max_element(vet.begin(), vet.end());

    if (min == max)
        return;

    long long meio = (min + max) / 2;

    vector<long long> inf;
    vector<long long> sup;

    for (int i = 0; i < (int)vet.size(); i++)
    {
        if (vet[i] <= meio)
            inf.push_back(vet[i]);
        else
            sup.push_back(vet[i]);
    }
    
    DivideAndSummarize(inf, possibilidades);
    DivideAndSummarize(sup, possibilidades);
}

int main(int argc, char const *argv[])
{
    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        int vettam;
        cin >> vettam;

        int testtam;
        cin >> testtam;

        vector<long long> vet(vettam);
        vector<long long> test(testtam);
        for (int i = 0; i < vettam; i++)
        {
            cin >> vet[i];
        }
        for (int i = 0; i < testtam; i++)
        {
            cin >> test[i];
        }

        unordered_set<long long> possibilidades;

        DivideAndSummarize(vet, possibilidades);

        for (int i = 0; i < vettam; i++)
        {
            if (possibilidades.count(test[i]) == 1)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }

        vet.clear();
        test.clear();
        possibilidades.clear();
    }
    
    return 0;
}
