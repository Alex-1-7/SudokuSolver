#include <iostream>

void printgrid(int grid[9][9]) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j< 9; j++) {
      std::cout << grid[i][j] << " ";
    }
    std::cout << "\n";
  }
}

//Can j go in position (x,y)? x = row, y = column (starting from top left)
bool allowed (int grid[9][9], int x, int y, int j) {
  bool answer = true;

  //check row
  for (int i = 0; i < 9; i++) {
    if (grid[x][i] == j) {
      answer = false;
    }
  }

  //check column
  for (int i = 0; i < 9; i++) {
    if (grid[i][y] == j) {
      answer = false;
    }
  }

  //check local square
  while ((x % 3) != 0) {
    x --;
  }
  while ((y % 3) != 0) {
    y --;
  }
  for (int a = x; a < x + 3; a++) {
    for (int b = y; b < y + 3; b++) {
      if (grid[a][b] == j){
        answer = false;
      }
    }
  }
  return answer;
}

void solve(int grid[9][9]) {
  for (int i = 0; i < 9; i++){
    for (int j = 0; j < 9; j++) {
      if (grid[i][j] == 0) {
        for (int k = 1; k < 10; k++) {
          if (allowed(grid, i, j, k)) {
            grid[i][j] = k;
            solve(grid);
            grid[i][j] = 0;
          }
        }
        return;
      }
    }
  }
  printgrid(grid);
}

int main() {
  int grid[9][9] = {{8,0,1,0,0,0,0,5,2},
                    {6,0,4,0,0,9,0,1,0},
                    {2,0,0,0,1,4,9,0,0},
                    {0,0,2,4,7,0,1,0,0},
                    {0,6,0,0,9,0,0,3,0},
                    {0,0,8,0,3,2,5,0,0},
                    {0,0,7,2,5,0,0,0,4},
                    {0,2,0,7,0,0,3,0,1},
                    {3,4,0,0,0,0,7,0,5}};
  printgrid(grid);
  std::cout << "\n";
  solve(grid);
}
