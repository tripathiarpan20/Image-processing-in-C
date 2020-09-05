#include "main.h"

typedef struct Pixel{
  int R;
  int G;
  int B;
}pixel;

typedef struct ppm{
  int m;
  int n;
  pixel **A;
}ppm;

void writePPM (ppm img, char name[]);
ppm readPPM (char name[]);
