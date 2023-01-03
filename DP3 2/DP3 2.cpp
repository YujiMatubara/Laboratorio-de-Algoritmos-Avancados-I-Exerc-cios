#include <iostream>

using namespace std;

void LCS(string& a, string& b)
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
    
    string lcs = "";
    while (tamb != 0 && tama != 0)
    {
        if (mat[tama-1][tamb] == mat[tama][tamb])
        {
            tama--;
        }
        else if (mat[tama][tamb-1] == mat[tama][tamb])
        {
            tamb--;
        }
        else
        {
            lcs = b[tamb - 1] + lcs;
            tama--;
            tamb--;
        }
    }

    cout << lcs;
    return;
}

int main(int argc, char const *argv[])
{   
    string a;
    string b;

    cin >> a >> b;

    LCS(a, b);

    return 0;
}