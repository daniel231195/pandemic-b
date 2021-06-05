#pragma once

#include "Player.hpp"

namespace pandemic{
    class FieldDoctor : public Player
    {

        public:
            FieldDoctor(Board& board_of_player, City city) : Player(board_of_player, city){};
            Player& treat(City dest) override;
            string role() override;
    };
};
