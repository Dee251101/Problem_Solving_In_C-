#include<iostream>
using namespace std;
/*
            input =  0 0 0 1 0 1 0 1 1 1 

            case 1=  0 1 0 1 0 1 0 1 0 1    odd = 1 even = 0
            case 2=  1 0 1 0 1 0 1 0 1 0    odd = 0 even = 1

    // ALGORITHM

        1. read the string till end
        2. check for the case one and case two 
            increase the counter for each case
        3. print minimum counter.
*/
main()
{
    string s;
    cin>>s;

    int c1 = 0 ;
    int c2 = 0 ; 
    for(int i = 0 ; i< s.length();i++)
    {
            // Matching case 1
            if((i%2==0 && s[i]=='1')||(i%2!=0 && s[i]=='0'))
            c1++;

            // Matchin case 2
            if((i%2==0 && s[i]=='0')||(i%2!=0 && s[i]=='1'))
            c2++;
    }

    // printing minimum case 
    cout<<min(c1,c2);

}