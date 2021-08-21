#include<bits/stdc++.h>
using namespace std;
/*
        || Problem : Longest Substring Without Repeating Characters ||

        // Example :  
                        Input : string A = abcdddec
                        Output : 4  // abcd

        // Algorithm :

        || Variable sliding window ||

*/

int Window_Size(string s)
{
    int ans = 0 ;
    map<char,int> m;
    
    int i = 0;
    int j = 0;
    while(j<s.length())
    {
        m[s[j]]++;

        if(m.size() == j-i+1)
        {
            ans = max(ans,j-i+1);
            j++;
        }
        else if(m.size()<j-i+1)
        {
            while(m.size()<j-i+1)
            {
            m[s[i]]--;
            if(m[s[i]]==0)
            m.erase(s[i]);
            i++;
            if(m.size() == j-i+1)
        {
            ans = max(ans,j-i+1);
             
        }
            }
            j++;
        }
    }
    return ans;
}
main()
{
    string s;
    
    //input
    cout<<"--> Enter the string s ";
    cin>>s;

    //Output
    cout<<"--> Longest window size with unique charcter is   "<<Window_Size(s);

}