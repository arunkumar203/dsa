#include<bits/stdc++.h>
using namespace std;

bool issafe(int row,int col,vector<string>&board,int n){
    int temprow=row;
    int tempcol=col;
    while(row>=0 && col>=0){
        if(board[row][col]=='Q') return false;
        row--;
        col--;
    }
    row=temprow;
    col=tempcol;
    while(col>=0){
        if(board[row][col]=='Q') return false;
        col--;
    }
    col=tempcol;
    while(row<n && col>=0){
        if(board[row][col]=='Q') return false;
        row++;
        col--;
    }
    return true;
}
int   solve(int col,vector<string>&board,vector<vector<string>>&ans,int n){
    static int k=0;
    if(col==n){
        // ans.push_back(board);
        
        k++;
        // cout<<k<<endl;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<board[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
    }
    for(int row=0;row<n;row++){
        if(issafe(row,col,board,n)){
            board[row][col]='Q';
            solve(col+1,board,ans,n);
            board[row][col]='.';
        }
    }
    return k;
}
    void  solveNQueens(int n) {
        vector<string> board(n);
        vector<vector<string>> ans;
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        cout<<solve(0,board,ans,n);
        
    }
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    solveNQueens(n);
    
}

//optimized

#include<bits/stdc++.h>
using namespace std;
void    solve(int col,vector<string>&board,vector<int>&leftrow,vector<int>&lowerdia,vector<int>&upperdia,int n){
    if(col==n){
        static int k=0;
        k++;
        cout<<k<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    for(int row=0;row<n;row++){
        if(leftrow[row]==0 && lowerdia[row+col]==0 && upperdia[col-row+n-1]==0){
            board[row][col]='Q';
            leftrow[row]=1;
            lowerdia[row+col]=1;
            upperdia[col-row+n-1]=1;
            solve(col+1,board,leftrow,lowerdia,upperdia,n);
            board[row][col]='.';
            leftrow[row]=0;
            lowerdia[row+col]=0;
            upperdia[col-row+n-1]=0;
            
        }
    }
}
    void  solveNQueens(int n) {
        vector<string> board(n);
        // vector<vector<string>> ans;
        vector<int> leftrow(n,0);
        vector<int> lowerdia(2*n-1,0);
        vector<int> upperdia(2*n-1,0);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,board,leftrow,lowerdia,upperdia,n);
        
    }
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    solveNQueens(n);
    
}