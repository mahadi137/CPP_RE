#include <iostream>
#include <array>

using namespace std;

// Variables
char space [3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char token = 'X';
string player_1, player_2;
bool GameTie;

    

// Tic Tac Toe Board

void ticTacToe ()
{

    cout << "            |            |           " << endl;
    cout << "            |            |           " << endl;
    cout << "      "<< space [0][0] << "     |      " << space [0][1] << "     |      " << space [0][2] << endl;
    cout << "            |            |           " << endl;
    cout << " ___ ___ __ | ___ ___ __ | ___ ___ __" << endl;
    cout << "            |            |           " << endl;
    cout << "            |            |           " << endl;
    cout << "      "<< space [1][0] << "     |      " << space [1][1] << "     |      " << space [1][2] << endl;
    cout << "            |            |           " << endl;
    cout << " ___ ___ __ | ___ ___ __ | ___ ___ __" << endl;
    cout << "            |            |           " << endl;
    cout << "            |            |           " << endl;
    cout << "      "<< space [2][0] << "     |      " << space [2][1] << "     |      " << space [2][2] << endl;
    cout << "            |            |           " << endl;
    cout << "            |            |           " << endl;

    cout << endl
    << endl;


}


// game start with position selection

void playersChoice ()
{

    int choice, row, col;


        // Token selected here by programmer
        // Player 1 position
        if (token == 'X')
        {
            cout << player_1 << " enter you position choice: ";
            cin >> choice;
        }

        // Player 2 position
        if (token == 'O')
        {
            cout << player_2 << " enter you position choice: ";
            cin >> choice;
        }
        
        
        // position selection
        switch (choice)
        {
        case 1:
            row = 0;
            col = 0;
            break;

        case 2:
            row = 0;
            col = 1;
            break;

        case 3:
            row = 0;
            col = 2;
            break;

        case 4:
            row = 1;
            col = 0;
            break;

        case 5:
            row = 1;
            col = 1;
            break;

        case 6:
            row = 1;
            col = 2;
            break;

        case 7:
            row = 2;
            col = 0;
            break;

        case 8:
            row = 2;
            col = 1;
            break;

        case 9:
            row = 2;
            col = 2;
            break;
        
        default:
            cout << "Alarm: Invalid selection! Please select from 1 to 9, which has free space." << endl;
            break;
        }


        // Validation: who is playing and is the position empty
        // For player_1
        if (token == 'X' && space [row][col] != 'X' && space [row][col] != 'O')
        {
            space [row][col] = 'X';
            token = 'O';
        }

        // For player_2
        else if (token == 'O' && space [row][col] != 'X' && space [row][col] != 'O')
        {
            space [row][col] = 'O';
            token = 'X';
        }

        else 
        {
            cout << "Alarm: Choice from empty position." << endl;
        }

}


// Decide the winner

bool winnerDecide ()
{

    // Row or col by matching check
    for (int i = 0; i < 3; i++)
    {
        if (space [i][0] == space [i][1] && space [i][1] == space [i][2] || space [0][i] == space [1][i] && space [1][i] == space [2][i])
        {
            GameTie = false;
            return true;
        }   
    }


    // Diagonal matching check
    if (space [0][0] == space [1][1] && space [1][1] == space [2][2] || space [0][2] == space [1][1] && space [1][1] == space [2][0])
    {
        GameTie = false;
        return true;
    }

    // if diagonal not match then check empty space
else
{
    // check for empty space
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Has empty space
            if (space[i][j] != 'X' && space[i][j] != 'O')
            {
                return false;
            }
        }     
    }
    
    // No empty space found
    cout << "Alert: There is no empty space!" << endl;
    GameTie = true;
    return true;
}
    
   

    return false;
}



// Main function here

int main ()
{

    cout << "Enter the name of first player: ";
    getline (cin, player_1);
    cout << "Enter the name of second player: ";
    getline (cin, player_2);
    cout << endl << endl;
    cout << player_1 << " will play first. " << endl << endl;
    

    // continue until winner is not decided
    while (!winnerDecide ())
    { 
        // call game board function
        ticTacToe ();
        playersChoice ();
        winnerDecide ();
       
    }
    
    ticTacToe ();
    // when winner found: check who won!!
    if (token == 'O' && GameTie == false)
    {
        
        cout << player_1 << " won!!";
    }

    else if (token == 'X' && GameTie == false)
    {
        cout << player_2 << " won!!";
    }

    else
    {
        cout << "___ It's a Tie ___";
    }
    
    return 0;
}