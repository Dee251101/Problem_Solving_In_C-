#include <bits/stdc++.h>
using namespace std;

/*
    ||   Problem :   Given an array containing N positive integers and an integer K. 
                    find the length of the longest Sub-Array with sum of the elements equal to the given value K.||
    
    || NOTE :- This approach is working for only positive number array ||

    // Example :
        
            Input = array = 4 1 1 1 2 3 5 
                    sum = 5
            Output = window size : 4
        
*/

int window_size(int a[], int m, int s)
{
    //ans
    int ans = 0;

    //Refrences of window
    int i = 0;
    int j = 0;

    int sum = 0;
    //Traversing array
    while (j < m)
    {
        //calculation
        sum = sum + a[j];
        
        // Condition matching 
        //Condition matched
        if (sum == s)
        {
            ans = max(ans, j - i + 1);  // ans updating
            j++;
        }
        else if (sum < s) 
        {
            j++;
        }
        else
        {
            //sliding i till sum > s 
            while (sum > s)
            {
                sum = sum - a[i];
                i++;

                //it possible to get subarray with same sum
                if (sum == s)
                {
                    ans = max(ans, j - i + 1);
                }
            }

            j++;
        }
    }
    //ans
    return ans;
}


main()
{
    // Input 
    int m = 3;
    int array[m] = {1, 1, 5};
    int sum = 5;

    //Output
    cout<<"--> Maximum length out of all subarrays having sum "<<sum<<" is  :  " ;
    cout << window_size(array, m, sum);
}