#include <bits/stdc++.h>
using namespace std;

/*
        || Problem : Smallest window in a string containing all the characters of another string ||

    // Example : 

        Input :     string s = ABADBCA
                    string t = ABC
        Output:     BCA

    // Algorithm :

    ( USING SLIDING WINDOW TECHNIQUE )

        1. CREATE MAP OF STRING T
        2. TRAVERSE STRING S
        3. DO THE CALCULATION AND REACH THE CONDITION 
        4. IF CONDITTION REACHED 
            WHILE(CONDITION MATCHED)
            {
                STORE THE ANS 
                SHRINK THE WINDOW
            }
        5. RETURN ANS

*/
//Function
string Minimum_Window(string s, string t)
{
    // map array
    // We can use the "map" too.
    // but Time complexity of map is greater than array so it gives TLE
    // O(map) > O(array)
    int m[256] = {0};

    // Answer
    int ans = INT_MAX; // length of ans
    int start = 0;     // starting index of ans

    // Charecter counter
    int count = 0;

    // storing charcter in array
    for (int i = 0; i < t.length(); i++)
    {
        if (m[t[i]] == 0)
            count++;
        m[t[i]]++;
    }

    //References of Window
    int i = 0;
    int j = 0;

    //Traversing the window
    while (j < s.length())
    {
        // Calculations
        // if s[j] is not available in string t then it will be < 0 
        // So no need to check if condition
        m[s[j]]--;          
        if (m[s[j]] == 0)   
            count--;

        //Condition matching
        if (count == 0)
        {
            // shrinking the window 
            while (count == 0)
            {
                // Soring ans
                if (ans > j - i + 1)
                {
                    ans = min(ans, j - i + 1);
                    start = i;
                }

                // Sliding I
                // Calculation for removing I
                m[s[i]]++;
                if (m[s[i]] > 0)
                    count++;
                i++;
            }
        }
        j++;
    }

    // returning ans
    if (ans != INT_MAX)
        return s.substr(start, ans);
    else
        return "-1";
}

main()
{
    string s;
    string t;

    //input
    cout << "--> Enter the string s  :  ";
    cin >> s;

    cout << "--> Enter the string t :  ";
    cin >> t;

    //Output
    cout << "--> Minimum window which contain the all the unique charcter of the string  " << t << " is  : ";
    cout << Minimum_Window(s, t);
}