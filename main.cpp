#include "tictactoe.h"
#include <iostream>


int main()
{
    unsigned char play_game = 'Y';
    int player_turn = 1;

    while(toupper(play_game) == 'Y')
    {
        Tictactoe game;
        game.initialize_game();
        game.board_display();

        while(!game.is_game_won()) {
            game.insert_position();
            game.board_display();
            player_turn++;
        }

        if (player_turn % 2 == 0) {
            std::cout << game.Player1.get_player_name() << " ,WON the game!!!";
        } else {
            std::cout << game.Player2.get_player_name() << " ,WON the game!!!";
        }

        std::cout << "\nDo you want to play again? (Y/N): ";
        std::cin >> play_game;
    }


    return 0;
}
