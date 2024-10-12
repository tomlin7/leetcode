// for n = 5

// 0
// 1 2
// 3 4 5
// 6 7
// 8

#include <stdio.h>

int min(int a, int b) { return a < b ? a : b; }

int main() {
  int n, c = 0;

  printf("Enter n: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int l = min(i + 1, n - i);
    for (int j = 0; j < l; j++) {
      printf("%d ", c++);
    }
    printf("\n");
  }
}