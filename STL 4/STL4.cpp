#include <iostream>
#include <set>

using namespace std;

int main(int argc, char const *argv[])
{
    int cases;
    int n;
    set<int> s;

    cin >> cases;
    bool flag = true;
    int max = 0;
    for (int i = 0; i < cases; i++)
    {
        cin >> n;

        int entrada[n];
        for (int i = 0; i < n; i++)
        {
            cin >> entrada[i];
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (s.find(entrada[j]) == s.end() && flag)
                {
                    s.insert(entrada[j]);
                }
                else
                {
                    flag = false;
                }
            }
            if (max < (int)s.size())
            {
                max = (int)s.size();
            }
            s.clear();
            flag = true;
        }
        cout << max << endl;
        max = 0;
    }
    
    return 0;
}
