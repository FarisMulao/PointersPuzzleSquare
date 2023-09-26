#include "puzzle.h"
#include <iostream>
using namespace std;

void Puzzle::create_grid(int r, int c) {
  rows = r;
  cols = c;
  symbols = new char* [r];
  for(int i = 0; i < r; i++){
    symbols[i] = new char[c];
  }
}

void Puzzle::delete_grid() {
  for(int i = 0; i < rows; i++){
    delete []symbols[i];
  }
  delete []symbols;
  symbols = nullptr;
}

void Puzzle::shift_row(int row, bool reverse) {
  char temp;
  int length = get_cols();
  if(reverse){
    temp = symbols[row][0];
    for(int j = 1; j < length; j++){
      symbols[row][j-1] = symbols[row][j];
    }
    symbols[row][length-1] = temp;
  }
  else{
    temp = symbols[row][length-1];
    for(int k = 1; k < length; k++){
      symbols[row][length-k] = symbols[row][length-k-1];
    }
    symbols[row][0] = temp;
  }
}


void Puzzle::shift_col(int col, bool reverse) {
  char temp;
  int length = get_rows(); 
  if(reverse){
    temp = symbols[0][col];
    for(int j = 1; j < length; j++){
      symbols[j-1][col] = symbols[j][col];
    }
    symbols[length-1][col] = temp;
  }
  else{
    temp = symbols[length-1][col];
    for(int k = 1; k < length; k++){
      symbols[length-k][col] = symbols[length-k-1][col];
    }
    symbols[0][col] = temp;
  }
}

void Puzzle::fill_grid() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> symbols[i][j];
    }
  }
}

void Puzzle::print_grid() const {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      cout << symbols[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}

const Puzzle &Puzzle::operator=(const Puzzle &rhs) {

  delete_grid();
  create_grid(rhs.rows, rhs.cols);
  for (int r = 0; r < rhs.rows; r++)
    for (int c = 0; c < rhs.cols; c++)
      symbols[r][c] = rhs.symbols[r][c];

  return *this;
}

Puzzle::Puzzle(const Puzzle &source) {
  symbols = nullptr;
  *this = source; 
}

Puzzle::~Puzzle() {
  if (symbols != nullptr)
    delete_grid();
}
