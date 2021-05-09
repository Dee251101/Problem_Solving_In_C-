#include <bits/stdc++.h>
using namespace std;

/* || Problem : Minimum characters to be added at front to make string palindrome ||

        INPUT : AACECAAAA
        OUTPUT: 2
                AA|AACECAAAA  //BECOME PALINDROM

    #ALGORITHM :

            (INPUT STRING S)

        1.  CREATE STRING STR = S + "$" + REVERS(S)                 // AACECAAAA$AAAACECAA
        2.  COUNT THE LPS OF STRING STR
            GET LAST LPS OF LPS ARRAY (LAST LPS IS THE SIZE OF LONGEST SUFFIX WHICH IS PREFIX TOO)
        3.  RETURN LENGTH(S)-LASTLPS 


    // Explanation :

        INPUT STRING S = AACECAAAA              REVERSE STRING R = AAAACECAA
                
                STR  = AACECAAAA$AAAACECAA
                LPS =  0100012220122234567
            
            LASTLPS = 7      LENGTHOF(S) = 9

            ANS = 9 - 7 = 2



*/

// COUNTING LPS
int coutLPS(string s)
{

    int n = s.length();
    int i = 0;   
    int j = 1;

    //LPS ARRAY
    int lps[n];

    lps[0] = 0;    // LPS[0] IS ALWAYS 0

    //TRAVERSING THE WHOLE STRING
    //ADDING VALUE TO LPS ARRAY
    while (j < n)
    {
        
        if (s[i] == s[j])
        {
            i++;
            lps[j] = i;
            j++;
        }
        else
        {
            if (i != 0)
                i = lps[i - 1];
            else
            {
                lps[j] = 0;
                j++;
            }
        }
    }

    //RETURN LAST ELEMENT OF LPS ARRAY
    return lps[n - 1];
}

int Ncharcter(string s)
{
    string r = s;

    reverse(r.begin(), r.end());

    //STRING S + $ +REVERSE(S)
    string str = s + "$" + r;

    int lastlps = coutLPS(str);         //LAST LPS

    return (s.length() - lastlps);
}
main()
{
    string s;

    //INPUT 
    cout<<"--> Enter the string"<<endl;
    cin >> s;

    //OUTPUT
    cout<<"--> Number of charcter to be added at front of string to make palindrom string "<<endl;
    cout << Ncharcter(s);
}