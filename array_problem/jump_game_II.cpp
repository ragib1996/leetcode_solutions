/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<bits/stdc++.h>

using namespace std;


int jump (vector <int> v)
{
    int ans = 0, end = 0, i,j,k, farest= 0;
    
    if( v.size() == 1 )
    {
        return 0;
    }
    
    for (i = 0; i< v.size(); i++)
    {
        if ( i + v[i] > farest)
        {
            farest = i + v[i];
            if (farest >= v.size() -1 )
            {
                return ans+1;
            }
        }
        
        if ( i == end)
        {
            ans++;
            end = farest;
        }
    }
    
    return ans;
    
}

int main()
{
    
    std::vector<int > v   {1,1,1,1} ;
    int ans = jump(v);
    cout << ans;

    return 0;
}