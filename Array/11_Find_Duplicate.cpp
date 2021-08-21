#include <bits/stdc++.h>
using namespace std;

/*
    || Problem :Find the Duplicate Number. There is only one repeated number in nums, return this repeated number. ||



*/

/*
// Brute force              // TC = O(nLogn)
int Duplicate(int a[],int n)
{
    sort(a,a+n);
    for(int i=0;i<n-1;i++)
    {
        if(a[i]==a[i+1])
            return a[i];
    }
    return -1; 
}
*/

/*
//Using Map         // TC  = O(n+log(n))       SC = O(N)
int Duplicate(int a[],int n)
{
    unordered_map<int,int> m;  // count and store the value value->count

    for(int i=0;i<n;i++)        //inserting into map
        m[a[i]]++;
    
    for(auto i:m)               //traverse map;
    {
        if(i.second>1)
        return i.first;
    }
    return -1;
}
*/

/*
// hare & tortoise method
int Duplicate(int a[],int n)
{ 
    int slow = a[0];
    int fast = a[0];
    //both slow & fast = 1

    //This method is called hare & tortoise method
    do{
        slow = a[slow]; //increment slow by 1 index        
        fast = a[a[fast]]; //increment fast by 2 indexes  
    } while(slow!=fast);

    fast = a[0];

    while(fast!=slow)
    {
        slow = a[slow];
        fast = a[fast];
    }

    return slow;
}


*/

//Using index updating  //Tc = O(n)       //SC = O(1)
int Duplicate(int a[],int n)
{
    int n = a.size();
         for(int i=0;i<a.size();i++)
         {
             a[a[i]%n] +=n;
         }
        for(int i=0;i<n;i++)
        {
            if(a[i]/n>1)
                return i;
        }
        return 0;
}


int Duplicate(int a[],int n)
{

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
    

    cout<<"--. Duplicate number in array is : ";
    cout<< Duplicate(a,n);
     return 0;
}
