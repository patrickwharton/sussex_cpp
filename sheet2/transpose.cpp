#include <iostream>


void swapr(double *a, double *b) {
  double temp = *a;
  *a = *b;
  *b = temp;
}

void transpose(double my_matrix[][3], int i=3) {
  for (int a = 0; a < i; a++) {
    for (int b = 0; b < 3 && b < a; b++) {
      swapr(&my_matrix[a][b], &my_matrix[b][a]);
    }
  }
}

void printm(double my_matrix[][3]) {
  // prints a 3x3 matrix
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3 ; j++) {
      std::cout << my_matrix[i][j] << '\t';
    }
    std::cout << '\n';
  }
}

int main(int argc, char const *argv[]) {
  double M[3][3] = {{0.36, 0.48, -0.8}, {-0.8, 0.6, 0.0}, {0.48, 0.64, 0.6}};
  // printm(M);
  transpose(M);
  printm(M);
  return 0;
}
