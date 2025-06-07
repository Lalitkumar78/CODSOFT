#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

void resetBoard() 
{
    char start = '1';
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            board[i][j] = start++;
}

void printBoard() 
{
    cout<<"\n";
    for(int i = 0; i < 3; i++) 
    {
        cout<< " ";
        for(int j = 0; j < 3; j++) {
            cout<<board[i][j];
            if(j < 2) cout<<" | ";
        }
        cout<<"\n";
        if(i < 2) cout<<"---+---+---\n";
    }
    cout<<"\n";
}

bool placeMark(int slot) 
{
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    if(slot < 1 || slot > 9 || board[row][col] == 'X' || board[row][col] == 'O')
        return false;
    board[row][col] = currentPlayer;
    return true;
}

bool checkWin() 
{
    for(int i = 0; i < 3; i++)
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
    for(int i = 0; i < 3; i++)
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    if(board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if(board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;
    return false;
}

bool checkDraw()
{
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void switchPlayer()
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main(){
    char again;
    do
    {
        resetBoard();
        currentPlayer = 'X';
        bool gameOver = false;
        while(!gameOver) 
        {
            printBoard();
            int move;
            cout<<"Player "<<currentPlayer<<", enter your move (1-9): ";
            cin>>move;
            if(!placeMark(move)) 
            {
                cout<<"Invalid move. Try again.\n";
                continue;
            }
            if(checkWin()) 
            {
                printBoard();
                cout<<"Player "<<currentPlayer<<" wins!\n";
                gameOver = true;
            } else if(checkDraw()) 
            {
                printBoard();
                cout << "It's a draw!\n";
                gameOver = true;
            } else 
            {
                switchPlayer();
            }
        }
        cout<<"Play again? (y/n): ";
        cin>>again;
    } while(again == 'y' || again == 'Y');
    return 0;
}