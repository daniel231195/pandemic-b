
#include <iostream>
#include <array>
#include "Player.hpp"
using namespace std;
using namespace pandemic;


Player& Player:: drive(City dest){ 
        if(dest != current_city){
                for(auto &i: Board::all_cities[current_city]){
                        if(i == dest){
                                current_city=dest;
                                return *this;
                        }
                }
        }
        throw std::out_of_range("Invalid move");
}

Player& Player::fly_direct(City dest){
        if(dest != current_city && my_cards.count(dest)>0){
                    current_city=dest;
                    my_cards.erase(dest);
                    return *this;
        }
        throw std::out_of_range("Invalid move");
}

Player& Player::fly_charter(City dest){
        if(dest != current_city && my_cards.count(current_city)>0){
                    my_cards.erase(current_city);
                    current_city=dest;
                    return *this;
        }
        throw std::out_of_range("Invalid move");
}

Player& Player::fly_shuttle(City dest){
        if(dest != current_city && 
                board_of_player.station.count(current_city)>0 
                && board_of_player.station.count(dest)>0){
                
                current_city=dest;
                return *this;
        }
        throw std::out_of_range("Invalid move");
}

Player& Player::build(){
       if(my_cards.count(current_city)>0){ 
        if(board_of_player.station.count(current_city)==0){
                board_of_player.station.insert(current_city);
                my_cards.erase(current_city);
                }
                return *this;
        }
        throw std::out_of_range("Invalid move");
}

Player& Player::discover_cure(Color color){
        int counter=0;
        if(board_of_player.station.count(current_city)>0 ){
                if(board_of_player.cure.count(color)>1){
                        return *this;
                }
                for(const auto &i : my_cards){
                        if(Board::cities_by_color[i]==color){
                                counter++;
                        }
                }
                if(counter>4){
                       auto itr = my_cards.begin();
                        while(counter > 0){
                            if (Board::cities_by_color[*itr] == color)
                            {
                                my_cards.erase(*itr++);
                                counter--;
                            }
                            else{
                                itr++;
                            }       
                    }
                    board_of_player.cure.insert(color);
                    return *this;

                }
        }
        throw std::out_of_range("Invalid move");
}

Player& Player::treat(City dest){
    if (board_of_player.city_by_disease_level[dest] > 0 && dest == current_city)
    {
       if (board_of_player.cure.count(Board::cities_by_color.at(dest)) > 0)
       {
           board_of_player.city_by_disease_level[dest] = 0;
       }
       else 
       {
            board_of_player.city_by_disease_level[dest]--;
       }
       return *this;
    }
    throw std::out_of_range("Invalid move");
}

string Player::role(){
    return "Player";
}

Player& Player::take_card(City city){
    if (my_cards.count(city) == 0)
    {
        my_cards.insert(city);
    }
    return *this;
}

void Player::remove_cards(){
        my_cards.clear();
}

