//Method 1: (Brute force)
/*

    // Algorithm

    1. find the number of distnict character in string.
    2. find ALL the substring of string s and find the distnict charcter of substring.
    3. compare the distnict char of string and distnict char of substring. 
            // We have to check here both conditions together
			// 1. substring's distinct characters is equal
			// to maximum distinct characters
			// 2. substing's length should be minimum


*/

#include <bits/stdc++.h>
using namespace std;

// Find maximum distinct characters in any string
int max_distinct_char(string str, int n){

	 set<char> s;

     for(int i = 0 ;i<str.length();i++)
        s.insert(str[i]);

    return s.size();
}

int smallesteSubstr_maxDistictChar(string str){

	int n = str.size();	 // size of given string

	// Find maximum distinct characters in any string
	int maxdc = max_distinct_char(str, n);
	int mi = n; // result
	
	// Brute force approach to find all substrings
	for (int i=0 ;i<n ;i++){
		for (int j=0; j<n; j++){
			string subs = str.substr(i,j);
			int subl = subs.size();
			int subdc = max_distinct_char(subs, subl);
			
			// We have to check here both conditions together
			// 1. substring's distinct characters is equal
			// to maximum distinct characters
			// 2. substing's length should be minimum
			if (maxdc== subdc){
				mi = min(mi,subl);
			}
		}
	}
	return mi;
}

/* Driver program to test above function */
int main()
{
	// Input String
	string str = "AABBBCBB";
	
	int len = smallesteSubstr_maxDistictChar(str);
	cout << " The length of the smallest substring"
			" consisting of maximum distinct "
			"characters : " << len;
	return 0;
}




/*
// Method 2: 


#include <iostream>
#include <set>
#include <map>
#include<climits>
using namespace std;

    // AlgoRithm

   1.   Count all distinct characters in given string.
   2.   Maintain a window of characters.
        Whenever the window contains all characters of given string, 
        we shrink the window from left side to remove extra characters 
        and then compare its length with smallest window fount so far.

main()
{
    string s;
    cin >> s;
    set<char> set;

    for (int i = 0; i < s.length(); i++)
        set.insert(s[i]);

    int n = set.size();
    int count = 0;
    int i = 0;
    int j = 1;
    map<char, int> m;

    m[s[i]]++;
    count++;
    int mi = INT_MAX;

    while(i<=j and j<s.length())
    {
        if (count < n)
        {
            if (m[s[j]]==0)
            {
                count++;
            }
            m[s[j]]++;
            j++;
        }
        else if(count==n)
        {
             mi = min(mi,j-i);
             if(m[s[i]]==1)
                count--;
            m[s[i]]--;
            i++;
        }

        
    }
    while(count==n)
        {
             mi = min(mi,j-i);
             if(m[s[i]]==1)
                count--;
            m[s[i]]--;
            i++;
        }
    
    cout<<mi<<endl;
}

*/