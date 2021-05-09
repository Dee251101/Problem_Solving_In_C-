#include <bits/stdc++.h>
using namespace std;

/*  || Problem : Minimum Swaps for Bracket Balancing ||

    #Example:       Input : []][][
                    Output : 2
                   
                   []][][ -> [][]][ -> [][][] 


    # Algorithm :  // METHOD 1 :

    Here is the algorithm :

    1. We declare ‘minSwaps’ and ‘count’ for storing the resultant answer 
        and for counting the difference of open and closed brackets, respectively.
    2. We run a loop for ‘i’ = ’0’ to ‘N’:
        1. If the current character is ‘(‘:
            ‘count++’
            Else:
            ‘count--’
        2. If ‘count’ is negative then we start balancing ‘BRACKETS’:
            J=I+1;
            We run a loop while ‘j’ < ‘N’ and ‘STR[j]’ = ‘)’.
            ‘j++’
            ‘minSwaps’ += ‘j’ - ‘i’
            SWAPPING BRACKETS
            RESET COUNTER TO 1:
    3. Finally, we return ‘minSwaps’ as our answer.

*/

/*
// METHOD 1 :
// Function : return minimum swap needed 
// Using greedy aproach :               TS = O(N^2)     SC = O(1)
int minimum_Swap(string s)
{
        int n = s.length();
        int count =0;       // count balanced bracket
        int swap = 0;       // ans
 
        // Traversing string
        for(int i = 0 ; i < n;i++)
        {
        
            if(s[i]=='[')
                count++;
            else
                count--;

            //if unbalanced bracket found 
            if(count<0)
            {
                int j = i+1;

                //finding the open bracket in rest string
                for(j = i+1; j<n;j++ )
                {
                    if(s[j]=='[')
                        break;
                }

                //minimum swap needed to swap opening bracket with closed bracket  swap(j,i);
                swap = swap + (j-i);
               
               // doing swapping of bracket
                while(j>i)
                {
                    s[j]=s[j-1];
                    j--;
                }
                s[i]=')';

                //reset the bracket counter
                count=1;
            }
        }

        //return ans
        return swap;
}
*/

// METHOD 2: 
// Using Vector :              // TS = O(N)   //  SC = O(N)
int minimum_Swap(string s)
{
    vector<int> v; // store index of opening bracket
    int n = s.length();

    // storing the index of '[' in vector
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '[')
            v.push_back(i);
    }

    int idx = 0;   //index of vector
    int swap = 0;  //ans
    int count = 0; //bracket counter

    // Traversing string
    for (int i = 0; i < n; i++)
    {

        if (s[i] == '[')
        {
            count++;
            idx++;
        }
        else
            count--;

        // Unbalnced bracket found
        if (count < 0)
        {
            //storing ans 
            swap = swap + (v[idx] - i);

            //swapping the bracket
            int temp = s[i];
            s[i] = s[v[idx]];
            s[v[idx]] = temp;

            //vector index and counter reseting 
            idx++;
            count = 1;
        }
    }

    //return ans
    return swap;
}
main()
{
    string s;

    cout << "--> Enter the string : " << endl;
    cin >> s;

    cout << "--> Minimum swap needed : " << endl;
    cout << minimum_Swap(s);
}