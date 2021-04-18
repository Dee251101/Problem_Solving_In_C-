#include <bits/stdc++.h>
using namespace std;

/* 
     || Problem : Count occurences of anagram ||

     # Sliding window :

    Func()
    {
        while(j < size)
        {
            // calculation

            if(j<k)
            {
                j++
            }
            else //reach the window
            {
                //Ans calculation

                //last element removing Calculation

                //sliding window
            }
        }

        return ans;
    }

*/

//Function
// return number of anagram
int anagram(string s, string t, int m, int k)
{
    map<char, int> M; // map for t string

    //ans
    int ans = 0;

    // Storing map
    for (int i = 0; i < k; i++)
    {
        M[t[i]]++;
    }

    int count = M.size();

    //References of window
    int i = 0;
    int j = 0;

    //Cheking for window
    while (j < m)
    {
        //Calculations
        if (M.find(s[j]) != M.end())
        {
            M[s[j]]--;
            if (M[s[j]] == 0)
                count--;
        }

        //reaching for the windows
        if (j + 1 < k)
        {
            j++;
        }
        else    //Reached to the window size
        {
            
            //Getting ans
            if (count == 0)
            {
                ans++;
            }

            //Calculation to remove ith charcter
            //Sliding window
            if (M.find(s[i]) != M.end())
            {
                M[s[i]]++;
                if (M[s[i]] == 1)
                    count++;
            }
            j++;
            i++;
        }
    }

    //return ans
    return ans;
}
main()
{
    string s;
    string k;


    //Input
    cout << "--> Enter main string : " << endl;
    cin >> s;
    cout << "--> Enter Pattern string : " << endl;
    cin >> k;

    //Output
    cout << "--> Number of anagram in strnig s is : " << endl;
    cout << anagram(s, k, s.length(), k.length());
}