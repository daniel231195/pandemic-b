#include "Scientist.hpp"
using namespace std;
using namespace pandemic;

Player& Scientist::discover_cure(Color color){
    if (board_of_player.station.count(current_city) > 0)
    {
        if (board_of_player.cure.count(color) > 0) 
        {
            return *this;
        }

        int count=0;
        for (const auto& i : my_cards){        
            if (Board::cities_by_color[i] == color)
            {
                count++;
            }
        }
        if (count >= num_cards){
            auto itr = my_cards.begin();
            while(count > 0){
                if (Board::cities_by_color[*itr] == color)
                {
                    my_cards.erase(*itr++);
                    count--;
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

string Scientist::role(){
    return "Scientist";
}