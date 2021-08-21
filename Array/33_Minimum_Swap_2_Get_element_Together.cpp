#include <bits/stdc++.h>
using namespace std;

/*
    || Problem : Minimum swaps and K together ||

    Input  : arr[ ] = {2, 1, 5, 6, 3} and K = 3
    Output : 1
    Explanation:
                 To bring elements 2, 1, 3 together, swap element '5' with '3'
            such that final array will be- arr[] = {2, 1, 3, 6, 5}
            
    //Aproach : Using sliding window teqnique

*/

//Sliding window teqnique          // Tc = O(n)
int minSwap(int *a, int n, int k)
{
    int good = 0;   //count the value which satisfying condition

    //counting value which satisfying conditoin
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= k)
            good++;
    }
    //if no value found
    if (good == 0)
        return 0;


    int i = 0;  //pointer to point start oof window
    int j = 0;  //pointer to point end of window

    int bad = 0;    //count the not satisfying value in current window =  our ans (swap)

    int ans = INT_MAX;
    
    //sliding window
    while (j < n)
    {
        //calculation
        if (a[j] > k)
            bad++;

        //reaching to window
        if (j < good - 1)
            j++;
        else    //reached to window
        {
            //Storing the ans 
            ans = min(ans, bad);

            //sliding window ahead 
            if (a[i] > k)
                bad--;
            i++;
            j++;
        }
    }

    //ans
    return ans;
}

int main()
{
    int n;
    cout << "--> Enter Number Of element for first array: ";
    cin >> n;
    int a[n];
    cout << "--> Enter elements of Array 1 : " << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int k;
    cout << "--> Ente the Value of K  : ";
    cin >> k;

    cout<<"--> Minimum swap required is :  ";
    cout<<minSwap(a,n,k);
    return 0;
}
