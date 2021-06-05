
#include "FieldDoctor.hpp"
using namespace std;
using namespace pandemic;

Player& FieldDoctor::treat(City dest){
    if (dest != current_city)
    {
        if (board_of_player.city_by_disease_level[dest] > 0)
            {
                for( auto &i : Board::cities[current_city]){
                    if(i==dest){
                        if (board_of_player.cure.count(Board::cities_by_color.at(dest)) > 0)
                        {
                             board_of_player.city_by_disease_level[dest] = 0;
                        }
                        else 
                        {
                            board_of_player.city_by_disease_level[dest]--;
                        }
                        cout<<"FieldDoctor treat : "<<Board::enum_to_string(dest)<<endl;
                        return *this;
                    }
                }
            }
    }  
    Player::treat(dest);
    return *this;
}

string FieldDoctor::role(){
    return "FieldDoctor";
}
