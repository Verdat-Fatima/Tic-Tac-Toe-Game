#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char turn;
    bool draw;

public:
    TicTacToe() {
        // Initialize the board
        char start = '1';
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = start++;
            }
        }
        turn = 'X';
        draw = false;
    }

    void display_board() {
    	
#ifdef _WIN32
    system("cls");   // Windows clear
#else
    system("clear"); // Linux/Mac clear
#endif
        cout<<"                         T i c k   T a c   T o e   G a m e"<<endl;
        cout<<"Player 1 [X]"<<endl;
	cout<<"Player 2 [O]"<<endl<<endl;

        cout << "\t\t\t     |     |     \n";
        cout << "\t\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
        cout << "\t\t\t_____|_____|_____\n";
        cout << "\t\t\t     |     |     \n";
        cout << "\t\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
        cout << "\t\t\t_____|_____|_____\n";
        cout << "\t\t\t     |     |     \n";
        cout << "\t\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
        cout << "\t\t\t     |     |     \n";
    }

    void player_turn() {
        int choice, row, column;
        while(true){
		if(turn=='X'){
		cout<<"\n\tPlayer 1 [X] turn :";
	}
	else if(turn=='O'){
		cout<<"\n\tPlayer 2 [O] turn :";
	}
	cin>>choice;
	
	// Validate input range
        if (choice < 1 || choice > 9) {
            cout << "Invalid choice! Please try again \n";
            continue; // Restart the loop
        }
	
        	switch(choice){
		case 1:
			row=0; column=0;
			break;
		case 2:
			row=0; column=1;
			break;
		case 3:
			row=0; column=2;
			break;
		case 4:
			row=1; column=0;
			break;
		case 5:
			row=1; column=1;
			break;
		case 6:
			row=1; column=2;
			break;
		case 7:
			row=2; column=0;
			break;
		case 8:
			row=2; column=1;
			break;
		case 9:
			row=2; column=2;
			break;
			
			default:
			   cout<<"Invalid choice"<<endl;						
	}
	if(turn=='X'  && board[row][column]!='X' && board[row][column]!='O'){
		board[row][column] ='X';
		turn='O';
		break; // Exit the loop for valid input
	}
	else if(turn=='O' && board[row][column]!='X' && board[row][column]!='O'){
		board[row][column] ='O';
		turn='X';
		break; // Exit the loop for valid input
	}
	else{
		cout<<"\n Box is already filled \n  Please try again!! \n\n";
		player_turn();
	   }
	
    }
	display_board();
	
    }

   bool game_over(){
	// check win    rows,column,diagonal
	for(int i=0;i<3;i++){
		// rows
		if(board[i][0]==board[i][1] && board[i][0]==board[i][2]){
			return false;
		}
		// column
		else if(board[0][i]==board[1][i] && board[0][i]==board[2][i]){
			return false;
		}
	}
		// Diagonal check
	 if(board[0][0]==board[1][1] && board[0][0]==board[2][2] || board[0][2]==board[1][1] && board[0][2]==board[2][0]){
			return false;
		}
	
	// if there is any box not filled
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(board[i][j]!='X' && board[i][j]!='O'){
				return true;
			}
		}
	}
	
	//Draw
	draw=true;
	return false;
}

    void play() {
        while(game_over()){
		display_board();
	    player_turn();
	    game_over();
	}
	
	if(turn=='X' && draw==false){
		cout<<"\n\t Player 2 [O]  Won the Game!!!   Congragulations!!"<<endl;
	}
	else if(turn=='O' && draw==false){
		cout<<"\n\t Player 1 [X]  Won the Game!!!   Congragulations!!"<<endl;
	}
	else{
		cout<<"\n\t Game draw!! \n";
	  }
	
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}
