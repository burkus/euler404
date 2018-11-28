#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
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
long long n = 1000;
long long **triples;
long long **m;

long long solve(long long n) {
  long long count = 0;
  for(long long ell = 0; ell <= 500; ell++) {
    for(long long k = 1; k < ell; k++) {
      long long A = a(k, ell);
      long long B = b(k, ell);
      long long C = c(k, ell);
      if(A > 0 && A < n) {
        if(A < B && B < C && C < 2 * A) {
          triples[count] = cons_triple(A, B, C);
          m[count] = cons_duo(k, ell);
          count++;
        }
      }
    }
  }
  triples[count] = cons_triple(0, 0, 0);
  return count;
}

void init() {
  _alpha = 1 / (sqrt(5) + 2);
  _beta = (sqrt(5) + sqrt(2)) / (sqrt(5) + 2 * sqrt(2));
  _gamma = _beta - _alpha;
  max_a = 4.1029;
  q_max = pow( (n / max_a), 2 );
  Estimate = _gamma * pow(q_max, 2);
  triples = (long long **) malloc(LENGTH * sizeof(long long**));
  m = (long long **) malloc(LENGTH * sizeof(long long**));
}

long long getCount(int argc, char **args) {
  if(argc > 0) {
    // takes N as CLI arg
    if(argc >= 2) {
      long long count = atoll(args[1]);
      if(count > 0) {
        return count;
      }
    }
  }
  return DEFAULT_N;
}

int getPrint(int argc, char **args) {
  if(argc == 3){
    if(strcmp(args[2], "-p") == 0) {
      return 1;
    }
  }
  return 0;
}

int main(int argc, char **argv) {
  init();
  long long count = getCount(argc, argv);
  int print = getPrint(argc, argv);
  printf("Running solution for Euler 404...\n");
  printf("\tSize of N is %lld\n", count);
  count = solve(count);
  printf("\tNumber of triples found %lld\n", count);
  if(print) {
    print_triples(triples, count);
  }
  free(triples);
  free(m);
  return 0;
}
