#include <iostream>
#include <stack>
using namespace std;

/*
|| PROBLEM : Remove Consecutive Characters ||  

        INPUT = AABBCC
        OUTPUT = ABC

    // ALGORITHM:
        1.    Traverse given string from left to right 
        2.    if stack is empty push current letter in the stack 
        3.    if stack is not empty then check whether stack's top element is same as current element or not .
                 If they are same then don't push current element in your stack 
                 else push current element in your stack.


*/

main()
{
    // input
    string s;
    cin >> s;

    string os = "";     //output string 

    stack<char> st;

    //Traversing the string 
    for (int i = 0; i < s.length(); i++)
    {
        // checking for duplicates
        // if found skip this charcter else push it into stack
        if (!st.empty() && st.top() == s[i])
            continue;
        else
            st.push(s[i]);
    }

    //Converting stack into string 
    for (int i = st.size(); i > 0; i--)
    {
        char x = st.top();
        os = x + os;
        st.pop();
    }
    cout << os << endl;
}