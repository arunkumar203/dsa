#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s="aaabbkkjjbhhbcddde";
    int len=s.length();
    int n=1,i=1;
    char c=s[0];
    while(s[i]){
        if(c==s[i]){
            n++;
            i++;
            if(i==len-1){
                cout<<c<<n;
            }
        }
        else{
            cout<<c<<n;
            c=s[i];
            if(i==len-1){
                cout<<c<<1;
            }
            i++;
            n=1;
        }
    }

    return 0;
}
