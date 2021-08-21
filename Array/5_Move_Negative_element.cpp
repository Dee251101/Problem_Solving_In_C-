#include <bits/stdc++.h>
using namespace std;

/*
    || PROBLEM : Move all negative numbers to beginning and positive to end with constant extra space ||

        Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
        Output: -12 -13 -5 -7 -3 -6 11 6 5
    
*/

//Using 2 pointer method
void MoveNegative(int a[], int n)
{
    int L = 0;     // left side of the pointer has negative element
    int H = n - 1; // Right side of this pointer has positive element only

    //Traverse array
    //Cheking for condition for L
    //a[L]<0
    //a[L]>0
    while (L <= H)
    {
        if (a[L] < 0)
            L++;
        else if (a[L] > 0)
        {
            swap(a[L], a[H]);
            H--;
        }
    }
}
main()
{
    // Input
    int n;
    cout << "--> Enter number of element : ";
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cout << "--> Element : ";
        cin >> a[i];
    }

    // Input End

    MoveNegative(a, n);

    cout << "--> Array with Moved all negative numbers to beginning is : ";

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
}