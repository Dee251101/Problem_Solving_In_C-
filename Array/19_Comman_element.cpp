#include <bits/stdc++.h>
using namespace std;
/*
    || Problem : Given three arrays sorted in increasing order. Find the elements that are common in all three arrays. ||


    Input:
        n1 = 6; A = {1, 5, 10, 20, 40, 80}
        n2 = 5; B = {6, 7, 20, 80, 100}
        n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
    Output: 20 80
    
    Explanation: 20 and 80 are the only
        common elements in A, B and C.
*/

//Using Pointer      //TC = O(n)
void comman(int a[], int b[], int c[], int n1, int n2, int n3)
{
    int i = 0;      // pointer for array 1
    int j = 0;      // pointer for array 2
    int k = 0;      // pointer for array 3

    int pre = 0;            //to remove duplicacy form ans. [stores Previous commun element]

    // Travers array 
    while (i < n1 && j < n2 && k < n3)   // x = y = z
    {

        //if common print ans  and increament 
        if (a[i] == b[j] && b[j] == c[k])
        {
            //ANS
            if (pre != a[i])
                cout << a[i] << "  ";

            pre = a[i]; //Storing previous ans to remove duplicacy formm ans 

            i++;
            j++;
            k++;
        }
        //We have to take care for ( x = y and y < x ) or (x < y and y = z)
        // so we increamenting only one by one pointer
        else if (a[i] < b[j])        // x < y
            i++;
        else if (b[j] < c[k])        // y < z
            j++;
        else                         // We reach here when x > y and z < y, i.e., z is smallest
            k++;
    }

}
int main()
{
    //Input
    int n1;
    cout << "--> Enter Number Of element  for Array 1 : ";
    cin >> n1;

    int a1[n1];
    cout << "--> Enter elements of Array 1 : " << endl;
    for (int i = 0; i < n1; i++)
        cin >> a1[i];

    int n2;
    cout << "--> Enter Number Of element for Array 2 : ";
    cin >> n2;

    int a2[n2];
    cout << "--> Enter elements of Array 2 : " << endl;
    for (int i = 0; i < n2; i++)
        cin >> a2[i];

    int n3;
    cout << "--> Enter Number Of element for Array 3 : ";
    cin >> n3;

    int a3[n3];
    cout << "--> Enter elements of Array 3 : " << endl;
    for (int i = 0; i < n3; i++)
        cin >> a3[i];
    //Input End

    cout << "--> Commun element in 3 array is : ";
    comman(a1, a2, a3, n1, n2, n3);

    return 0;
}
