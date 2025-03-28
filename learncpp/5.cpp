//dis btwn 2 point
#include <bits/stdc++.h>
using namespace std;
class point
{
public:
    int x, y;
    point(int a,int b){
        x=a;
        y=b;
    }
};
double distance(point c,point d){
    int b=abs(c.x-d.x);
    int v=abs(c.y-d.y);
    double e=sqrt(b*b+v*v);
    return e;
};
int main(){
    point c=point(1,0);
    point d=point(70,0);
    cout<<distance(c,d)<<endl;
    return 0;
}