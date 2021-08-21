#include <bits/stdc++.h>
using namespace std;

/*
    || Problem : Minimum number of jumps ||

    # Input:
        N=11 
        arr=1 3 5 8 9 2 6 7 6 8 9 
    # Output: 3 

    # Explanation: 
        First jump from 1st element to 2nd 
        element with value 3. Now, from here 
        we jump to 5th element with value 9, 
        and from here we will jump to last.

*/



//Using DP                //TC = O(N^2)

/*
        Example :
                Array    3 3 0 2 1 2 4 2 0 0
                         | | | | | | | | | |               
                DP       4 4 N 3 3 2 1 1 N 0  (N is NULL or -1&& Number is Jump)

        starting to storing value from right to left.
        dp[0] is the ans of problem.
*/
int MinJump(int a[], int n)
{
    int dp[n + 1];
    memset(dp, -1, sizeof(dp));
    dp[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        int step = a[i];
        int min = INT_MAX;
        for (int j = 1; j <= step && i + j < n; j++)
        {
            if (dp[i + j] != -1 && dp[i + j] < min)
                min = dp[i + j];
        }
        if (min != INT_MAX)
        {
            dp[i] = 1 + min;
        }
    }
    return dp[0];
}

/*Left need to understand
int MinJump(int a[],int n)
{
        int curReach = a[0];
        int Jump = 1;
        int curMax = a[0];

        for(int i=0;i<n;i++)
        {
            if(i+a[i]>curMax)
            curMax = i+a[i];
            if(i==curReach)
            {
                Jump++;
                curReach = curMax;
            }
        }
    return Jump;
}
*/
int main()
{
    //Input
    int n;
    cout << "--> Enter Number Of element : ";
    cin >> n;

    int a[n];
    cout << "--> Enter elements of Array : " << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    //Input End


    cout<<"--> Minimum jump need to reach end of the array  is : ";
    cout << MinJump(a, n);

    return 0;
}
