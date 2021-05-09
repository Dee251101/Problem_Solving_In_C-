#include <bits/stdc++.h>
using namespace std;

/* || Problem : Count Palindorme Subsequence ||

        


*/
int dp[1000][1000];


// Using Recurison + DP    // TC = O(n^2)

int Palin_sub(string s, int n, int m)
{
     // set -1 to matrix
    //memset(dp, -1, sizeof(dp));

    // Base case
    if (n > m)
        return 0;

    // subcases
    if (n == m)
        return 1;

    //checking in matrix for value
    if (dp[n][m] != -1)
        return dp[n][m];

    if (s[n] == s[m])
        return dp[n][m] = 1 + Palin_sub(s, n + 1, m) + Palin_sub(s, n, m - 1);
    else
        return dp[n][m] = Palin_sub(s, n, m - 1) + Palin_sub(s, n + 1, m) - Palin_sub(s, n + 1, m - 1);
    
}


/*

//USING DP 
int Palin_sub(string str,int N)
{
	 

	// create a 2D array to store the count of palindromic
	// subsequence
	memset(dp, 0, sizeof(dp));

	// palindromic subsequence of length 1
	for (int i = 0; i < N; i++)
		dp[i][i] = 1;

	// check subsequence of length L is palindrome or not
	for (int L = 2; L <= N; L++) {
		for (int i = 0; i <= N-L; i++) {
			int k = L + i - 1;
			if (str[i] == str[k])
				dp[i][k]
					= dp[i][k - 1] + dp[i + 1][k] + 1;
			else
				dp[i][k] = dp[i][k - 1] + dp[i + 1][k]
							- dp[i + 1][k - 1];
		}
	}

	// return total palindromic subsequence
	return dp[0][N - 1];
}
*/
int main()
{
    string s;
    cin >> s;

    

    // Call first aproach
   cout << Palin_sub(s, 0, s.length() - 1);  
      
    // Calling second aproach
    //  cout<<Palin_sub(s,s.length());
}