#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 600

int Compare(string a, string b)
{
    if (a[0] <= b[0])
    {
        if (a[0] == b[0])
        {
            if (a[1] <= b[1])
            {
                return 0;
            }
            else
            {
                return 1;
            }
            
        }
        
        return 0;
    }
    else
    {
        return 1;
    }
}

void insertionSortInt(pair<int, string> p[], int tam)
{
    int i, key, j;
    string str;
    for (i = 1; i < tam; i++)
    {
        key = p[i].first;
        str = p[i].second;
        j = i - 1;
 
        while (j >= 0 && p[j].first < key)
        {   
            p[j + 1].first = p[j].first;
            p[j + 1].second = p[j].second;
            j = j - 1;
        }
        p[j + 1].first = key;
        p[j + 1].second = str;
    }
}

void SortString(pair<int, string> p[], int tam)
{
    int pos;
    for (int i = 0; i < tam - 1; i++)
    {
        if (p[i].first == p[i + 1].first)
        {
            string key = p[i].second;
            int qnt = p[i].first;
            for (int j = i + 1; j < tam; j++)
            {
                if (Compare(key, p[j].second) == 1)
                {
                    key = p[j].second;
                    qnt = p[j].first;
                    pos = j;
                }
            }
            p[pos].first = p[i].first;
            p[pos].second = p[i].second;
            p[i].first = qnt;
            p[i].second = key;
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<vector<string>> v;
    vector<string> read;
    vector<string> repeted;
    pair<int, string> inscricao[MAX];

    bool flag = false;
    bool flag2 = false;
    bool flag3 = false;

    string line; 
    getline(cin, line);

    while (line[0] != '0')
    {
        if (line[0] >= 65 && line[0] <= 90)
        {
            if (flag)
            {
                v.push_back(read);
                read.clear();
            }
            flag = true;
            read.push_back(line);
        }
        else if (line[0] >= 97 && line[0] <= 122)
        {
            for (int i = 0; i < (int)v.size() ; i++)
            {
                for (int j = 0; j < (int)v[i].size(); j++)
                {
                    //cout << line << " - " << v[i][j] << endl;
                    if (line.compare(v[i][j]) == 0)
                    {
                        flag2 = true;
                    }
                }
            }
            for (int i = 0; i < (int)read.size(); i++)
            {
                if (line.compare(read[i]) == 0)
                {
                    flag3 = true;
                }
                
            }

            if (flag2)
            {
                repeted.push_back(line);
                flag2 = false;
            }
            if (!flag3)
            {
                read.push_back(line);
            }
        }
        else if (line[0] == '1')
        {
            v.push_back(read);

            int count = 0;
            int flagr = false;
            for (int i = 0; i < (int)v.size(); i++)
            {
                for (int j = 1; j < (int)v[i].size(); j++)
                {
                    for (int k = 0; k < (int)repeted.size(); k++)
                    {
                        if (v[i][j].compare(repeted[k]) == 0)
                        {
                            flagr = true;
                            break;
                        }
                    }
                    if (!flagr)
                    {
                        count++;
                    }
                    
                }
                inscricao[i].first = count;
                inscricao[i].second = v[i][0];
                count = 0;
                flagr = false;
            }

            insertionSortInt(inscricao, v.size());
            SortString(inscricao, v.size());

            for (int i = 0; i < (int)v.size(); i++)
            {
                cout << inscricao[i].second << " " << inscricao[i].first << endl;
            }
            v.clear();
            read.clear();
            repeted.clear();
        }
        getline(cin, line);   
    }

    return 0;
}
