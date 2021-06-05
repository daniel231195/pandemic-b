
#include "GeneSplicer.hpp"
using namespace std;
using namespace pandemic;

Player& GeneSplicer::discover_cure(Color color){
   if (board_of_player.station.count(current_city) > 0)    
    {
        if (board_of_player.cure.count(color) > 0)         
        {
            return *this;
        }
        if (my_cards.size() > 4)  
        {   
            auto itr = my_cards.begin();
            for (size_t i = 0; i < MIN_CARDS; i++)
            {
                my_cards.erase(*itr);
            }
            
            board_of_player.cure.insert(color);
            return *this;   
        }
    }
    throw std::out_of_range("Invalid move");        
}

string GeneSplicer::role(){
    return "GeneSplicer";
}