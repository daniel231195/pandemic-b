
#include <iostream>
#include "Board.hpp"
#include <fstream>
#include <vector>

using namespace std;
using namespace pandemic;   

    map<City,vector<City>> Board::all_cities;
    map<City,Color> Board::cities_by_color;

    Board::Board(){
        init_map();
    }
    void Board::init_map(){
       
       ifstream cities_txt{"cities_map.txt"};
       string line;
       while(getline(cities_txt, line))
       {
           
           string CityName = line.substr(0, line.find(' '));
           string right = line.substr(line.find(' ')+1, line.length());
           string color = right.substr(0, right.find(' '));
           string Neighbors = right.substr(right.find(' '), right.length());
           std::vector<City> v;
           while(Neighbors.find(' ')<Neighbors.length()){               
               string nei = Neighbors.substr(0, Neighbors.find(' '));
               v.push_back(string_to_enum(nei));
               Neighbors=Neighbors.substr(Neighbors.find(' ')+1, right.length());
           }
           v.push_back(string_to_enum(Neighbors));
           Board::all_cities[string_to_enum(CityName)]=v;
                Color p = string_to_color(color);
                Board::cities_by_color[string_to_enum(CityName)] = p;
        }
    }
    Color Board::string_to_color(const std::string& c){

        if(c ==  "Black"){
            return Color::Black;}
        if(c ==  "Yellow"){
            return Color::Yellow;}
        if(c ==  "Blue"){
            return Color::Blue;}
        if(c ==  "Red"){
            return Color::Red;}  

        return Color::Black;      

    }

    City Board::string_to_enum(const std::string& c){
            if(c== "Algiers"){
                return City::Algiers;}
            if(c=="Atlanta"){
                return City::Atlanta;}
            if(c== "Baghdad"){
                return City::Baghdad;}
            if(c== "Bangkok"){
                return City::Bangkok;}
            if(c== "Beijing"){
                return  City::Beijing;}
            if(c== "Bogota"){
                return City::Bogota;} 
            if(c== "BuenosAires"){
                return City::BuenosAires;}
            if(c== "Cairo"){
                return City::Cairo;}
            if(c== "Chennai"){ 
                return City::Chennai;}
            if(c==  "Chicago"){
                return City::Chicago;}
            if(c==  "Delhi"){
                return City::Delhi;}
            if(c==  "Essen") { 
                return City::Essen;}
            if(c== "HoChiMinhCity"){
                return City::HoChiMinhCity;}
            if(c== "HongKong" ){
                return City::HongKong;}
            if(c== "Istanbul"){
                return City::Istanbul;}
            if(c== "Jakarta") {
                return City::Jakarta;}
            if(c== "Johannesburg"){
                return City::Johannesburg;}
            if(c== "Karachi"){
                return City::Karachi;}
            if(c== "Khartoum"){
                return City::Khartoum;}
            if(c== "Kinshasa"){
                return City::Kinshasa;}
            if(c== "Kolkata"){
                return City::Kolkata ;}
            if(c==  "Lagos"){
                return City:: Lagos;}
            if(c== "Lima" ){
                return City::Lima;}
            if(c== "London"){
                return City::London;}
            if(c== "LosAngeles"){
                return City:: LosAngeles;}
            if(c== "Madrid"){
                return City::Madrid;}
            if(c== "Manila"){
                return City:: Manila;}
            if(c== "MexicoCity"){
                return City::MexicoCity;}
            if(c== "Miami"){
                return City::Miami;}
            if(c== "Milan") { 
                return City::Milan;}
            if(c== "Montreal"){
                return City::Montreal;}
            if(c== "Moscow"){
                return City::Moscow;}
            if(c== "Mumbai"){
                return City::Mumbai;}
            if(c== "NewYork"){
                return City::NewYork;}
            if(c==  "Osaka"){
                return City::Osaka;}
            if(c==  "Paris"){
                return City::Paris;}
            if(c==  "Riyadh") {   
                return City:: Riyadh;}
            if(c== "SanFrancisco"){
                return City::SanFrancisco;}
            if(c==  "Santiago"){
                return City::Santiago;}
            if(c==  "SaoPaulo"){
                return City::SaoPaulo;}
            if(c==  "Seoul"){
                return City::Seoul;}
            if(c== "Shanghai"){
                return City::Shanghai;}
            if(c== "StPetersburg"){
                return City::StPetersburg;}
            if(c==  "Sydney"){
                return City::Sydney;}
            if(c==  "Taipei"){
                return City::Taipei;}
            if(c==  "Tehran"){
                return City::Tehran;}
            if(c== "Tokyo" ){
                return City::Tokyo;}
            if(c== "Washington" ){
                return City::Washington;}

            return City::daniel;
        
    }


    bool Board::is_clean(){
        for(auto &i : city_by_disease_level){
            if(i.second != 0 ){ 
                return false;
            }
        }
        return true;
    }   
    void Board ::remove_cures(){   
            cure.clear();
    }
    void Board::remove_stations(){
        station.clear();
    }
    int& Board::operator[] (City city){
         return city_by_disease_level[city]; 
    }
    ostream& pandemic::operator<< (std::ostream& os ,const Board& b){
        return os;  
    }
    
