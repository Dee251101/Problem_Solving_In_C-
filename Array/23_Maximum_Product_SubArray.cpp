#include <bits/stdc++.h>
using namespace std;

/*
        || Problem : Maximum Product Subarray ||

        Input:
            N = 5
            Arr[] = {6, -3, -10, 0, 2}
        
        Output: 180

        Explanation:     Subarray with maximum product
                        is  6, -3, -10 which gives product as 180.


        Aproach 1 : BruteForce     (Log(N^2))

        Aproach 2 : Using 2 Traversal       // Log(N)

            # Algorithm : 

                1.  Maximum product in left to right traversal.
                2.  Maximum product in right to left traversal.

            Traversal and max product finding by Kadane's algo.
*/
/*
// Aproach 3 :  Tc = O(n)
int MaxProduct(int a[], int n)
{
    int CurMax = 1;     // store max product till ith position  //store 1 or positive product
    int CurMin = 1;     //store min product till ith position   //store 1 or negative product
   
    int MaxP = INT_MIN;     //Final ans

    //Traverse
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)                             // x==0
        CurMax = CurMin =1;
        else if(a[i]>0)                         //x>0
        {
            //update min and max
            CurMax = CurMax*a[i];
            CurMin = min(CurMin*a[i],1);
        }
        else{                                    // x<0
            
            //SWap min and max
            int temp = CurMax;      // x = -a     y = b  --> x = b and y = -a
            CurMax = CurMin;    
            CurMin = temp;

            //Update min and max
            CurMin = CurMin*a[i];       // x = b*-c = -bc(Negative)
            CurMax = a[i]*CurMax;       // y = -a*-c = ac(positive)
            CurMax = max(1,CurMax);
        }

        //Store max
        MaxP = max(MaxP,CurMax);
    }
    return MaxP;
}
*/

//Aproach 2: Using 2 Traversal    // TC = O(N)
int MaxProduct(int a[], int n)
{

    int MaxForward = INT_MIN;       //Max product in forward traversal
    int MaxBackward = INT_MIN;      // Max Product in Backward traversal

    int CurntMax = 1;      // Curnt Product till ith position

    //Step 1:

    // Traversing and finding Max product
    // left to right 
    for (int i = 0; i < n; i++)
    {

        CurntMax = CurntMax * a[i];

        MaxForward = max(MaxForward, CurntMax); //update maxforward

        // condition to change the train compartment
        if (CurntMax == 0)
            CurntMax = 1;
    }

    // reseting 
    CurntMax = 1;
    
    //Step 2:

    // Traversing and finding Max product
    // right to left
    for (int i = n - 1; i >= 0; i--)
    {
        CurntMax = CurntMax * a[i];

        MaxBackward = max(MaxBackward, CurntMax);   //update maxforward

         // condition to change the train compartment
        if (CurntMax == 0)
            CurntMax = 1;
    }


    return max(MaxForward, MaxBackward);
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

    cout << "--> Maximum product of subArray is : ";
    cout << MaxProduct(a, n);

    return 0;
}
