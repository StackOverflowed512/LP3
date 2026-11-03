#include<bits/stdc++.h>
using namespace std;

int n, cnt = 0;

bool isSafe(vector<vector<int>>& board, int row, int col){
    for(int i = 0;i<row; i++){
        if(board[i][col] == 1){
            return false;
        }
    }

    for(int i = row-1, j = col-1; i>=0&& j>=0; i--, j--){
        if(board[i][j] == 1){
            return false;
        }
    }

    for(int i = row-1, j = col+1; i>=0&& j<n; i--, j++){
        if(board[i][j] == 1){
            return false;
        }
    }
    
    return true;
}

void solve(vector<vector<int>>& board, int row){
    if(row == n){
        cnt++;
        cout<<"Solution  no. "<<cnt<<endl;
        for(int i = 0;i<n; i++){
            for(int j = 0;j<n; j++){
                cout<<board[i][j] <<" ";
            }
            cout<<endl;
        }
        return;
    }
    for(int col = 0;col<n; col++){
        if(isSafe(board, row, col)){
            board[row][col] = 1;
            solve(board, row+1);
            board[row][col] = 0;
        }
    }
}

int main(){
   
    cin>>n;
    vector<vector<int>> board(n, vector<int>(n,0));
    board[0][0] = 1;
    solve(board,1);
}
