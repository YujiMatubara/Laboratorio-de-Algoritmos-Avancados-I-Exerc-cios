#include <iostream>

using namespace std;

#define TAREFAS 3

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    int mat[n][TAREFAS];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < TAREFAS; j++)
        {
            cin >> mat[i][j];
        }
    }
    
    int dp[n][TAREFAS];
    for (int i = 0; i < TAREFAS; i++)
    {
        dp[0][i] = mat[0][i];
    }
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < TAREFAS; j++)
        {
            if (j == 0)
            {
                dp[i][j] = mat[i][j] + max(dp[i - 1][j + 1], dp[i - 1][j + 2]);
            }
            else if (j == 1)
            {
                dp[i][j] = mat[i][j] + max(dp[i - 1][j + 1], dp[i - 1][j - 1]);
            }
            else
            {
                dp[i][j] = mat[i][j] + max(dp[i - 1][j - 2], dp[i - 1][j - 1]);
            }
        }
    }
    
    cout << max(max(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]) << endl;

    return 0;
}
