// File:   sudokuCheck.cc
// Author: baavgai
//

// Created on November 21, 2007

//

// This offers one way to check for a valid sudoku board.


#include <stdlib.h>

#include <iostream>



//using namespace std;

// The position on the board

// it should be understood there every cell has three "paths" that it belongs

// to row, col, and box.  The value of that cell must be unique in all three

// paths, otherwise it's invalid.

struct BoardPos {

   int index;

   int row, col, box;

};

// calculate BoardPos for index, where index is 0..80

void loadBoardPosFromIndex(BoardPos &pos, int index) {

   pos.index = index;

   pos.row = index / 9;
   pos.col = index - (pos.row * 9);

   int boxRow = pos.row / 3;

   int boxCol = pos.col / 3;

   pos.box = (boxRow*3) + boxCol;

}
// if all values conform to sudoku rules, return true.
// note, the character string has character values for the numbers
// e.g. "32541"
bool isValid(char *puzzle) {
   BoardPos pos;
   // These track what we've already found.
   // For example, there are 9 rows, so rowTrack has 9 integers
   // each of those integers is considered a binary value 0000000000
   // so, if we find 3, we create a value 0000000100 and add it to our value
   // if we find 4, we create a value 000001000 and add it = 000001100
   // if we find 3 again, we create a value 000000100 and do a logical and
   // we already found a three, it's a bad sudoku
   int rowTrack[9], colTrack[9], boxTrack[9];
   for(int i=0; i<9; i++) { rowTrack[i] = colTrack[i] = boxTrack[i] = 0; }
   int index = 0;
   // this is a C string, if a value is true ASCII 0, we're at that end.
   while(*puzzle != 0) {
      // get the position for index: row, col, and box
      loadBoardPosFromIndex(pos, index);
      // our character value is ASCII, make an int from it.
      int value = (int)(*puzzle - '0');
      // we choose to igore invalid chars, don't forget to increment
      if (value<1 || value>9) {  index++; puzzle++; continue;  }
      // For testing, show what we have
      // printf("%d: (%d,%d)[%d]: %d\n", pos.index, pos.row, pos.col, pos.box, value);

      // make our bitmask
      int mask = 1 << value;
      // do an and on our tracker values, if it's not zero then
      // we've seen it before and should leave
      if ((rowTrack[pos.row] & mask)!=0) { return false; }
      if ((colTrack[pos.col] & mask)!=0) { return false; }
      if ((boxTrack[pos.box] & mask)!=0) { return false; }
      // made it this far, record the value in all paths
      rowTrack[pos.row] += mask;
      colTrack[pos.col] += mask;
      boxTrack[pos.box] += mask;
      // inc index and next char
      index++;
      puzzle++;
   }
   // if we made it where, and processed 81 numbers, it's good
   return (index==81);
}
int main(int argc, char** argv) {
   char *puzzle = "534678912672195348198342567859761423426853791713924856961537284287419635345286179";
   printf("%s\n", puzzle);
   if (isValid(puzzle)) {
      printf("Is Valid!\n");
   } else {
      printf("Is NOT Valid.\n");
   }
   return (EXIT_SUCCESS);
}
