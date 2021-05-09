#include<iostream>
#include<map>
using namespace std;

/* || PROBLEM : Longest Repeating Subsequence ||

        INPUT : String A = AXXXY
        OUTPUT : 2   // LENGTH OF LONGEST REPEATING SUBSEQUENCE

    #ALGORITHM 

    FINDING LCS WHICH HAS //I!=J// CONDITION 
*/
int dp[1000][1000];

// USING DP + ITRETION (optimal solution)
// Run without TLE
int LCS(string a,int n)
{
    // Set the base condition
    // first row and collumn to 0
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            if (i == 0 || j == 0)
                dp[i][j] = 0;

    // Traversing the string 
    // filling matrix of DP
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //storing the value in matrix
            //subcase
            if (a[i] == a[j]&&i!=j)
                dp[i + 1][j + 1] = 1 + dp[i][j];
            else
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        }
    }

    // return the ans 
    // ans is always the last cube of matrix
    return dp[n][n];
}

main()
{   

    string a;

    cin>>a;


    cout<<LCS(a,a.length());
}