#include<iostream>
#include<map>
using namespace std;

/*
|| PROBLEM : iSOMORPHIC STRING ||       

        INPUT : S1 = ABBAA       S1 = ABBAA
                S2 = XYYXX       S2 = XYYYX
        OUTPUT: YES               NO

    // Algorithm 

    1.  if length of string 1 nad 2 are not same return false
    2.  read the all the charcter of the string and store the value of its map
        if already stored value for that value in map 
            check for that value is same as map 
            if not matched return false
    3.  return true 

*/

// Using array mapping....

string Isisomorphic(string s1,string s2)
{

    // map for corresponding  string
    int m1[256]={0};  // for s1 
    int m2[256] ={0};  // for s2

    // length are diff.
    if(s1.length()!=s2.length())
        return "NO";

    // traversing string
    for(int i = 0 ; i < s1.length() ; i++)
    {
        // if map value is 0 for ith charcter (it means apear first time in string )
        // add the value for map 
        if(!m1[s1[i]]&&!m2[s2[i]])
        {
            m1[s1[i]] = s2[i];
            m2[s2[i]] = s1[i];
        }
        // checking for the value in the map is true or not 
        else if(m1[s1[i]]!=s2[i])
            return "No";
    }

    return "Yes";
}

main()
{
    string s1;
    string s2;
    
    cout<<"Enter String 1 :";
    cin>>s1;
    cout<<"Enter String 2: ";
    cin>>s2;

    cout<<"Is String is isomorphic? "<<endl;
    cout<<Isisomorphic(s1,s2);



}