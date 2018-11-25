#include <math.h>
#include <stdlib.h>

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

void print_triples(long long *triples) {

}

void print_triple(long long *triple) {

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
