#include<iostream>
using namespace std;

void IsPalindrm(string s)
{
    int mid = s.length()/2;
    int flag = 0;

    for(int i = 0; i < mid ;i++)
    {
        if(s[i]!=s[s.length()-i-1])
        {
            flag = 1;
            break;
        }
    }
    
    cout<<"--> Output : "<<endl;
    if(flag==0)
    cout<<"Yes,String is palindrom";
    else
    cout<<"No,String is not palindrom";
}
main()
{

    string s;

    cout<<"--> Enter the string :";
    cin>>s;
    
    IsPalindrm(s);

}