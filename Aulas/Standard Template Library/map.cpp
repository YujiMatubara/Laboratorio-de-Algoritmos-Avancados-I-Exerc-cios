#include <unordered_map>
#include <map>
#include <iostream>
#include <sstream>

//programa que crie um histogramas de palavras e imprime a frequência de cada palavra

using namespace std;

map <string, int> hist;

int main(int argc, char const *argv[])
{
    string s = "essa é minha string";
    stringstream ss(s);
    string palavra;
    while (ss >> palavra)
    {
        hist[palavra]++;
    }
    
    map <string, int>::iterator it;
    for (it = hist.begin(); it != hist.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }
    
    return 0;
}
