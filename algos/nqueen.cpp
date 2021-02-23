#include<bits/stdc++.h>
using namespace std;

bool isSafe(int board[][100], int row, int col, int n) {
    //check coloum
    for(int i=row; i>=0; --i) {
        if(board[i][col]==1) return false;
    }
    //check left diagonal
    int x=row, y=col;
    while(x>=0 && y>=0) {
        if(board[x][y]==1) return false;
        --x, --y;
    }
    //check right diagonal
    x = row, y=col;
    while(x>=0 && y<n) {
        if(board[x][y]==1) return false;
        --x, ++y;
    }
    return true;
}

bool solveNQueen(int board[][100], int row, int n) {
    if(row == n) {
        return true;
    }
    for(int col=0; col<n; ++col) {
      // bool isSafe(board, row, col, n); 
        if(isSafe(board, row, col, n)) {
            board[row][col] = 1;                //set queen to the cell
            if(solveNQueen(board, row+1, n))
                return true;
            board[row][col] = 0;    //assumption is wrong, so remove queen again

        }
    }
    return false;       //returning value to the if(slolveNQueen) condition || backtracking
}

int main() {
    int n;
    cin >> n;
    int board[100][100] = {0};
    if(solveNQueen(board, 0, n)) {
        for(int row=0; row<n; ++row)
        {
            for(int col=0; col<n; ++col)
                cout << board[row][col] << " ";
            cout << "\n";
        }
    }
    else cout << "No possible solution exists \n";
    return 0;
}

