#include <bits/stdc++.h>
using namespace std;

/*  || Problem : Find next greater number with same set of digits ||

        INPUT :  " 218765 "     (STRING)
        OUTPUT:  " 251678 "

    # EXPLANATION :
        1. -> NOT IN DECREASING ORDER
        2. -> BREAKING POINT -> INDEX = 1 
        3. -> SMALLEST NUMBER IN 1 TO END_OF(S) -> SMALL_iNDEX = 5
        4. -> SWAP(INDEX 1 TO INDEX 5)   // 258765
        5. -> SORT(S,I+1 TO END);        //251678
        6. -> RETURN S


    # ALGORITHM :

    1.  TRAVERSE THE STRING FROM LEFT TO RIGHT 
        IF STRING IS IN DECREASING ORDER 
            RETURN  NOT POSSILE STRING
    2.  WHEN S[I] < S[I+1]
            BREAK;
    3.  FIND THE SMALLEST NUMBER IN I+1 TO END OF STRING 
    4.  SWAP(S[I],S[SMALL])
    5.  SORT REST STRING S FROM i+1 TO END
    6.  RETURN STRING 

*/


//  FUNCTION TO FIND SMALLEST VALUED INDEX
int smallest(string s, int x)
{
    int m = x;
    for (int i = x; i < s.length(); i++)
    {
        if (s[i] < s[m])
            m = i;
    }
    return m;
}

// FUNCTION TO SWAP ELEMENT
void swap(string &s, int a, int b)
{
    int temp = s[a];
    s[a] = s[b];
    s[b] = temp;
}

// FUNCTION RETURN THE NEXT GREATER NUMBER
string GNumber(string s)
{
    int size = s.length();
    int i; 

    // FINDING THE CONDITION BREAKING POINT/INDEX
    for (i = size - 1; i > 0; i--)
    {
        if (s[i + 1] > s[i])
            break;
    }

    // IF CONDITION BREAKING INDEX 0
    // ALREADY  GREATEST NUMBER
     if (i == 0 && s[0]>s[1])
        return "Not possible";

    // SMALLEST NUMBER INT STRING AFTER THE BREAKING POINT
    int small = smallest(s, i + 1);

    // SWAP SMALLEST INDEX WITH I
    swap(s, i, small);

    // SORT REST STRING 
    sort(s.begin() + i + 1, s.end());

    return s;
}
main()
{
    string s;

    // INPUT
    cout<<"--> Enter the number string : "<<endl;
    cin >> s;

    cout<<"--> Next greater number of the string is : "<<endl;
    cout << GNumber(s);
}