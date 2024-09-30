//
//  main.cpp
//  b
//
//  Created by Giovanni Rossi on 2/20/24.
//

#include <iostream>
#include "Player.hpp"
#include "Card.hpp"
#include<vector>
#include <cassert>
#include <array>

using namespace std;

//EFFECTS returns player's name
class Simple : public Player{
    public:
    Simple(const string playername) 
    : name(playername){}

    const std::string & get_name() const{
        return name;
    }
    
    //REQUIRES player has less than MAX_HAND_SIZE cards
    //EFFECTS  adds Card c to Player's hand
    void add_card(const Card &c){
        hand.push_back(c);
    }
    
    
    bool make_trump(const Card &upcard, bool is_dealer,
                    int round, Suit &order_up_suit)const{
        int faceCounter = 0;
        Suit trumpSuit = upcard.get_suit();
        if(round == 1){
            for(int i = 0; i < hand.size(); i++){
                if(hand[i].is_trump(trumpSuit)){
                    if(hand[i].is_face_or_ace() || hand[i].is_left_bower(trumpSuit)){
                        faceCounter++;
                    }
                }
            }
            if(faceCounter > 1){
                order_up_suit = trumpSuit;
                return true;
            }else{
                return false;
            }
        }else if(round == 2){
            trumpSuit = Suit_next(upcard.get_suit());
            if(is_dealer){
                order_up_suit = trumpSuit;
                return true;
            }
            for(int i = 0; i < hand.size(); i++){
                if(hand[i].is_trump(trumpSuit)){
                    if(hand[i].is_face_or_ace() || hand[i].is_left_bower(trumpSuit)){
                        faceCounter++;
                    }
                }
            }
            if(faceCounter > 0){
                order_up_suit = trumpSuit;
                return true;
            }
        }
        return false;
    }
     
     //REQUIRES Player has at least one card
     //EFFECTS  Player adds one card to hand and removes one card from hand.
     void add_and_discard(const Card &upcard){
         int lowestIndex = 0;
         hand.push_back(upcard);
         Card currentLowest = hand[0];
         for(int i = 0; i < hand.size(); i++){
             if(Card_less(hand[i], currentLowest, upcard.get_suit())){
                 lowestIndex = i;
                 currentLowest = hand[i];
             }
         }
         hand.erase(hand.begin() + lowestIndex);
         return;
     }
     
     //REQUIRES Player has at least one card
     //EFFECTS  Leads one Card from Player's hand according to their strategy
     //  "Lead" means to play the first Card in a trick.  The card
     //  is removed the player's hand.
     Card lead_card(Suit trump){
     Card highest = hand[0];
     vector<int> indx; // indexes of non-trump card in hand
     int curr = 0; // index in hand of card being played
     for(int a = 0; a<hand.size(); a++){
        if(hand[a].get_suit(trump) != trump){
            indx.push_back(a);
        }
     }
     if (!indx.empty()){
        highest = hand[indx[0]];
        for (int i = 0; i<indx.size(); i++){
            if(Card_less(highest,hand[indx[i]], trump)){
                highest = hand[indx[i]];
                curr = indx[i];
            }
        }
     }else{
        for(int i =0; i<hand.size(); i++){
            if (Card_less(highest, hand[i], trump)){
                highest = hand[i];
                curr = i;
            }
        }
     }
     cout << hand.at(curr);
        hand.erase(hand.begin() + curr);
        return highest;
     }
     
    
    Card play_card(const Card &led_card, Suit trump){
         Card card1 = hand[0];
         int counter = 0;
         int index = 0;
         for(int i = 0; i < hand.size(); i++){
             if(hand[i].get_suit(trump) == led_card.get_suit(trump)){
                 counter++;
             }
         }
         
         if(counter == 0){
             for(int i = 0; i < hand.size(); i++){
                 if(Card_less(hand[i], card1, led_card, trump)){
                     card1 = hand[i];
                     index = i;
                 }
             }
         }
         else{
             for(int i = 0; i < hand.size(); i++){
                 if( (Card_less(card1, hand[i], led_card, trump)) && 
                 (led_card.get_suit(trump) == hand[i].get_suit(trump))){
                     card1 = hand[i];
                     index = i;
                 }
             }
         }
         hand.erase(hand.begin() + index);
         return card1;

     }

     private:
         std::string name;
         std::vector<Card> hand;
     };
class Human : public Player{
    public:
    Human(const string playername) 
    : name(playername){}
    void print_hand() const {
        vector<Card> sorted_hand;
        vector<Card> copy = hand;
        int hand_size = hand.size();
        for(int x = 0; x<hand_size; x++){
            Card min = copy.at(0);
            int minindx = 0;
            for(int j =0; j<hand_size-x ;j++){
                if(min>copy.at(j)){
                    min = copy.at(j);
                    minindx = j;
                }
            }
            sorted_hand.push_back(min);
            copy.erase(copy.begin() + minindx);
        }
      for (size_t i=0; i < hand.size(); ++i)
          std::cout << "Human player " << name << "'s hand: "
             << "[" << i << "] " << sorted_hand.at(i) << "\n";
    }
    const string & get_name() const {
        return name;
    }    
    void add_card(const Card &c){
        hand.push_back(c);
       }
    bool make_trump(const Card &upcard, bool is_dealer,
                          int round, Suit &order_up_suit) const {
    bool choice = false;                       
    string s;
    print_hand();
    cout << "Human player " << name << ", please enter a suit, or \"pass\":\n";
    cin >> s;
    if (s != "pass"){
        choice = true;
        Suit ordered_up = string_to_suit(s);
        order_up_suit = ordered_up;
        cout << name << " orders up " << ordered_up <<endl;

    }else{
        cout<< name << " passes" << endl;
    }
    return choice;
    }
    
    void add_and_discard(const Card &upcard){
        int a;
        print_hand();
        cout << "Discard upcard: [-1]\n";
        cout << "Human player " << name << ", please select a card to discard:\n";
        cin >> a;
        if(a != -1){
            hand.erase(hand.begin()+a);
            hand.push_back(upcard);
        }
    }

    Card lead_card(Suit trump){
        print_hand();
        cout << "Human player " << name << ", please select a card:"<<endl;
        int indx;
        cin >> indx;
        Card chosen = hand[indx];
        // cout << chosen << " led by "<< name <<endl;
        hand.erase(hand.begin() + indx);
        return chosen;
    }
    
    Card play_card(const Card &led_card, Suit trump){
        print_hand();
        sort();
        cout << "Human player " << name << ", please select a card:"<<endl;
        int indx;
        cin >> indx;
        Card chosen = hand[indx];
        // cout << chosen << " played by "<< name <<endl;
        hand.erase(hand.begin() + indx);
        return chosen;
    }

    void sort(){
        vector<Card> sorted_hand;
    vector<Card> copy = hand;
            int hand_size = hand.size();
        for(int x = 0; x<hand_size; x++){
            Card min = hand.at(0);
            int minindx = 0;
            for(int j =0; j<hand_size-x ;j++){
                if(min>hand.at(j)){
                    min = copy.at(j);
                    minindx = j;
                }
            }
            sorted_hand.push_back(min);
            copy.erase(copy.begin() + minindx);
        }
        hand = sorted_hand;
    }
    private:
    string name;
        std::vector<Card> hand;
};
     
     
     Player * Player_factory(const std::string &name, const std::string &strategy){
     if(strategy == "Human"){
    return new Human(name);
     }
     if(strategy == "Simple"){
    return new Simple(name);
     }
     assert(false);
     return nullptr;
     }
    
    //EFFECTS: Prints player's name to os
    std::ostream & operator<<(std::ostream &os, const Player &p){
        os << p.get_name();
        return os;
    }


