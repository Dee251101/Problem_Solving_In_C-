#include <iostream>
#include <stack>
#include <string>
using namespace std;


/* ----------------ALGORITHM----------------------

    1) input string 
    2) read the characters of string 1 by 1 using while()
        1) if OP is {,[,(  then push it into stack
        2) if OP is },],) then pop from the stack and compare with OP 
            if poped element is opposite to OP 
                goto step 2
            else 
                expression is invalid
    3) exit Loop
    4) checking the stack 
            if stack is empty 
                expression is valid 
            else 
                expression is invalid
    5) end
-----------------------------------------------------*/

main()
{
    stack<int> s;
    string s1;
    cin >> s1;
    int i = 0;
    cout<<"---->Testing the expression"<<endl;
    while (s1[i] != '\0')
    {
        cout << s1[i] << endl;

        if (s1[i] == '{' || s1[i] == '(' || s1[i] == '[')
            s.push(s1[i]);
        else if (s1[i] == '}' || s1[i] == ')' || s1[i] == ']')
        {
            char temp = s1[i];
            int x = temp;
            int y = s.top();
            s.pop();
            if (x == y + 1 || x == y + 2)
                break;
            else
            {
                cout << "!! invalid expression !!";
            }
                 
        }

        i++;
    }
    if (s.empty())
        cout << "!! valid expression !!";
    else
        cout << "!! invalid  expression !!";
}



