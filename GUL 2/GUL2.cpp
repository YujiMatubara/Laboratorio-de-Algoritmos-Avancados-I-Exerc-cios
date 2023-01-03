#include <iostream>
#include <cstring>
#include <string>

using namespace std;

#define TAMEXPRESSION 12

long int TimesFirst(int numtam, int optam, int num[TAMEXPRESSION], char op[TAMEXPRESSION - 1])
{
    int aux;
    for (int i = 0; i < optam; i++)
    {
        if (op[i] == '*')
        {
            aux = num[i] * num[i + 1];
            num[i] = aux;
            for (int j = i + 1; j < numtam; j++)
            {
                num[j] = num[j + 1];
            }
            for (int j = i; j < optam; j++)
            {
                op[j] = op[j + 1];
            }
            numtam--;
            optam--;
            i--;
        }
    }

    //somar tudo
    long int result = 0;
    for (int i = 0; i < numtam; i++)
    {
        result += num[i];
    }
    return result;
}


long int PlusFirst(int numtam, int optam, int num[TAMEXPRESSION], char op[TAMEXPRESSION - 1])
{
    int aux;
    for (int i = 0; i < optam; i++)
    {
        if (op[i] == '+')
        {
            aux = num[i] + num[i + 1];
            num[i] = aux;
            for (int j = i + 1; j < numtam; j++)
            {
                num[j] = num[j + 1];
            }
            for (int j = i; j < optam; j++)
            {
                op[j] = op[j + 1];
            }
            numtam--;
            optam--;
            i--;
        }
    }

    //multiplicar tudo
    long int result = 1;
    for (int i = 0; i < numtam; i++)
    {
        result *= num[i];
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    long int num[TAMEXPRESSION];
    char op[TAMEXPRESSION - 1];

    string line;
    getline(cin, line); //ignora o primeiro /n de n
    for (int i = 0; i < n; i++)
    {
        memset(num, -1, sizeof(num));
        memset(op, -1, sizeof(op));

        getline(cin, line);

        int numcount = 0;
        int opcount = 0;

        char number[10];
        for (int i = 0; i < (int)line.size(); i++)
        {
            if ((char)line[i] == '+' || (char)line[i] == '*')
            {
                op[opcount] = line[i];
                opcount++;
            }
            else
            {
                int k = 0;
                while ((char)line[i] != '+' && (char)line[i] != '*' && i < (char)line.size())
                {
                    number[k] = line[i];
                    k++; i++;
                }
                number[k] = '\0';
                num[numcount] = atoi(number);
                numcount++;
                i--;
            }
        }

        int numplus[TAMEXPRESSION];
        char opplus[TAMEXPRESSION - 1];

        int numtimes[TAMEXPRESSION];
        char optimes[TAMEXPRESSION - 1];
        
        for (int i = 0; i < numcount; i++)
        {
            numplus[i] = num[i];
            numtimes[i] = num[i];
        }
        for (int i = 0; i < opcount; i++)
        {
            opplus[i] = op[i];
            optimes[i] = op[i];
        }

        cout << "The maximum and minimum are " << PlusFirst(numcount, opcount, numplus, opplus) << " and " 
        << TimesFirst(numcount, opcount, numtimes, optimes) << "." << endl;
    }
    

    return 0;
}