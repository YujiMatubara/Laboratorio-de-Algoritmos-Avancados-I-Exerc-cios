#include <iostream>

using namespace std;

#define MAXGRID 6
#define MAXPALAVRA 10

int mov[4][2] = {1, 0,
                 0, 1,
                 -1, 0,
                 0, -1};

bool flag = true;

void Search(int n, int m, char grid[MAXGRID][MAXGRID], bool gridb[MAXGRID][MAXGRID], int tam, char palavra[MAXPALAVRA], int posx, int posy, int posp)
{
    if (posp == tam && flag)
    {
        cout << "Yes" << endl;
        flag = false;
        return;
    }
    
    for (int i = 0; i < 4; i++)
    {
        if (palavra[posp] == grid[posx + mov[i][0]][posy + mov[i][1]] && gridb[posx + mov[i][0]][posy + mov[i][1]] == false &&
        (posx + mov[i][0] >= 0) && (posx + mov[i][0] <= n) && 
        (posy + mov[i][1] >= 0) && (posy + mov[i][1] <= m))
        {
            gridb[posx][posy] = true;
            Search(n, m, grid, gridb, tam, palavra, posx + mov[i][0], posy + mov[i][1], ++posp);
            posp--;
            gridb[posx][posy] = false;
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;

    char grid[MAXGRID][MAXGRID];
    bool gridb[MAXGRID][MAXGRID];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf(" %c", &grid[i][j]);
            gridb[i][j] = false;
        }
    }

    int tam;
    char palavra[MAXPALAVRA];
    
    cin >> tam;
    for (int i = 0; i < tam; i++)
    {
        cin >> palavra[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (palavra[0] == grid[i][j])
            {
                Search(n, m, grid, gridb, tam, palavra, i, j, 1);
            }
        }
    }   

    if (flag)
    {
        cout << "No" << endl;
    }
    
    return 0;
}
