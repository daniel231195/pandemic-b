#pragma once

#include <iostream>
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include <vector>
#include <fstream>

using namespace std;

namespace pandemic{
    class Board{
        public:
            Board();
            static map<City,vector<City>> cities;
            static map<City,Color> cities_by_color;
            set <City> station;
            set <Color> cure;
            map<City,int> city_by_disease_level;
            bool is_clean();
            void remove_cures();
            void remove_stations();
            int& operator[] (City city);
            friend std::ostream& operator<< (std::ostream& os,const Board& b);
            static void init_map();
            static City string_to_enum(const std::string& c);
            static Color string_to_color(const std::string& c);
            static string enum_to_string(City c);
    };
};