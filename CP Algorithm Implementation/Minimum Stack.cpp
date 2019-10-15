#include <bits/stdc++.h>
using namespace std;
struct stack_1
{
    stack<int>s;
    int minele;

void push(int n)
{
    if(s.empty()){s.push(n);minele=n;cout<<"minele="<<minele<<endl;}
    else if(n<minele){ s.push(2*n-minele); minele=n;}
    else s.push(n);
    cout<<"Minimum element:"<<minele<<endl;
}
void pop()
{
    if(s.empty()){cout<<"Stack is empty";}
    int t=s.top();
    s.pop();
    if(t<minele){minele=2*minele-t;}
    cout<<"Minimum element:"<<minele<<endl;
}
};
int main()
{
    stack_1 s;
    int x;
    int minele;
    char ch;
    cout<<"Enter Command:"<<endl;
    cout<<"a.pop()"<<endl<<"b.push()"<<endl<<"c.exit()"<<endl;
    while(1)
    {
    cin>>ch;
    switch(ch)
    {
        case 'a':{s.pop();break;}
        case 'b':{cin>>x;s.push(x);break;}
        case 'c':{cout<<"Minimum element in the stack is:"<<s.minele<<endl;break;}
    }
    if(ch=='c')break;
    }

    return 0;
}
