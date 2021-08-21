#include <iostream>
using namespace std;

/*
    || Z -  Algorithm ||

    ==> What is Z array ?
            An element Z[i] of Z array stores length of the longest substring starting from str[i] 
        which is also a prefix of str[0..n-1].
        
        //first element of z array is always 0 or undefine:


    ==> Example :

            Index            0   1   2   3   4   5   6   7   8   9  10  11 
            Text             a   a   b   c   a   a   b   x   a   a   a   z
            Z values         X   1   0   0   3   1   0   0   2   2   1   0 
         
    ==> Algorithm :

            The idea is to maintain an interval [L, R] which is the interval with max R
        such that [L,R] is prefix substring (substring which is also prefix). 

        Steps for maintaining this interval are as follows – 

        1)  If i > R then there is no prefix substring that starts before i and 
            ends after i, so we reset L and R and compute new [L,R] by comparing 
            str[0..] to str[i..] and get Z[i] (= R-L+1).

        2)  If i <= R then let K = i-L,  now Z[i] >= min(Z[K], R-i+1)  because 
            str[i..] matches with str[K..] for atleast R-i+1 characters (they are in
            [L,R] interval which we know is a prefix substring).     
            
            Now two sub cases arise – 

            a) If Z[K] < R-i+1  then there is no prefix substring starting at 
                str[i] (otherwise Z[K] would be larger)  so  Z[i] = Z[K]  and 
                interval [L,R] remains same.
            b) If Z[K] >= R-i+1 then it is possible to extend the [L,R] interval
                thus we will set L as i and start matching from str[R]  onwards  and
                get new R then we will update interval [L,R] and calculate Z[i] (=R-L+1).

*/

// function to create Z array
void Z_Array(string s)
{

    int n = s.length();
    int z[n];           // Z array

    // window references
    int right = 0;
    int left = 0;

    //First element always 0 or undefine
    z[0] = 0;

    // storing value in Z array
    for (int i = 1; i < n; i++)
    {

        if (i > right)
        {
            left = right = i;

            //checking for same charcter
            //length of similar window
            while (right < n && s[right] == s[right - left])
            {
                right++;
            }

            //storing length
            z[i] = right - left;

            right--;
        }
        else
        {

            int k1 = i - left;

            if (z[k1] < right - i + 1)
            {
                z[i] = z[k1];
            }
            else
            {
                left = i;
                
                while (right < n && s[right] == s[right - left])
                {
                    right++;
                }
                z[i] = right - left;
                right--;
            }
        }
    }

    for (int i = 0; i < s.length(); i++)
    {
        cout << z[i] << "  ";
    }
}
main()
{
    string s;
    cin >> s;

    int a[s.length()];
    Z_Array(s);
}