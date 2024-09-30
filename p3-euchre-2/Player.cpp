#include <iostream>
#include "Player.hpp"
#include <array>
#include <cassert>
#include <algorithm>
using namespace std;

//EFFECTS returns player's name
class Simple : public Player{
public:
    Simple(const std::string name1){
        name = name1;
    }
    const std::string & get_name() const override{
        return name;
    }
    
    //REQUIRES player has less than MAX_HAND_SIZE cards
    //EFFECTS  adds Card c to Player's hand
    void add_card(const Card &c) override{
        hand.push_back(c);
    }
    
    //REQUIRES round is 1 or 2
    //MODIFIES order_up_suit
    //EFFECTS If Player wishes to order up a trump suit then return true and
    //  change order_up_suit to desired suit.  If Player wishes to pass, then do
    //  not modify order_up_suit and return false.
    
    bool make_trump(const Card &upcard, bool is_dealer,
                    int round, Suit &order_up_suit)const override{
        int faceCounter = 0;
        Suit trumpSuit = upcard.get_suit();
        if(round == 1){
            for(int i = 0; i < hand.size(); i++){
                if(hand[i].is_trump(trumpSuit) && (hand[i].is_face_or_ace() 
                || hand[i].is_left_bower(trumpSuit))){
                        faceCounter++;
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
                if(hand[i].is_trump(trumpSuit) && (hand[i].is_face_or_ace() 
                || hand[i].is_left_bower(trumpSuit))){
                        faceCounter++;
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
    void add_and_discard(const Card &upcard) override{
        int lowestIndex = 0;
        add_card(upcard);
        Card currentLowest = hand[0];
        for(int i = 0; i < hand.size(); i++){
            if(Card_less(hand[i], currentLowest, upcard.get_suit())){
                lowestIndex = i;
                currentLowest = hand[i];
            }
        }
        hand.erase(hand.begin() + lowestIndex);
    }
    
    //REQUIRES Player has at least one card
    //EFFECTS  Leads one Card from Player's hand according to their strategy
    //  "Lead" means to play the first Card in a trick.  The card
    //  is removed the player's hand.
    // Card lead_card(Suit trump) override{
    //     Card highest = hand[0];
    //     int curr = 0; // index in hand of card being played
    //     int counter = 0;
    //     for(int a = 0; a<hand.size(); a++){
    //         if(hand[a].get_suit(trump) != trump){
    //             counter++;
    //         }
    //     }
    //     if (counter > 0){
    //         // int j = 1;
    //         // while(highest.get_suit() == trump){
    //         //     highest = hand[j];
    //         //     if(j < hand.size() - 1){
    //         //         j++;
    //         //         curr = j;
    //         //     }
    //         // }
            
    //         for (int i = 1; i<hand.size(); i++){
    //             if(Card_less(highest, hand[i], trump) && (hand[i].get_suit(trump) != trump)){
    //                 highest = hand[i];
    //                 curr = i;
    //             }
    //         }
    //     }else{
    //         for(int i =0; i<hand.size(); i++){
    //             if (Card_less(highest, hand[i], trump)){
    //                 highest = hand[i];
    //                 curr = i;
    //             }
    //         }
    //     }
    //     hand.erase(hand.begin() + curr);
    //     return highest;
        
        
    // }
    Card lead_card(Suit trump) override{

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

                    if(Card_less(highest, hand[indx[i]], trump)){

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

       /* for(int i = 0; i < hand.size(); i++){

            cout << hand.at(i) << " ";

        }

        cout << hand.at(curr) << " was deleted";

        */

                hand.erase(hand.begin() + curr);

                return highest;

             }
     
     //REQUIRES Player has at least one card
     //EFFECTS  Plays one Card from Player's hand according to their strategy.
     //  The card is removed from the player's hand.
     Card play_card(const Card &led_card, Suit trump) override{
        Card card1 = hand[0];
        int counter = 0;
        int index = 0;
        if(led_card.get_suit(trump) != trump){
            for(int i = 0; i < hand.size(); i++){
                if(hand[i].get_suit(trump) == led_card.get_suit(trump)){
                    counter++;
                }
            }
        }else{
            for(int i = 0; i < hand.size(); i++){
                if(hand[i].is_trump(led_card.get_suit(trump))){
                    counter++;
                }
            }
        }if(counter == 0){
                 for(int i = 0; i < hand.size(); i++){
                     if(Card_less(hand[i], card1, trump)){
                         card1 = hand[i];
                         index = i;
                     }
                 }
             }
             else{
                 for(int i = 0; i < hand.size(); i++){
                     if(led_card.get_suit(trump) == trump){
                         if(Card_less(card1, hand[i], trump)){
                             card1 = hand[i];
                             index = i;
                         }
                     }else{
                         if(Card_less1(card1, hand[i], led_card) /*&& !hand[i].is_trump(trump)*/){
                                card1 = hand[i];
                                index = i;
                            }
                     }
                 }
             }
             hand.erase(hand.begin() + index);
             return card1;
         }
    
    bool Card_less1( Card &a,  Card &b, const Card &led_card){

        if(a.get_suit() == led_card.get_suit() && b.get_suit() != led_card.get_suit()){

            return false;

        }else if(b.get_suit() == led_card.get_suit()

                 && a.get_suit() != led_card.get_suit()){

            return true;

        }else{

            return a < b;

        }

        

        


    }
private:
    std::string name;
    std::vector<Card> hand;
};
 
     
 class Human : public Player{
public:
    Human(const std::string playername)
    : name(playername){}
    void print_hand() const {
        for (size_t i=0; i < hand.size(); ++i)
            std::cout << "Human player " << name << "'s hand: "
            << "[" << i << "] " << hand[i] << "\n";
    }
    const std::string & get_name() const {
        return name;
    }
    void add_card(const Card &c){
        hand.push_back(c);
        std::sort(hand.begin(), hand.end());
    }
    bool make_trump(const Card &upcard, bool is_dealer,
                    int round, Suit &order_up_suit) const {
        bool choice = false;
        std::string s;
        print_hand();
        cout << "Human player " << name << ", please enter a suit, or \"pass\":\n";
        cin >> s;
        if (s != "pass"){
            choice = true;
            Suit ordered_up = string_to_suit(s);
            order_up_suit = ordered_up;
            
        }
        return choice;
    }
    
    void add_and_discard(const Card &upcard){
        int a;
        std::sort(hand.begin(), hand.end());
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
        std::sort(hand.begin(), hand.end());
        print_hand();
        cout << "Human player " << name << ", please select a card:"<<endl;
        int indx;
        cin >> indx;
        Card chosen = hand[indx];
        hand.erase(hand.begin() + indx);
        return chosen;
    }
    
    Card play_card(const Card &led_card, Suit trump){
        std::sort(hand.begin(), hand.end());
        print_hand();
        cout << "Human player " << name << ", please select a card:"<<endl;
        int indx;
        cin >> indx;
        Card chosen = hand[indx];
        hand.erase(hand.begin() + indx);
        return chosen;
    }
    
    
private:
    std::string name;
    std::vector<Card> hand;
};    
Player * Player_factory(const std::string &name, const std::string &strategy){
    if(strategy == "Human"){
        return new Human(name);
    }
    
    if(strategy == "Simple"){
        return new Simple(name);
    }
    //assert(false);
    return nullptr;
}
    
    //EFFECTS: Prints player's name to os
    std::ostream & operator<<(std::ostream &os, const Player &p){
        os << p.get_name();
        return os;
    }
