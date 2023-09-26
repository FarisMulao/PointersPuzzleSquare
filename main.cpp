#include "puzzle.h"
#include <iostream>
using namespace std;

int main() {
  int rows = 0;
  int cols = 0;
  int moves;
  int n;
  char direction;
  
  int puzzles; 
  cin >> puzzles;
  Puzzle puzzle; 

  for (int k = 0; k < puzzles; k++) {
    cin >> rows;
    cin >> cols;
    cin >> moves;
    puzzle.create_grid(rows,cols);
    puzzle.fill_grid();
    for(int i = 0; i < moves; i++){
      cin >> n;
      cin >> direction;
      switch(direction){
      case 'U':
        puzzle.shift_col(n, true);
        break;
      case 'D':
        puzzle.shift_col(n, false);
        break;
      case 'L':
        puzzle.shift_row(n, true);
        break;
      case 'R':
        puzzle.shift_row(n, false);
        break;
      }
    }
    puzzle.print_grid();
    puzzle.delete_grid();
  }

  return 0;
}