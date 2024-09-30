#include "Player.hpp"
#include "unit_test_framework.hpp"

#include <iostream>

using namespace std;

TEST(test_player_get_name) {
    Player * alice = Player_factory("Alice", "Simple");
    Player * sam = Player_factory("Sam", "Human");
    ASSERT_EQUAL("Alice", alice->get_name());
    ASSERT_EQUAL("Sam", sam->get_name());
    delete alice;
}


TEST(test_play_card){
    Player * sam = Player_factory("Sam", "Simple");
    sam-> add_card(Card(ACE, HEARTS));
    sam-> add_card(Card(JACK, DIAMONDS));
    sam-> add_card(Card(NINE, DIAMONDS));
    sam-> add_card(Card(TEN,DIAMONDS));
    sam->add_card(Card(QUEEN, DIAMONDS));
    const Card led(NINE, HEARTS);
    Card c = sam->play_card(led, HEARTS );
    ASSERT_EQUAL (c, Card(JACK, DIAMONDS));
    delete sam;
}


TEST(test_add_and_discard){
    Player * sam = Player_factory("Sam", "Simple");
    Player * max = Player_factory("Max", "Simple");
    sam-> add_card(Card(ACE, HEARTS));
    sam-> add_card(Card(JACK, SPADES));
    sam-> add_card(Card(TEN, DIAMONDS));
    sam-> add_card(Card(NINE, HEARTS));
    max->add_card(Card(TEN, CLUBS));
    max->add_card(Card(JACK, CLUBS));
    max->add_card(Card(QUEEN, CLUBS));
    max->add_card(Card(KING, CLUBS));
    max->add_card(Card(ACE, CLUBS));
    const Card upcard1(KING, HEARTS);
    const Card upcard2(NINE, CLUBS);
    sam->add_and_discard(upcard1);
    Card c = sam->play_card(Card(NINE, DIAMONDS), HEARTS); // will be ten of diamonds if it was not removed
    cout << c << endl;
    ASSERT_EQUAL ( c, Card(JACK, SPADES));
    max->add_and_discard(upcard2);
    vector<Card> maxCards;
    
    maxCards.push_back(max->play_card(Card(NINE, DIAMONDS), CLUBS));
    maxCards.push_back(max->play_card(Card(NINE, DIAMONDS), CLUBS));
    maxCards.push_back(max->play_card(Card(NINE, DIAMONDS), CLUBS));
    maxCards.push_back(max->play_card(Card(NINE, DIAMONDS), CLUBS));
    maxCards.push_back(max->play_card(Card(NINE, DIAMONDS), CLUBS));
    for(int i = 0; i < 5; i++){
        ASSERT_NOT_EQUAL(Card(NINE, CLUBS), maxCards[i]);
    }
    delete sam;
    
}
TEST(test_get_name){
    Player * sam = Player_factory("Sam", "Simple");
    ASSERT_EQUAL("Sam", sam->get_name());
    delete sam;
}
TEST(test_make_trump){
    Player * sam = Player_factory("Sam", "Simple");
    Player * max = Player_factory("Max", "Simple");
    Player * alex = Player_factory("Alex", "Simple");
    Card upcard1 = Card(KING, SPADES);
    Card upcard2 = Card(ACE, HEARTS);
    Card upcard3 = Card(ACE, HEARTS);
    Suit suitSam;
    Suit suitMax;
    Suit suitAlex;
    sam-> add_card(Card(ACE, HEARTS));
    sam-> add_card(Card(JACK, DIAMONDS));
    sam-> add_card(Card(TEN, DIAMONDS));
    sam-> add_card(Card(NINE, HEARTS));
    sam-> add_card(Card(TEN, HEARTS));
    max-> add_card(Card(NINE, HEARTS));
    max-> add_card(Card(TEN, HEARTS));
    max-> add_card(Card(JACK, HEARTS));
    max-> add_card(Card(QUEEN, HEARTS));
    max-> add_card(Card(KING, HEARTS));
    alex-> add_card(Card(KING, HEARTS));
    alex-> add_card(Card(TEN, SPADES));
    alex-> add_card(Card(JACK, DIAMONDS));
    alex-> add_card(Card(QUEEN, SPADES));
    alex-> add_card(Card(KING, SPADES));
    //test both rounds
    ASSERT_FALSE(sam->make_trump(upcard1, true, 1, suitSam));
    ASSERT_TRUE(sam->make_trump(upcard1, true, 2, suitSam));
    ASSERT_EQUAL(suitSam, CLUBS);
    ASSERT_FALSE(sam->make_trump(upcard1, false, 1, suitSam));
    ASSERT_TRUE(max->make_trump(upcard1, true, 2, suitMax));
    ASSERT_EQUAL(suitMax, CLUBS);
    ASSERT_TRUE(max->make_trump(upcard2, false, 1, suitMax));
    ASSERT_TRUE(alex->make_trump(upcard3, false, 1, suitAlex));
    ASSERT_EQUAL(suitAlex, HEARTS);
    ASSERT_EQUAL(suitMax, HEARTS);
    
    
    delete sam;
    delete max;
}

TEST_MAIN();
