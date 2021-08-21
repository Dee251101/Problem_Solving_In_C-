#include <iostream>
using namespace std;

/*
    || Problem : Given an array, rotate the array by one position in clock-wise direction.||

        Input:
            N = 5
            A[] = {1, 2, 3, 4, 5}
        Output:
            5 1 2 3 4


*/

void rotate(int arr[], int n)
{
    int temp = arr[n-1];    // Store last element of array 
    
    for(int i = n;i>0;i--)  // traverse and shift element by one unit
        arr[i] = arr[i-1];
    
    arr[0] =temp;   // set first element
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

    //Output

    cout<<endl<<"==> Array before rotate : ";
     for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    rotate(a,n);

    cout<<endl<<"==> Array After rotate : ";
     for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;
}
