#include <math.h>
#include <stdlib.h>

int a(int p, int q) {
  return (
    (pow(q, 2) + p * q - pow(p, 2))
    *
    (pow(p, 2) + 4 * p * q - pow(q, 2))
  );
}

int b(int p, int q) {
  return (
    (pow(p, 2) + pow(q, 2))
    *
    (pow(p, 2) + 4 * p * q - pow(q, 2))
  );
}

int c(int p, int q) {
  return (
    2.0
    *
    (pow(p, 2) + pow(q, 2))
    *
    (pow(q, 2) + p * q - pow(p, 2))
  );
}

void print_triples(long *triples) {

}

void print_triple(long *triple) {

}

long* cons_triple(int a, int b, int c) {
  long *triple = (long*) malloc(3 * sizeof(long*));
  triple[0] = a;
  triple[1] = b;
  triple[2] = c;
  return triple;
}

long* cons_duo(int a, int b) {
  long *db = (long*) malloc(2 * sizeof(long*));
  db[0] = a;
  db[1] = b;
  return db;
}
