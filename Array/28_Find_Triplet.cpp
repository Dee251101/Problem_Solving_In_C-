#include <bits/stdc++.h>
using namespace std;
/*
        
        || Problem : Triplet Sum in Array ||

        Input:
            n = 6, X = 13
            arr[] = [1 4 45 6 10 8]
        Output:
            1
        Explanation:
            The triplet {1, 4, 8} in 
            the array sums up to 13.

        --> Aproach 1 : BruteForce   // TC = O(N^3)
        --> Aproach 2 : Using map    // TC = O(N^2)      SC = O(N)
        --> Aproach 3 : Using sliding pointer  //TC = O(N^2)    SC = O(1)

                    1. sort an array
                    2. travsrse and array
                    3. apply sliding pointer to every element to find the triplet
                        if found return 1
*/
/*
//Using map 
int Triplet(int a[], int n, int X)
{
    //store element
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        m[a[i]] = 1;
    }

    //search for the element left sum in map 
    //if found return 1
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            if (m[X - a[i] - a[j]])
                return 1;
        }
    }
    return 0;
}

*/
//Using 2 Pointer 
int Triplet(int a[], int n, int k)
{
    //Sort
    sort(a, a + n);

    int l, r;       //l for left number pointer // r for right number pointer

    //if not triplet
    if (n < 3)
        return 0;

    //Traverse
    for (int i = 0; i < n - 2; i++)
    {
        //i is the first number
        l = i + 1;  // second number
        r = n - 1;  //third Number

        //searching for the second and third number
        while (l < r)
        {
            if (a[i] + a[l] + a[r] == k)
            {
                cout<<a[i] <<" , "<<a[l]<<" , "<<a[r]<<endl;
                return 1;
            }
            else if (a[i] + a[l] + a[r] < k)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    //if not found
    return 0;
}
int main()
{
    int n;
    cout << "--> Enter Number Of element for first array: ";
    cin >> n;
    int a[n];
    cout << "--> Enter elements of Array 1 : " << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m;
    cout << "--> Ente the sum of the triplet : ";
    cin >> m;

    cout << "--> Is triplet availabe in Array with given Sum ?  : ";
    cout << Triplet(a, n, m);

    return 0;
}
