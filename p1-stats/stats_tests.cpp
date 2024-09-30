/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 *
 * EECS 280 Project 1
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */


#include "stats.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;

void test_sum_small_data_set();
void testsummarize();
void testCount();
void testMean();
void testMedian();
void testMode();
void testMax();
void testMin();

// Add prototypes for you test functions here.

int main() {
  test_sum_small_data_set();
  // Call your test functions here
  testsummarize();
  testCount();
  testMean();
  testMedian();
  testMode();
  testMin();
  testMax();
  return 0;
}

void test_sum_small_data_set() {
  cout << "test_sum_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(sum(data) == 6);
    cout << "Pass!!";

}

void testsummarize(){
  cout << "test_summarize" << endl;
  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
  data.push_back(1);
  data.push_back(2);
  data.push_back(1);
  data.push_back(2);

  if (summarize(data).at(0).first == 1 && summarize(data).at(0).second == 3){
    cout << "Pass!!" << endl;
  }
}

void testCount(){
  cout << "testCount" << endl;
  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
  data.push_back(1);
  data.push_back(2);
  data.push_back(1);
  data.push_back(2);

  if (count(data) == 7){
    cout << "Pass!!" << endl;
  }
}


void testMean(){
  cout << "testMean" << endl;
  vector<double> data;
  data.push_back(2);
  data.push_back(4);
  data.push_back(6);
  data.push_back(8);
  data.push_back(10);
  data.push_back(12);
  data.push_back(14);

  if (mean(data) == 8){
    cout << "Pass!!" << endl;
  }
}

void testMedian(){
  cout << "testMedian" << endl;
  vector<double> data;
  data.push_back(6);
  data.push_back(4);
  data.push_back(2);
  data.push_back(12);
  data.push_back(14);
  data.push_back(8);
  data.push_back(10);

  if (median(data) == 8){
    cout << "Pass!!" << endl;
  }
}

void testMode(){
  cout << "testMode" << endl;
  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
  data.push_back(1);
  data.push_back(2);
  data.push_back(1);
  data.push_back(2);
  data.push_back(1);
  data.push_back(1);

  if (mode(data) == 1){
    cout << "Pass!!" << endl;
  }
}

void testMin(){
  cout << "testMin" << endl;
  vector<double> data;
  data.push_back(6);
  data.push_back(4);
  data.push_back(2);
  data.push_back(12);
  data.push_back(14);
  data.push_back(8);
  data.push_back(10);

  if (min(data) == 2){
    cout << "Pass!!" << endl;
  }
}

void testMax(){
  cout << "testMax" << endl;
  vector<double> data;
  data.push_back(6);
  data.push_back(4);
  data.push_back(2);
  data.push_back(12);
  data.push_back(14);
  data.push_back(8);
  data.push_back(10);

  if (max(data) == 14){
    cout << "Pass!!" << endl;
  }
}

