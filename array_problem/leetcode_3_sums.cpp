/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

    vector<vector<int>> threeSum( vector<int>& nums) 
    {
        int i, j,k,l,r, sum ;
        sort(nums.begin() , nums.end());
        cout << "sorted array :\n";
        for ( i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << " ";
        }
        vector <vector <int> > v;
        
        for (i = 0; i<nums.size(); i++)
        {
            if (i >= 1 && nums[i] == nums[i-1])
            {
                continue;
            }
            
            j = i+1;
            k = nums.size() - 1;
            
            while ( j > i && k > j )
            {
               sum = nums[i] + nums[j] + nums[k];
               if (sum > 0)
               { 
                   k--;

               }
               else if ( sum < 0)
               {
                   j++;
               }
               else
               {
                   v.push_back(   { nums[i] , nums[j], nums[k] } );
                   j++;
                   if (v.size() == 6)
                   {
                       printf("size is 6");
                   }
                    while ( j < k && nums[j] == nums[j-1])
                   {    
                      j++;
                   }
                }
            
               
             }
        }
        return v;

    }
int main()
{
    vector<int> vec { -1,0,1,2,-1,-4,-2,-3,3,0,4  };
    vector < vector <int> > ans = threeSum(vec);
    cout << ans.size() << "\n";
    
    for (int i = 0; i < ans.size() ; i++)
    {
        for ( int j = 0; j< ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
