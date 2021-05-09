#include <iostream>
using namespace std;


/*

            Input : HELLO WORLD
            Output : 4433555555666096667775553

    // ALGORITHM

    1. For each character, store the sequence which should be obtained at its respective position in an array, 
             i.e. for Z, store 9999. For Y, store 999. For K, store 55 and so on.
    2. For each character, subtract ASCII value of ‘A’ and obtain the position in the array pointed
        by that character and add the sequence stored in that array to a string.
    3. If the character is a space, store 0
    4. Print the overall sequence.
*/
string NumaricalValue(string s)
{
    string output = "";

    // stroring possible sequence for A to Z
    string str[] = {"2", "22", "222",
                    "3", "33", "333",
                    "4", "44", "444",
                    "5", "55", "555",
                    "6", "66", "666",
                    "7", "77", "777", "7777",
                    "8", "88", "888",
                    "9", "99", "999", "9999"};

    // checking for the every charcter
    for (int i = 0; i < s.length(); i++)
    {
        // if charcter is space
        if (s[i] == ' ')
        {
            output = output + "0";
        }
        else
        {
            // geting the index which is equalent to str array
            int index = s[i] - 'A';
            output = output + str[index];
        }
    }
    return output;
}
main()
{
    string s;

    // Iput string
    cout << "-->Enter the string : ";
    cin >> s;

    // Function call
    cout << NumaricalValue(s);
}