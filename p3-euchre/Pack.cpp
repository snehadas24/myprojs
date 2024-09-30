//
//  main.cpp
//  a
//
//  Created by Giovanni Rossi on 2/19/24.
//

#include <iostream>
#include <array>
#include "Pack.hpp"
#include "Card.hpp"


// EFFECTS: Initializes the Pack to be in the following standard order:
//          the cards of the lowest suit arranged from lowest rank to
//          highest rank, followed by the cards of the next lowest suit
//          in order from lowest to highest rank, and so on.
// NOTE: The standard order is the same as that in pack.in.
// NOTE: Do NOT use pack.in in your implementation of this function
// NOTE: The pack is initially full, with no cards dealt.
Pack::Pack(){
    next = 0;
    int j = 7;
    for(int i = 0; i < PACK_SIZE; i++){
        if(i < 6){
            Card card1(Rank(j), string_to_suit("Spades"));
            cards[i] = card1;
            j++;
        }else if(i > 6 && i < 12){
            Card card1(Rank(j), string_to_suit("Hearts"));
            cards[i] = card1;
            j++;
        }else if(i > 12 && i < 18){
            Card card1(Rank(j), string_to_suit("Clubs"));
            cards[i] = card1;
            j++;
        }else{
            Card card1(Rank(j), string_to_suit("Diamonds"));
            cards[i] = card1;
            j++;
        }
    }
    
}

// REQUIRES: pack_input contains a representation of a Pack in the
//           format required by the project specification
// MODIFIES: pack_input
// EFFECTS: Initializes Pack by reading from pack_input.
// NOTE: The pack is initially full, with no cards dealt.
Pack::Pack(std::istream& pack_input){
    next = 0;
    std::string rank;
    std::string suit;
    std::string middle;
    for(int i = 0; i < PACK_SIZE; i++){
        pack_input >> rank >> middle >> suit;
        Card card(string_to_rank(rank), string_to_suit(suit));
        cards[i] = card;
    }
}

// REQUIRES: cards remain in the Pack
// EFFECTS: Returns the next card in the pack and increments the next index
Card Pack::deal_one(){
    int current = next;
    next++;
    return cards[current];
}

// EFFECTS: Resets next index to first card in the Pack
void Pack::reset(){
    next = 0;
}

// EFFECTS: Shuffles the Pack and resets the next index. This
//          performs an in shuffle seven times. See
//          https://en.wikipedia.org/wiki/In_shuffle.
void Pack::shuffle(){

    next = 0;

    //seperate into halves and then interweave the halves

    Pack pack1;

    Card first_half[PACK_SIZE / 2];

    Card second_half[PACK_SIZE / 2];

    for(int i = 0; i < 7; i++){

        for(int j = 0; j < PACK_SIZE / 2; j++){

            first_half[j] = cards[j];

            second_half[j] = cards[PACK_SIZE / 2 + j];

        }

        for(int k = 0, j = 1, z = 0; k < PACK_SIZE - 1; k+=2, j = k + 1, z++){

            cards[k] = second_half[z];

            cards[j] = first_half[z];

        }

    }

    return;

    

}

// EFFECTS: returns true if there are no more cards left in the pack
bool Pack::empty() const{
    if(next == PACK_SIZE){
        return true;
    }
    return false;
}
