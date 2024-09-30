#include "List.hpp"

#include "unit_test_framework.hpp"



using namespace std;



// Add your test cases here



TEST(test_push) {

    List<int> newList;

    newList.push_back(1);

    newList.push_back(2);

    newList.push_back(3);

    newList.push_front(0);

    int j = 0;

    for (List<int>::Iterator it = newList.begin(); it != newList.end(); ++it, ++j) {

        ASSERT_EQUAL(*it, j);

    }

    ASSERT_EQUAL(j, newList.size());

    

    List<int> list2;

    list2.push_front(2);

    list2.push_front(1);

    List<int>::Iterator iter = list2.begin();

    ++iter;

    ASSERT_EQUAL(*iter, 2);

}



TEST(test_front_back){

    List<int> newList;

    newList.push_back(1);

    newList.push_back(2);

    newList.push_back(3);

    newList.push_front(0);

    ASSERT_EQUAL(newList.back(), 3);

    ASSERT_EQUAL(newList.front(), 0);

    

}



TEST(test_pop_clear){

    List<int> newList;

    newList.push_back(1);

    newList.push_back(2);

    newList.push_back(3);

    newList.push_front(0);

    newList.pop_front();

    ASSERT_EQUAL(newList.front(), 1);

    newList.pop_back();

    ASSERT_EQUAL(newList.back(), 2);

    newList.pop_back();

    ASSERT_EQUAL(newList.front(), 1);

    ASSERT_EQUAL(newList.back(), 1);

    newList.clear();

    ASSERT_EQUAL(newList.size(), 0);

    

    

}



TEST(Iterator_equalities_pointer) {

    List<int>::Iterator a;

    List<int>::Iterator b;

    

    List<int> newList;

    newList.push_back(1);

    newList.push_back(2);

    newList.push_back(3);

    a = newList.begin();

    b = newList.begin();

    ASSERT_TRUE(a == b);

    b++;

    ASSERT_FALSE(a == b);

    a = b;

    ASSERT_TRUE(a == b);

    

    

    

   

}

TEST(Iterator_operators_constructors){
List<int>::Iterator a;
    List<int> newList;
    newList.push_back(1);
    newList.push_back(2);
    newList.push_back(3);
    a = newList.begin();
    ASSERT_TRUE(*a == 1);
    a++;
    ASSERT_TRUE(*a == 2);
    a--;
    ASSERT_TRUE(*a == 1);
    List<int>::Iterator b;
    b = a;
    ASSERT_TRUE(*b == 1);
    ASSERT_TRUE(a == b);
    ASSERT_FALSE(a != b);
    List<int> list2;
    list2 = newList;
    for (List<int>::Iterator it = newList.begin(), it2 = list2.begin(); it != list2.end(); ++it, ++it2) {
        ASSERT_EQUAL(*it, *it2);
    }
    ASSERT_EQUAL(list2.size(), newList.size());
    List<int> list3(list2);
    for (List<int>::Iterator it = list3.begin(), it2 = list2.begin(); it != list2.end(); ++it, ++it2) {
        ASSERT_EQUAL(*it, *it2);
    }
    List<int> list5;
      list5 = list2;
      list5 = newList;
      List<int>::Iterator r = list5.begin();
      List<int>::Iterator s = newList.begin();
      int j = 0;
      for(j = 0; r != list5.end(); ++r, ++s, ++j){
          ASSERT_EQUAL(*r, *s);
      }
    List<int>::Iterator iter1 = list5.begin();
    List<int>::Iterator iter2 = list5.end();
    iter2 = iter1;

    ASSERT_EQUAL(iter2, iter1);

    

}



TEST(begin_end){
    List<int> newList;
    newList.push_back(1);
    newList.push_front(0);
    List<int>::Iterator it = newList.begin();
    List<int>::Iterator it2 = newList.end();
    List<int>::Iterator it3 = newList.end();
    ASSERT_EQUAL(*it, newList.front());
    ASSERT_EQUAL(*--it2, newList.back());
    ASSERT_EQUAL(++it, --it3);
}



TEST(insert_erase){
    List<int> newList;
    newList.push_back(1);
    newList.push_front(0);
    List<int>::Iterator it = newList.begin();
    newList.insert(it, 5);
    ASSERT_EQUAL(newList.front(), 5);
    it = newList.end();
    newList.insert(it, 2);
    int counter = 0;
    for(List<int>::Iterator i = newList.begin(); i != newList.end(); ++i){
        if(*i == 2){
            counter++;
        }
    }
    ASSERT_EQUAL(counter, 1);
    it = newList.begin();
    newList.erase(it);
    ASSERT_EQUAL(newList.front(), 0);
    List<int>::Iterator i = newList.begin();
    for(int k = 0; k != 3; ++k){
        newList.erase(i);
        i = newList.begin();
    }
    ASSERT_TRUE(newList.empty())
    List<int> list10;
    list10.push_back(1);
    list10.push_back(2);
    list10.push_back(3);
    List<int>::Iterator iter = list10.begin();
    iter = list10.erase(iter);
    ASSERT_EQUAL(*iter, 2);
    list10.push_front(1);
    iter = list10.begin();
    ++iter;
    iter = list10.erase(iter);
    ASSERT_EQUAL(*iter, 3);
    list10.push_front(1);
    iter = list10.begin();
    iter++;
    ++iter;
    iter = list10.erase(iter);
    ASSERT_EQUAL(iter, list10.end());
}

TEST(plus_and_minus){
    List<int> newList;
    newList.push_back(1);
    newList.push_back(2);
    newList.push_back(3);
    newList.push_back(4);
    newList.push_back(5);
    newList.push_back(6);
    List<int>::Iterator iter = newList.begin();
    iter++;
    iter++;
    ASSERT_TRUE(*iter == 3);
    iter++;
    iter--;
    iter--;
    ASSERT_TRUE(*iter == 2);
}

TEST(clear){
    List<int> newList;
    newList.push_back(1);
    newList.push_back(2);
    newList.push_back(3);
    ASSERT_TRUE(newList.size() == 3);
    newList.clear();
    ASSERT_TRUE(newList.size() == 0);
    ASSERT_TRUE(newList.empty());
}

TEST(front_back){
    List<int> newList;
    newList.push_back(1);
    ASSERT_TRUE(newList.front() == 1);
    ASSERT_TRUE(newList.back() == 1);
    newList.push_back(2);
    newList.push_back(3);
    ASSERT_TRUE(newList.back() == 3);
    newList.pop_front();
    ASSERT_TRUE(newList.front() == 2);
}

TEST(assignment){
    List<int> newList;
    newList.push_back(1);
    newList.push_back(2);
    newList.push_back(3);
    List<int> newList2;
    newList2.push_back(4);
    newList2.push_back(5);
    newList2 = newList;
    List<int>::Iterator a = newList.begin();
    List<int>::Iterator b = newList2.begin();
    ASSERT_EQUAL(newList.size(), newList2.size());
    ASSERT_EQUAL(*a, *b);
    a++;
    b++;
    ASSERT_EQUAL(*a, *b);
    a++;
    b++;
    ASSERT_EQUAL(*a, *b);

}

TEST(test_empty){
List<int> newList;
ASSERT_TRUE(newList.empty());
newList.push_back(2);
ASSERT_FALSE(newList.empty());
newList.pop_back();
ASSERT_TRUE(newList.empty());
}

TEST_MAIN()

