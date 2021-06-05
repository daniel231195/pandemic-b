#pragma once

#include "Player.hpp"

namespace pandemic{
    class Researcher : public Player
    {
        public:
            Researcher(Board& board_of_player, City city) : Player(board_of_player, city){};
            Player& discover_cure(Color color)override;
            string role()override;
    };
};
