#include <bits/stdc++.h>
using namespace std;

/*
        || Problem : Merge Intervals ||

        Input: 
                intervals = [[1,3],[2,6],[8,10],[15,18]]
        Output:    
                [[1,6],[8,10],[15,18]]
        Explanation: 
                Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].


        Aproach 1: Using Stack and Pair            // TC  = O(NLog(N))     // SC = O(N)

            # Algorithm : 

                intialize: 
                    vector<pair<int,int>> -> input pair
                    stack<pair<int,int>> -> merged pair 


                1.  Sort the vector of pairs
                2.  Traverse the vector of pair and check for the condition
                        If pair are overlapping                  [for (x1,y1) & (x2,y2) -> x2<=y1 -> overlapped pair ]
                            merged the pair and store int stack  
                        else
                            store ans in pair stack
                3.  print stack


        Aproach 2: Using Index pointer and updating Vector itself  // TC = O(Nlog(N))       // SC = O(1)

                intialize: 
                    vector<pair<int,int>> -> input pair
                    int index  = pointer to point last ans pair
                    int i = pointer to traverse vector  

                1.  Sort the vector of pairs
                2.  Traverse the vector of pair and check for the condition
                        If pair are overlapping                  [for (x1,y1) & (x2,y2) -> x2<=y1 -> overlapped pair ]
                            update the index pair  
                        else
                            index++
                            update index pair = current pair
                3.  print vector () 0 to index ) as ans
*/

/*
//Aprroach 1: Using Stack 
int main()
{

    // Input
    int n;
    cout<<"--> Enter number of interval : ";
    cin>>n;
    
    vector<pair<int ,int>> interval;  //vector to store interval (Pair)

    cout<<"--> Enter value x and y for each interval : "<<endl;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cout<<"X : ";
        cin>>x;
        cout<<"Y : ";
        cin>>y;
        cout<<endl;

        interval.push_back({x,y});
    }
    // Input End


    // sorting interval using the first element of interval
    sort(interval.begin(),interval.end()); 

    // stack which stores the ans pair
    stack<pair<int,int>> ans;

    //stores the first pair in to ans stack 
    ans.push({interval[0].first,interval[0].second});

    //traverse pair vector
    for(int i=0;i<n;i++)
    {
        int p1_start = ans.top().first;     //ans pair
        int p1_end = ans.top().second;

        int p2_start = interval[i].first;        //pair of the element to be compare with the ans pair
        int p2_end = interval[i].second;

        //Checking if in pair (x1,y1) and (x2,y2) --> is y1 < x2
        //for example (1,2) (3,4) --> is 2 < 3 , if true then push the pair in stack}
        //pairs are overlapping and we have to merge them

        if(p2_start<=p1_end)         //Pair are overlapping 
        {
            ans.pop();              //pop and update the second element of the ans pair 
            p1_end = max(p1_end,p2_end);
            ans.push({p1_start,p1_end});    //push again updated pair
        }
        else        // Pair are not overlapping so simply push pair to stack
        {
            ans.push({p2_start,p2_end});
        }
    }


    //Output : print the stack 

    cout<<"--> Merged Interval : "<<endl;
    while(!ans.empty())
    {
        cout<<ans.top().first<<" , "<<ans.top().second<<endl;
        ans.pop();
    }
 
    return 0;
}
*/


//Aprroach 2: using Index pointer and updating vector of pair it self
//(Optimal soln)   //TC = O(nlongn)     //SC = O(1)
int main()
{

    // Input
    int n;
    cout<<"--> Enter number of interval : ";
    cin>>n;
    
    vector<pair<int ,int>> interval;  //vector to store interval (Pair)

    cout<<"--> Enter value x and y for each interval : "<<endl;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cout<<"X : ";
        cin>>x;
        cout<<"Y : ";
        cin>>y;
        cout<<endl;

        interval.push_back({x,y});
    }
    // Input End


    // sorting interval using the first element of interval
    sort(interval.begin(),interval.end()); 

    //taking index to point the ans of merged pair in interval vector
    int index = 0;

    //traverse pair vector
    for(int i=0;i<n;i++)
    {
        int p1_start = interval[index].first;     //last updated pair of interval
        int p1_end = interval[index].second;

        int p2_start = interval[i].first;        //pair of the element to be compare with the ans pair
        int p2_end = interval[i].second;


        if(p2_start<=p1_end)         //Pair are overlapping 
        {
            p1_end = max(p1_end,p2_end);        // update the pair at index
            interval[index].second = p1_end;
        }
        else        // Pair are not overlapping 
        {
            index++;                            // move to the index ahead  
            interval[index].first = p2_start;      //and update the index pair value with current pair value
            interval[index].second = p2_end;
        }
    }


    //Output : output is getting in inverval vector (0 to index pair)

    cout<<"--> Merged Interval : "<<endl;
    for(int i=0;i<=index;i++)
    {
        cout<<<<{"[ "}>>nterval[i].first<<" , "<<interval[i].second<<" ] "<<endl;
    }
     
 
    return 0;
}
