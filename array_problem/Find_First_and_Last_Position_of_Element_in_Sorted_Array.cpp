/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector <int > ans;
        int i,j,k,l,p, mid;
        int left = 0, right = nums.size() - 1;
        bool flag = false;

        while (left <= right)
        {
            mid = left + (right - left) /2;

            if (nums[mid] == target)
            {
                flag = true;
                break;
            }
            else if ( nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }    

        if (flag == true)
        {
            // left check
            p = mid-1;

            for ( ; p >= 0; p--)
            {
                if (nums[p] != target)
                {
                    ans.push_back(p+1);
                    break;
                }
            }
            
            if ( p + 1 == 0 && nums[p+1] == target)
            {
                ans.push_back(0);
            }

            p = mid + 1;

            for ( ; p < nums.size() ; p++)
            {
                 if (nums[p] != target)
                {
                    ans.push_back(p-1);
                    break;
                }
            }
            
            if ( p == nums.size() && nums[p - 1] == target )
            {
                ans.push_back(p-1);
            }

           
        }
        else
        {
            ans.push_back(-1);
            ans.push_back (-1);
        }

        return ans;

        
    }


int main()
{
    // 2 2
    vector <int > v {5,7,7,8,8,10};
    int target = 5; 
    vector <int > ans = searchRange(v, target);
    
    for (int i = 0; i< ans.size() ; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}