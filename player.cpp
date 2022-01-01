//
// Created by JOSEPH BAQAEEN on 2021-12-29.
//

#include "player.h"
#include <iostream>


std::istream& insert_name(std::istream& is, Player& player)
{
    /***
       insert_name is a friend function for class Player to get the user input for a player name.
   **/

    is >> player.player_name;
    return is;
}
