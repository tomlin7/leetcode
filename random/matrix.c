#include <stdio.h>

void printMatrix(int m, int n, int matrix[m][n]) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("\t|\t%d", matrix[i][j]);
    }
    printf("\t|\n");
  }
  printf("\n");
}

int main() {
  int m, n;

  printf("Enter the number of rows and columns: ");
  scanf("%d %d", &m, &n);

  int A[m][n], B[m][n];

  printf("Enter elements of the first matrix: \n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  printf("Enter elements of the second matrix: \n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &B[i][j]);
    }
  }

  printMatrix(m, n, A);
  printMatrix(m, n, B);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (A[i][j] != B[i][j]) {
        printf("Matrices are not equal\n");
        return 0;
      }
    }
  }

  printf("Matrices are equal\n");
  return 0;
}

// Enter the number of rows and columns: 3
// 3
// Enter elements of the first matrix:
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// Enter elements of the second matrix:
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
//         |       1       |       2       |       3       |
//         |       4       |       5       |       6       |
//         |       7       |       8       |       9       |

//         |       1       |       2       |       3       |
//         |       4       |       5       |       6       |
//         |       7       |       8       |       9       |

// Matrices are equal