#include <iostream>
using namespace std;
/*
            (inout is n)
        for n=1     output     1
            n=2     output     11
            n=3     output     21
            n=4     output     1211
            n=5     output     111221
            n=6     output     312211
            n=7     output     13112221

    // algorithm

    1. for n= 1 or n=2 return the string 1 or 11 ADN the intialize string s;
    2. play the loop from i =3 to i = n 
           1. read the character from s one by one from index 1 
                1 check  the  previous character is == currunt characher or not
                    if same 
                        than count ++
                    else 
                        add the charcter in temp string 
                        t = t + counter + previous character
                        reset the counter
                2. set  s string = temp string
    3. return string s: 
*/
string count_say(int n)
{

    // for n = 1 or 2
    if (n == 1)
        return "1";
    if (n == 2)
        return "11";

    string s = "11";
    int i = 3;
    while (i <= n)
    {
        string t = "";
        int count = 1;

        for (int i = 1; i <= s.length(); i++)
        {
            // count the number of same character
            if (s[i] == s[i - 1])
                count++;
            else
            {
                // adding the counter and charcter in result string
                t = t + to_string(count);   // to string is to convert the character into the string 
                t = t + s[i - 1];
                count = 1;
            }
        }
        s = t;
        i++;
    }
    return s;
}

main()
{
    int n;
    cout<<"--> Enter the number ";
    cin >> n;
    cout<<endl<<"--> count and say Value ";
    cout<<count_say(n);
}