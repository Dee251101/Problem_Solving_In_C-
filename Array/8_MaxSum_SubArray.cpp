#include <bits/stdc++.h>
using namespace std;

/*
    || KADANE's ALGORITHM ||
    || Problem :  Find the contiguous sub-array with maximum sum. ||


    // Algorithm:

    Initialize:

    max_so_far = INT_MIN

    max_ending_here = 0

    Loop for each element of the array

        (a) max_ending_here = max_ending_here + a[i]
        (b) if(max_so_far < max_ending_here)
                max_so_far = max_ending_here
        (c) if(max_ending_here < 0)
                max_ending_here = 0
            return max_so_far
*/

/*
//Working for all negative element 
int maxSubarraySum(int a[], int n){
        
       
    int currentSum = 0;
    int maxSum = INT_MIN;

    for(int i=0;i<n;i++)
    {
        currentSum += a[i];
        if(currentSum < a[i])
            currentSum = a[i];
        if(currentSum > maxSum)
            maxSum = currentSum;
        
    }
    return maxSum;
        
}
*/

//Kadane's Algorithm
// Note : Not working for all negative element
int maxSubarraySum(int a[], int n)
{
    
    int currentSum = 0;     // storing current sum

    int maxSum = INT_MIN;   //ANS storing variable

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
