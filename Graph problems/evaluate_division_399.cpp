// evaluate_division_399.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>
#include<vector>
#include<unordered_map>

using namespace std;

struct node
{
    string s;
    vector<struct node*> e;
    vector <double > val;
};

/*
void f(int matrix[j][j] , int j)
{
    int x, y, z;
    for (x = 0; x <= j; x++)
    {
        for (y = 0; y <= j; y++)
        {
            if (y == x)
            {
                continue;
            }
            for (z = x + 1; z <= j; z++)
            {
                if (z == x || z == y)
                {
                    continue;
                }
                if (matrix[x][z] == 0)
                {
                    if (matrix[x][y] != 0 && matrix[y][z] != 0)
                    {
                        matrix[x][z] = matrix[x][y] * matrix[y][z];
                        matrix[z][x] = 1 / matrix[x][z];
                    }

                }
            }
        }
    }
}
*/
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
{
    vector <double> ans{};
    int i, j= -1, k, l, x, y, z;
    unordered_map < string, int > um{};
    struct node* n[40];
    /*
    for (i = 0; i < equations.size(); i++)
    {
        if (um.find(equations[i][0]) == um.end())
        {
            n[j] = new(node);
            n[j]->s = equations[i][0];
            um[equations[i][0]] = n[j];
            j++;
        }
        if (um.find(equations[i][1]) == um.end())
        {
            n[j] = new(node);
            n[j]->s = equations[i][1];
            um[equations[i][1]] = n[j];
            j++;
        }

        um[equations[i][0]]->e.push_back(um[equations[i][1]]);
        um[equations[i][0]]->val.push_back(values[i]);
        um[equations[i][1]]->e.push_back(um[equations[i][0]]);
        um[equations[i][1]]->val.push_back(1/values[i]);

    }
    
    cout << n[0]->val.size();
    */
    double matrix[40][40]; 

    for (i = 0; i < 40; i++)
    {
        for (j = 0; j < 40; j++)
        {

            matrix[i][j] = 0.0;
        }
    }

    j = -1;
    for (i = 0; i < equations.size(); i++)
    {
        string s1 = equations[i][0];
        string s2 = equations[i][1];
        
        if (um.find(s1) == um.end())
        {
            j++;
            um[s1] = j;
            k = j;
        }
        else
        {
            k = um[s1];
        }

        if (um.find(s2) == um.end())
        {
            j++;
            um[s2] = j;
            l = j;
        }
        else
        {
            l = um[s2];
        }

        matrix[k][l] = values[i];
        matrix[l][k] = 1 / (values[i]);

        //cout << matrix[k][l] << " " << matrix[l][k] << " ";
    }

    for (x = 0; x <= j; x++)
    {
        for (y = 0; y <= j; y++)
        {
            if (y == x)
            {
                continue;
            }
            for (z = 0 ; z <= j ; z++)
            {
                if (z == x || z == y)
                {
                    continue;
                }
                if (matrix[x][z] == 0)
                {
                    if (matrix[x][y] != 0 && matrix[y][z] != 0)
                    {
                        matrix[x][z] = matrix[x][y] * matrix[y][z];
                        matrix[z][x] = 1 / matrix[x][z];
                    }
                    
                }
            }
        }
    }

    for (i = 0; i < queries.size(); i++)
    {
        if (um.find(queries[i][0]) == um.end())
        {
            j = -1;
            //cout << queries[i][0] << " Not found. ";
        }
        else
        {
            j = um[queries[i][0]];
        }
        if (um.find(queries[i][1]) == um.end())
        {
            k = -1;
            //cout << queries[i][1] << " Not found. ";
        }
        else
        {
            k = um[queries[i][1]];
        }

        if (j == -1 || k == -1)
        {
            ans.push_back(-1);
        }
        else if (j == k)
        {
            ans.push_back(1);
        }
        else if (matrix[j][k] == 0)
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(matrix[j][k]);
        }
        
    }

    return ans;
}

int main()
{
    vector <vector <string>> equations{ {"a", "c"}, { "b", "e" } , {"c", "d"}, {"e" , "d"} };

    vector <double> values {2.0 , 3.0, 0.5, 5.0 };
    vector <vector <string>> queries{ {"a", "b"} }; // { "x1", "x5" }, { "x1", "x3" }, { "x5", "x5" }, { "x5", "x1" }, { "x3", "x4" }, { "x4", "x3" }, { "x6", "x6" }, { "x0", "x0" }


    vector <double> ans = calcEquation(equations, values, queries);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
