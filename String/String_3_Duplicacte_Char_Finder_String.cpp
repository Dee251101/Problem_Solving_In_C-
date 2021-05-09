#include<iostream>
using namespace std;


main()
{
    string s;
    static int duplicat[256] ;
    cout<<"-->Enter the string"<<endl;
    getline(cin,s);
    for(int i =0; i<s.length();i++)
    {
        int x = s[i];
                 duplicat[x]++;
    }
    
    int i = 0;

    cout<<"--> List of the duplicate character in string :"<<endl;
     while(i!=256)
    {
        if(duplicat[i]>1)
          cout<<(char)i<<"---"<<(duplicat[i])<<endl;
          i++;
    }


}