#include <bits/stdc++.h>
using namespace std;
/*
        || Problem : Longest consecutive subsequence ||

        Aproach 1: Naive Aproach 

        Aproach 2: Using set 


*/
/*
//Naive Aproach         //TC = O(NLog(N))         //SC = O(1)
int ConsSubSeq(int a[],int n)
{
    sort(a,a+n);    //Sort array 

    int ans = INT_MIN;  // ans
     
    int count=1;    // Current counter of sequence length

    for(int i=0;i<n-1;i++)      //Traverse
    {
        if(a[i+1]-a[i]!=1 && a[i+1]!=a[i])  // if sequence break a[i+1]-a[i] !=1
        {
            ans = max(count,ans);
            count = 1;      //starting new sequence
        }
        else if(a[i+1]!=a[i])   //If sequence Found
        {
            count++;
        }
    }
    //Update ans if sequence found till end 
    ans = max(ans,count);

    return ans;
}
*/

//Aproach : Using Set           // TC = O(N)          //SC = O(N)
int ConsSubSeq(int a[], int n)
{

    set<int> s;

    //Creating set
    for (int i = 0; i < n; i++)
        s.insert(a[i]);


    int CurrentCount = 1;       //Current counter of sequence length
    int ans = -1;               //ans

    //Traverse
    for (int i = 0; i < n; i++)
    {
        //if a[i] is the starting point of sequence
        if (!s.count(a[i] - 1))         //i.e if a[i] = 5 then  5-4 is not availabe is set then 5 is starting of sequence
        {

            int CurrentNum = a[i];
            
            CurrentCount = 1;   //reset counter

            //counter till the sequence found
            while (s.count(CurrentNum + 1))     
            {
                CurrentCount++;
                CurrentNum++;
            }
        }
        //store ans 
        ans = max(ans, CurrentCount);
    }

    return ans;
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

    cout << "--> Length of consequetive sub sequence is  : ";
    cout << ConsSubSeq(a, n);

    return 0;
}
