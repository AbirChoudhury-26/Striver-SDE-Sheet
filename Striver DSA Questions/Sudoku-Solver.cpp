#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>>&board,int row,int col,char c)
{
    for(int i=0;i<9;i++)
    {
        if(board[i][col]==c)           // Row Checking for the value if the number exist
         return false;

         if(board[row][i]==c)         // Column checking if the nuber exist
          return false;

          if(board[3*(row/3)+i/3][3*(col/3)+(i%3)]==c)   //  Check in its own matrix of 3*3 if the number is present in the matrix or not
           return false;
    }
    return true;
}
 
bool solveSoduku(vector<vector<char>>&board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (isValid(board, i, j, c))
                    {
                        board[i][j] = c;
                        if (solveSoduku(board))
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

    int main()
    {
        vector<vector<char>> board{
            {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
            {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
            {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
            {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
            {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
            {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
            {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
            {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
            {'7', '.', '6', '1', '8', '5', '4', '.', '9'}};

        solveSoduku(board);

         for(int i=0;i<9;i++)
         {
             for(int j=0;j<9;j++)
              cout<<board[i][j]<<" ";
            cout<<endl;
         }
    }