/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<bits/stdc++.h>

using namespace std;


bool canjump(vector <int> v)
{
    
    int i=0, far = 0, farest = 0, end = 0;
    
    if (v.size() == 1)
    {
        return true;
    }
    
    for (i = 0; i< v.size(); i++)
    {
        if ( i+ v[i] > farest)
        {
            farest = i + v[i];
            if (farest >= v.size() - 1)
            {
                return true;
            }
        }
        if (i==end)
        {
            end = farest;
            
            if ( i == end and v[i] == 0)
            {
                return false;
            }
        }
    }
    
    return false;
}

int main()
{
    std::vector< int > v { 0 } ;
    bool ans = canjump(v);
    cout << ans;
    return 0;
}