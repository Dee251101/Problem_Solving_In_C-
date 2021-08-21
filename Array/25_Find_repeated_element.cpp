#include <bits/stdc++.h>
using namespace std;

/*
    || Problem : Given an array of size n and a number k, find all elements that appear more than n/k times ||
*/
//Using map
void RepeatedElement(int a[],int n,int k)
{
    unordered_map<int,int> m;

    //creating map
    for(int i=0;i<n;i++)
    {
        m[a[i]]++;
    }
    
    //searching for ans
    for (auto i : m)
    {
        if(i.second > n/k)
        {
            cout<<i.first<<" ";
        }
    }
    
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
    
    int k;
    cout<<"--> Enter the value of K : ";
    cin>>k; 
    //Input End

    cout<<"--> Repeated element is : ";
     RepeatedElement(a, n,k);
    

    return 0;
}
