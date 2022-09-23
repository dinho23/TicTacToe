#include <iostream>
#include <vector>

using namespace std;

void display_board(const vector<vector<int>> &board);
void modify_board(vector <vector<int>> &board, const int &position, const int &player);
int verify_game_status( const vector <vector<int>> &board);

int verify_game_status( const vector <vector<int>> &board) {
    int t=0;
    
    if ((board.at(0).at(0) == board.at(1).at(1)) && (board.at(0).at(0) == board.at(2).at(2))) {
        t = board.at(0).at(0);
        return t;
    }
    
    if ((board.at(0).at(2) == board.at(1).at(1)) && (board.at(0).at(2) ==board.at(2).at(0))) {
        t = board.at(1).at(1);
        return t;
    }
    
    for ( int i=0; i<3; i++){
        if ((board.at(i).at(0) == board.at(i).at(1)) && (board.at(i).at(0) == board.at(i).at(2))) {
            t = board.at(i).at(0);
            return t;
        }
        if ((board.at(0).at(i) == board.at(1).at(i)) && (board.at(0).at(i) == board.at(2).at(i))) {
            t = board.at(0).at(i);
            return t;
        }
    }
    
    return t;
}

void modify_board(vector <vector<int>> &board, const int &position, const int &player) {
    int i{}, j{};
    i = (position - 1) / 3;
    j = (position - 1) % 3;
    board.at(i).at(j) = player;
}

void game(vector <vector<int>> &board) {
    int position{}, status{};
    int move_number{}, i{}, j{};
    while (move_number != 9) {
        if (move_number % 2 == 0){
            cout << "Player 1 chose a place on the board where to place X:\n";
            display_board(board);
            cin >> position;
            if (position < 1 || position > 9)
                cout << "\nPosition invalid. \nPlease chose a valid position.\n";
            else {
                i = (position - 1) / 3;
                j = (position - 1) % 3;
                if ( board.at(i).at(j) == 10 || board.at(i).at(j) == 11)
                    cout << "That position has already been occupied, please chose another one.\n";
                else {
                        modify_board(board, position, 10);
                        move_number++;
                }
            }
        }
        else {
            cout << "Player 2 chose a place on the board where to place O:\n";
            display_board(board);
            cin >> position;
            if (position < 1 || position > 9)
                cout << "\nPosition invalid. \nPlease chose a valid position.\n";
            else {
                i = (position - 1) / 3;
                j = (position - 1) % 3;
                if ( board.at(i).at(j) == 10 || board.at(i).at(j) == 11)
                    cout << "That position has already been occupied, please chose another one.\n";
                else {
                        modify_board(board, position, 11);
                        move_number++;
                }
            }
        }
        if (move_number >= 5)
            status = verify_game_status(board);
        if (status == 10) {
            cout << "\n";
            display_board(board);
            cout << "\nPlayer 1 wins!\n";
            break;
        }
        else if (status == 11) {
            cout << "\n";
            display_board(board);
            cout << "\nPlayer 2 wins!\n";
            break;
        }
    }
    if (status == 0){
        display_board(board);
        cout <<"\It's a draw!\n";
    }
}

void init_board(vector <vector<int>> &board){
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board.at(i).at(j) = i * 3 + j + 1;
}

void display_board(const vector <vector<int>> &board) {
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            if (board.at(i).at(j) == 10)
                cout << "X ";
            else if (board.at(i).at(j) == 11)
                cout << "O ";
            else 
                cout << board.at(i).at(j) << " ";
        }
        cout << '\n';
    }
}

int main()
{
    vector <vector<int>> board(3, vector<int>(3));
    
    init_board(board);
    game(board);
    
    return 0;
}