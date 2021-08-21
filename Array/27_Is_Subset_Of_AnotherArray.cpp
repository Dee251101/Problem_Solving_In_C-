#include <bits/stdc++.h>
using namespace std;

/*
        || Problem : Array Subset of another array  ||

        --> Example : 
                Input:
                    a1[] = {11, 1, 13, 21, 3, 7}
                    a2[] = {11, 3, 7, 1}
                Output:
                    Yes
                Explanation:
                    a2[] is a subset of a1[]

        --> Aproach 1 : BruteForce

        --> Aproach 2 : Using sorting + 2 pointer method        TC = O(NlogN)

                    1. Sort array a1 and a2
                    2. Traverse array a2 and compare with a1.
                        if all found return Yes 
                        if reach the end of a1
                            retur No

        --> Aproach 3 : Using HashMap STL                      TC = O(N) SC = O(N) 

                    1. Traverse a1 & Store all the value of in map with maping value 1
                    2. Traverse a2 & find value in Map 
                        if not found return No
                        if found all element return YES;

*/

/*
//Aproach 2 : 
//Using Sorting + 2 Pointer       //TC  = O(Nlog(N)
string isSubset(int a1[], int a2[], int n, int m)
{

    //Sort A1 and A2
    sort(a1, a1 + n);
    sort(a2, a2 + m);

    int i = 0; //pointer for a1
    int j = 0; //pointer for a2

    //traversing
    while (i < n)
    {
        if (j < m)      // still element left in a2
        {
            if (a1[i] == a2[j]) //same element
            {
                i++;
                j++;
            }
            else    //diff element then move to ahead in a1
            {
                i++;
            }
        }
        else    /reached to end of a2
            return "Yes";
    }

    //Checking if last element is matched 
    if (j < m) 
        return "No";
    else
        return "Yes";

}
*/

// Aproach 2 : Using map     // TC  = O(N+M)  // SC = O(N)

string isSubset(int a1[], int a2[], int n, int m)
{
    //map to store value of a1
    unordered_map<int, int> map;

    //mapping value 
    for (int i = 0; i < n; i++)
    {
        map[a1[i]] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        if (!map[a2[i]])    //element doesnt found
            return "No";
    }

    return "Yes";
}

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

    cout << "--> Is Array 2 is the subset of Array 1 ? :  ";
    cout << isSubset(a, b, n, m);
    return 0;
}
