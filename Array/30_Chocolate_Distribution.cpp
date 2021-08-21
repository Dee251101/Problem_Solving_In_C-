#include <bits/stdc++.h>
using namespace std;
/*

    || Problem : Given an array A[ ] of positive integers of size N, 
                where each value represents the number of chocolates in a packet. 
                Each packet can have a variable number of chocolates. 
                There are M students, the task is to distribute chocolate packets among M students such that :
                
                1. Each student gets exactly one packet.
                2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.
        
        Input:
            N = 8, M = 5
            A = {3, 4, 1, 9, 56, 7, 9, 12}
        Output: 6
        Explanation: The minimum difference between 
            maximum chocolates and minimum chocolates 
            is 9 - 3 = 6 by choosing following M packets :
            {3, 4, 9, 7, 9}.
*/
int ChocolateDistribution(int a[],int n,int m)
{
    sort(a,a+n);
        
        int i= 0;
        int j = m-1;
        int ans = INT_MAX;
        while(j<n)
        {
            int x = a[j]-a[i];
            i++;
            j++;
            ans = min(ans,x);
        }
        return ans;
}
int main()
{
     //Input
    int n;
    cout << "--> Enter Number Of element for first array: ";
    cin >> n;
    int a[n];
    cout << "--> Enter elements of Array 1 : " << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m;
    cout<<"--> Number of Students : ";
    cin>>m;
    
    cout<<"-->  minimum possible difference between maximum and minimum number of chocolates given to a student :  ";
    cout<<ChocolateDistribution(a,n,m);
     return 0;
}
