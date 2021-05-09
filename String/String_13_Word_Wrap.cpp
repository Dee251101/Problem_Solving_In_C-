#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
/*
        || Problem : Word Wrap ||

    # Example : 
                input :     array A = {3,2,2,5}   // size of each word
                            int N = 6     // size of line 
                Output:     (1,1),(2,3),(4,4)

    # Explaination  :

        possible output :

        (1)                                                         (2)
            3 2     space = 6-3-2-1 = 0                                     3       space = 6-3 = 3
            2       space = 6-2 =4                                          2 2     space = 6-2-2-1 = 1
            5       space = 0  // last line                                 5       space = 0   //last line
        
        total space = 0+16+0 = 16                                           total space  =  9+1+0 
        
      
        hence ans 2 is optimized ans.

        // NOTE  :  we can't get ans (2) using greedy method.
        // so we have used DP

    # Algorithm   : [ DP ]

        1.  calculate the spaces after putting all charcter in each line 
                CHAR from i to n
        2.  Calculate the cost
        3.  Calculate the least cost to arrenge the all word
        4.  print word of each line

*/

// A utility function to print the solution
int printSolution(int p[], int n);

// l[] represents lengths of different words in input sequence.
// For example, l[] = {3, 2, 2, 5} is for a sentence like
// "aaa bb cc ddddd". n is size of l[] and M is line width
// (maximum no. of characters that can fit in a line)
void solveWordWrap(int l[], int n, int M)
{
    // For simplicity, 1 extra space is used in all below arrays

    // space[i][j] will have number of extra spaces if words from i
    // to j are put in a single line
    int space[n + 1][n + 1];

    // lc[i][j] will have cost of a line which has words from
    // i to j
    int lc[n + 1][n + 1];

    // c[i] will have total cost of optimal arrangement of words
    // from 1 to i
    int c[n + 1];

    // p[] is used to print the solution.
    int p[n + 1];

    int i, j;

    // calculate extra spaces in a single line. The value extra[i][j]
    // indicates extra spaces if words from word number i to j are
    // placed in a single line
    for (i = 1; i <= n; i++)
    {
        if(l[i-1]>M)
        {
            cout<<"--> NOT POSSIBLE";
            return ;
        }
        space[i][i] = M - l[i - 1];
        for (j = i + 1; j <= n; j++)
            space[i][j] = space[i][j - 1] - l[j - 1] - 1;
    }

    // Calculate line cost corresponding to the above calculated extra
    // spaces. The value lc[i][j] indicates cost of putting words from
    // word number i to j in a single line
    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (space[i][j] < 0)
                lc[i][j] = INF;
            else if (j == n && space[i][j] >= 0)
                lc[i][j] = 0;
            else
                lc[i][j] = space[i][j] * space[i][j];
        }
    }

    // Calculate minimum cost and find minimum cost arrangement.
    // The value c[j] indicates optimized cost to arrange words
    // from word number 1 to j.
    c[0] = 0;
    for (j = 1; j <= n; j++)
    {
        c[j] = INF;
        for (i = 1; i <= j; i++)
        {
            if (c[i - 1] != INF && lc[i][j] != INF &&
                (c[i - 1] + lc[i][j] < c[j]))
            {
                c[j] = c[i - 1] + lc[i][j];
                p[j] = i;
            }
        }
    }
    cout << "--> Mimimum space Cost of arrengment is  :  ";
    cout << c[n] << endl;

    //Print the line in the word
    printSolution(p, n);
}

int printSolution(int p[], int n)
{
    int k;
    if (p[n] == 1)
        k = 1;
    else
        k = printSolution(p, p[n] - 1) + 1;
    cout << "--> Line number " << k << ": From word no. " << p[n] << " to " << n << endl;
    return k;
}
main()
{

    int x;
    cout << "--> Enter the number of word  :";
    cin >> x;
    int size[x];
    int l;
    cout << "--> Enter the size of each word :" << endl;
    for (int i = 0; i < x; i++)
    {
        cout << "--> Size of word " << i << "  :  ";
        cin >> size[i];
    }

    cin >> l;

    cout << endl<< "  #  answer  #  " << endl;

    solveWordWrap(size, x, l);
}