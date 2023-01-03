#include <iostream>

using namespace std;

int Ada(string& a, string& b)
{
    long long tama = a.size();
    long long tamb = b.size();

    long long mat[tama + 1][tamb + 1];

    for (int i = 1; i <= tama; i++)
    {
        mat[i][0] = 0;
    }
    for (int i = 0; i <= tamb; i++)
    {
        mat[0][i] = 0;
    }
    

    for (int i = 1; i <= tama; i++)
    {
        for (int j = 1; j <= tamb; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                mat[i][j] = mat[i - 1][j - 1] + 1;
            }
            else
            {
                mat[i][j] = max(mat[i][j - 1], mat[i - 1][j]);
            }
            
        }
    }
    
    return mat[tama][tamb];
}

int main(int argc, char const *argv[])
{   
    long long tama;
    long long tamb;

    cin >> tama >> tamb;

    long long alfabeto[26];

    for (int i = 0; i < 26; i++)
    {
        cin >> alfabeto[i];
    }

    string a;
    string b;

    cin >> a >> b;

    string a2;
    string b2;

    for (int i = 0; i < (int)a.size(); i++)
    {
        for (int j = 0; j < (int)alfabeto[a.at(i) - 97]; j++)
        {
            a2.push_back(a.at(i));
        }
    }
    for (int i = 0; i < (int)b.size(); i++)
    {
        for (int j = 0; j < (int)alfabeto[b.at(i) - 97]; j++)
        {
            b2.push_back(b.at(i));
        }
    }

    cout << Ada(a2, b2);

    return 0;
}