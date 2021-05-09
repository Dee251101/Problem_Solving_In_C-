#include<iostream>
using namespace std;

/*  || Problem : vCount of number of given string in 2D character array ||

    Input : A = {B,B,M,B,B,B},
                {C,B,A,B,B,B},
                {I,B,G,B,B,B},
                {G,B,I,B,B,B},
                {A,B,C,B,B,B},
                {M,C,I,G,A,M}
            
            String s = MAGIC

    Output : 4 

    Algorithm :

        1- Traverse matrix character by character and take one character as string start 
        2- For each character find the string in all the four directions recursively 
        3- If a string found, we increase the count 
        4- When we are done with one character as start, we repeat the same process for the next character 
        5- Calculate the sum of count for each character 
        6- Final count will be the answer

*/

int countString(string s, string input[],int i,int j,int size,int idx)
{
    int found =0;

    // Base condition
    if(i>=0 && j>=0 && j<6 && i<6 && s[idx]==input[i][j])
    {
        //doing visited charcter to 0
        int temp  = input[i][j];
        input[i][j] =0;
        idx++;

        //whole string found
        if(idx==size)
        {
            found = 1;
        }
        else
        {
            found+= countString(s,input,i,j-1,size,idx);    //UPPER
            found+= countString(s,input,i-1,j,size,idx);    //LEFT
            found+= countString(s,input,i+1,j,size,idx);    //RIGHT
            found+= countString(s,input,i,j+1,size,idx);    //DOWN
        }

        // backtracking 
        input[i][j] = temp;
    }

    //return ans
    return found;
}
main()
{
    string input[] = { "BBABBM",
                       "CBMBBA",
                       "IBABBG",
                       "GOZBBI",
                       "ABCBBC",
                       "MCIGAM" };

    string s = "MAGIC";

    int ans = 0;

    //TRAVERSING THE WHOLE CHARCTER ARRAY
    for(int i = 0;i<6;i++)
        for(int j = 0; j<6;j++)
            ans  = ans + countString(s,input,i,j,s.length(),0);
    
    //ans
    cout<<"--> Number of string in 2D charcter array "<<endl;
    cout<<ans;      
}