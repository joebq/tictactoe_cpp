//
// Created by JOSEPH BAQAEEN on 2021-12-29.
//

#include <iostream>
#include <array>
#include <cctype>

#ifndef TICTACTOE_CPP_PLAYER_H
#define TICTACTOE_CPP_PLAYER_H

class Player
{
private:
    std::string player_name {};
    unsigned char player_symbol {};

public:
    friend std::istream& insert_name(std::istream&, Player&);
    constexpr static std::array<char, 2> game_symbols {'X', 'O'};
    Player() = default;
    ~Player() = default;
    /** constructors reserved for future expansion **/
    //explicit Player(std::string& p_name) : player_name (p_name) {}
    //Player(std::string& p_name, char p_symbol ) : player_name (p_name), player_symbol(p_symbol) {}
    //Player(std::string&& p_name, char p_symbol ) : player_name (p_name), player_symbol(p_symbol) {}
    [[nodiscard]] inline std::string get_player_name() const { return player_name; }
    [[nodiscard]] inline unsigned char get_symbol() const { return player_symbol; }
    inline void set_player_symbol(unsigned char symbol) { player_symbol = symbol; }
};

std::istream& insert_name(std::istream&, Player&);

#endif //TICTACTOE_CPP_PLAYER_H
