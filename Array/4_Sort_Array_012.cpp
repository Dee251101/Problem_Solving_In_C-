#include <bits/stdc++.h>
using namespace std;

/*
|| Problem  : Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order. ||

        Input: 
            N = 5
            arr[]= {0 2 1 2 0}
        Output:
            0 0 1 2 2
        Explanation:
            0s 1s and 2s are segregated 
            into ascending order.
*/

/*  ||Aproach 1: 

    //Algorithm :               //TC = O(n)                        //SC = O(1)

        1.  Keep three counter c0 to count 0s, c1 to count 1s and c2 to count 2s
        2.  Traverse through the array and increase the count of c0 is the element is 0,
            increase the count of c1 is the element is 1 and increase the count of c2 is the element is 2
        3.  Now again traverse the array and replace first c0 elements with 0, 
            next c1 elements with 1 and next c2 elements with 2.

void sort012(int a[], int n)
{
    int c1, c2, c3;
    //counter to count 0s,1s,2s;
    c1 = c2 = c3 = 0;

    //Traversing array
    //counting 0s,1s,2s;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            c1++;
        else if (a[i] == 1)
            c2++;
        else
            c3++;
    }

    //Sorting array 
    for (int i = 0; i < n; i++)
    {
        if (c1 > 0)
        {
            a[i] = 0;
            c1--;
        }
        else if (c2 > 0)
        {
            a[i] = 1;
            c2--;
        }
        else if (c3 > 0)
        {
            a[i] = 2;
            c3--;
        }
    }
}

main()
{
    //input
    int n;
    cout << "--> Enter the number of element : ";
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cout << "--> Element : ";
        cin >> a[i];
    }
    //Input end;

    sort012(a, n);

    //Output
    cout << "--> Sorted array without using sorting algorithm : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
}

*/

/*  ||Aproach 2: ( Dutch national Flag algorithm )

    //Algorithm :               //TC = O(n)                        //SC = O(1)

    // Example : 

                0 1 2 1 2 0 1
                |           |
               M,L          H

                0 1 2 1 2 0 1
                  |         |
                 M,L        H

                0 1 2 1 2 0 1
                  | |       |
                  L M       H

                0 1 1 1 2 0 2       (Swap(M,H))and H--
                  | |       |
                  L M       H

                0 1 1 1 2 0 2       (Swap(M,H))and H--
                  |     |   |
                  L     M   H

                0 1 1 1 2 0 2       (Swap(M,H))and H--
                  |     | |
                  L     M H
                
                0 1 1 1 0 2 2       (Swap(M,L))and L++,M++
                  |     | 
                  L    M,H

                0 0 1 1 1 2 2       M>H Loop Break;
                    |   | |         Sorting Done
                    L   H M   

    1.  Keep three indices low = 1, mid = 1 and high = N.
    2.  Traverse the array from start to end and mid is less than high. (Loop counter is i)
            If the element is 0 then swap the element with the element at index low and update low = low + 1 and mid = mid + 1
            If the element is 1 then update mid = mid + 1
            If the element is 2 then swap the element with the element at index high and update high = high – 1 and update i = i – 1. 
    3.  Print the output array.

*/


void sort012(int a[], int n)
{
    int L, M, H;
    L = 0;     // left side of L pointer has only 0s
    M = 0;     // mid pointer to traverse array
    H = n - 1; //right side of the R poointer has only 2s

    //Tarverse mid pointer
    while (M <= H)
    {
        //checking for condition
        // A[m]->0
        // A[m]->1
        // A[m]->2
        if (a[M] == 0)
        {
            swap(a[L], a[M]);
            L++;
            M++;
        }
        else if (a[M] == 1)
        {
            M++;
        }
        else if (a[M] == 2)
        {
            swap(a[H], a[M]);
            H--;
        }
    }
}
main()
{
    //input
    int n;
    cout << "--> Enter the number of element : ";
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cout << "--> Element : ";
        cin >> a[i];
    }
    //Input end;

    sort012(a, n);

    //Output
    cout << "--> Sorted array without using sorting algorithm : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
}
