#include "main.h"

ppm* blur (ppm* A){
    ppm *ret = (ppm *) malloc(sizeof(ppm));
    ret->m = A->m;
    ret->n = A->n;
    ret->A = (pixel **)malloc(ret->m * sizeof(pixel *)); 
    for (int i=0; i< ret->m; i++) {
      ret->A[i] = (pixel *)malloc(ret->n * sizeof(pixel));
    }
    for (int i=0; i < ret->m - 1; i++) {
      for(int j=0; j<ret->n - 1; j++) {
        int avg_R=0;
	int avg_G=0;
	int avg_B=0;
	for (int k=0; k < 2; k++) {
          for (int l=0; l < 2; l++) {
            avg_R += ret->A[i+k][j+l].R;
	    avg_G += ret->A[i+k][j+l].G;
	    avg_B += ret->A[i+k][j+l].B;
	  }
	}
	avg_R = avg_R / 4.0;
	avg_G = avg_G / 4.0;
	avg_B = avg_B / 4.0;
	
        for (int k=0; k < 2; k++) {
          for (int l=0; l < 2; l++) {
            ret->A[i+k][j+l].R = avg_R;
	    ret->A[i+k][j+l].G = avg_G;
	    ret->A[i+k][j+l].B = avg_B;
	  }
	}
      }
    }   

    return *ret;
}


    //TODO: Blurring fuction exception if 'matrix' (resulted by grayscale) is
    //inputted (can't be done with function overloading, as only parameters
    // can be different, but not return types)
