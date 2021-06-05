#pragma once

#include "Player.hpp"

namespace pandemic{
    class OperationsExpert : public Player
    {

        public:
            OperationsExpert(Board& board_of_player, City city) : Player(board_of_player, city){};
            Player& build()override;
            string role()override;
    };



};
