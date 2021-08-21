#include<iostream>
using namespace std;


//function return max sum of subarray
int max_sum(int a[],int k,int m)
{

    int sum = 0; // sum of subarray
    int ans = 0; // ans

    // references of the windows
    int j = 0;
    int i = 0;  

    //Traversing array
    while(j< m)
    {
        // Calculation
        sum = sum + a[j];
        
        //window finding 
        if(j+1<k)
        {
            j++;
        }
        else // Reach the window
        {
            // Ans
            ans = max(ans,sum);
            
            //sliding the window
            sum = sum-a[i];  //removing the front element from sum 
            i++;
            j++;
        }
    }

    //ans
    return ans;
}
main()
{
    int k = 3;
    int m = 8;
    
    int array[m] = {1,4,53,2,54,31,24,32};

    cout<<"--> Maximum sum of sub array is "<<endl;
    cout<<max_sum(array,k,m);
}