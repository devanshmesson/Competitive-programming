#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
     int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        char s[n];
        cin>>s;
  char vowel[]={'a','e','i','o','u'};
long count=0;
	    for(int i=0; i<n; i++)
	    {
	        if((!binary_search(vowel , vowel+5, s[i])) && (binary_search(vowel, vowel+5, s[i+1])))
	        {
	            count++;
	            i++;
	        }
	    }

	    cout<<count<<" "<<endl;
    }

    return 0;
}
