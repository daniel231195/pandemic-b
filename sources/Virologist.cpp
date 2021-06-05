
#include "Virologist.hpp"
using namespace std;
using namespace pandemic;

Player& Virologist::treat(City dest){
    if (((board_of_player.city_by_disease_level[dest] > 0) 
    && (my_cards.count(dest)>0))
    || (dest == current_city))
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
string Virologist::role(){
    return "Virologist";
}