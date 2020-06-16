#include <iostream>
using namespace std;
int main()
{
    int r,s,p,book;
    cin>>r>>s;
    cin>>book;
    p=r*s;

    if(book>p) cout<<p<<" "<<book-p;

    else if(book==p) cout<<p<<" "<<0;
    else cout<<book<<" "<<0;
}
