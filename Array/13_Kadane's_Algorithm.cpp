#include <bits/stdc++.h>
using namespace std;

/*
    || KADANE's ALGORITHM ||
    || Problem :  Find the contiguous sub-array with maximum sum. ||


    // Algorithm:

    # Initialize:

        maxSum = INT_MIN;
        currntSum = 0;

    # Loop for each element of the array

        (a) currntSum = currntSum + a[i]
        (b) if(maxSum < currntSum)
                maxSum = currntSum
        (c) if(currntSum < 0)
                currntSum = 0
            return maxSum
*/

//Kadane's Algorithm           // TC  = O(n)      //SC = O(1)
int maxSubarraySum(int a[], int n)
{
    
    int currentSum = 0;     // storing current sum

    int maxSum = INT_MIN;   //ANS storing variable

    //Traversing array
    for(int i=0;i<n;i++)
    {
        currentSum += a[i];     // Updating currnt sum

        if(currentSum > maxSum) // checking for the maxsum and set max sum
            maxSum = currentSum;

        if(currentSum < 0)      // if negative sum then changing the train box(Starting new subarray)
            currentSum = 0;
    }

    return maxSum;      
}
int main()
{
    //Input
    int n;
    cout<<"--> Enter Number Of element : ";
    cin>>n;

    int a[n];
    cout<<"--> Enter elements of Array : "<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    //Input End  

    //Output
    cout<<"--> Maximum Sum of the contiguous sub array : ";
    cout<<maxSubarraySum(a,n);
    
    return 0;
}
