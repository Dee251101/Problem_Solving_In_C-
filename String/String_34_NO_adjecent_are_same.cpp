#include<bits/stdc++.h>
using namespace std;

/* || Problem : Rearrange characters in a string such that no two adjacent are same using hashing ||

        Input : string : geeksforgeeks
        Output: Yes

        Input : BBBB
        Output: No

    # algorithm :

        1. Find the freq. of max freq. charcter 
        2. if max_freq is less than (length-max_freq.+1)
            return Yes
            else
            reuturn No
        
*/


string ispossible(string s)
{

    map<char,int> m;

    int max = 0;

    //getting max freq.
    for(int i = 0 ; i<s.length();i++)
    {
        m[s[i]]++;
        if(m[s[i]]>max)
        max = m[s[i]];
    }

    //condition checking 
    if(max <= s.length()-max+1)
        return "Yes";
    else
        return "No";
}

main()
{
    string s;

    //input
    cin>>s;

    //output
    cout<<"--> Is possible to rearrenge the charcter such that no 2 adjencence are same : "<<endl;
    cout<<ispossible(s);
}