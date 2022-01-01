//
// Created by JOSEPH BAQAEEN on 2021-12-29.
//

#include "player.h"
#include <iostream>
#include <array>
#include <vector>

#ifndef TICTACTOE_CPP_TICTACTOE_H
#define TICTACTOE_CPP_TICTACTOE_H

class Player;

class Tictactoe
{
private:
    std::vector<int> positions { 1,2,3,4,5,6,7,8,9 };
    static std::size_t number_of_play;
    //char play_game = 'Y';
    //bool game_won = false;
    std::size_t board_index_1 {0};
    std::size_t board_index_2 {0};
    //std::array<std::array<unsigned char, 3>, 3> tic_tac_toe {{{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}};
    std::array<std::array<unsigned char, 3>, 3> tic_tac_toe {{{}, {}, {}}};
    inline void player_one_update_board();
    inline void player_two_update_board();

public:
    Tictactoe() = default;
    //Tictactoe(std::string& name_one, std::string& name_two) : Player1(name_one), Player2(name_two) {}
    ~Tictactoe() = default;
    Player Player1;
    Player Player2;
    void board_display();
    void initialize_game();
    void insert_position();
    bool is_game_won();
};


#endif //TICTACTOE_CPP_TICTACTOE_H
