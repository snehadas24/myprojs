#ifndef LIST_HPP
#define LIST_HPP
/* List.hpp
 *
 * doubly-linked, double-ended list with Iterator interface
 * EECS 280 Project 4
 */

#include <iostream>
#include <iterator> //std::bidirectional_iterator_tag
#include <cassert>  //assert


template <typename T>
class List {
  //OVERVIEW: a doubly-linked, double-ended list with Iterator interface
public:
    
    List() : num(0), first(nullptr), last(nullptr){}
    
    List(List &other){
        copy_all(other);
    }
    ~List(){
        clear();
    }
  //EFFECTS:  returns true if the list is empty
    bool empty() const{
        return(first == nullptr);
    }

  //EFFECTS: returns the number of elements in this List
  //HINT:    Traversing a list is really slow. Instead, keep track of the size
  //         with a private member variable. That's how std::list does it.
    int size() const{
        return num;
    }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the first element in the list by reference
    T & front(){
        return first->datum;
    }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the last element in the list by reference
    T & back(){
        return last->datum;
    }

  //EFFECTS:  inserts datum into the front of the list
    void push_front(const T &datum){
        Node *p = new Node;
        p->datum = datum;
        p->prev = nullptr;
        p->next = first;
        first->prev = p;
        this->first = p;
        if(empty()){
            first = last = p;
        }
        ++num;
    }

  //EFFECTS:  inserts datum into the back of the list
    void push_back(const T &datum){
        Node *p = new Node;
        p->datum = datum;
        p->next = nullptr;
        p->prev = last;
        if(empty()){
            first = last = p;
        }else{
            last->next = p;
            last = p;
            
        }
        ++num;
    }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the front of the list
    void pop_front(){
        Node* to_delete = first;
        if(num < 2){
            
            first = last = nullptr;
        }else{
            first = first->next;
        }
        delete to_delete;
        num--;
         
    }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the back of the list
    void pop_back(){
        Node* to_delete = last;
        if(size() < 2){
            first = nullptr;
            last = nullptr;
        }else{
            last = last->prev;
            last->next = nullptr;
        }
        delete to_delete;
       num--;
    }

  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes all items from the list
    void clear(){
        while(!empty()){
            pop_front();
        }
    }
    
   

  // You should add in a default constructor, destructor, copy constructor,
  // and overloaded assignment operator, if appropriate. If these operations
  // will work correctly without defining these, you should omit them. A user
  // of the class must be able to create, copy, assign, and destroy Lists.

    
    List<T>& operator=(const List &other){
        
        copy_all(other);
        return this;
    }
  //  List<T>& operator=( List &other){
        
  //       copy_all(other);
  //       return *this;
  //   }
    
private:
    int num;
  //a private type
  struct Node {
    Node *next;
    Node *prev;
    T datum;
  };

  //REQUIRES: list is empty
  //EFFECTS:  copies all nodes from other to this
    void copy_all(const List<T> &other){
        num = other.num;
        if (other.empty()) {
        first = nullptr;
        last = nullptr;
      }else{
      first = new Node;
      first->datum = other.first->datum;
      first->prev = nullptr;
      first->next= other.first->next;
      Node *curr_node = first;
       Node *other_curr = other.first->next; 
      while (other_curr != nullptr) {
        Node *new_node = new Node;
        new_node->datum = other_curr->datum;
        new_node->prev = curr_node;
        curr_node->next = new_node;
        
        curr_node = new_node;
        other_curr = other_curr->next;
    }
    last = curr_node;
    last->next = nullptr;
}
      
        // first = other.first;
        // Node *curr = first;
        // // Node *ptr currthis =
        // for(Node *ptr = other.first; ptr != other.last; ptr = ptr->next){
        //     *(curr->next) = *ptr;
        //     curr = curr->next;
        // }
        // last = ptr->next;

    }

  Node *first;   // points to first Node in list, or nullptr if list is empty
  Node *last;    // points to last Node in list, or nullptr if list is empty

public:
  ////////////////////////////////////////
  class Iterator {
  public:
    //OVERVIEW: Iterator interface to List

    // Add a default constructor here. The default constructor must set both
    // pointer members to null pointers.
      Iterator(){
          list_ptr = nullptr;
          node_ptr = nullptr;
      }


    // Add custom implementations of the destructor, copy constructor, and
    // overloaded assignment operator, if appropriate. If these operations
    // will work correctly without defining these, you should omit them. A user
    // of the class must be able to copy, assign, and destroy Iterators.
      
      Iterator(Iterator const &other){
          list_ptr = other.list_ptr;
          node_ptr = other.node_ptr;
      }


    // Your iterator should implement the following public operators:
    // *, ++ (both prefix and postfix), == and !=.
    // Equality comparisons must satisfy the following rules:
    // - two default-constructed iterators must compare equal
    // - a default-constructed iterator must compare unequal to an
    //   iterator obtained from a list, even if it is the end iterator
    // - two iterators to the same location in the same list must
    //   compare equal
    // - two iterators to different locations in the same list must
    //   compare unequal
    // - comparing iterators obtained from different lists results in
    //   undefined behavior
    //   - Your implementation can handle this however you like, but
    //     don't assume any particular behavior in your test cases --
    //     comparing iterators from different lists essentially
    //     violates the REQURES clause.
    // Note: comparing both the list and node pointers should be
    // sufficient to meet these requirements.
      bool operator==(const Iterator& i) const{
        return node_ptr == i.node_ptr ;
      }
      
      bool operator!=(const Iterator& i) const{
          return !(i.node_ptr == node_ptr && list_ptr == i.list_ptr);
      }
      
      Iterator operator++(int /*dummy*/) { // postfix ++ (e.g. it++)
        Iterator copy = *this;
        operator++();
        return copy;
      }
      
      Iterator& operator++() { // prefix ++ (e.g. ++it)
          assert(list_ptr);
          if (node_ptr) {
            node_ptr = node_ptr->next;
          } else { // decrementing an end Iterator moves it to the last element
            node_ptr = list_ptr->first;
          }
          return *this;
      }
      Iterator& operator=(const Iterator i){
          node_ptr = i.node_ptr;
          list_ptr = i.list_ptr;
          return *this;
      }

      
      
    // Type aliases required to work with STL algorithms. Do not modify these.
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    // This operator will be used to test your code. Do not modify it.
    // REQUIRES: Iterator is decrementable. All iterators associated with a
    //           list are decrementable, including end iterators, except for
    //           begin iterators (those equal to begin() on the list)
    // EFFECTS:  moves this Iterator to point to the previous element
    //           and returns a reference to this Iterator
    Iterator& operator--() { // prefix -- (e.g. --it)
      assert(list_ptr);
      assert(*this != list_ptr->begin());
      if (node_ptr) {
        node_ptr = node_ptr->prev;
      } else { // decrementing an end Iterator moves it to the last element
        node_ptr = list_ptr->last;
      }
      return *this;
    }

    // This operator will be used to test your code. Do not modify it.
    // REQUIRES: Iterator is decrementable. All iterators associated with a
    //           list are decrementable, including end iterators, except for
    //           begin iterators (those equal to begin() on the list)
    // EFFECTS:  moves this Iterator to point to the previous element
    //           and returns a copy of the original Iterator
    Iterator operator--(int /*dummy*/) { // postfix -- (e.g. it--)
      Iterator copy = *this;
      operator--();
      return copy;
    }

    // REQUIRES: Iterator is dereferenceable
    // EFFECTS: returns the underlying element by pointer
    // NOTE: T must be a class type to use the syntax it->. If T has a
    //       member variable f, then it->f accesses f on the
    //       underlying T element.
    T* operator->() const {
        return &operator*();
    }
      
      T& operator*() const{
              return node_ptr->datum;
      }
      
     
  private:
    const List *list_ptr; //pointer to the List associated with this Iterator
    Node *node_ptr; //current Iterator position is a List node
    // add any additional necessary member variables here

    // add any friend declarations here
      friend class List;

    // construct an Iterator at a specific position in the given List
      Iterator(const List *lp, Node *np){
                list_ptr = lp;
                node_ptr = np;
                
      }

  };//List::Iterator
  ////////////////////////////////////////

  // return an Iterator pointing to the first element
    Iterator begin() const{
               
        return Iterator(this, first);
        
    }

  // return an Iterator pointing to "past the end"
    Iterator end() const{
       // Iterator i;
         /*    List const *ptr = &this;
            i.list_ptr = ptr;
            i.node_ptr = last->next;
            return i;
          */
        //return Iterator(this, last);
        return Iterator(this, nullptr);
    }
    
  //REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container.
  //         Returns An iterator pointing to the element that followed the
  //         element erased by the function call
    Iterator erase(Iterator i){
        Node *curr = i.node_ptr;
     if (curr == last){
         pop_back();
         return end();
     }else if(curr == first){
         pop_front();
         return begin();
     }else{
         Node* previous = curr->prev;
         Node* next1 = curr->next;
         previous->next = next1;
         next1->prev = previous;
         --num;
         delete curr;
         return Iterator(i.list_ptr, next1);
     }
    }

  //REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: Inserts datum before the element at the specified position.
  //         Returns an iterator to the the newly inserted element.
    Iterator insert(Iterator i, const T &datum){
        Node n = new Node;
        Node* a = &n;
        a->datum = datum;
        a->next = a->prev = nullptr;
        if(empty()){
            first = a;
            last = a;
            num++;
            return Iterator(this, a);
        }
        
        Node *b = i.node_ptr;
        if(b == first){
            push_front(datum);
        }else if(b == last->next){
            push_back(datum);
        }else{
            a->prev = b->prev;
            a->next = b;
            b->next->prev = a;
            b->prev = a;
            num++;
        }
        return Iterator(this, a);
    }

};//List



////////////////////////////////////////////////////////////////////////////////
// Add your member function implementations below or in the class above
// (your choice). Do not change the public interface of List, although you
// may add the Big Three if needed.  Do add the public member functions for
// Iterator.


#endif // Do not remove this. Write all your code above this line.
