#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*  || PROBLEM : Edit Distance ||

    input : string A = sunday
            string B = saturday

    ouput : 3  // replace n with r, insert t , insert a;

*/

int dp[1000][1000];

/*
// USING RECURSION + DP 
int EditD(string a, string b, int n, int m)
{
    memset(dp, -1, sizeof(dp));


    if (n == 0)
        return m;
    if (m == 0)
        return n;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (a[n - 1] == b[m - 1])
        return dp[n][m] = EditD(a, b, n - 1, m - 1);

    int x = EditD(a, b, n, m - 1);
    int y = EditD(a, b, n - 1, m);
    int z = EditD(a, b, n - 1, m - 1);

    return dp[n][m] = 1 + min(x, min(y, z));
}
*/

//Using DP with ITRATION
int EditD(string a, string b, int n, int m)
{
    // Traversing the string
    // filling matrix of DP
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            // Base case 
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;

            //storing the value in matrix
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            else
            {
                int x = dp[i - 1][j - 1]; // Replace
                int y = dp[i - 1][j];     // DELETE
                int z = dp[i][j - 1];     //Insert

                dp[i][j] = 1 + min(x, min(y, z));
            }
        }
    }

    // return the ans
    // ans is always the last cube of matrix
    return dp[n][m];
}
main()
{
    string a;
    string b;

    //Input
    cin >> a;
    cin >> b;

    int n = a.length();
    int m = b.length();

    //Function call
    cout << EditD(a, b, n, m);
}