#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "euler.h"
#define LENGTH 512
#define DEFAULT_N 1024

// some of these are already taken by the
// math library, underscores fix it
double _alpha;
double _beta;
double _gamma;
double max_a;
double q_max;
double Estimate;
long n = 1000;
long **triples;
long **m;

long solve(long n) {
  long count = 0;
  for(long ell = 0; ell <= 500; ell++) {
    for(long k = 1; k < ell; k++) {
      long A = a(k, ell);
      long B = b(k, ell);
      long C = c(k, ell);
      if(A > 0 && A < n) {
        if(A < B && B < C && C < 2 * A) {
          triples[count] = cons_triple(A, B, C);
          m[count] = cons_duo(k, ell);
          count++;
        }
      }
    }
  }
  return count;
}

void init() {
  _alpha = 1 / (sqrt(5) + 2);
  _beta = (sqrt(5) + sqrt(2)) / (sqrt(5) + 2 * sqrt(2));
  _gamma = _beta - _alpha;
  max_a = 4.1029;
  q_max = pow( (n / max_a), 2 );
  Estimate = _gamma * pow(q_max, 2);
  triples = (long **) malloc(LENGTH * sizeof(long**));
  m = (long **) malloc(LENGTH * sizeof(long**));
}

int getCount(int argc, char **args) {
  if(argc > 0) {
    // takes N as CLI arg
    if(argc == 2) {
      long count = atoi(args[1]);
      if(count > 0) {
        return count;
      }
    }
  }
  return DEFAULT_N;
}

int main(int argc, char **argv) {
  init();
  long count = getCount(argc, argv);
  printf("Running solution for Euler 404...\n");
  printf("\tSize of N is %ld\n", count);
  count = solve(count);
  printf("\tNumber of triples found %ld\n", count);
  free(triples);
  free(m);
  return 0;
}
