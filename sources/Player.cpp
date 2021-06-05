
#include <iostream>
#include <array>
#include "Player.hpp"
using namespace std;
using namespace pandemic;


Player& Player:: drive(City dest){ 
        if(dest != current_city){
                for(auto &i: Board::cities[current_city]){
                        if(i == dest){
                                current_city=dest;
                                cout<<"player drive to : "<<Board::enum_to_string(dest)<<endl;
                                return *this;
                        }
                }
        }
        throw std::out_of_range("Invalid move");
}

Player& Player::fly_direct(City dest){
        if(dest != current_city && cards.count(dest)>0){
                    current_city=dest;
                    cards.erase(dest);
                    cout<<"player fly_direct to : "<<Board::enum_to_string(dest)<<endl;
                    return *this;
        }
        throw std::out_of_range("Invalid move");
}

Player& Player::fly_charter(City dest){
        if(dest != current_city && cards.count(current_city)>0){
                    cards.erase(current_city);
                    current_city=dest;
                    cout<<"player fly_charter to : "<<Board::enum_to_string(dest)<<endl;
                    return *this;
        }
        throw std::out_of_range("Invalid move");
}

Player& Player::fly_shuttle(City dest){
        if(dest != current_city && 
                board_of_player.station.count(current_city)>0 
                && board_of_player.station.count(dest)>0){
                
                current_city=dest;
                cout<<"player fly_shuttle to : "<<Board::enum_to_string(dest)<<endl;
                return *this;
        }
        throw std::out_of_range("Invalid move");
}

Player& Player::build(){
       if(cards.count(current_city)>0){ 
        if(board_of_player.station.count(current_city)==0){
                board_of_player.station.insert(current_city);
                cards.erase(current_city);
                }
                cout<<"player build"<<endl;
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
                for(const auto &i : cards){
                        if(Board::cities_by_color[i]==color){
                                counter++;
                        }
                }
                if(counter>4){
                       auto itr = cards.begin();
                        while(counter > 0){
                            if (Board::cities_by_color[*itr] == color)
                            {
                                cards.erase(*itr++);
                                counter--;
                            }
                            else{
                                itr++;
                            }       
                    }
                    board_of_player.cure.insert(color);
                    cout<<"player discover_cure"<<endl;
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
       cout<<"player treat : "<<Board::enum_to_string(dest)<<endl;
       return *this;
    }
    throw std::out_of_range("Invalid move");
}

string Player::role(){
    return "Player";
}

Player& Player::take_card(City city){
    if (cards.count(city) == 0)
    {
        cards.insert(city);
    }
    cout<<"player take_card of : "<<Board::enum_to_string(city)<<endl;
    return *this;
}

void Player::remove_cards(){
        cout<<"player remove_cards"<<endl;
        cards.clear();
}

