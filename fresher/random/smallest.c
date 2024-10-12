#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char *smallest_number(int K) {
  int start = pow(10, K - 1);
  int end = pow(10, K) - 1;

  for (int i = start; i <= end; i++) {
    int sum = 0;
    int p = 1;
    int n = i;

    while (n) {
      int d = n % 10;
      n /= 10;
      sum += d;
      p *= d;
    }

    if (p >= sum) {
      char *out_ = (char *)malloc(20 * sizeof(char));
      sprintf(out_, "%d", i);
      return out_;
    }
  }

  return "";
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t_i = 0; t_i < T; t_i++) {
    int K;
    scanf("%d", &K);

    char *out_ = smallest_number(K);
    printf("%s\n", out_);

    free(out_);
  }
  return 0;
}