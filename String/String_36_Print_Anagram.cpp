#include<bits/stdc++.h>

using namespace std;
/*
        Input :  N = 5
                words[] = {act,god,cat,dog,tac}
        Output:  act,cat,tac
                 god,dog

    Map :  map<string,vector>
        
        //FORMATE :  
        
            SORT(S)--->STOR-->MAP[SORT[S]] = S;

            //MAP VALUE  = sorted string 
            
            MAP[ACT] = {ACT,CAT,TAC}
            MAP[GDO] = {GOD,DOG}

    // ALGORITHM:

        1.  Create map of string and vector
        2.  traverse the string array 
            store the string in map to corresponding place 
        3.  print the map 


*/

void Anagram(string s[],int n )
{
    // creating map of string and vector
    map<string,vector<string>> m;

    // storing data on map
    for(int i=0;i<n;i++)
    {
        //map value 
        string st = s[i];
        sort(st.begin(),st.end());

        //push string to their map value
        m[st].push_back(s[i]);
    }
    

    cout<<"--> Output :"<<endl;
    // printing map
    for(auto x:m)
    {
        //pointing to the vector
        vector<string> v = x.second;

        //printing vector
        for(int i = 0;i<v.size();i++)
        {
            cout<<v[i]<<",";
        }
        cout<<endl;   
    }
}
main()
{
    int n;
    
    cout<<"Enter the size of array : ";
    cin>>n;

    string s[n];

    for(int i = 0 ; i < n ;i++)
    {
        cout<<"Enter the string "<<i<<" : ";
        cin>>s[i];
    }

    //function call
    Anagram(s,n);

}