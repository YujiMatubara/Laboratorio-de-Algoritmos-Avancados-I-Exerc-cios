#include <iostream>
#include <cstring>

using namespace std;

void swapping(int &a, int &b)
{
   int temp;
   temp = a;
   a = b;
   b = temp;
}

void display(int *array, int size)
{
    for(int i = 0; i<size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void merge(int *array, int l, int m, int r) {
    int i, j, k, nl, nr;
    nl = m-l+1; nr = r-m;
    int larr[nl], rarr[nr];
    for(i = 0; i<nl; i++)
        larr[i] = array[l+i];
    for(j = 0; j<nr; j++)
        rarr[j] = array[m+1+j];
    i = 0; j = 0; k = l;
    while(i < nl && j<nr)
    {
        if(larr[i] <= rarr[j])
        {
            array[k] = larr[i];
            i++;
        }
        else
        {
            array[k] = rarr[j];
            j++;
        }
        k++;
    }
    while(i<nl)
    {
        array[k] = larr[i];
        i++; k++;
    }
    while(j<nr)
    {
        array[k] = rarr[j];
        j++; k++;
    }
}

void mergeSort(int *array, int l, int r)
{   
    int m;
    if(l < r)
    {
        m = l+(r-l)/2;
        mergeSort(array, l, m);
        mergeSort(array, m+1, r);
        merge(array, l, m, r);
    }
}

void Print(int n, int* vet)
{
    for (int i = 0; i < n; i++)
    {
        cout << vet[i] << " ";
    }
    cout << endl;
}

int FindKnight(int cabeca, int n, int* knights)
{
    for (int i = 0; i < n; i++)
    {
        if (knights[i] >= cabeca)
        {
            return i;
        }   
    }
    
    return -1;   //retorna a posição do cavaleiro no vetor
}

void War(int n, int m, int* heads, int* knights)
{
    mergeSort(heads, 0, n - 1); //ordenar cabeças crescentemente
    mergeSort(knights, 0 ,m - 1);   //ordenar cavaleiros crescentemente

    int exercito[n];
    memset(exercito, -1, sizeof(exercito));
    int k = 0;
    for (int i = 0; i < n; i++) //passa por todas as cabeças
    {
        int pos = FindKnight(heads[i], m, knights);   //acha o menor cavaleiro possível
        
        if (pos == -1)  //não foi possível encontrar um cavaleiro disponível
        {
            cout << "Loowater is doomed!" << endl;
            return;
        }

        exercito[k] = knights[pos];   //monta o exercito e retira o cavaleiro da lista de cavaleiros disponíveis
        knights[pos] = -1;
        k++;
    }
    
    int gold = 0;
    for (int i = 0; i < n; i++)
    {
        gold += exercito[i];
    }
    cout << gold << endl;
}

int main(int argc, char const *argv[])
{
    int n, m;

    while (true)
    {
        cin >> n >> m;

        int heads[n];
        int knights[m];

        if (n == 0 && m == 0)
        {
            break;
        }

        for (int i = 0; i < n; i++)
        {
            cin >> heads[i];
        }    

        for (int i = 0; i < m; i++)
        {   
            cin >> knights[i];
        }

        War(n, m, heads, knights);
    }

    return 0;
}