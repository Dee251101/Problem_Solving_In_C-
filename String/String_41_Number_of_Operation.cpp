#include<iostream>
using namespace std;

/* || PROBLEM : Transform One String to Another using Minimum Number of Given Operation ||

        INPUT :     String a =  EACBD   ||      String A = EACBD
                    String B =  EABCD   ||      Stirng B = AEBCD
        OUTPUT:     3                   ||      3

    #Explanation:  E A C B D -> B E A C D -> A B E C D -> E A C B D    // FIRST CASE   
                                 MOVE B       MOVE C        MOVE E
                   E A C B D -> B E A C D -> A B E C D -> E A C B D   // SECOND CASE

                   WE HAVE TO MOVE 3 CHARCTER TO FRONT TO MAKE STRING 2.
                   DOESNT MATTER IN WHICH ORDER WE DO.  
                   IT DOESNT MATTER IN WHICH ORDER YOU MOVE CHARCTER.   
        
        
        // ALGORITHM :           // TS = O(N)

        BY THIS WE CAN COUNT ONLY THE CHARCTER NEED TO MOVE BUT CANT ABLE TO SAY IN WHICH ORDERED.

        1. CHECK FOR THE LENGTH OF A AND B STIRNG 
                IF NOT SAME RETURN -1
        2. CHECK FOR THE STRING HAVING SAME NUMBER OF CHARCTER OR NOT 
        3. TRAVERS BOTH STRING FROM RIGHT END
                IF(A[I]=B[J])
                        JUST GO AHEAD WITH I--,J--
                ELSE
                        FIND FOR B[J] IN STIRNG A
                        WHILE(B[J] FIND IN A)
                        {
                                I--;
                                ANS++;   // INTIALIZED  0 BEFOR USED 
                        }
        4. RETURN ANS;
                
*/

int Operation(string a,string b,int n,int m)
{
        int temp[256] = {0};

        int ans = 0 ; 

        for(int i = 0;i<n;i++)
        {
                temp[a[i]]++;
                temp[b[i]]--;
        }
        for(int i = 0;i<n;i++)
        {
                if(temp[a[i]]!=0||temp[b[i]]!=0)
                return -1;
        }

        int i = n-1;
        int j =m-1;
        while(i>=0 && j>=0)
        {
                 
                if(a[i]==b[j])
                {
                        i--;
                        j--;
                }
                else
                {
                        while(i>=0&&a[i]!=b[j])
                        {
                                
                                i--;
                                ans++;
                        }
                }
        }
        return ans;

}

int main()
{
        string a;
        string b;

        cin>>a;
        cin>>b;

        int n = a.length();
        int m = b.length();

        if(n==m)
                cout<<Operation(a,b,n,m);    


}