#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    vector<long long> dp(n, 0x7fffffff);
    dp[0] = 0;

    for (long long i = 0; i < n; i++)
    {
        for (long long j = i + 1; j <= i + 2; j++)
        {
            if (j < n)
            {
                dp[j] = min(dp[j], dp[i] + abs(v[i] - v[j]));
            }
        }
    }
    cout << dp[n - 1];

    return 0;
}
