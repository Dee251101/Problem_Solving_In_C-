#include <bits/stdc++.h>
using namespace std;
/*

*/

void negative_Number(int a[], int m, int k)
{
    list<int> l;  // store the negetive value

    // Output storing 
    int output[100];
    int idx = 0;

    //window reference pointer 
    int j = 0;
    int i = 0;

    //Traversing array
    while (j <  m)
    {
       
        //adding the value to list
        if (a[j] < 0)
            l.push_back(a[j]);
        
        //Condtion  for window sliding
        if (j+1 < k)
        {
            j++;
        }
        else // Reach the window size 
        {
           
            if (l.empty())
            {
               
                output[idx] = 0;
                idx++;
            }
            else
            {  
                
                
                // creating output
                output[idx] = l.front();
                
                idx++;

                // Updating list
                if (l.front() == a[i])
                {
                    l.pop_front();
                }  
            }
             //sliding window
                j++;
                i++;
          
        }
    }

    // Outpur printing
    for (int i = 0; i < idx; i++)
        cout << output[i] << ",";
}

main()
{
    int m = 5;
    int k = 2;

    //Input
    int array[m] = {-1, 2, -3, 4, -10};
    
    //Output
    cout<<"--> list of first negative number in window size of "<<k<<" : ";
    negative_Number(array, m, k);
}
