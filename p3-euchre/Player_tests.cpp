#include "Player.hpp"
#include "unit_test_framework.hpp"
#include <iostream>

using namespace std;

TEST(test_play_card){
    Player * sam = Player_factory("Sam", "Simple");
    sam-> add_card(Card(ACE, HEARTS));
    sam-> add_card(Card(JACK, DIAMONDS));
    sam-> add_card(Card(NINE, DIAMONDS));
    const Card led(NINE, HEARTS);
    Card c = sam->play_card(led, HEARTS );
    ASSERT_EQUAL (c, Card( JACK, DIAMONDS));
    delete sam;
}
TEST(test_add_and_discard){
    Player * sam = Player_factory("Sam", "Simple");
    sam-> add_card(Card(ACE, HEARTS));
    sam-> add_card(Card(JACK, SPADES));
    sam-> add_card(Card(TEN, DIAMONDS));
    sam-> add_card(Card(NINE, HEARTS));
    const Card upcard(KING, HEARTS);
    sam->add_and_discard(upcard);
    Card c = sam->play_card(Card(NINE, DIAMONDS), HEARTS); // will be ten of diamonds if it was not removed 
    cout << c << endl;
    ASSERT_EQUAL ( c, Card(JACK, SPADES));
    delete sam;
}

TEST(test_lead_card){
    Player * sam = Player_factory("Sam", "Simple");
    sam-> add_card(Card(ACE, HEARTS));
    sam-> add_card(Card(TEN, HEARTS));
    sam-> add_card(Card(TEN, DIAMONDS));
    sam-> add_card(Card(NINE, HEARTS));
    Card c = sam->lead_card(SPADES);
    ASSERT_EQUAL(c, Card(ACE, HEARTS));
    delete sam;
}
// Add more tests here

TEST(test_player_get_name) {

    Player * alice = Player_factory("Alice", "Simple");

    Player * sam = Player_factory("Sam", "Human");

    ASSERT_EQUAL("Alice", alice->get_name());

    ASSERT_EQUAL("Sam", sam->get_name());

    delete alice;
    delete sam;

}

TEST(test_make_trump){

    Player * sam = Player_factory("Sam", "Simple");

    Player * max = Player_factory("Max", "Simple");

    Card upcard1 = Card(KING, SPADES);

    Card upcard2 = Card(ACE, HEARTS);

    Suit suitSam;

    Suit suitMax;

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

    //test both rounds

    ASSERT_FALSE(sam->make_trump(upcard1, true, 1, suitSam));

    ASSERT_TRUE(sam->make_trump(upcard1, true, 2, suitSam));

    ASSERT_EQUAL(suitSam, CLUBS);

    ASSERT_FALSE(sam->make_trump(upcard1, false, 1, suitSam));

    ASSERT_TRUE(max->make_trump(upcard1, true, 2, suitMax));

    ASSERT_EQUAL(suitMax, CLUBS);

    ASSERT_TRUE(max->make_trump(upcard2, false, 1, suitMax));

    ASSERT_EQUAL(suitMax, HEARTS);

    

    

    delete sam;

    delete max;

}



TEST_MAIN()
