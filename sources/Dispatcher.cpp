
#include "Dispatcher.hpp"
using namespace std;
using namespace pandemic;

Player& Dispatcher::fly_direct(City dest){
    if(board_of_player.station.count(current_city) > 0 && 
    dest!=current_city){
        current_city=dest;
        return *this;
    }
    Player::fly_direct(dest);
    return *this;
}

string Dispatcher::role(){
    return "Dispatcher";
}
