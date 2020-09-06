#include "main.h"

ppm* blur (ppm* A){
    ppm *ret = (ppm *) malloc(sizeof(ppm));
    ret->m = A->m - 1;
    ret->n = A->n - 1;
    ret->pxl = (pixel **)malloc(ret->m * sizeof(pixel *)); 
    for (int i=0; i< ret->m; i++) {
      ret-pxl[i] = (pixel *)malloc(ret->n * sizeof(pixel));
    }
    for (int i=0; i < ret->m - 1; i++) {
      for(int j=0; j<ret->n - 1; j++) {
        float avg_R=0.0;
	float avg_G=0.0;
	float avg_B=0.0;
	      
	for (int k=0; k < 2; k++) {
          for (int l=0; l < 2; l++) {
            avg_R += ret->pxl[i+k][j+l].R;
	    avg_G += ret->pxl[i+k][j+l].G;
	    avg_B += ret->pxl[i+k][j+l].B;
	  }
	}
	avg_R = avg_R / 4.0;
	avg_G = avg_G / 4.0;
	avg_B = avg_B / 4.0;
	
	ret->pxl[i][j].R = avg_R;
	ret->pxl[i][j].G = avg_G;
	ret->pxl[i][j].B = abg_B;
        /*for (int k=0; k < 2; k++) {
          for (int l=0; l < 2; l++) {
            ret->pxl[i+k][j+l].R = avg_R;
	    ret->pxl[i+k][j+l].G = avg_G;
	    ret->pxl[i+k][j+l].B = avg_B;
	  }
	}*/
      }
    }   

    return ret;
}


    //TODO: Blurring fuction exception if 'matrix' (resulted by grayscale) is
    //inputted (can't be done with function overloading, as only parameters
    // can be different, but not return types)
