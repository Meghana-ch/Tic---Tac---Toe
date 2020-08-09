#include <iostream>
#include <string>
using namespace std;

void drawboard(char board[])
{
    cout << "" << board[0] << " " << "|" << " " << board[1] << " " << "|" << " " << board[2] << " " << endl;
    cout << "___|___|___" << endl;
    cout << " " << board[3] << " " << "|" << " " << board[4] << " " << "|" << " " << board[5] << " " << endl;
    cout << "___|___|___" << endl;
    cout << " " << board[6] << " " << "|" << " " << board[7] << " " << "|" << " " << board[8] << " " << endl;
    cout << "   |   |   " << endl;
}

bool validity(int player_option, char board[])
{
    if(board[player_option] == '.')
    {
        return true;
    }
    return false;
}

void check_win(string &status, char board[])
{
// horizontal
    if(board[0] == board[1] and board[1] == board[2] and board[0] != '.')
    {
        status = "win";
    }
    else if(board[3] == board[4] and board[4] == board[5] and board[3] != '.')
    {
        status = "win";
    }
    else if(board[6] == board[7] and board[7] == board[8] and board[6] != '.')
    {
        status = "win";
    }
// vertical
    else if(board[0] == board[3] and board[3] == board[6] and board[0] != '.')
    {
        status = "win";
    }
    else if(board[1] == board[4] and board[4] == board[7] and board[1] != '.')
    {
        status = "win";
    }
    else if(board[2] == board[5] and board[5] == board[8] and board[2] != '.')
    {
        status = "win";
    }
// diagonal
    else if(board[0] == board[4] and board[4] == board[8] and board[4] != '.')
    {
        status = "win";
    }
    else if(board[2] == board[4] and board[4] == board[6] and board[4] != '.')
    {
        status = "win";
    }
    else
    {
        status = "running";
    }
}
int main()
{
    char board[9] = {'.', '.', '.', '.', '.', '.', '.', '.', '.'};
    int player = 1;
    int chance = 1;
    char mark, mark1, mark2;
    int player_option;
    string status = "running";
    cout << "Welcome to Tic-Tac- Toe!" << endl;
    cout << "Lets get started" << endl;
    drawboard(board);
    cout << "PLayer 1 please enter your mark: ";
    cin >> mark1;
    while(mark1 != 'X' && mark1 != 'O')
    {
        cout << "Invalid" << endl;
        cout << "PLayer 1 please enter your mark: ";
        cin >> mark1;
    }
    switch(mark1)
    {
        case 'X':
            cout << "Player 1 - 'X' and Player 2 - 'O'" << endl;
            mark2 = 'O';
            break;
        case 'O':
            cout << "Player 1 - 'O' and Player 2 - 'X'" << endl;
            mark2 = 'X';
            break;
        default:
            cout << "Invalid!" << endl;
    }
    while(chance <= 9)
    {
        if (player % 2 != 0) {
            player = 1;
            mark = mark1;
        } else {
            player = 2;
            mark = mark2;
        }
        cout << chance << "." << " " << "Player" << " " << player << " " << "choose the position to place your mark: ";
        cin >> player_option;
        if(!validity(player_option, board))
        {
            while(!validity(player_option, board))
            {
                cout << "Invalid!" << endl;
                cout << chance << "." << " " << "Player" << " " << player << " " << "choose the position to place your mark: ";
                cin >> player_option;
            }
        }
        if (0 <= player_option <= 8)
        {
            if(validity(player_option, board))
            {
                board[player_option] = mark;
                check_win(status, board);
                drawboard(board);
                chance++;
                player++;
                if(status == "win")
                {
                    player--;
                    if(player % 2 == 0)
                    {
                        cout << "Player 2 have won!"<<endl;
                        break;
                    }
                    cout << "PLayer 1 has won!" << endl;
                    break;
                }
            }
        }
    }
    if(chance > 8)
    {
        cout << "Its' a draw!";
    }
    return 0;
}
