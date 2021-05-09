#include <iostream>
#include<string>
using namespace std;


/*      s1 = ABC    s2  = BCA
       
        1. take temp string  with s1+s1 or s2+s2
        2. like temp = s1+s1 = ABCABC
        3. find s2 in temp 
                 if s2 found in temp
                        it is rotational string of s1;
                 else 
                        its not rotational string of s2;

*/
void IsRotation(string t1,string t2)
{
    string temp ;
    temp = t2+t2;

    if(temp.find(t1)!=string::npos)
            cout<<"Yes,string 1 and string 2 is rotatoin of each other";
        else
        cout<<"No ,string 1 and string 2 is not rotation of each other";

}
main()
{
    string s1,s2;
    cout << "-->Enter the string 1 :  ";
    cin >> s1;
    cout << "-->Enter the string 2 :  ";
    cin >> s2;
    IsRotation(s1,s2);

}