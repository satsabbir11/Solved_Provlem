#include <bits/stdc++.h>
using namespace std;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

int row, col;
char turn = 'X';
bool draw = false;

string n1 = "";
string n2 = "";
string choice;

void display_board()
{

    cout << "     |     |     " << endl;
    cout << "  " << board[0][0] << "  | " << board[0][1] << "   |  " << board[0][2] << " " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[1][0] << "  | " << board[1][1] << "   |  " << board[1][2] << " " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[2][0] << "  | " << board[2][1] << "   |  " << board[2][2] << " " << endl;
    cout << "     |     |     " << endl;
}

void player_turn()
{
    if (turn == 'X')
    {
        cout << n1 << " goes for : ";
    }
    else if (turn == 'O')
    {
        cout << n2 << " goes for : ";
    }

    cin >> choice;

    cout << endl;

    if (choice == 1)
    {
        row = 0;
        col = 0;
    }
    else if (choice == 2)
    {
        row = 0;
        col = 1;
    }
    else if (choice == 3)
    {
        row = 0;
        col = 2;
    }
    else if (choice == 4)
    {
        row = 1;
        col = 0;
    }
    else if (choice == 5)
    {
        row = 1;
        col = 1;
    }
    else if (choice == 6)
    {
        row = 1;
        col = 2;
    }
    else if (choice == 7)
    {
        row = 2;
        col = 0;
    }
    else if (choice == 8)
    {
        row = 2;
        col = 1;
    }
    else if (choice == 9)
    {
        row = 2;
        col = 2;
    }
    else
    {
        cout << "Invalid Move" << endl;
        return;
    }

    if (turn == 'X' && board[row][col] != 'X' && board[row][col] != 'O')
    {

        board[row][col] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][col] != 'X' && board[row][col] != 'O')
    {

        board[row][col] = 'O';
        turn = 'X';
    }
    else
    {
        cout << "Box already filled!n Please choose another!!";
    }

    cout << endl;
}

bool gameover()
{

    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return false;
        }
    }

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return false;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return true;
            }
        }
    }
    draw = true;
    return false;
}

int main()
{
    display_board();
    cout << endl;

    cout << "player 1 is : ";
    cin >> n1;

    cout << "player 2 is : ";
    cin >> n2;

    cout << endl;

    while (gameover())
    {
        player_turn();
        display_board();
    }
    if (turn == 'O' && draw == false)
    {
        cout << "Congratulations! " << n1 << ", you won the game";
    }
    else if (turn == 'X' && draw == false)
    {
        cout << "Congratulations! " << n2 << ", you won the game";
    }
    else
    {
        cout << "GAME DRAW :(";
    }
}
