#include "main.h"
#define MAX_RGB_VALUE 255

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

void writePPM (ppm img, char* name);
ppm readPPM (char* name);
