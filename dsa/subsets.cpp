#include<bits/stdc++.h>
using namespace std;
void subset(char *input,char *output,int i,int j){
    if(input[i]=='\0' and j==2){
        output[j]='\0';
        cout<<output<<endl;
        return;
    }
    output[j]=input[i];
    subset(input,output,i+1,j+1);
    subset(input,output,i+1,j);
}
int main(){
    char input[100];
    char output[100];
    cin>>input;
    subset(input,output,0,0);
    return 0;
}