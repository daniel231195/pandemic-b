
#include "Medic.hpp"
using namespace std;
using namespace pandemic;

Player& Medic::drive(City dest){
    Player::drive(dest);
    if (board_of_player.cure.count(Board::cities_by_color[dest]) > 0)
    {
        board_of_player[dest] = 0;
    }
    cout<<"Medic drive to : "<<Board::enum_to_string(dest)<<endl;
    return *this;
}

Player& Medic::fly_direct(City dest){
    Player::fly_direct(dest);
    if (board_of_player.cure.count(Board::cities_by_color[dest]) > 0)
    {
        board_of_player[dest] = 0;
    }
    cout<<"Medic fly_direct to :"<<Board::enum_to_string(dest)<<endl;
    return *this;
}

Player& Medic::fly_charter(City dest){
    Player::fly_charter(dest);
    if (board_of_player.cure.count(Board::cities_by_color[dest]) > 0)
    {
        board_of_player[dest] = 0;
    }
    cout<<"Medic fly_charter to : "<<Board::enum_to_string(dest)<<endl;
    return *this;
}

Player& Medic::fly_shuttle(City dest){
    Player::fly_shuttle(dest);
    if (board_of_player.cure.count(Board::cities_by_color[dest]) > 0)
    {
        board_of_player[dest] = 0;
    }
    cout<<"Medic fly_shuttle to : "<<Board::enum_to_string(dest)<<endl;
    return *this;
}

 Player& Medic::treat(City dest){
    if (board_of_player.city_by_disease_level[dest] > 0 && dest == current_city)
    {
        board_of_player.city_by_disease_level[dest] = 0;
       return *this;
    }
    cout<<"Medic treat : "<<Board::enum_to_string(dest)<<endl;
    throw std::out_of_range("Invalid move");
}

string Medic::role(){
    return "Medic";
}