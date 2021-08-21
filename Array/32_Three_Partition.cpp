#include <bits/stdc++.h>
using namespace std;
/*
    || Problem : Three way partitioning  ||

    Aproach 1 : sort the array O(NlogN)

    Aproach 2 : Using dutch flag algo 
*/
void partition(int array[],int n,int a,int b)
{
        int l = 0;  //point the position which left has smaller value than in
        int h = n-1;    //point the position which right has greater value 

        int i=0;    //itreator 
        while(i<=h)
        {
            if(array[i]<a)
                {
                swap(array[i],array[l]);
                l++;
                i++;
                }
            else if(array[i]>b)
                {
                swap(array[i],array[h]);
                h--;
                }
            else
                i++;
            
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

    int x,y;
    cout<<"--> Enter a : ";
    cin>>x;
    cout<<"--> Enter b : ";
    cin>>y;
    //Input End
    
    partition(a,n,x,y);

    cout << "--> partition  Array : " << endl;
    for (int i = 0; i < n; i++)
        cout<< a[i]<<" ";

    return 0;
}
