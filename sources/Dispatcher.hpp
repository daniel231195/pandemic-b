#pragma once

#include "Player.hpp"

namespace pandemic{
    class Dispatcher : public Player
    {

        public:
            Dispatcher(Board& board_of_player, City city) : Player(board_of_player, city){};
            Player& fly_direct(City dest) override;
            string role() override; 
    };
};
