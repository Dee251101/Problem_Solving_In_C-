#include<iostream>
#include<bits/stdc++.h>
using namespace std;

main()
{

    string s = "HELLO how are you ?" ;
     
   // cin>>s;
    vector<int> arr = {3,2,1};

    
    next_permutation(arr.begin(),arr.end());
    cout<<arr[0]<<arr[1]<<arr[2];
}