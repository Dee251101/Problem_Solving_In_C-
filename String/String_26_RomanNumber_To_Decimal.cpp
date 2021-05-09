#include <iostream>
#include <map>
using namespace std;

/*
            //      M   M     M   D   C   C  X   C  I V
            //    1000 1000 1000 500 100 100 10 100 1 5
            //    1000 + 1000 + 1000 + 500 + 100 + 100 - 10 + 100 + 1 + 5 = 3794


        --> AlGORITHM

       1.  Split the Roman Numeral string into Roman Symbols (character).
       2.  Convert each symbol of Roman Numerals into the value it represents.(i used external array to store the value of string)
       3.  Take symbol one by one from starting from index 0: 
                  If current value of symbol is less then the value of next symbol,          
                         subtract this value by adding the value of next symbol to the running total
                         and skip the next element and jump to the next to next:
                  else 
                        then add currunt value to the running total. 

*/

// METHOD 1 : (SIMPLE)
// USING SWTICH CASE AND LOOP

main()
{

    string s = "MMMDCCXCIV";
    // cin >> s;
    int i = 0;
    int tempArray[s.length()];

    // reading the character of string and storing its value to temp array
    while (i != s.length())
    {
        switch (s[i])
        {
        case 'I':
        {
            tempArray[i] = 1;
            break;
        }
        case 'X':
        {
            tempArray[i] = 10;
            break;
        }
        case 'V':
        {
            tempArray[i] = 5;
            break;
        }
        case 'L':
        {
            tempArray[i] = 50;
            break;
        }
        case 'C':
        {
            tempArray[i] = 100;
            break;
        }
        case 'D':
        {
            tempArray[i] = 500;
            break;
        }
        case 'M':
        {
            tempArray[i] = 1000;
            break;
        }
        default:
        {
            cout << "Invalid Input";
            exit(0);
        }
        }
        i++;
    }

    // variable to store output 
    int Decimal = 0;

    // Traversing temparray and calculating value 
    for (int j = 0; j < s.length(); j++)
    {

        if (tempArray[j] < tempArray[j + 1])
        {
            Decimal = Decimal - tempArray[j] + tempArray[j + 1];
            j++;
        }
        else
            Decimal = Decimal + tempArray[j];
    }

    // output 
    cout<<"--> Your String is :  "<<s<<endl;
    cout <<"--> Decimal value is :- " << Decimal;
}

// METHOD 2 : (MAP)
// USING MAP AND LOOP

/*
main()
{
    string s = "MMMDCCXCIV";

    map<char, int> m;
    m.insert({'I', 1});
    m.insert({'V', 5});
    m.insert({'X', 10});
    m.insert({'L', 50});
    m.insert({'C', 100});
    m.insert({'D', 500});
    m.insert({'M', 1000});

    int Decimal = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (m[s[i]] < m[s[i + 1]])
        {
            Decimal = Decimal - m[s[i]] + m[s[i + 1]];
            i++;
        }
        else
            Decimal = Decimal + m[s[i]];
    }

    cout<<"--> Your String is :  "<<s<<endl;
    cout <<"--> Decimal value is :- " << Decimal;
}

*/