#include <bits/stdc++.h>
using namespace std;

/*
  || Problem : Longest Common Subsequence ||

            intput :    stirng A = A B C D G H 
                        string B = A E D F H R
            output :    3    //COMMAN LATTER = A,D,H


*/

/*
// USING RECURSION ONLY 

int LCS(string a,string b,int n,int m)
{
    // Base condition for recursion
    if(n==0||m==0)
    return 0;
     
    //checking the last character 
    if(a[n-1]==b[m-1])
    return 1+LCS(a,b,n-1,m-1);
    else
        {
            int x,y;
            x = LCS(a,b,n,m-1);
            y = LCS(a,b,n-1,m);
            return max(x,y);
        }

}
*/

int dp[1000][1000];

/*
//USING RECURSION + DP

int LCS(string a, string b, int n, int m)
{
    memset(dp, -1, sizeof(dp));  // to assign the value -1 to whole matrix
    
    //Base condition
    if (n == 0 || m == 0)
        return 0;

    //checking for the value is in DP or not
    if (dp[n][m] != -1)
        return dp[n][m];

    //choice condition
    //checking for the value of last charcter of string
    if (a[n - 1] == b[m - 1])
        return dp[n][m] = 1 + LCS(a, b, n - 1, m - 1);
    else
    {
        int x, y;
        x = LCS(a, b, n, m - 1);
        y = LCS(a, b, n - 1, m);
        return dp[n][m] = max(x, y);
    }
}
*/

// USING DP + ITRETION (optimal solution)
// Run without TLE
int LCS(string a, string b, int n, int m)
{
    // Set the base condition
    // first row and collumn to 0
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            if (i == 0 || j == 0)
                dp[i][j] = 0;

    // Traversing the string 
    // filling matrix of DP
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //storing the value in matrix
            if (a[i] == b[j])
                dp[i + 1][j + 1] = 1 + dp[i][j];
            else
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        }
    }

    // return the ans 
    // ans is always the last cube of matrix
    return dp[n][m];
}
int main()
{
    string a;
    string b;

    // taking input
    cout << "Enter stirng 1";
    cin >> a;
    cout << "Enter string 2";
    cin >> b;

    int x, y;
    x = a.length();
    y = b.length();

    // function call
    cout << LCS(a, b, x, y);
}