#include <iostream>
using namespace std;
/*
    // Method 1:  [ SIMPLE METHOD]

            input  = BLABLABLA
            output = 6;

            B L A B L A B L A
            | |
            i j
    // here i =  pointing the starting point of  prefix   
            j =  pointing the starting point of suffix

    // ALGORITHM 

        1. INTIALIZE THE I AND J WITH 0 AND 1 
        2. PLAY THE LOOP TO READ THE EACH CHARACTER OF THE STRING
        3. COMPARE THE CHARCTER ONE BY ONE
            IF(S[I]=S[J])
                I++
                J++
            ELSE
                RESET I AND J
        4. EXIT

*/

/*
main()
{
    //input string
    string s;
    cin >> s;

    int i = 0;
    int j = 1;

    while (j < s.length())
    {
        if (s[i] == s[j])
        {
            cout << i << endl;
            i++;
            j++;
        }
        else
        {

            j = j - i + 1;
            i = 0;
        }
    }

    cout << i;
}

*/

/*
        // METHOD : 2    USING KMAP ALGO

*/
 
int longestPrefixSuffix(string s)
{
    int n = s.length();

    int lps[n];
    lps[0] = 0; // lps[0] is always 0

    // length of the previous
    // longest prefix suffix
    int len = 0;

    // the loop calculates lps[i]
    // for i = 1 to n-1
    int i = 1;
    while (i < n)
    {
        if (s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider
            // the example. AAACAAAA
            // and i = 7. The idea is
            // similar to search step.
            if (len != 0)
            {
                len = lps[len-1];

                // Also, note that we do
                // not increment i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    int res = lps[n-1];

    // Since we are looking for
    // non overlapping parts.
    return (res > n/2)? n/2 : res;
}

// Driver program to test above function
int main()
{
    string s = "BLABLABLA";
    cout << longestPrefixSuffix(s);
    return 0;
}