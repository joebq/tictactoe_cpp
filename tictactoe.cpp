//
// Created by JOSEPH BAQAEEN on 2021-12-29.
//

#include "tictactoe.h"
#include "player.h"
#include <vector>
#include <iostream>
#include <cassert>
#include <iomanip>

std::size_t Tictactoe::number_of_play = 1;

void Tictactoe::initialize_game()
{
    /***
        initialize_game setups the initial values of the players, their symbols and checks if the values
        that were entered by the user are valid. This function is only called when the game starts or restarts
    **/

    // game greetings
    std::cout << "Welcome to the tic tac toe game!\n";
    //request first player name and symbol
    std::cout << "Insert Player One name: ";
    insert_name(std::cin, Player1);
    //request second player name and symbol
    std::cout << "Insert Player Two name: ";
    insert_name(std::cin, Player2);
    if(!tic_tac_toe.empty())
    {
        for(auto& outer : tic_tac_toe){
            for(auto& inner : outer){
                inner = ' ';
            }
        }
    }
    assert(!Player::game_symbols.empty());
    unsigned char temp_symbol {};
    std::cout << "Choose between X or O: ";
    while(true)
    {
        std::cin >> temp_symbol;
        temp_symbol = toupper(temp_symbol);
        auto found = std::find(Player::game_symbols.begin(),
                                        Player::game_symbols.end(),
                                        temp_symbol);
        if (found == Player::game_symbols.end())
        {
            std::cerr <<"Wrong Symbol please chose again between X and O: ";
        }
        else if (toupper(*found) == 'O')
        {
            Player1.set_player_symbol(*found);
            Player2.set_player_symbol('X');
            break;
        }
        else if (toupper(*found) == 'X')
        {
            Player1.set_player_symbol(*found);
            Player2.set_player_symbol('O');
            break;
        }

    }
}

void Tictactoe::board_display()
{
    /***
        board_display displays the game board at the beginning of the game and after each player turn
        and shows the updated status of the board
    **/

    std::cout << '\n';
    std::cout << tic_tac_toe[0][0] << std::setw(3) << '|' << tic_tac_toe[0][1] << std::setw(3) << '|' << tic_tac_toe[0][2] ;
    std::cout << "\n-----------\n";
    std::cout << tic_tac_toe[1][0] << std::setw(3) << '|' << tic_tac_toe[1][1] << std::setw(3) << '|'  << tic_tac_toe[1][2];
    std::cout << "\n-----------\n";
    std::cout << tic_tac_toe[2][0] << std::setw(3) << '|' << tic_tac_toe[2][1] << std::setw(3) << '|' << tic_tac_toe[2][2];
    std::cout << '\n';
}

bool Tictactoe::is_game_won()
{
    /***
       is_game_won checks if any of the player has won the game after their last action, if yes, it will display the winner
       and ends the game
   **/

    if (
            ((tic_tac_toe[0][0] == 'X') && (tic_tac_toe [0][1] == 'X') && (tic_tac_toe[0][2] == 'X')) ||
            ((tic_tac_toe[1][0] == 'X') && (tic_tac_toe [1][1] == 'X') && (tic_tac_toe[1][2] == 'X')) ||
            ((tic_tac_toe[2][0] == 'X') && (tic_tac_toe [2][1] == 'X') && (tic_tac_toe[2][2] == 'X')) ||
            ((tic_tac_toe[0][0] == 'X') && (tic_tac_toe [1][0] == 'X') && (tic_tac_toe[2][0] == 'X')) ||
            ((tic_tac_toe[0][1] == 'X') && (tic_tac_toe [1][1] == 'X') && (tic_tac_toe[2][1] == 'X')) ||
            ((tic_tac_toe[0][1] == 'X') && (tic_tac_toe [1][1] == 'X') && (tic_tac_toe[2][1] == 'X')) ||
            ((tic_tac_toe[0][2] == 'X') && (tic_tac_toe [1][2] == 'X') && (tic_tac_toe[2][2] == 'X')) ||
            ((tic_tac_toe[0][0] == 'X') && (tic_tac_toe [1][1] == 'X') && (tic_tac_toe[2][2] == 'X')) ||
            ((tic_tac_toe[0][2] == 'X') && (tic_tac_toe [1][1] == 'X') && (tic_tac_toe[2][0] == 'X')) ||

            ((tic_tac_toe[0][0] == 'O') && (tic_tac_toe [0][1] == 'O') && (tic_tac_toe[0][2] == 'O')) ||
            ((tic_tac_toe[1][0] == 'O') && (tic_tac_toe [1][1] == 'O') && (tic_tac_toe[1][2] == 'O')) ||
            ((tic_tac_toe[2][0] == 'O') && (tic_tac_toe [2][1] == 'O') && (tic_tac_toe[2][2] == 'O')) ||
            ((tic_tac_toe[0][0] == 'O') && (tic_tac_toe [1][0] == 'O') && (tic_tac_toe[2][0] == 'O')) ||
            ((tic_tac_toe[0][1] == 'O') && (tic_tac_toe [1][1] == 'O') && (tic_tac_toe[2][1] == 'O')) ||
            ((tic_tac_toe[0][1] == 'O') && (tic_tac_toe [1][1] == 'O') && (tic_tac_toe[2][1] == 'O')) ||
            ((tic_tac_toe[0][2] == 'O') && (tic_tac_toe [1][2] == 'O') && (tic_tac_toe[2][2] == 'O')) ||
            ((tic_tac_toe[0][0] == 'O') && (tic_tac_toe [1][1] == 'O') && (tic_tac_toe[2][2] == 'O')) ||
            ((tic_tac_toe[0][2] == 'O') && (tic_tac_toe [1][1] == 'O') && (tic_tac_toe[2][0] == 'O'))
     )
    {
        number_of_play = 1;
        std::cout << "game won!\n";
        return true;
    }
    else
    {
        return false;
    }

}

void Tictactoe::insert_position()
{
    /***
       insert_position updates the tic tac toe board with the symbol entered by the player with X or O
       also checks against the legality of the position of the insert
   **/
   int position { 1 };
    while( true )
    {
       std::cout << "Enter a position between (1-9): ";
       std::cin >> position;
       if (std::find(positions.begin(), positions.end(), position) != positions.end())
       {
           break;
       }
   }

    switch(position)
    {
        case 1:
            board_index_1 = 0;
            board_index_2 = 0;
            //positions.erase(positions.begin());
            break;

        case 2:
            board_index_1 = 0;
            board_index_2 = 1;
            //positions.erase(positions.begin() + 1);
            break;

        case 3:
            board_index_1 = 0;
            board_index_2 = 2;
            //positions.erase(positions.begin() + 2);
            break;

        case 4:
            board_index_1 = 1;
            board_index_2 = 0;
           // positions.erase(positions.begin() + 3);
            break;

        case 5:
            board_index_1 = 1;
            board_index_2 = 1;
            //positions.erase(positions.begin() + 4);
            break;

        case 6:
            board_index_1 = 1;
            board_index_2 = 2;
            //positions.erase(positions.begin() + 5);
            break;

        case 7:
            board_index_1 = 2;
            board_index_2 = 0;
            //positions.erase(positions.begin() + 6);
            break;

        case 8:
            board_index_1 = 2;
            board_index_2 = 1;
            //positions.erase(positions.begin() + 7);
            break;

        case 9:
            board_index_1 = 2;
            board_index_2 = 2;
            //positions.erase(positions.begin() + 8);
            break;

        default:
            break;
    }

    if(number_of_play % 2 == 0){
        player_one_update_board();
        number_of_play++;
    }
    else
    {
        player_two_update_board();
        number_of_play++;
    }

}


inline void Tictactoe::player_one_update_board()
{
    /***
      update_board updates the contents of the board with the input of player one
  **/
    tic_tac_toe[board_index_1][board_index_2] = Player1.get_symbol();
}

inline void Tictactoe::player_two_update_board()
{
    /***
      update_board updates the contents of the board with the input of player two
  **/
    tic_tac_toe[board_index_1][board_index_2] = Player2.get_symbol();
}