#include <bits/stdc++.h>
using namespace std;

/*
        ||Problem : Subarray with 0 sum ||

        Aproach 1 : BruteForce
        Aproach 2 : Using map

        # Algorithm

           CONDITION 1:  IF PREFIX SUM IS REPEATING THAN THERE IS THE SUBARRAY SUM = 0 
           CONDITION 2:  IF SINGLE ELEMENT IS ZERO THAN...
           CONDITION 3:  IF SUM TILL THE TRAVSERSAL IS ZERO
*/

// Aproach using Map       // TC = O(N)    //SC = O(N)
string isSumZero(int a[],int n)
{
    //To store the prefix sum 
    //we have to check it for later
    unordered_map<int,int>  m;

    int sum=0;

    //traverse
    for(int i= 0;i<n;i++)
    {
        sum  = sum + a[i];  // prefix sum
        //check for 
        //prefix sum = 0
        //a[i] = 0
        //repeated prefix sum
        if(sum==0 || m[sum] || a[i]==0 )    
        return "YES";
        else
            m[sum] = 1; //storing the sum for checking later

    }
    return "No";

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
    //Input End

    cout<<"--> Array contain Sub array with sum zero or not ? : ";
    cout<<isSumZero(a,n);
    
     return 0;
}
