#include<bits/stdc++.h>
using namespace std;
int main()
{
    string name;
    ofstream hout("hello2.txt");
    cout<<"enter ur name:";
    cin>>name;
    hout<<"my name is "<<name;
    hout.close();

    return 0;
}