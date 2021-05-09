#include <iostream>
using namespace std;
#define R 3
#define C 3

/*  || PROBLEM : Recursively print all sentences that can be formed from list of word lists ||

        arr[R][C]  =    {{"you", "we"},
                        {"have", "are"},
                        {"sleep", "eat", "drink"}};

        00 + 10 + 20    -> you have sleep
        00 + 10 + 21    -> you have eat
        00 + 10 + 22    -> you have drink
        00 + 11 + 20    -> you are sleep
        00 + 11 + 21    -> you are eat
        00 + 11 + 22    -> you are drink
        00 + 12 + 20    -> NULL  |
        00 + 12 + 21    -> NULL  |    || dosnt go ahead cz 12 is not available ||
        00 + 12 + 22    -> NULL  |


    --> repeating this process for other words of first raw:

*/

// UISNG RECURSION :
void print(string s[R][C], string ans, int r)
{

    // BASE CASE 
    // Printing OUTPUT
    if (r == R)
    {
        cout << ans << endl;
        return;
    }

    // recursive call
    for (int i = 0; i < C; i++)
    {
        // if string is null then dosnt called ahead 
        if (s[r][i] != "")
            print(s, ans + " " + s[r][i], r + 1);
    }
}
main()
{
    string arr[R][C] = {{"you", "we"},
                        {"have", "are"},
                        {"sleep", "eat", "drink"}};

    // calling function
    print(arr, "", 0);   //(original string,output string ,counting start from 0)
}