#include <iostream>
using namespace std;

/* || PROBLEM : Function to find Number of customers who could not get a computer ||

        INPUT : 3, “GACCBDDBAGEE”
        OUTPUT: 1

    # ALGORITHM :  //USING MAP

    1.  Traverse the given sequence.
            While traversing, keep track of occupied computers  
            this can be done by keeping track of characters
            (which have appeared only once and a computer was available when they appeared).
            At any point, if count of occupied computers is equal to ‘n’, and there is a new customer, 
                increment result by 1.
    

    INSHORT
    
         PERSON(CHARCTER) -> IS FIRST TIME? -> YES -> IS HE GOT PC?--> YES -> N--;
                                    |                          |
                                    NO                         NO -> ANS++;
                                    |
                                WAS HE USED PC? -> YES --> N++;


        X[I] = 0  --> CHAR COME FIRST TIME
        X[I] = 1  --> CHAR DIDNT GOT pc
        X[I] = 2  --> CHAR GOT PC
        
*/

int NCustomer(int n, string s)
{
    int ans = 0;    // ans stroring
    int x[256] = {0};       // map array


    // TRAVERSING STIRNG
    for (int i = 0; i < s.length(); i++)
    {
        // IS ENTERED PERSON IS NEW?
        if (x[s[i]] == 0)
        {
            x[s[i]] = 1;  // SHOWS THAT CUSTOMER ENTER IN ROOM

            // IF PC IS AVAILABLE OR NOT
            if (n > 0)  
            {
                x[s[i]] = 2;   // SHOWS THAT CUSTOMER GET PC
                n--;
            }
            else
                ans++;  
        }
        else
        {
            if (x[s[i]] == 2)
            {
                n++;
            }

            x[s[i]]--;
        }
    }
    return ans;
}

int main()
{
    string s;
    int n;

    cout << "-->Enter the number of computer : ";
    cin >> n;
    cout << "--> Enter the string : ";
    cin >> s;

    cout << "--> Number of customer : ";
    cout << NCustomer(n, s);
}