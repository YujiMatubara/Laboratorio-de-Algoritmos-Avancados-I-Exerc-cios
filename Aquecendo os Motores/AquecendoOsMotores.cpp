#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    int m;

    scanf("%d", &n);
    scanf("%d", &m);

    map<string, string> servers;
    for (int i = 0; i < n; i++)
    {
        string aux1, aux2;

        cin >> aux1 >> aux2;    
        servers.insert(make_pair(aux2, aux1));  //servers[aux2] = aux1;
    }
    
    for (int i = 0; i < m; i++)
    {
        string aux1, aux2;
        
        cin >> aux1 >> aux2;
        aux2.pop_back();

        cout << aux1 << " " << aux2 << "; #" << servers[aux2] << endl;
    }

    return 0;
}