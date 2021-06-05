
#include "Researcher.hpp"
using namespace std;
using namespace pandemic;

 Player& Researcher::discover_cure(Color color){
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
    // for(std::set<City>::iterator it=my_cards.begin();it!=my_cards.end();++*it){
    //     if (Board::cities_by_color[*it] == color)
    //     {
    //         count++;
    //     }
    // }
    if (count > 4)
    {
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
    throw std::out_of_range("Invalid move");

}

string Researcher::role(){
    return "Researcher";
}
