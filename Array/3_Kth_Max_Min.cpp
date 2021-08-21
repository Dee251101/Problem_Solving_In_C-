#include<bits/stdc++.h>
using namespace std;

/*
// Aproach 1 || BruteForce ||
// TC = O(nLogn)
main()
{
    // Input 
    int n,spos;
    cout<<"--> Enter the number of element :";
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
    {
        cout<<"--> Enter element  "<<i+1<<" : ";
        cin>>a[i];
    }
    // Input End

    //Sorting array 
    sort(a,a+n);

     
    cout<<"--> Ente the position : ";
    cin>>spos;

    //Output
    cout<<"--> Smallest element at that possition is  :";
    cout<<a[spos];
}
*/

// Aproach 2 || Heap = Priority Queue ||
// TC = O(nLogk)


int min(int arr[],int n,int k)
{
    //Heap aka Priority queue
    priority_queue<int> max;

    for(int i = 0 ;i<n;i++)
    {
        max.push(arr[i]);
        
        if(max.size()>k)
        max.pop();
    }
    return max.top();
}
main()
{
    // Input 
    int n,spos;
    cout<<"--> Enter the number of element :";
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
    {
        cout<<"--> Enter element  "<<i+1<<" : ";
        cin>>a[i];
    }
    cout<<"--> Ente the position : ";
    cin>>spos;
    // Input End

    //Output
    cout<<"--> Smallest element at that possition is  :";
    cout<<min(a,n,spos);

}
