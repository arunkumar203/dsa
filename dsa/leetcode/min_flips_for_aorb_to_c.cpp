//1318
#include<bits/stdc++.h>
using namespace std;
int minFlips(int a, int b, int c) {
        int ans=0;
        while(a>0||b>0||c>0){
            int temp=c&1;
            int temp1=a&1;
            int temp2=b&1;
            if((temp1|temp2)!=temp){
                if((temp1==temp2)&&(temp1==1)) ans=ans+2;
                else ans=ans+1;
            }
            a=a>>1;
            b=b>>1;
            c=c>>1;


        }
        return ans;
    }
int main(){
    int a=2,b=6,c=5;
    cout<<minFlips(a,b,c)<<endl;
    return 0;
}
// acutual num req
// 0      00   0   not req
// 1      01   0   1
// 1      10   0   1
// 1      11   0   2(as both need to converted to 0)

// ac  num  req
// 0   00   1   1(as we can convert either of 0 to 1 )
// 1   01   1   not req
// 1   10   1   not req
// 1   11   1   not req

