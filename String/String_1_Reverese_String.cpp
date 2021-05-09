#include <iostream>
#include <string>
using namespace std;

string revers(string s)
{
    int length = s.length();
    int n = s.length() / 2;
    for (int i = 0; i <n; i++)
    {
        int temp = s[i];
        s[i] = s[length - i - 1];
        s[length - i - 1] = temp;
    }
    return s;
}
main()
{

    string s;
    //taking input as string

    cout << "-->Enter the string : ";
    getline(cin, s);
    //Printing string
    cout << "-->String befor reversing :";
    cout << s << endl;

    cout << "-->String after reversing :";
    cout << revers(s);
}
