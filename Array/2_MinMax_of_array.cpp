#include<bits/stdc++.h>
using namespace std;

void MinMax(int a[],int n)
{
    int min = INT_MAX;
    int max = 0;

    for(int i = 0 ;i<n;i++)
    {
        if(a[i]<a[min])
        min=i;
        if(a[i]>a[max])
        max=i;
    }

    cout<<"==> Minimum element of the array is :  "<<a[min]<<endl;
    cout<<"==> Maximum element of the array is :  "<<a[max]<<endl; 
 
}
main()
{

    int n;
    cout<<"--> Enter the size of array  :  ";
    cin>>n;
    cout<<"--> Enter the element :"<<endl;
    int a[n];
    for(int i = 0;i<n;i++)
    {
        cout<<"==> Enter element "<<i<<" : ";
        cin>>a[i];
    }

    cout<<endl<<"--> Your array is  :"<<endl;
    for(int i = 0 ;i<n;i++)
    {
        cout<<a[i]<<"  ";
    }

    cout<<endl<<endl;

    MinMax(a,n);
}