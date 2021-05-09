#include <iostream>
#include <stack>
using namespace std;

/* // Method 1 : [ USING STACK ]        // TS = O(N)  // SA = O(N)


    INPUT : }{{}}{{{
    REMOVED BALANCEPART : = {{}}
    ELSE STRING :  } {{{

    output changes : { } { }  need 3 changes;

*/

main()
{

    int t;
    cin >> t;

    // for testcase
    while (t--)
    {

        string s;
        cin >> s;

        stack<int> st;

        int count1 = 0; //count { bracket in stack
        int count2 = 0; // count } bracket in stack

        // If length of string is even then and only then the bracket will be balanced
        if (s.length() % 2 == 0)
        {
            //reading character of string 
            // Stroring the unbalanced  in the stack
            for (int i = 0; i < s.length(); i++)
            {

                if (s[i] == '}' && !st.empty() && st.top() == '{')
                {
                    st.pop();
                    count1--;
                }
                else
                {
                    st.push(s[i]);
                    if (s[i] == '{')  //count { and } in stack 
                        count1++;
                    else
                        count2++;
                }
            }

            // Calculating the count of reversion we need
            if (count1 % 2 == 0)
                count1 = count1 / 2;
            else
                count1 = (count1 / 2) + 1;
            if (count2 % 2 == 0)
                count2 = count2 / 2;
            else
                count2 = (count2 / 2) + 1;

            cout << count1 + count2 << endl;
        }
        else // If string length is odd than simply return -1
            cout << "-1" << endl;
    }
}


/*

// METHOD 2:  [ WITHOUT USING STACK ]                  // TS = O(N)  // SA  = O(1)
 

#include <bits/stdc++.h>
using namespace std;

// Returns count of minimum reversals for making
// expr balanced. Returns -1 if expr cannot be
// balanced.
int countMinReversals(string expr)
{
	int len = expr.length();

	// Expressions of odd lengths
	// cannot be balanced
	if (len % 2 != 0) {
		return -1;
	}
	int left_brace = 0, right_brace = 0;
	int ans;
	for (int i = 0; i < len; i++) {
	
		// If we find a left bracket then we simply
		// increment the left bracket
		if (expr[i] == '{') {
			left_brace++;
		}
	
		// Else if left bracket is 0 then we find
		// unbalanced right bracket and increment
		// right bracket or if the expression
		// is balanced then we decrement left
		else {
			if (left_brace == 0) {
				right_brace++;
			}
			else {
				left_brace--;
			}
		}
	}
	ans = ceil(left_brace / 2) + ceil(right_brace / 2);
	return ans;
}

// Driver program to test above function
int main()
{
	string expr = "}}{{";
	cout << countMinReversals(expr);
	return 0;
}

*/