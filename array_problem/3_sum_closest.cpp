/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
//#include <bits/stdc++.h>
#include <bits/stdc++.h>

using namespace std;

    int threeSumClosest(vector<int>& v, int t ) 
    {
        int i,j,k,l, c_sum = INT_MAX, sum = INT_MAX, d = INT_MAX, c_d = INT_MAX;
        sort (v.begin() , v.end());
    /*
    for (i = 0; i < v.size() ; i++)
    {
        cout << v[i];
    }
    cout << "\n";
    */
    //i = 0, j = i+1, k = v.size() - 1;
    
        for (i = 0; i< v.size(); i++)
       {
           j = i+1;
           k = v.size() - 1;
        
           while ( j < k)
           {
               c_sum = v[i] + v[j] + v[k];
               if (sum == INT_MAX)
               {
                   sum = c_sum;
               }
               c_d = t - c_sum;
            
               if ( abs (c_d) < d)
               {
                   d = abs(c_d);
                   sum = c_sum;
               }
            
               if ( c_d > 0 )
               {
                   j++;
                   /*
                   while( v[j] == v[j-1] && j < k )
                   {
                       j++;
                   }
                   */
               }
               else if ( c_d < 0)
               {
                   k--;
                   /*
                   while ( v[k] == v[k+1] && j < k)
                   {
                       k++;
                   }
                   */
               }
               else
               {
                    return sum;     
               }
            
            }
        
        
        }
    
         return sum;    
    }
    
 
    
    
                   


int main()
{
    std::vector< int > v {1, 1, 1 , 1} ;
    int target = 0;
    
    int ans = threeSumClosest(v, target);
    
    std::cout <<  ans;

    return 0;
}