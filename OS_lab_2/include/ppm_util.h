#include "main.h"

typedef struct Pixel{
  int R;
  int G;
  int B;
}pixel;

typedef struct ppm{
  int m;
  int n;
  pixel **img;
}ppm;
