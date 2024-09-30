#include "Card.hpp"
#include "unit_test_framework.hpp"
#include <iostream>

using namespace std;


TEST(test_card_ctor) {

    Card c(ACE, HEARTS);

    ASSERT_EQUAL(ACE, c.get_rank());

    ASSERT_EQUAL(HEARTS, c.get_suit());

}



TEST(test_card_default_ctor){

    Card c;

    ASSERT_EQUAL(SPADES, c.get_suit());

    ASSERT_EQUAL(TWO, c.get_rank());

}



TEST(test_card_get_suit){

    Card c(JACK, SPADES);

    ASSERT_EQUAL(c.get_suit(CLUBS), CLUBS);

    ASSERT_EQUAL(c.get_suit(), SPADES);

}



TEST(test_card_face_or_ace){

    Card a(JACK, SPADES);

    Card b(NINE, CLUBS);

    Card  c(ACE, HEARTS);

    ASSERT_TRUE(a.is_face_or_ace());

    ASSERT_FALSE(b.is_face_or_ace());

    ASSERT_TRUE(c.is_face_or_ace());

}

TEST(test_card_right_left_bower){

    Card a(JACK, SPADES);

    Card b(JACK, CLUBS);

    Card c(TEN, CLUBS);

    ASSERT_TRUE(a.is_right_bower(SPADES));

    ASSERT_FALSE(a.is_right_bower(CLUBS));

    ASSERT_TRUE(b.is_right_bower(CLUBS));

    ASSERT_FALSE(b.is_right_bower(SPADES));

    ASSERT_TRUE(a.is_left_bower(CLUBS));

    ASSERT_FALSE(a.is_left_bower(SPADES));

    ASSERT_TRUE(b.is_left_bower(SPADES));

    ASSERT_FALSE(b.is_left_bower(CLUBS));

    ASSERT_FALSE(c.is_right_bower(CLUBS));

    ASSERT_FALSE(c.is_right_bower(HEARTS));

    ASSERT_FALSE(c.is_right_bower(SPADES));

    ASSERT_FALSE(c.is_left_bower(SPADES));

    ASSERT_FALSE(c.is_left_bower(CLUBS));

}



TEST(test_card_is_trump){

    Card a(JACK, CLUBS);

    Card b(JACK, SPADES);

    Card c(TEN, SPADES);

    ASSERT_EQUAL(a.is_trump(CLUBS), b.is_trump(CLUBS));

    ASSERT_TRUE(a.is_trump(CLUBS));

    ASSERT_TRUE(b.is_trump(SPADES));

    ASSERT_FALSE(a.is_trump(HEARTS));

    ASSERT_FALSE(b.is_trump(HEARTS));

    ASSERT_FALSE(c.is_trump(HEARTS));

    ASSERT_TRUE(c.is_trump(SPADES));

}



TEST(test_card_less_greater_than_and_or_equal_to){

    Card a(TEN, CLUBS);

    Card b(ACE, CLUBS);

    Card c(TEN, SPADES);

    Card d(TEN, CLUBS);

    Card e(JACK, CLUBS);

    Card f(JACK, SPADES);

    Card g(JACK, CLUBS);

    ASSERT_TRUE(b > a);

    ASSERT_TRUE(b >= a);

    ASSERT_FALSE(b < a);

    ASSERT_FALSE(b <= a);

    ASSERT_FALSE(a == b);

    ASSERT_FALSE(a == c);

    ASSERT_TRUE(a == d);

    ASSERT_TRUE(d > c);

    ASSERT_TRUE(a != b);

    ASSERT_FALSE(a != d);

    ASSERT_TRUE(e != f);

    ASSERT_TRUE(e == g);

    ASSERT_EQUAL(e, g);

}



TEST(test_suit_next){

    ASSERT_EQUAL(CLUBS, Suit_next(SPADES));

    ASSERT_EQUAL(SPADES, Suit_next(CLUBS));

    ASSERT_EQUAL(HEARTS, Suit_next(DIAMONDS));

    ASSERT_EQUAL(DIAMONDS, Suit_next(HEARTS));

    ASSERT_NOT_EQUAL(CLUBS, Suit_next(HEARTS));

}



TEST(test_card_less){

    Card a(TEN, CLUBS);

    Card b(ACE, CLUBS);

    Card c(TEN, SPADES);

    Card d(TEN, CLUBS);

    Card e(JACK, CLUBS);

    Card f(JACK, DIAMONDS);

    ASSERT_TRUE(Card_less(a, b, CLUBS));

    ASSERT_TRUE(Card_less(b, e, CLUBS));

    ASSERT_TRUE(Card_less(b, e, SPADES));

    ASSERT_FALSE(Card_less(b, e, HEARTS));

    ASSERT_TRUE(Card_less(c, e, SPADES));

    ASSERT_FALSE(Card_less(a, c, e, CLUBS));

    ASSERT_TRUE(Card_less(a, b, d, CLUBS));

}

/*TEST(test_card_output){
    Card a(JACK, SPADES);
    ASSERT_EQUAL("Jack of Spades", cout << a);
}
 */
TEST_MAIN()
