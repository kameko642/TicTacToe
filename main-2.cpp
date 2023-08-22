#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3',}, {'4', '5', '6'}, {'7', '8', '9'}};
char current_marker;
int current_player;
void drawBoard(){
    cout <<" "<< board[0][0]<<" | " << board[0][1]<< " | " << board[0][2] << endl;
    cout <<"-----------\n";
    cout <<" "<< board[1][0]<<" | " << board[1][1]<< " | " << board[1][2] << endl;
    cout <<"------------\n";
    cout <<" "<< board[2][0]<<" | " << board[2][1]<< " | " << board[2][2] << endl;
}

void placeMaker(int slot){
    int row = slot / 3;
    int col;
    
    if(slot% 3 == 0){
        row = row - 1;
        col = 2;
    }
    else col = (slot % 3) - 1;
    
    board[row][col] = current_marker;
}
char winner(){
    for (int i = 0; i < 3; i++){
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return current_player;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return current_player;
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[1][2]) return current_player;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) return current_player;
    
    return 0;
}

void swap_player_and_marker(){
if(current_marker == 'x') current_marker = 'o';
else current_marker = 'x';

if(current_player == 1) current_player = 2;
else current_player = 1;
}

void game(){
    cout << "Player one, choose your marker: ";
    char marker_p1;
    cin >> marker_p1;
    
    current_player = 1;
    current_marker = marker_p1;
    
    drawBoard();
    
    int player_won;
    
    for(int i = 0; i < 9; i++){
        cout << "It's player " << current_player << "'s turn. Enter your slot : ";
        int slot;
        cin >> slot;
        
        placeMaker(slot);
        drawBoard();
        
        player_won = winner();
        
        if(player_won == 1){
            cout << "Player one won! Congratulation!";
            break;
        }
        if (player_won == 2){
            cout << "Player two won! Congratulation!";
            break;
        }
        
        swap_player_and_marker();
        
    }
    if(player_won == 0){
        cout << "That is a tie game!";
    }
}
int main()
{
    game();
}



