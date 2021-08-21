#include<iostream>
using namespace std;

void reverse(int a[],int n)
{
        //Swap element of array
        for(int i = 0 ;i<n/2;i++)
        {
                int temp = a[i];
                a[i] = a[n-i-1];
                a[n-i-1]  = temp;
        }
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

    //reverse
    reverse(a,n);
    
    cout<<endl<<"--> Reverse array is  :"<<endl;
    for(int i = 0 ;i<n;i++)
    {
        cout<<a[i]<<"  ";
    }
}