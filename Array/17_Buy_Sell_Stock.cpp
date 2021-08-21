#include <bits/stdc++.h>
using namespace std;

/*
    || Problem : Best Time to Buy and Sell Stock    ||

    Aproach 1 : BruteForce
    Aproach 2 : Logiclly

    # Algorithm / Logic for Aproach 2 :

        take every day as selling day. we must have to sell the stock 

        [ the Max_Profit is = todays price - minimum price till now ]

        1. Traverse array 
            Keep track the min price and calculate profit for every days
        2. return max profit.
*/


/*
// Aprroach 1 : Brute force    //Tc = O(N^2)

int profit(int a[],int n)
{
    int profit=0;
   
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(a[i]<=a[j])
                {
                    profit  = max(profit,a[j]-a[i]);
                }
            }
        }
        return profit;
}

*/

// Aproach 2 : LOGICLLY          //TC = O(N)
// Valley Pick Aproach
int profit(int a[],int n)
{

         //to keep track of previous min
         
        int minPrice = a[0]; // tract the minimum price before the current day price 
        int maxProfit = 0;      // track maximumm profit till the day 

        // Travrse the arraay 
        // Considering the every day is the selling day 
        for(int i=0;i<n;i++)
        {

            minPrice = min(minPrice,a[i]);  //updating min price before the day
            
            maxProfit = max(maxProfit,a[i]-minPrice); // max profit till the day

        }


        return maxProfit;
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

    cout<<"--> Maximum Profit is : ";
    cout<<profit(a,n);
    
    return 0;
}
