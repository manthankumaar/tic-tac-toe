#include <iostream>
#include <cstdlib>
using namespace std;

char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
char player = 'X';

void draw_board()
{
    system("cls");
    cout << "\n\n     Tic Tac Toe\n\n";
    cout << "     Player1 (X)  -  Player2 (O)" << endl << endl;
    cout << "               |     |     " << endl;
    cout << "            " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "          _____|_____|_____" << endl;
    cout << "               |     |     " << endl;
    cout << "            " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "          _____|_____|_____" << endl;
    cout << "               |     |     " << endl;
    cout << "            " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "               |     |     " << endl << endl;
}

void player_turn()
{
    int choice;
    cout << "It's " << player << " turn. Enter a number to place your mark: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        if (board[0][0] == '1')
            board[0][0] = player;
        else
        {
            cout << "Invalid move, try again.\n";
            player_turn();
        }
        break;
    case 2:
        if (board[0][1] == '2')
            board[0][1] = player;
        else
        {
            cout << "Invalid move, try again.\n";
            player_turn();
        }
        break;
    case 3:
        if (board[0][2] == '3')
            board[0][2] = player;
        else
        {
            cout << "Invalid move, try again.\n";
            player_turn();
        }
        break;
    case 4:
        if (board[1][0] == '4')
            board[1][0] = player;
        else
        {
            cout << "Invalid move, try again.\n";
            player_turn();
        }
        break;
    case 5:
        if (board[1][1] == '5')
            board[1][1] = player;
        else
        {
            cout << "Invalid move, try again.\n";
            player_turn();
        }
        break;
    case 6:
        if (board[1][2] == '6')
            board[1][2] = player;
        else
        {
            cout << "Invalid move, try again.\n";
            player_turn();
        }
        break;
    case 7:
        if (board[2][0] == '7')
            board[2][0] = player;
        else
        {
            cout << "Invalid move, try again.\n";
            player_turn();
        }
        break;
    case 8:
        if (board[2][1] == '8')
            board[2][1] = player;
        else
        {
            cout << "Invalid move, try again.\n";
            player_turn();
        }
        break;
    case 9:
        if (board[2][2] == '9')
            board[2][2] = player;
        else
        {
            cout << "Invalid move, try again.\n";
            player_turn();
        }
        break;
    default:
        cout << "Invalid move, try again.\n";
        player_turn();
        break;
    }
}

void switch_player()
{
    if (player == 'X')
        player = 'O';
    else
        player = 'X';
}

char check_winner()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    return ' ';
}

bool check_draw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

int main()
{
    while (true)
    {
        draw_board();
        player_turn();
        switch_player();

        char winner = check_winner();
        if (winner == 'X' || winner == 'O')
        {
            draw_board();
            cout << winner << " wins!\n";
            break;
        }
        else if (check_draw())
        {
            draw_board();
            cout << "Draw!\n";
            break;
        }
    }
    cout << "Press enter to exit...";
    
    return cin.get();
}

system("pause");
