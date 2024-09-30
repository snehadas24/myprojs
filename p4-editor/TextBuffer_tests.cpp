#include "TextBuffer.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Add your test cases here

TEST(forward_and_backward) {
    // Add test code here
    TextBuffer buffer;
    buffer.insert('h');
    buffer.insert('e');
    buffer.insert('l');
    buffer.insert('l');
    buffer.insert('o');
    buffer.insert('\n');
    buffer.insert('a');
    buffer.insert('b');
    buffer.insert('c');
    ASSERT_TRUE(buffer.data_at_cursor() == 'h');
    buffer.forward();
    buffer.forward();
    ASSERT_TRUE(buffer.data_at_cursor() == 'l')
    buffer.backward();
    ASSERT_TRUE(buffer.data_at_cursor() == 'e')
}

TEST(compute_column){
    TextBuffer buffer;
    buffer.insert('h');
    buffer.insert('e');
    buffer.insert('l');
    buffer.insert('l');
    buffer.insert('o');
    buffer.insert('\n');
    buffer.insert('a');
    buffer.insert('b');
    buffer.insert('c');
    ASSERT_FALSE(buffer.forward());
    ASSERT_EQUAL(buffer.compute_column(), 3);
    ASSERT_TRUE(buffer.is_at_end());
    buffer.insert('\n');
    ASSERT_EQUAL(buffer.compute_column(), 0);
    buffer.up();
    ASSERT_EQUAL(buffer.compute_column(), 0);
    buffer.move_to_column(0);
    buffer.move_to_row_end();
    ASSERT_TRUE(buffer.get_column()== 5);
    buffer.down();
    ASSERT_TRUE(buffer.get_column()== 4);
   
}

TEST(insert){
    TextBuffer buffer;
    buffer.insert('h');
    buffer.insert('e');
    buffer.insert('l');
    buffer.insert('l');
    buffer.insert('o');
    ASSERT_TRUE(buffer.get_column() == 5);
    buffer.insert('\n');
    ASSERT_TRUE(buffer.get_column() ==0);
    ASSERT_TRUE(buffer.get_row() == 1);
}

TEST(remove){
    TextBuffer buffer;
    buffer.insert('h');
    buffer.insert('e');
    buffer.insert('l');
    buffer.insert('l');
    buffer.insert('o');
    ASSERT_FALSE(buffer.remove());
    buffer.backward();
    ASSERT_TRUE(buffer.data_at_cursor() =='o');
    buffer.remove();
    ASSERT_TRUE(buffer.data_at_cursor() =='l');
    ASSERT_TRUE(buffer.get_column() ==3);
    buffer.insert('\n');
    buffer.forward();
    ASSERT_TRUE(buffer.get_row() == 1);
}

TEST(backward){
    TextBuffer buffer;
    buffer.insert('h');
    buffer.insert('e');
    buffer.insert('l');
    buffer.insert('l');
    buffer.insert('o');
    buffer.insert('\n');
    ASSERT_EQUAL(buffer.get_row(), 1);
    ASSERT_EQUAL(buffer.get_column(), 0);
    buffer.backward();
    ASSERT_EQUAL(buffer.get_column(), 5);
    buffer.move_to_row_start();
    ASSERT_FALSE(buffer.backward());
}

TEST_MAIN()
