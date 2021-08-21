#include <bits/stdc++.h>
using namespace std;

/*
    || Problem : Merge Without Extra Space  ||

        //We can merge it by merge sort too but there is mentioned to not to use extra space so we cant. 

*/
void print(int a[], int b[],int n, int m)
{
    for(int k = 0; k < n ; k++)
    {
        cout<<a[k]<<" ";
    }
    for(int k = 0; k < m ; k++)
    {
        cout<<b[k]<<" ";
    }
}

//both array must be sorted         //Tc = O(M+Nlog(n+m))
//optimized soln
void mergedwithsort(int a[],int b[],int n,int m )
{
        int i=n-1;      //pointer of array a
	    int j=0;           //pointer of array b
	   
	    while(i>=0 && j<m)
	    {
	        if(a[i]>b[j])       //swaping till a[i]>b[j]
	        {
	            swap(a[i],b[j]);
	            i--;
	            j++;
	        }
	        else
	        {
	            break;
	        }
	    }

	    sort(b,b+m);
	    sort(a,a+n);
}

/*
//complexity is high  //cz of using sort function again and again 
void mergedwithsort(int a[],int b[],int n,int m )
{
    int i = 0;
    int j = 0;
    while (i<n && j<m)
    {
       
        if(a[i] > b[j])     //if arr1[i] has bigger element, then swap and sort the second array
        {
            swap(a[i],b[j]);     //swap to keep the smaller element of arr2 at correct position in arr1
            sort(b,b+m);        // after swapping sort the arr2 to bring the smallest in arr2 at pos=0
            i++;
        }
    }
}

*/
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
    
    
    //Input
    int m;
    cout << "--> Enter Number Of element for seocnd array : ";
    cin >> m;
    int b[m];
    cout << "--> Enter elements of Array 2 : " << endl;
    for (int i = 0; i < m; i++)
        cin >> b[i];
    //Input End
    
    mergedwithsort(a,b,n,m);


    cout<<endl<<"--> Array after merged and sort : ";
    print(a,b,n,m);


}
