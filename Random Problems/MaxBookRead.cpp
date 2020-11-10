/*
Problem - Given 'n' number of inputs each containing Book name , total no. of pages , no. of pages which are read by the person. 
Print the book name which is being read the maximum among all other books.
Compare by calculating percentage signifying how much percent a book has been completed.


Input-
2
The Adventures of Huckleberry Finn 366pages 46pages
The Great Gatsby 192pages 120pages

Percentage of how much "The Great Gatsby" has been completed - 120/192
Percentage of how much "The Adventures of Huckleberry Finn" has been completed - 46/366

*/

#include<bits/stdc++.h>
using namespace std;

main()
{
  int ok=1;
  string t;
  getline(cin, t); //taking number of inputs as getline becuase using cin before using getline gives some undefined behaviour.

  int n=int(t[0])-48; //int(char) converts it into ASCII value
  int answer=INT_MIN,num,den;
  string ans;
  while(n--)
  {
  string s;
  getline(cin,s);  //using getline to take white spaces of the string.
  map<string,int>mp;
  string book;
  int  flag=0,index;
  for(int i=0;i<s.size();i++)  //This loop is segregating book name from the string
  {
     if(int(s[i])>=48 && int(s[i])<=57)
     {
       flag=1;
       index=i;
       break;
     }
     else  
     {
       book+=s[i];
     }
  }

  vector<int>full;
  int stop1,stop2;
  for(int i=index;i<s.size();i++)  //this loop is segregating "total number of pages of book" from the input string and storing into vector
  {
     if(int(s[i])>=48 && int(s[i])<=57)
     {
       full.push_back(int(s[i])-48);
     }
     if(s[i]=='p')
     {
       stop1=i;
       break;
     }
  }
  
  stop1+=5;
  vector<int>read;
  
  for(int i=stop1;i<s.size();i++) //this loop is segregating "number of pages of book completed" from the input string and storing into vector
  { 
    if(int(s[i])>=48 && int(s[i])<=57)
     {
       read.push_back(int(s[i])-48);
     }
     if(s[i]=='p')
     {
       stop2=i;
       break;
     }
  }
   
  

  int fullpages=0,readpages=0;
  int mult=1;
  for(int i=full.size()-1;i>=0;i--) //converting into number form from vector
  {
    fullpages+=mult*full[i];
    mult*=10;
  }


  mult=1;
  for(int i=read.size()-1;i>=0;i--) //converting into number form from vector
  {
    readpages+=mult*read[i];
    mult*=10;
  }


  if(ok==1)
  {
   num=readpages;
   den=fullpages;
   ok=0;
  }

  if( num*fullpages <= den*readpages ) //comparing the percentage by cross multiplication rather than dividing the numbers.i did this to prevent any errors due to floating point number
  {
      num=readpages;
      den=fullpages;
      ans=book;
  }
}
double per=(double)num/(double)den;
cout<<"Max. percentage="<<per<<endl;
cout<<"ans="<<ans<<endl;
  return 0;
}
