#include <bits/stdc++.h>
using namespace std;

/*
        || Problem : Longest K unique characters substring ||

        // Example :
                        Input  :    String s = aabacbebebe
                                    unique char = 3
                        Output :    7       //Longest window size 
        
        // Algorithm 

        || Variable Window Sliding ||

        fun()
        {
            while(j < size)
            {
                //Calculation

                if(condition == k)
                {
                    //Calculate ans
                    j++;
                }
                else if(condition < k)
                {
                    j++;
                }
                else    //(condtion > k)
                {
                    while(condition>k)
                    {
                        // Calculation of removing i
                        i++;

                        condition checking
                    }
                    j++;
                }
            }
            return ans;
        }
*/

//Function
int Longest_window(string s, int m, int n)
{
    // map store the charcter and occurence of charcter
    map<char, int> M;

    //References of Window
    int j = 0;
    int i = 0;

    //ans
    int ans = 0;

    //Traversing string
    while (j < m)
    {
        // Calculation
        M[s[j]]++;

        //Condition Matching
        //Condition matched
        if (M.size() == n)
        {
            ans = max(ans, j - i + 1);  //ans calculation
            j++;
        }
        else if (M.size() < n) // less then condition
        {
            j++;
        }
        else 
        {
            // sliding i till given condtition reach
            while (M.size() > n)
            {
                // Calculation for removing I
                M[s[i]]--;
                if (M[s[i]] == 0)
                    M.erase(s[i]);
                i++;
                
                //Condition checking
                if (M.size() == n)
                {
                    ans = max(ans, j - i + 1);
                }
            }
            j++;
        }
    }

    //return ans
    return ans;
}
main()
{
    string s;
    int n;

    cout << "--> Enter the string : ";
    cin >> s;
    cout << "--> Enter the number of unique charcter in window : ";
    cin >> n;

    cout << "--> size of Longest winodow which contain " << n << " Unique charcter : ";
    cout << Longest_window(s, s.length(), n);
}