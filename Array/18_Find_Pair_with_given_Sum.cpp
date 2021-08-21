#include <bits/stdc++.h>
using namespace std;

/*
        || Problem :  Count pairs with given sum ||

                Given an array of N integers, and an integer K, 
            find the number of pairs of elements in the array whose sum is equal to K.

        Input:
            N = 4, K = 6
            arr[] = {1, 5, 7, 1}
        Output: 2
        Explanation: 
            arr[0] + arr[1] = 1 + 5 = 6 
            and arr[1] + arr[3] = 5 + 1 = 6.


        Aproach 1: Brute force
        Aproach 2: using Hashmap    (Optimal)

*/
/*
//Aproach 1 : BruteForce             // TC = O(N^2) 
int pairCount(int a[],int n,int sum)
{
    int count = 0 ;

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(a[i]+a[j]==sum)
            count++;
        }
    }

    return count;
}
*/

//Aprroach 2: Using Hashmap        // TC = O(N)        //SC = O(N)
int pairCount(int a[], int n, int sum)
{
    //use to store number and counter of that number
    unordered_map<int, int> m;

    int x;  // Difference between sum and number a[i]

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        x = sum - a[i]; //diff or needed number to be pair

        //Check for the x is available before or not.
        if (m[x] != 0)  //if number x is present in the map.
        {
            count = count + m[x]; // given number a[i] will make pair m[x] numbers of times 
        }

        m[a[i]]++; //store the counter of every number 
    }

    return count;
}

/*
//Aproach 3 : Using 2 pointer method     // TC = Nlog(n)
int pairCount(int a[],int n,int sum)
{
    int i = 0;      //front pointer
    int j = n-1;    //back pointer

    int count  = 0; //Counter

    //sort
    sort(a,a+n);

    //Traverseing array 
    while(i<j)
    {

        if(a[i]+a[j]<sum)
        {
                i++;
        }
        else if(a[i]+a[j]>sum)
        {
            j--;
        }
        else        //sum = a[i]+a[j;]
        {
            count++;
            i++;  // or j-- any thing we can do 
        }
    }

    return count;
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

    int sum;
    cout << "--> Enter SUM Of pairs : ";
    cin >> sum;
    //Input End

    cout << "--> Number of pair with given sum is :  ";
    cout << pairCount(a, n, sum);
    return 0;
}
