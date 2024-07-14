// unique_bst.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>

using namespace std;

int num_bst(int n)
{
    int a[n+1],i=0,j,k, nodes, root, total = 0, left = 0, right = 0 ;
    for (i = 0; i < n+1; i++)
    {
        a[i] = 1;
    }

    if (i == 0 || i == 1)
    {
        return 1;
    }

    for (nodes = 2; nodes <= n; nodes++)
    {
        total = 0;
        for (root = 1; root <= nodes; root++)
        {
            left = root - 1;
            right = nodes - root;
            total = total + a[left] * a[right];
        }
        a[nodes] = total;
    }

    return a[n ];

}

int main()
{
    int n;
    cin >> n;
    int ans = num_bst(n);
    cout << ans;
    
    return 0;
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
