#include <bits/stdc++.h>
using namespace std;
/*
    || Problem : Rearrange array in alternating positive & negative items with O(1) extra space | Set 1 ||


    ==> Aprroach 1 : USing inbuilt sort function        //Tc = O(NLog(N))

            //inbuilt STL sort function's time complexity to high so we sort it by ourselfs.

    ==> Aprrouch 2 : By sorting array by traversing array   //TC = O(N)


        # Algorithm :

             int i = 0;   --> fisrt negative or positive element pointer
             int j = 0;   --> first element pointer of array

            1.  sort Array in any order
            2.  traverse till first negative or first positive element  ( depends on sorting)
            3.  Rearrenge the array 
                     doingin swapping swap(i,j)
                     i++;
                     j = j+2;
*/

/*
//  Aproach 1 :
// Using STL Sort functio     //TC  =  O(Nlog(N))       //SC = O(1)
void alternatArray(int a[], int n)
{
    //sort array
    sort(a, a + n);

    int i = 0; //pointer to point first negative element int sorted array
    int j = 0; //pointer to point first positive element in sorted array

    // traverse till first positive element
    while (a[i] < 0)
    {
        i++;
    }

    // Swap element or ReArrenge elements
    while (i < n && j < n)
    {
        swap(a[i], a[j]);

        i++;        //Increment positive element pointer
        j = j + 2;  //descrement by neagtive element pointer
    }
}
*/
 
//  Aproach 2 :
// by sorting ourself  
void alternatArray(int a[], int n)
{
    //Step-1 : Sort the array and get the pointer i  
    //Move all the positive to left side and and all negative to right side

    int i = 0;
    int j = n - 1;

    while (i <= j)
    {
        if (a[i] > 0) //if a[i] is positive then increment i
            i++;
        else if (a[j] < 0) //if a[j] is negative then decrement j
            j--;
        else if (a[i] > 0 && a[j] < 0) //if a[i] is positive and a[j] is negative then do i++ and j--
        {
            i++;
            j--;
        }
        else if (a[i] < 0 && a[j] > 0) //if not then swap to change the negative element to right side and positive to left
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    //Step 2 - Rearranging

    //i will be pointing to the first negative element
    int k = 0; //k will point to start of arr

    while (i < n)
    {
        swap(a[i], a[k]);
        i++;       //increment i by one
        k = k + 2; //increment k by 2 to get the alternative position
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
    //Input End

    alternatArray(a, n);

    cout << "--> Alternating positive and negative array is : ";

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}