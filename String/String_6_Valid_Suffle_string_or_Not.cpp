#include<iostream>
using namespace std;

/*
            s1 = xy   s2  = 12
            s = x1y2   -->  valid suffle
            s = x2y1   -- >  invalid suffle
        
        //Algorithm
        
        1. check the lenght of s= s1 + s2
            if s = s1 + s2
                1.  read the character of s string one by one till end 
                2.  check the character is in s1 string or s2 string 
                        if character in s1 or s2 string 
                             Increment counter of s1 or s2
                        else
                             return "not valid suffles"            
                3.  checking is any character left ni s1 or s2 
                     if sum of counter is equals to lenght of s (it means there is no any character left in s1 or s1)
                        return "valid suffles";
        2. if upper both return statement dosnt run for that 
            return " not valid suffles "
*/


string isvalidsuffle(string s1,string s2,string s)
{
    int l = s1.length()+s2.length();

        // cheking is lenght of s = s1+s2
        if(l==s.length())
        {
            //  coutn1--> point --> index of s1
            //  count2--> point --> index of s2
            int count1 = 0;
            int count2= 0;

            // reading character of s
            for(int i = 0; i<s.length();i++)
            {
                // check the character of s is in s1 or s2 ;
                if(s[i]==s1[count1]&&count1<s1.length())
                    count1++;
                else if(s[i]==s2[count2]&&count2<s2.length())
                    count2++;
                else
                    return "Not valid Suffle";       
            }
             
            // check that is any charecter left in s1 or s2
            if((count1+count2)==l)
                return "Valid suffules";
        }
        
        return "Not valid suffle";
}
main()
{
        string s1,s2,s;
        cout<<"--> Enter string s1 : ";
        cin>>s1;
        cout<<"--> Enter string s2 : ";
        cin>>s2;
        cout<<"--> Enter string s : ";
        cin>>s;
        cout<<"           Result :  ";
        cout<<isvalidsuffle(s1,s2,s);

        
}