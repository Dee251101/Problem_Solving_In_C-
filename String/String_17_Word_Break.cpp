#include <bits/stdc++.h>
using namespace std;


/*  || Problem : Word Break ||

        Input :  ilike
        output:  Yes

// Algorithm : 

    i -> found then go for the left string
    like -> l not found 
            li - not found
            lik - not found
            like - found
    NULL -> if NULL return "YES"
    
*/


string dictionary[13] = {"mobile", "samsung", "sam", "sung",
                         "man", "mango", "icecream", "and",
                         "go", "i", "like", "ice", "cream"};
map<string,string> dp;

// Checking for the word is available in dictionary or not
int Indictionary(string s)
{
    for (int i = 0; i < 13; i++)
    {
        if (dictionary[i].compare(s) == 0)
            return 1;
    }
    return 0;
}


// Using Dp + recursion
string wordBreak(string s)
{

    int size = s.length();

    // Base condition
    if (s == "")
        return "Yes";

    // checking in DP
    if(dp[s]!="") 
        return dp[s];

    //checking for substrings
    for (int i = 0; i <= s.length(); i++)
    {
        string ts = s.substr(0, i);

        if (Indictionary(ts))
        {
            return dp[s] = wordBreak(s.substr(i, size - i));
        }
    }

    return dp[s] = "No";
}
main()
{

    string s;

    cout<<"--> Enter string s : "<<endl; 
    cin >> s;

    cout<<"--> Is wordbreak possible ? "<<endl;
    cout << wordBreak(s);
}