#pragma once

#include "Player.hpp"

namespace pandemic{
    class Scientist : public Player
    {
        private:
            int num_cards;

        public:
            Scientist(Board& board_of_player, City city, int n=4) : Player(board_of_player, city), num_cards(n){};
            Player& discover_cure(Color color)override;
            string role()override;
    };
};
