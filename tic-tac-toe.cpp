#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE 3
#define BOT1MOVE 'X'
#define BOT2MOVE 'O'

void init(char board[][SIZE], vector<int> &moves)
{
    srand(unsigned(time(0)));
 
    // Initialize empty board
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = ' ';
    
    for (int i = 0; i < SIZE*SIZE; i++)
        moves[i] = i;

    random_shuffle(moves.begin(), moves.end());
}

void show_board(char board[][SIZE])
{
    cout << endl << endl;

    cout << "\t " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "\t---|---|---" << endl;
    cout << "\t " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "\t---|---|---" << endl;
    cout << "\t " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool game_over(char board[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        // Column Cross
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
        // Row Cross
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
    }
    // Diagonal Cross
    if (board[2][0] != ' ' && board[2][0] == board[1][1] && board[1][1] == board[0][2]) return true;
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;

    return false;
}

int main()
{
    char board[SIZE][SIZE];
    vector<int> moves(SIZE*SIZE);

    init(board, moves);
    int idx = 0, turn = 1;

    while (!game_over(board) && idx != SIZE*SIZE)
    {
        if (turn == 1)
        {
            int r = moves[idx] / SIZE;
            int c = moves[idx] % SIZE;

            board[r][c] = BOT1MOVE;
            show_board(board);
            idx++;
            turn = 2;
        }
        else
        {
            int r = moves[idx] / SIZE;
            int c = moves[idx] % SIZE;

            board[r][c] = BOT2MOVE;
            show_board(board);
            idx++;
            turn = 1;
        }
    }

    if (!game_over(board) && idx == SIZE*SIZE) cout << "DRAW :(" << endl;
    else if (turn == 2) cout << endl << "\t--BOT1 WON--" << endl << endl;
    else cout << endl << "\t--BOT2 WON--" << endl << endl;

    return 0;
}
