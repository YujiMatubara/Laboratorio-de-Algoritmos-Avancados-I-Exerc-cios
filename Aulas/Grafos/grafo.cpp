#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define VISITADO 1
#define NAOVISITADO 0

typedef pair<int, int> ii;  //vertice e peso
typedef vector<ii> vii; //adjacentes
typedef vector<int> vi;
vector<vii> AdjList(200);   //grafo

int v; //#num de vertices
int a;

vi visitado;

void printAdjList()
{
    for (int i = 0; i < v; i++)
    {
        cout << i << ":";
        for (int j = 0; j < AdjList[i].size(); j++)
        {
            cout << "(" << AdjList[i][j].first << "," << AdjList[i][j].second << ") ";
        }
        cout << endl;
    }
    
}

void DFS(int a)
{
    cout << a + 1 << " ";
    visitado[a] = VISITADO;

    for (int i = 0; i < AdjList[a].size(); i++)
    {
        ii v = AdjList[a][i];
        if (visitado[v.first] == NAOVISITADO)
        {
            DFS(v.first);
        }
    }
    return; 
}

int main(int argc, char const *argv[])
{
    cin >> v;

    int a, b;
    while (cin >> a >> b)
    {
        AdjList[a - 1].push_back(ii(b - 1, 0)); //inserindo no grafo
        AdjList[b - 1].push_back(ii(a - 1, 0)); //nao orientado, entao duplicar
    }
    
    visitado.assign(v, NAOVISITADO);

    printAdjList();

    DFS(0);  //Depth First Search -  Busca em Profundidade

    return 0;
}
