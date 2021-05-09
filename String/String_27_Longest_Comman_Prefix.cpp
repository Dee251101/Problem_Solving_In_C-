#include <bits/stdc++.h>
using namespace std;
/*
        input stirng  =  {"flower","flow","flight"}

        flower - flow -> flow -> 4   
                                     output = min(2,4)   
        flower - flight ->fl  -> 2 


        output = "fl"

    // ALGORITHM                   TS  = O(N*M)  
                                   N = NUMBER OF STRING || M = MAX LENGTH OF STRING

            BASIC ALGO IS THAT COMPARING THE FIRST STRING WITH THE ALL STRING ONE BY ONE
        AND RETURN THE MINIMUL MATCHING STRING.

        1. READ THE STRING ARRAY FROM 1 TO END'
        2. READ THE STRING CHARCTER OD 0TH AND iTH STRING TILL WHICH IS IS LESS.
            WHEN STRING MISSMATCH FOUND 
                BREAK THE LOOP 
            ELSE INCREASE THE COUNTER
        3. STORE THE MINIMUM CUNTER AMONG THE ALL THE COMPARISON     
        4. PRINT THE SUBSTRING TILL THE COUNTER.

*/
string longestCP(string s[], int x)
{
    string output = "";
    int m = INT_MAX;

    // TRAVERSING ARRAY STRING
    for (int i = 1; i < x; i++)
    {
        int j = 0;
        int k = 0;
        int lc = 0; // COUNTER FOR THE MATCHING LATTER OF STRING

        // TRAVERSING THE CHARCTER OF STRING
        while (j < s[0].length() && k < s[i].length())
        {
            //MATCHING CHARCTER
            // IF MATCH FOUND INCREAMENT THE COUNTER 

            if (s[0][j] == s[i][k])
                lc++;
            else
                break;

            j++;
            k++;
        }
        m = min(m, lc);
    }
    // RETURN THE OUTPUT STRING
    output = output + s[0].substr(0, m);
    return output;
}
main()
{
    int x;
    cin >> x;
    string a[x];
    int m;
    string output = "";
    for (int i = 0; i < x; i++)
    {
        cin >> a[i];
    }

    // FUNCTION CALL
    cout << longestCP(a, x);
}