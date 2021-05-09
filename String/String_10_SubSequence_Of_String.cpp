#include<iostream>
#include<string>
using namespace std;


// Subsequence and substrings are diff. 


    // Using recursion orinting the subsequence of string
void printSubsequence(string input, string output)
{
    // Base Case
    // if the input is empty print the output string
    if (input.empty()) {
        cout << output << endl;
        return;
    }
 
    // output is passed with including 
    // the Ist characther of
    // Input string
    printSubsequence(input.substr(1), output + input[0]);
 
    // output is passed without 
    // including the Ist character
    // of Input string
    printSubsequence(input.substr(1), output);
}
 
/*
// substring using loop 
void sub_string(string s )
{
     int l = s.length();                                      
    
    // finding substring of string s;
    for (int i = 0; i <= l; i++)
    {

        for (int j = 0 ; j <= l-i; j++)
        {
              cout<<s.substr(i,j)<<endl;
        }
}
}
*/
main()
{
    
    string s;
    string output;
    cin>>s;
    //sub_string(s);
     printSubsequence(s,output);

}
