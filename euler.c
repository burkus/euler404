#include <math.h>
#include <stdlib.h>
#include <stdio.h>

long long a(long long p, long long q) {
  return (
    (pow(q, 2) + p * q - pow(p, 2))
    *
    (pow(p, 2) + 4 * p * q - pow(q, 2))
  );
}

long long b(long long p, long long q) {
  return (
    (pow(p, 2) + pow(q, 2))
    *
    (pow(p, 2) + 4 * p * q - pow(q, 2))
  );
}

long long c(long long p, long long q) {
  return (
    2.0
    *
    (pow(p, 2) + pow(q, 2))
    *
    (pow(q, 2) + p * q - pow(p, 2))
  );
}

void print_triple(long long *triple) {
  long long a = triple[0], b = triple[1], c = triple[2];
  printf("\t\t(a, b, c) = (%lld, %lld, %lld)\n", a, b, c);
}

int triples_equal(long long *a, long long *b) {
  return(
    a[0] == b[0] && a[1] == b[1] && a[2] == b[2]
  );
}

void print_triples(long long **triples, long long count) {
  printf("\tTriples found:\n");
  int i = 0;
  while(i <= count) {
    print_triple(triples[i]);
    i++;
  }
}

long long* cons_triple(long long a, long long b, long long c) {
  long long *triple = (long long*) malloc(3 * sizeof(long long*));
  triple[0] = a;
  triple[1] = b;
  triple[2] = c;
  return triple;
}

long long* cons_duo(long long a, long long b) {
  long long *db = (long long*) malloc(2 * sizeof(long long*));
  db[0] = a;
  db[1] = b;
  return db;
}
