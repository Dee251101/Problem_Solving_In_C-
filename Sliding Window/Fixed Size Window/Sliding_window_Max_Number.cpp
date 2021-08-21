#include <bits/stdc++.h>
using namespace std;

/*
    || Problem : Maximum of all subarrays of size k ||

    # Sliding window :

    Func()
    {
        while(j < size)
        {
            // calculation

            if(j<k)
            {
                j++
            }
            else //reach the window
            {
                //Ans calculation

                //last element removing Calculation

                //sliding window
            }
        }

        return ans;
    }

*/

//Function
//print the max number in each window
void Max_Number(int a[], int k, int m)
{
    vector<int> v; //output
    list<int> l;   //max number

    //Refereces of windows
    int j = 0;
    int i = 0;

    int max; // temp ans

    //Traversing array
    while (j < m)
    {
        // Calculations
        if (l.back() < a[j])
        {
            l.pop_back();
            l.push_back(a[j]);
        }

        // Cheking for the windows
        if (j + 1 < k)
        {
            j++;
        }
        else    // Reached to the windows size
        {
            // Ans Calculation
            max = l.front();
            v.push_back(max);

            //Removing front element
            //Sliding Windows
            if (l.front() == a[i])
            {
                l.pop_front();
            }
            i++;
            j++;

        }
    }

    //Printing output
    for (int k = 0; k < v.size(); k++)
        cout << v[k] << " , ";
}
main()
{
    int array[10] = {5, 2, 7, 12, -56, 3, 76, 32, 6, 90};
    int k = 3;
    
    //Output
    cout<<"--> Maximum element in each windows is : " <<endl;
    Max_Number(array, k, 10);
}