#include <iostream>
using namespace std;


/* Spiral traversal */
/*

k = point the starting point of columns
l = point the starting points of row 
m = point the ending point of columns 
n =  point the endling points of the row

*/

/*
matrix 4*4

*/

void spiral_traversal(int matrix[100][100], int m, int n)
{
    int i, k = 1, l = 1;
    while (l <= n && k <= m)                       
    {
        for (i = k; i <= m; i++)                             //traversal of  'l'th row
        {
            cout << matrix[l][i] << "  ";
        }

        l++;

        for (i = l; i <= n; i++)                             // traversal of mth column
        {
            cout << matrix[i][m] << "  ";
        }

        m--;

        if (k <= m)
        {
            for (i = m; i >= k; i--)                         //traversal of nth row
                cout << matrix[n][i] << "  ";

            n--;
        }

        if (l <= n)                                          // traversal of kth column
        {
            for (i = n; i >= l; i--)
                cout << matrix[i][k] << "  ";

            k++;
        }
    }
}

void traversal(int matrix[100][100], int m, int n)                     //normal traversal of matrix
{
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= m ; j++)
        {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}
main()
{

    int matrix[100][100];
    int m, n;

    cout << "-> Enter the row size of matrix" << endl;
    cin >> m;
    cout << "-> Enter the column size of matrix" << endl;
    cin >> n;

    cout << "-> Enter the element of matrix" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "-> the element of matrix" << endl
         << endl;
     traversal(matrix,m,n);

    cout << "--> Spiral traversal of matrix is :" << endl
         << endl;
    spiral_traversal(matrix, m, n);
}