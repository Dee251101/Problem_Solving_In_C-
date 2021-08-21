#include <bits/stdc++.h>
using namespace std;
/*
        || Problem : Smallest subarray with sum greater than x  ||

    Input : 
        A[] = {1, 4, 45, 6, 0, 19}
         x  =  51
    Output: 3
    Explanation:
        Minimum length subarray is 
        {4, 45, 6}

    
        Aproach 1 : BruteForce
        Aproach 2 : Sliding window Teqnique 
        
*/

//Aproach : Using Sliding window Teqnique         //TC =  O(N)  //SC = O(1)
int MinSubArray(int a[], int n, int sum)
{
    int i = 0;  // window starting pointer
    int j = 0;  // window ending pointer
    int s = 0;  //Curnt sum
    int ans = INT_MAX; //answer

    //Traverse
    while (j < n)
    {
        //Calculation
        s = s + a[j];
        
        //Base case for increament window
        if (s < sum)
        {
            j++;
        }
        else    //Shrinking window
        {
            //Shrinking 
            while (s >= sum)
            {
                //Answer storing
                ans = min(ans, j - i + 1);

                // slideing window
                s = s - a[i];
                i++;
            }

            //increment window size
            j++;
        }
    }

    return ans;
}
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

    int sum;
    cout << "--> Enter the sum : ";
    cin >> sum;
    //Input End

    cout << "--> minmum Window size is ";
    cout << MinSubArray(a, n, sum);
    return 0;
}
