#include<bits/stdc++.h>
using namespace std;
/*
        || Problem : Factorial Of large Number ||

        factorial(n) 
                1) Create an array fac[]’ of MAX size where MAX is number of maximum digits in output. 
                2) Initialize value stored in ‘fac[]’ as 1 and initialize ‘fac_size’ (size of fac[]’) as 1. 
                3) Do following for all numbers from x = 2 to n. 
                        a) Multiply x with fac[] and update fac[] and fac_size to store the multiplication result.

        multiply(fac[], x) 
                1) Initialize carry as 0. 
                2) Do following for i = 0 to fac_size – 1 
                ….a) Find value of fac[i] * x + carry. Let this value be prod. 
                ….b) Update fac[i] by storing last digit of prod in it. 
                ….c) Update carry by storing remaining digits in carry. 
                3) Put all digits of carry in fac[] and increase fac_size by number of digits in carry.
*/

//Function to multiply the number with every number
int Multiply(int n,int fac[],int fac_size)
{
    int carry  = 0;  //Stor Carry 

    //Traverse and applying arithmetic Multiplication
    for(int i = 0;i<fac_size;i++)
    {
        //temp  --> sotre multiplication 
        int temp = n*fac[i]+carry;
        //Update Array
        fac[i] = temp%10;
        //Carry
        carry = temp/10;
    }

    //Storing carry to new block of array 
    while(carry)
    {
        fac[fac_size] = carry%10;
        carry = carry/10;
        fac_size++;
    }

    return fac_size;

}

//factorial
void Factorial(int n)
{
        int fac[100000]; //store ans

        //Factorial of 0 is = 1 
        fac[0] = 1;
        int fac_size = 1;   //size of factorial 

        //multiplying every number of factorial i.e  =  5! = 5*4*3*2*1 = 120  a[2] = 1 ,a[1] = 2 , a[0] = 0
        for(int i=2;i<=n;i++)
        {
            fac_size = Multiply(i,fac,fac_size);
        }

        //Print Output
        cout<<"--> Factorial is  : ";
        for(int i = fac_size-1;i>=0;i--)
        {
            cout<<fac[i];
        }
}


main()
{
    int n;
    cout<<"--> Enter the number : ";
    cin>>n;

    Factorial(n);
}