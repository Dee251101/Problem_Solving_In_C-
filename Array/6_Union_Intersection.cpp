#include <bits/stdc++.h>
using namespace std;

/*
    || problem : Given two arrays a[] and b[] of size n and n respectively. 
                 The task is to find union and intersect between these two arrays.
*/

//Ordered Set is implemented using Red-Black Tree
//Time Complexity: O(log n)

//Unordered set is implemented using Hash Table
//Time complexity: O(1) to O(n) - Insertion
//                 O(1) - Searching
//                 Average - Deletion


//Union functino implement using set 
//TC = O(N+M)
void UnionArray(int a[], int b[], int m, int n)
{
    set<int> s;  //ordered set to store merged array

    //Insert element in set
    for (int i = 0; i < m; i++)
        s.insert(a[i]);
    for (int i = 0; i < n; i++)
        s.insert(b[i]);

    //Output
    cout << "--> Size of Union Array : ";
    cout << s.size();

    cout<<endl<<"--> Union Array is : ";     
    for(auto x:s)
        cout<<x<<" ";
}

//Intersection function is implement using Merge sort snippit
void IntersectionArray(int a[], int b[], int m, int n)
{
    int i = 0;      // reference to Array 1
    int j = 0;      // Reference to Array 2
    int count = 0;  

    sort(a,a+m);    //sort
    sort(b,b+n);
    
    int Array[n+m]; //Output array

    while (i < m && j < n)
    {
        if (a[i] == b[j])
        {
            Array[count]= a[i];
            count++;
            i++;
            j++;
        }
        else if (a[i] > b[j])
            j++;
        else if (b[j] > a[i])
            i++;
       
    }

    //Output
    cout << endl
         << "--> Size of intersect Array is : ";
    cout << count;

    cout<<endl<<"--> Intersect Array is : "; 
    for(int i = 0 ;i<count;i++)
        cout<<Array[i]<<" ";
}
int main()
{
    int m, n;

    //Input
    cout << "--> Enter the size of the Array : " << endl;
    cout << "--> Size of Array 1 : ";
    cin >> m;
    cout << "--> Size of Array 2 : ";
    cin >> n;

    int a[m];
    int b[n];
    cout << "==> Enter element for Array 1" << endl;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    cout << "==> Enter element for Array 2" << endl;
    for (int i = 0; i < n; i++)
        cin >> b[i];

    //Input End

    UnionArray(a, b, m, n);

    IntersectionArray(a, b, m, n);

    return 0;
}
