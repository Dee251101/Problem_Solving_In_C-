#include<iostream>
#include<algorithm>
using namespace std;


// USING  RECURSION (WORK LIKE INORDER TRAVERSAL)

void Permute(string s,int l,int n)
{
    // there is no charcter left to permute or swap 
    if(n==l)
    {
        cout<<s<<" ";
    }
    else
    {
        // read the left charcter 
        for(int i = l ; i<s.length();i++)
        {
            
            swap(s[i],s[l]);
           // By recurtion reach to the last left nodes of tree
            Permute(s,l+1,n);
           // for backtracking set string as it is 
            swap(s[i],s[l]);
        }
    }
}

main()
{
    string s;

    cout<<"Enter the String :";
    cin>>s;

    cout<<"--> ALL Permutation is "<<endl;
    Permute(s,0,(s.length()-1));
}

/*
// USING STL 
main()
{
    string s;

    cout<<"Enter the String :";
    cin>>s;
        cout<<s<<" ";

    // SORT THE  STRING 
    sort(s.begin(),s.end());

    cout<<"--> ALL Permutation is "<<endl;
    // PRINT THE PERMUTATION USING STL
    while(next_permutation(s.begin(),s.end()))
    {
        cout<<s<<" ";
    }
}

*/