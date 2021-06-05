
#include "OperationsExpert.hpp"
using namespace std;
using namespace pandemic;

Player& OperationsExpert::build(){
    if(board_of_player.station.count(current_city)==0){
        board_of_player.station.insert(current_city);
    }
    return *this;
}

string OperationsExpert::role(){
    return "OperationsExpert";
}