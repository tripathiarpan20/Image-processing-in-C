#include "matrixmath.h"

ppm* blur (ppm* A){
    ppm *ret = (ppm *) malloc(sizeof(ppm));
    ret->m = A->m - 1;
    ret->n = A->n - 1;
    ret->pxl = (pixel **)malloc(ret->m * sizeof(pixel *)); 
    for (int i=0; i< ret->m; i++) {
      ret->pxl[i] = (pixel *)malloc(ret->n * sizeof(pixel));
    }
    for (int i=0; i < ret->m; i++) {
      for(int j=0; j<ret->n; j++) {
        float avg_R=0.0;
	float avg_G=0.0;
	float avg_B=0.0;
	      
	avg_R = A->pxl[i][j].R + A->pxl[i][j+1].R + A->pxl[i+1][j].R + A->pxl[i+1][j+1].R;
	avg_G = A->pxl[i][j].G + A->pxl[i][j+1].G + A->pxl[i+1][j].G + A->pxl[i+1][j+1].G;
	avg_B = A->pxl[i][j].B + A->pxl[i][j+1].B + A->pxl[i+1][j].B + A->pxl[i+1][j+1].B;
	avg_R = avg_R / 4.0;
	avg_G = avg_G / 4.0;
	avg_B = avg_B / 4.0;
	
	ret->pxl[i][j].R = (int) avg_R;
	ret->pxl[i][j].G = (int) avg_G;
	ret->pxl[i][j].B = (int) avg_B;
        
      }
    }   

    return ret;
}


    //TODO: Blurring fuction exception if 'matrix' (resulted by grayscale) is
    //inputted (can't be done with function overloading, as only parameters
    // can be different, but not return types)
