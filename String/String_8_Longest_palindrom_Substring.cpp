#include <iostream>
#include <string>
using namespace std;

/*
        0 1 2 3 4 5 6 7 8 9 10
        K L A B A C A B A D E 

        output is  "ABAVABA"

        create "max = NULL" string to store the output string
        1. Find the substring using for loop 
        2. find palindrom string 
            if its palindrom 
                compare with max 
                    if(max.length < palindromsubstring.length)
                                max  = palindromsubstring
        3. repeat step 2 till the end of string;
        4. print max;


*/

// simple reverse function to reverse string
string reverse(string s)
{
    int length = s.length();
    int n = s.length() / 2;
    for (int i = 0; i < n; i++)
    {
        int temp = s[i];
        s[i] = s[length - i - 1];
        s[length - i - 1] = temp;
    }
    return s;
}
// Function to find maximmum
string longestPalindromstring(string s)
{
    // declaring usefull variable 
    int l = s.length();
    string max = "";                                        //to store output string 
    
    // finding substring of string s;
    for (int i = 0; i <= l; i++)
    {

        for (int j = 0 ; j <= l-i; j++)
        {
             // check for palindrom string 
    
            if (s.substr(i, j) == reverse(s.substr(i, j)))
            {  
                // compare the string with max string and change according to condition
                if (s.substr(i, j).length() > max.length())
                    max = s.substr(i, j);
            }
        }
    }
    
    //return output string
    return max;
}
main()
{
    string s;
    cout << "--> Enter the String :";
    cin >> s;

   // if (longestPalindromstring(s).length() > 2)
        cout << endl<< "--> longest palindrom String is  : " << longestPalindromstring(s) << endl;
   // else
        cout << "-->No, palindrom String is available";
}