#include <iostream>
#include <string>
using namespace std;

/*
            input 11000101
            output :  1100 01 01 

    Approach:
        
    // for just counting the number of substring with equal 0s and 1s
       
       1. Initialize count = 0 and traverse the string character by character 
       2. keep track of the number of 0s and 1s so far, 
       3. whenever the count of 0s and 1s become equal increment the count. 
       4. If the count of 0s and 1s in the original string is not equal then print 0
             else print the value of count after the traversal of the complete string. 

    // FOR PRINTING THE SUBSTRING WITH EQUAL 0S AND 1S I USE WHILE LOOP OTHER WISE WE CAN DO IS WITHOUT WHILE 
    
*/

main()
{

    string s = "1110000101";

    int count0 = 0;
    int count1 = 0;
    int n = 0;
    int l = s.length();
    int Scount = 0;

    cout << "--> The substring of  " << s << "  with equals 0s and 1s is :" << endl;

    // While loop is for printing the substring only
    while (n != l)
    {

        // for loop to read each word of string
        for (int j = 0; j < l; j++)
        {
            // count 1s and 0s
            if (s[n + j] == '0')
                count0++;
            else
                count1++;

            // when the count of 0s and 1s same increasing substringcount variable
            if (count0 == count1)
            {
                cout << s.substr(n, j + 1) << endl;
                Scount++;
                n = j + n + 1;
                break;
            }

            // if no equal 0s and 1s substring is available
            else if (j == l - 1)
                n++;
        }
    }

    // printing output
    cout << "--> Total number of substring is : ";
    cout << Scount << endl;
    cout << "--> Total Number of 0s : " << count0 << endl;
    cout << "--> Total Number of 1s : " << count1;
}
