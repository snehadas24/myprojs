#include "BinarySearchTree.hpp"
#include "unit_test_framework.hpp"
using namespace std;
TEST(test_stub) {
    BinarySearchTree<int> empty;
    BinarySearchTree<int> empty2(empty);
    ASSERT_TRUE(empty.height() == 0);
    ASSERT_TRUE(empty.size() == 0);
    ASSERT_TRUE(empty.begin() == empty.end());
    ASSERT_TRUE(empty.check_sorting_invariant());
    ASSERT_TRUE(empty.max_element() == empty.end());
    ASSERT_TRUE(empty.min_element() == empty.end());
    ASSERT_TRUE(empty2.height() == 0);
    ASSERT_TRUE(empty2.size() == 0);
    ASSERT_TRUE(empty2.begin() == empty.end());
    ASSERT_TRUE(empty2.check_sorting_invariant());
    ASSERT_TRUE(empty2.max_element() == empty.end());
    ASSERT_TRUE(empty2.min_element() == empty.end());
    ASSERT_TRUE(empty.find(100) == empty.end());
    
    ostringstream oss_empty;
    ostringstream oss_empty2;
    empty.traverse_inorder(oss_empty);
    cout << "inorder empty" << endl;
    cout << oss_empty.str() << endl << endl;
    ASSERT_TRUE(oss_empty.str() == "");
    empty.traverse_preorder(oss_empty2);
    cout << "preorder empty" << endl;
    cout << oss_empty2.str() << endl << endl;
    ASSERT_TRUE(oss_empty2.str() == "");
    BinarySearchTree<int> tree;
    BinarySearchTree<int> tree2;
    ASSERT_TRUE(tree.empty())
    tree.insert(5);
    ASSERT_TRUE(tree.find(5) == tree.begin());
    tree.insert(10);
    ASSERT_TRUE(tree.height() == 2);
    ASSERT_TRUE(tree.size() == 2);
    tree.insert(4);
    ASSERT_FALSE(tree.empty());
    ASSERT_TRUE(tree.size() == 3);
    ASSERT_TRUE(tree.height() == 2);
    ASSERT_FALSE(tree.empty());
    ASSERT_TRUE(tree.find(5) != tree.end());
    
    tree.insert(7);
    ASSERT_TRUE(tree.check_sorting_invariant());
    tree.insert(3);
    ASSERT_TRUE(tree.height() == 3);
    ASSERT_TRUE(tree.check_sorting_invariant());
    ASSERT_TRUE(*tree.max_element() == 10);
    ASSERT_TRUE(*tree.min_element() == 3);
    ASSERT_TRUE(*tree.min_greater_than(5) == 7);
    tree2 = tree;
    ASSERT_TRUE(tree2.check_sorting_invariant());
    ASSERT_TRUE(*tree2.max_element() == 10);
    tree2.insert(15);
    ASSERT_TRUE(*tree2.max_element() == 15);
    ASSERT_TRUE(*tree2.min_element() == 3);
    ASSERT_TRUE(*tree2.min_greater_than(5) == 7);
    BinarySearchTree<int> tree3(tree);
    ASSERT_TRUE(tree3.check_sorting_invariant());
    ASSERT_TRUE(*tree3.max_element() == 10);
    ASSERT_TRUE(*tree3.min_element() == 3);
    ASSERT_TRUE(*tree3.min_greater_than(5) == 7);
    ASSERT_TRUE(*tree3.min_greater_than(0) == 3);
    ASSERT_TRUE(empty.min_greater_than(0) == empty.end());
    ASSERT_TRUE(tree3.min_greater_than(1000) == tree3.end());
    cout << "cout << tree.to_string()" << endl;
    cout << tree.to_string() << endl << endl;
    cout << "cout << tree" << endl << "(uses iterators)" << endl;
    cout << tree << endl << endl;
    ostringstream oss_preorder;
    ostringstream oss2;
    tree.traverse_preorder(oss_preorder);
    tree2.traverse_preorder(oss2);
    cout << "preorder" << endl;
    cout << oss_preorder.str() << endl << endl;
    cout << "preorder2" << endl;
    cout << oss2.str() << endl << endl;
    ASSERT_TRUE(oss_preorder.str() == "5 4 3 10 7 ");
    ASSERT_TRUE(oss2.str() == "5 4 3 10 7 15 ");
    ostringstream oss_inorder;
    tree.traverse_inorder(oss_inorder);
    cout << "inorder" << endl;
    cout << oss_inorder.str() << endl << endl;
    ASSERT_TRUE(oss_inorder.str() == "3 4 5 7 10 ");


    ASSERT_EQUAL(tree.find(1), nullptr); //added
    *tree.begin() = 20;
    ASSERT_FALSE(tree.check_sorting_invariant());
}

TEST(test2){
   BinarySearchTree<int> tree;
   tree.insert(10);
   tree.insert(3);
   tree.insert(1);
   tree.insert(11);
   tree.insert(15);
   tree.insert(20);
   ASSERT_TRUE(tree.size() == 6);
   ASSERT_TRUE(tree.height() == 4);
   ASSERT_EQUAL(tree.begin(), tree.find(10));
   ASSERT_TRUE(*tree.max_element() == 20);
   ASSERT_TRUE(*tree.min_element()== 1);
   ASSERT_EQUAL(tree.find(50), nullptr);
   ASSERT_TRUE(tree.check_sorting_invariant());
   *tree.begin() = 5;
   ASSERT_FALSE(tree.check_sorting_invariant());
   *tree.begin() = 9;
   ASSERT_TRUE(tree.check_sorting_invariant());
   ASSERT_TRUE(*tree.min_greater_than(8) == 9);
   ASSERT_TRUE(tree.min_greater_than(1000) == tree.end());
   ASSERT_TRUE(*tree.find(15) == 15);

}
TEST_MAIN()