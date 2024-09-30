// Uncomment the following line to use your List implementation
#include "List.hpp"
#include "TextBuffer.hpp"


  // Comment out the following two lines and uncomment the two below
  // to use your List implementation
    //using CharList = List<char>;
    //using Iterator = List<char>::Iterator;
  using CharList = List<char>;
  using Iterator = List<char>::Iterator;


 

  // INVARIANT (cursor iterator):
  //   `cursor` points at an actual character in the list, or is
  //   at the past-the-end position (i.e. an end() iterator).

  // INVARIANT (row/column):
  //   `row` and `column` are the row and column numbers of the
  //   character the cursor is pointing at, determined by the
  //   placement of '\n' newline characters in the buffer.
  //   row is 1-indexed, whereas column is 0-indexed.

  // INVARIANT: (index)
  //   `index` is the 0-based index of the character the cursor is
  //   pointing at, or equal to the total number of characters in the
  //   list if the cursor is at the past-the-end position.
  //   0 <= index <= data.size()

  // The above invariants are established by the constructor and are
  // assumed to hold at the start of any member function call (i.e.
  // they are implicit conditions in the REQUIRES clause). Each function
  // must maintain these invariants (if they are temporarily broken, the
  // function must restore them before it returns).

  //EFFECTS: Creates an empty text buffer. Its cursor is at the past-the-end
  //         position, with row 1, column 0, and index 0.
    // TextBuffer::TextBuffer(){
    //     cursor = data.end();
    //     row = 1;
    //     column = 0;
    //     index = 0;
    // }

  //MODIFIES: *this
  //EFFECTS:  Moves the cursor one position forward and returns true,
  //          unless the cursor is already at the past-the-end position,
  //          in which case this does nothing and returns false.
  //NOTE:     Your implementation must update the row, column, and index
  //          if appropriate to maintain all invariants.
    bool TextBuffer::forward(){
        if(is_at_end() || cursor == data.end()){
            return false;
        }else{
            cursor++;
            if(*cursor == '\n'){
                row++;
                column = 0;
                
            }else{
                column++;
            }
            index++;
            return true;
        }
    }

  //MODIFIES: *this
  //EFFECTS:  Moves the cursor one position backward and returns true,
  //          unless the cursor is is already at the first character in
  //          the buffer, in which case this does nothing and returns false.
  //HINT:     Implement and use the private compute_column() member
  //          function to compute the column when moving left from the
  //          beginning of a line to the end of the previous one.
  //NOTE:     Your implementation must update the row, column, and index
  //          if appropriate to maintain all invariants.
bool TextBuffer::backward(){
    if(cursor == data.begin()){
        return false;
    }

    --cursor;
   // std::cout << *cursor << "cursor";
    if(*cursor == '\n'){
       // std::cout << "hi";
        --row;
        --index;
        
        column = compute_column();
        //std::cout << column;
        
        //std::cout<<column;
        
        return true;
    }else{
        --index;
        --column;
    }
    return true;
  //  if(cursor == data.begin()){
  //       return false;
  //   }

  //   --cursor;
  //  // std::cout << *cursor << "cursor";
  //   if(*cursor == '\n'){
  //      // std::cout << "hi";
  //       --row;
  //       --index;
  //       Iterator copy = cursor;
  //       --cursor;
  //       int oldColumn = column;
  //       //std::cout << column;
  //       column = compute_column();
  //       //std::cout << column;
  //       if(oldColumn > column){
  //           column = oldColumn;
  //       }
  //       //std::cout<<column;
  //       cursor = copy;
       
  //       return true;
  //   }else{
  //       --index;
  //       --column;
  //   }
  //   return true;
   }

  //MODIFIES: *this
  //EFFECTS:  Inserts a character in the buffer before the cursor position.
  //          If the cursor is at the past-the-end position, this means the
  //          inserted character is the last character in the buffer.
  //          The cursor remains in the same place as before the insertion.
  //NOTE:     Your implementation must update the row, column, and index
  //          if appropriate to maintain all invariants.
    void TextBuffer::insert(char c){
        
        if (c != '\n'){
            data.insert(cursor, c);
            column++;
            index++;
        }else{
            data.insert(cursor, c);
           
            row++;
            column = 0;
            index++;
        }
    }

  //MODIFIES: *this
  //EFFECTS:  Removes the character from the buffer that is at the cursor and
  //          returns true, unless the cursor is at the past-the-end position,
  //          in which case this does nothing and returns false.
  //          The cursor will now point to the character that was after the
  //          deleted character, or the past-the-end position if the deleted
  //          character was the last one in the buffer.
  //NOTE:     Your implementation must update the row, column, and index
  //          if appropriate to maintain all invariants.
    bool TextBuffer::remove(){
        if (cursor == data.end()){
             return false;
           }
           cursor = data.erase(cursor);
           return true;
    }



  //MODIFIES: *this
  //EFFECTS:  Moves the cursor to the start of the current row (column 0).
  //NOTE:     Your implementation must update the row, column, and index
  //          if appropriate to maintain all invariants.
void TextBuffer::move_to_row_start(){
    while(*cursor != '\n' && *cursor != data.front()){
        cursor--;
        column--;
        index--;
    }
    if(*cursor == '\n'){
      forward();
      index++;
      column++;
    }
     
    /*while(*cursor != '\n' && backward()){
    }
     */
        
}

  //MODIFIES: *this
  //EFFECTS:  Moves the cursor to the end of the current row (the
  //          newline character that ends the row, or the past-the-end
  //          position if the row is the last one in the buffer).
  //NOTE:     Your implementation must update the row, column, and index
  //          if appropriate to maintain all invariants.
    void TextBuffer::move_to_row_end(){
        while(*cursor != '\n' && *cursor != data.back()){
            cursor++;
            column++;
            index++;
        }
        // cursor++;
        // column++;
        // index++;
        
       
        
            }
    

  //REQUIRES: new_column >= 0
  //MODIFIES: *this
  //EFFECTS:  Moves the cursor to the given column in the current row,
  //          if it exists. If the row does not have that many columns,
  //          moves to the end of the row (the newline character that
  //          ends the row, or the past-the-end position if the row is
  //          the last one in the buffer).
  //NOTE:     Your implementation must update the row, column, and index
  //          if appropriate to maintain all invariants.
    void TextBuffer::move_to_column(int new_column){
        if(new_column - column> 0){
              while(column < new_column ){
                forward();
                if (column == 0){
                  backward();
                  return;
                }
              }
            }else{
              while(column > new_column ){
                backward();
              }
            }
    }

  //MODIFIES: *this
  //EFFECTS:  Moves the cursor to the previous row, retaining the
  //          current column if possible. If the previous row is
  //          shorter than the current column, moves to the end of the
  //          previous row (the newline character that ends the row).
  //          Does nothing if the cursor is already in the first row.
  //          Returns true if the position changed, or false if it did
  //          not (i.e. if the cursor was already in the first row).
  //NOTE:     Your implementation must update the row, column, and index
  //          if appropriate to maintain all invariants.
bool TextBuffer::up(){
    int curr = column;
    if(row == 1){
        return false;
    }
    backward();
    while(*cursor != '\n'){
        backward();
    }
    int newcol = compute_column();

    if(newcol < curr){
      return true;
    }else{
      while(newcol>curr){
        backward();
        newcol--;
      }
    }
    column = curr;
    return true;
}
   /*if(row == 1){
        return false;
    }
    --row;
    while(*cursor != '\n'){
        --cursor;
    }
    --cursor;
    if(column > compute_column()) {
        column = compute_column();
    }
    int col = column;
    --cursor;
    while(column!=col){
        --cursor;
        col--;
    }
     
        return false;
    
    }
    */

  //MODIFIES: *this
  //EFFECTS:  Moves the cursor to the next row, retaining the current
  //          column if possible. If the next row is shorter than the
  //          current column, moves to the end of the next row (the
  //          newline character that ends the row, or the past-the-end
  //          position if the row is the last one in the buffer). Does
  //          nothing if the cursor is already in the last row.
  //          Returns true if the position changed, or false if it did
  //          not (i.e. if the cursor was already in the last row).
  //NOTE:     Your implementation must update the row, column, and index
  //          if appropriate to maintain all invariants.
bool TextBuffer::down(){
    
    int counter = 1;
    for(Iterator it = data.begin(); it != data.end(); ++it){
        if(*it == '\n'){
            counter++;
        }
    }
    if(row == counter){
        return false;
    }
    ++row;
    while(*cursor != '\n'){
        ++cursor;
        ++column;
        ++index;
    }
    column = 0;
    ++cursor;
    ++index;
    while(*cursor != '\n' && cursor != data.end()){
        ++cursor;
        ++column;
        ++index;
    }
    
  //  --cursor;
    if(column > compute_column()){
        column = compute_column();
    }
   // int col = column;
    //for(int i = col - )
    return true;
}
   

    

  //EFFECTS:  Returns whether the cursor is at the past-the-end position.
    bool TextBuffer::is_at_end() const{
        //return(index == data.size());
        return cursor == data.end();
    }

  //REQUIRES: the cursor is not at the past-the-end position
  //EFFECTS:  Returns the character at the current cursor
    char TextBuffer::data_at_cursor() const{
        return *cursor;
    }

  //EFFECTS:  Returns the row of the character at the current cursor.
    int TextBuffer::get_row() const{
        return row;
    }

  //EFFECTS:  Returns the column of the character at the current cursor.
    int TextBuffer::get_column() const{
        return column;
    }

  //EFFECTS:  Returns the index of the character at the current cursor
  //          with respect to the entire contents. If the cursor is at
  //          the past-the-end position, returns size() as the index.
    int TextBuffer::get_index() const{
        if(is_at_end()){
            return index;
        }else{
            return size();
        }
    }

  //EFFECTS:  Returns the number of characters in the buffer.
    int TextBuffer::size() const{
        return static_cast<int>(data.size());
    }

  //EFFECTS:  Returns the contents of the text buffer as a string.
  //HINT: Implement this using the string constructor that takes a
  //      begin and end iterator. You may use this implementation:
  //        return std::string(data.begin(), data.end());
    std::string TextBuffer::stringify() const{
        return std::string(data.begin(), data.end());
    }

  //EFFECTS: Computes the column of the cursor within the current row.
  //NOTE: This does not assume that the "column" member variable has
  //      a correct value (i.e. the row/column INVARIANT can be broken).
int TextBuffer::compute_column() const{
  
    
     Iterator copy = cursor;
  int counter = 0;
  if(*copy == '\n'){
    copy--;
    if(*copy == '\n'){
        return 0;
    }
    counter++;
  }
  
  if(copy == data.end()){
    copy--;
    if(*copy == '\n'){
        return 0;
    }else{
        counter++;
    }
  }
  
  while(*copy != '\n' && copy != data.begin()){
    copy--;
    counter++;
  }
  if(copy == data.begin()){
    return counter;
  }
  return (counter-1);
    
}
// Iterator copy = cursor;
    //   int counter = 0;
    //   if(*copy == '\n'){
    //     copy--;
    //     if(*copy == '\n'){
    //         return 0;
    //     }
    //     counter++;
    //   }
      
    //   if(copy == data.end()){
    //     copy--;
    //     if(*copy == '\n'){
    //         return 0;
    //     }else{
    //         counter++;
    //     }
    //   }
      
    //   while(*copy != '\n' && copy != data.begin()){
    //     copy--;
    //     counter++;
    //   }
    // if(counter == 1 || counter == 0){
    //     return 0;
    // }
    //   return (++counter);


// #include <list>
// #include <string>
// // Uncomment the following line to use your List implementation
// #include "List.hpp"

// class TextBuffer {
//   // Comment out the following two lines and uncomment the two below
//   // to use your List implementation
// //   using CharList = std::list<char>;
// //   using Iterator = std::list<char>::iterator;
//   using CharList = List<char>;
//   using Iterator = List<char>::Iterator;

// private:
//   CharList data;           // linked list that contains the characters
//   Iterator cursor;         // iterator to current element in the list
//   int row;                 // current row
//   int column;              // current column
//   int index;               // current index

//   // INVARIANT (cursor iterator):
//   //   `cursor` points at an actual character in the list, or is
//   //   at the past-the-end position (i.e. an end() iterator).

//   // INVARIANT (row/column):
//   //   `row` and `column` are the row and column numbers of the
//   //   character the cursor is pointing at, determined by the
//   //   placement of '\n' newline characters in the buffer.
//   //   row is 1-indexed, whereas column is 0-indexed.

//   // INVARIANT: (index)
//   //   `index` is the 0-based index of the character the cursor is
//   //   pointing at, or equal to the total number of characters in the
//   //   list if the cursor is at the past-the-end position.
//   //   0 <= index <= data.size()

//   // The above invariants are established by the constructor and are
//   // assumed to hold at the start of any member function call (i.e.
//   // they are implicit conditions in the REQUIRES clause). Each function
//   // must maintain these invariants (if they are temporarily broken, the
//   // function must restore them before it returns).

// public:
//   //EFFECTS: Creates an empty text buffer. Its cursor is at the past-the-end
//   //         position, with row 1, column 0, and index 0.
//   TextBuffer() : row(1), column(0), index(0){}

//   //MODIFIES: *this
//   //EFFECTS:  Moves the cursor one position forward and returns true,
//   //          unless the cursor is already at the past-the-end position,
//   //          in which case this does nothing and returns false.
//   //NOTE:     Your implementation must update the row, column, and index
//   //          if appropriate to maintain all invariants.
//   bool forward(){
//     if(is_at_end()){
//             return false;
//         }else{
//             cursor++;
//             if(*cursor == '\n'){
//                 row++;
//                 column = 0;
//             }else{
//                 column++;
//             }
//             index++;
//             return true;
//         }
//   }

//   //MODIFIES: *this
//   //EFFECTS:  Moves the cursor one position backward and returns true,
//   //          unless the cursor is is already at the first character in
//   //          the buffer, in which case this does nothing and returns false.
//   //HINT:     Implement and use the private compute_column() member
//   //          function to compute the column when moving left from the
//   //          beginning of a line to the end of the previous one.
//   //NOTE:     Your implementation must update the row, column, and index
//   //          if appropriate to maintain all invariants.
//   bool backward(){
//     if(cursor == data.begin()){
//         return false;
//     }

//     --cursor;
//    // std::cout << *cursor << "cursor";
//     if(*cursor == '\n'){
//         --row;
//         --index;
//          column = compute_column();
//         return true;
//     }else{
//         --index;
//         --column;
//     }
//     return true;
//   }

//   //MODIFIES: *this
//   //EFFECTS:  Inserts a character in the buffer before the cursor position.
//   //          If the cursor is at the past-the-end position, this means the
//   //          inserted character is the last character in the buffer.
//   //          The cursor remains in the same place as before the insertion.
//   //NOTE:     Your implementation must update the row, column, and index
//   //          if appropriate to maintain all invariants.
//   void insert(char c){
//     Iterator i;
//     i = data.insert(cursor, c);
//     cursor = i;
//   }

//   //MODIFIES: *this
//   //EFFECTS:  Removes the character from the buffer that is at the cursor and
//   //          returns true, unless the cursor is at the past-the-end position,
//   //          in which case this does nothing and returns false.
//   //          The cursor will now point to the character that was after the
//   //          deleted character, or the past-the-end position if the deleted
//   //          character was the last one in the buffer.
//   //NOTE:     Your implementation must update the row, column, and index
//   //          if appropriate to maintain all invariants.
//   bool remove(){
//     if (cursor == data.end()){
//       return false;
//     }
//     cursor = data.erase(cursor);
//     return true;
//   }

//   //MODIFIES: *this
//   //EFFECTS:  Moves the cursor to the start of the current row (column 0).
//   //NOTE:     Your implementation must update the row, column, and index
//   //          if appropriate to maintain all invariants.
//   void move_to_row_start(){
//     for(int i = 0; i<column; i++){
//       backward();
//     }
//   }

//   //MODIFIES: *this
//   //EFFECTS:  Moves the cursor to the end of the current row (the
//   //          newline character that ends the row, or the past-the-end
//   //          position if the row is the last one in the buffer).
//   //NOTE:     Your implementation must update the row, column, and index
//   //          if appropriate to maintain all invariants.
//   void move_to_row_end(){
//     while (forward() && column != 0){
//     }
//     if (column == 0){
//       backward();
//     }
//   }

//   //REQUIRES: new_column >= 0
//   //MODIFIES: *this
//   //EFFECTS:  Moves the cursor to the given column in the current row,
//   //          if it exists. If the row does not have that many columns,
//   //          moves to the end of the row (the newline character that
//   //          ends the row, or the past-the-end position if the row is
//   //          the last one in the buffer).
//   //NOTE:     Your implementation must update the row, column, and index
//   //          if appropriate to maintain all invariants.
//   void move_to_column(int new_column){
//     if(new_column - column> 0){
//       while(column < new_column && forward()){
//       }
//     }else{
//       while(column > new_column && backward()){
//       }
//     }
//   }

//   //MODIFIES: *this
//   //EFFECTS:  Moves the cursor to the previous row, retaining the
//   //          current column if possible. If the previous row is
//   //          shorter than the current column, moves to the end of the
//   //          previous row (the newline character that ends the row).
//   //          Does nothing if the cursor is already in the first row.
//   //          Returns true if the position changed, or false if it did
//   //          not (i.e. if the cursor was already in the first row).
//   //NOTE:     Your implementation must update the row, column, and index
//   //          if appropriate to maintain all invariants.
//   bool up(){
//     int curr = column;
//     if(column == 0){
//       return false;
//     }
//     backward();
//     while(column != curr){
//       backward();
//     }
//     return true;
//   }

//   //MODIFIES: *this
//   //EFFECTS:  Moves the cursor to the next row, retaining the current
//   //          column if possible. If the next row is shorter than the
//   //          current column, moves to the end of the next row (the
//   //          newline character that ends the row, or the past-the-end
//   //          position if the row is the last one in the buffer). Does
//   //          nothing if the cursor is already in the last row.
//   //          Returns true if the position changed, or false if it did
//   //          not (i.e. if the cursor was already in the last row).
//   //NOTE:     Your implementation must update the row, column, and index
//   //          if appropriate to maintain all invariants.
//   bool down(){
//     int startcol = column;
//     int startrow = row;
//     while (forward() && row == startrow){
//     }
//     if (forward() == false){//in the last row
//       while(column != startcol){
//         backward();
//       }
//       return false;
//     }
//     while(column != startcol && column!=0){
//       forward();
//     }
//     if(column == 0){// next row is too short
//     backward();
//     }
//     return true;
//   }

//   //EFFECTS:  Returns whether the cursor is at the past-the-end position.
//   bool is_at_end() const{
//   return  (index == data.size());
//   }

//   //REQUIRES: the cursor is not at the past-the-end position
//   //EFFECTS:  Returns the character at the current cursor
//   char data_at_cursor() const{
//     return *cursor;
//   }

//   //EFFECTS:  Returns the row of the character at the current cursor.
//   int get_row() const{
//     return row;
//   }

//   //EFFECTS:  Returns the column of the character at the current cursor.
//   int get_column() const{
//     return column;
//   }

//   //EFFECTS:  Returns the index of the character at the current cursor
//   //          with respect to the entire contents. If the cursor is at
//   //          the past-the-end position, returns size() as the index.
//   int get_index() const{
//     return index;
//   }

//   //EFFECTS:  Returns the number of characters in the buffer.
//   int size() const{
//     return data.size();
//   }

//   //EFFECTS:  Returns the contents of the text buffer as a string.
//   //HINT: Implement this using the string constructor that takes a
//   //      begin and end iterator. You may use this implementation:
//   //        return std::string(data.begin(), data.end());
//   std::string stringify() const{
//     return std::string(data.begin(), data.end());
//   }

//   //EFFECTS: Computes the column of the cursor within the current row.
//   //NOTE: This does not assume that the "column" member variable has
//   //      a correct value (i.e. the row/column INVARIANT can be broken).
//   int compute_column() const{
//     Iterator copy = cursor;
//   int counter = 0;
//   if(*copy == '\n'){
//     copy--;
//     if(*copy == '\n'){
//         return 0;
//     }
//     counter++;
//   }
  
//   if(copy == data.end()){
//     copy--;
//     if(*copy == '\n'){
//         return 0;
//     }else{
//         counter++;
//     }
//   }
  
//   while(*copy != '\n' && copy != data.begin()){
//     copy--;
//     counter++;
//   }
//   return (counter);
//     //Iterator 
//   }
// };