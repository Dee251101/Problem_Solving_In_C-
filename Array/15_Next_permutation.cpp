#include <bits/stdc++.h>
using namespace std;

/*
        || Problem : Find Next permutation ||

        Aproach 1 : Using STL           TC = O(n!)
                    Using simple functions of STL next_permutation(); 
        Aproach 2 : Uing single pass aproach     // TC = O(n)

            # Algorithm :

                    1.  Traverse from back and find Decreasing element (a[i+1]<=a[i])
                    2.  Traverse from back to i and find greater element than a[i];
                    3.  Swap(i,j)
                    4.  reverse array i+1 to n;

            # Explanation :
                           
                            Array :  1 3 5 8 4 7 6 5 3 1

                    Step 1 : Find Decreassing element  (traverse n to 0)

                                1 3 5 8 4 7 6 5 3 1
                                        |
                                        i
                                      (4<7)  
                    Step 2 : Find greater element than a[i] from (n to i+1);

                                1 3 5 8 4 7 6 5 3 1
                                        |     |
                                        i     j
                    Step 3 : Swaap(i,j);

                                1 3 5 8 5 7 6 4 3 1     (swapped)
                                        |     |
                                        i     j                             
                    Step 4 : Reverse Array i+1 to n

                                1 3 5 8 5 1 3 4 6 7     <---  (ANSWER)
                                        |
                                        i

*/

// Function to reverse array 
void reverse(int a[],int i,int j)
{
    while(i<j)
    {

        swap(a[i],a[j]);

        i++;
        j--;
    }
}

//Function
void permute(int a[],int n)
{
    int i = n-2;            //pointer to point decreasing element

    // Finding first decreasing element from n to 0;
    while(i>=0 && a[i+1]<=a[i])
    {
        i--;
    }

    // Finding first greater element than a[i] from n to i+1;
    if(i>=0)
    {
        int j =n-1;          //Pointer to point greater element  

       while (a[j] <= a[i] && j>=0)
        {
            j--;
        }
    
        // swap i and j
        swap(a[i],a[j]); 

    }
   
    // Reverse array from i+1 to n;
     reverse(a,i+1,n-1);

}
int main()
{
    
    //Input
    int n;
    cout<<"--> Enter Number Of element : ";
    cin>>n;

    int a[n];
    cout<<"--> Enter elements of Array : "<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    //Input End 

    cout<<"--> Next permutation is : ";
   
    permute(a,n);

    //Using STL  //Tc = O(n!)    
    // next_permutation(a,a+n);
    
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
