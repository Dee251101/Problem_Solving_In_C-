#include <iostream>
using namespace std;
/*
        || Problem : Trapping Rain Water ||

        Input:
            N = 4
            arr[] = {7,4,0,9}
        Output:
            10
        Explanation:
            Water trapped by above 
            block of height 4 is 3 units and above 
            block of height 0 is 7 units. So, the 
            total unit of water trapped is 10 units.
                      

                     |       
                     | 
            |        |
            |        |
            |        |
            |  |     |
            |  |     |
            |  |     |
            |  |     |
            7  4  0  9

            (7-7) + (7-4) + (7-0) + (9-9)

        1.   count the max height at left side of a[i]
        2.   count the max height at right side of a[i]
        3.   min(Maxleft,Maxright) - a[i] gives the water stores on a[i]th block
        4.   sum all and return 
        
*/
int Water(int a[], int n)
{
    int left[n];        // left side of element a[i] most height array
    int right[n];          //Right side of the element a[i] most height array


    //Storing most height of left side 
    left[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] >= left[i - 1])
            left[i] = a[i];
        else
            left[i] = left[i - 1];
    }

    //Storing most height of right side
    right[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] >= right[i + 1])
            right[i] = a[i];
        else
            right[i] = right[i + 1];
    }

    //Calculating the stored water 
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = min(left[i], right[i]) - a[i] + sum;  // min(left height,right Heigth)-current height 
    }
    return sum;
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

    cout << "--> Number of water units which will be store : ";
    cout << Water(a, n);

    return 0;
}
