#include <bits/stdc++.h>
using namespace std;

/*
        || Problem  : Count Inversions ||

        Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

        Input: N = 5, arr[] = {2, 4, 1, 3, 5}
        Output: 3
        Explanation: The sequence 2, 4, 1, 3, 5 
                    has three inversions (2, 1), (4, 1), (4, 3).


        Aproach : Basically using merge function && BruteForce

            //Just count the inversion needed during the merging of the array

*/
//Using merge Sort //Tc = Nlog(N)     //Sc = O(N)
//Merge Function
int Merge(int a[], int l, int mid, int h)
{
    // Temp array to store merged Array
    int temp[h - l + 1];
    
    int i = l;       // point the first element of left array
    int j = mid + 1; //point the first element of right array

    int k = 0; //tracing the element of temp array
    int inv = 0; //count inversion
    //Merging
    while (i <= mid && j <= h)
    {
        if (a[i] <= a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
           
            temp[k] = a[j];
            k++;
            j++;
            inv += mid-i+1;  //Count Inversion 
        }
    }
    // Merging rest element of the both array
    while (j <= h)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    while (i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }
    
    // Transfering the sorted array to Original Array
    for (int x = 0; x < k; x++)
        a[x + l] = temp[x];
        
        return inv;  //return inversion 

}
int MergeSort(int a[], int i, int j)
{
    int inv = 0;
    if (i < j)
    {

        int mid = (i + j) / 2;
        inv+=MergeSort(a, i, mid);
        inv+=MergeSort(a, mid + 1, j);
        inv+=Merge(a, i, mid, j);   
    }
    return inv;
}
main()
{
    //input
    int n;
    cout << "--> Enter the number of elements for array 1 : ";
    cin >> n;

    cout << "--> Enter the elements for Array 1 : " << endl;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    
    cout<<"--> Inversion count is : ";
    cout<<MergeSort(a,0,n-1);
}