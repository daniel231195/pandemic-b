#pragma once

#include <iostream>
#include <map>
using namespace std;

#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include <set>
#include <stdexcept>
#define MIN_CARDS 5

namespace pandemic{
    class Player{
        protected:
            Board& board_of_player;
            City current_city;
            set <City> cards;
            

        public:
            Player(Board& board, City city): board_of_player(board), current_city(city){}
            virtual Player& drive(City dest);
            virtual Player& fly_direct(City dest);
            virtual Player& fly_charter(City dest);
            virtual Player& fly_shuttle(City dest);
            virtual Player& build();
            virtual Player& discover_cure(Color color);
            virtual Player& treat(City dest);
            virtual string role();
            void remove_cards();
            virtual Player& take_card(City city);

    };
};