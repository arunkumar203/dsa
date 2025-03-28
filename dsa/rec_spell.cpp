#include<bits/stdc++.h>
using namespace std;
string a[]={"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
void print(int n){
  if(n==0){
    return ;
  }
  int lastdigit=n%10;
  print(n/10);
  cout<<a[lastdigit]<<" ";

} 
int main(){
    int n;
    cin>>n;
    
    print(n);
    return 0;
}