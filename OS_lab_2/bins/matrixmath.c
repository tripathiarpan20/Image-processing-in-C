#include <stdio.h>
#include <stdlib.h>
#include "matrixmath.h"
//We'll define '-I' parameter of gcc command as the 'include' folder



int multiply (matrix P, matrix A, matrix B){
  if (A->n != B->m) {
    printf("Dimensions of input matrices don't match:\n");
    printf("Dimensions of A = (%d,%d)\nDimension of B = (%d,%d)",A->m,A->n,B->m,B->n);
    return -1;
  }

  else if (P == NULL || P->A == NULL) {
    //matrix** backup = &P;
    //P = (matrix*) malloc(sizeof(matrix));
    //*backup = P;
    
    P->m = A->m;
    P->n = B->n;
    P->A = (float **)malloc(P->m * sizeof(float *)); 
    for (int i=0; i< P->m; i++) {
         P->A[i] = (float *)malloc(P->n * sizeof(float));
    }
    printf("%d\n",P->m);
    printf("%d\n",P->n);
  }
  
  int sum;
  for (int c = 0 ; c < A->m ; c++ ){
     for (int d = 0 ; d < B->n ; d++ ){
       for (int k = 0 ; k < A->n ; k++ ){
          sum = sum + A->A[c][k] * B->A[k][d];
       }
       P->A[c][d] = sum;
       sum = 0;
     }
  }
  return 0;
}

int dot (matrix P, matrix A, matrix B){
  if (A->m != B->m || A->n != B->n) {
    printf("Dimensions of input matrices don't match:\n");
    printf("Dimensions of A = (%d,%d)\nDimension of B = (%d,%d)",A->m,A->n,B->m,B->n);
    return -1;
  }

  P->m = 1;
  P->n = 1;
  P->A = (float **)malloc(P->m * sizeof(float *)); 
  for (int i=0; i<P->m; i++) {
      P->A[i] = (float *)malloc(P->n * sizeof(float));
  }

  for (int c = 0 ; c < A->m ; c++ ){
     for (int d = 0 ; d < A->n ; d++ ){
       P->A[0][0] += A->A[c][d] * B->A[c][d];
     }
  }
  return 0;
}

int elementwise_mul (matrix P, matrix A, matrix B){
  if (A->m != B->m || A->n != B->n) {
    printf("Dimensions of input matrices don't match:\n");
    printf("Dimensions of A = (%d,%d)\nDimension of B = (%d,%d)",A->m,A->n,B->m,B->n);
    return -1;
  }

  else if (P == NULL || P->A == NULL) {
    //P = (matrix*) malloc(sizeof(matrix));
    P->m = A->m;
    P->n = B->n;
    P->A = (float **)malloc(P->m * sizeof(float *)); 
    for (int i=0; i< P->m; i++) {
         P->A[i] = (float *)malloc(P->n * sizeof(float));
    }
  }

  for (int c = 0 ; c < A->m ; c++ ){
     for (int d = 0 ; d < A->n ; d++ ){
       P->A[c][d] = A->A[c][d] * B->A[c][d];
     }
  }
  return 0;
}

int transpose (matrix P, matrix A) {
  if (P == NULL || P->A == NULL) {
    //P = (matrix*) malloc(sizeof(matrix));
    P->m = A->n;
    P->n = A->m;
    P->A = (float **)malloc(P->m * sizeof(float *)); 
    for (int i=0; i< P->m; i++) {
    	P->A[i] = (float *)malloc(P->n * sizeof(float));
    }
  }
  
  for (int c = 0 ; c < A->m ; c++ ){
     for (int d = 0 ; d < A->n ; d++ ){
       P->A[d][c] = A->A[c][d];
     }
  }
  return 0;
}

int covariance_mat (matrix P, matrix A){
  if (A->m != 1) {
    printf("The input matrix must be of dimension 1 x n\n");
    printf("Dimensions of input matrix = (%d,%d)",A->m,A->n);
    return -1;
  }
  matrix B = (matrix) malloc(sizeof(struct matrix_t));
  transpose(B, A);
  
  P->m = A->m;
  P->n = B->n;
  P->A = (float **)malloc(P->m * sizeof(float *)); 
  for (int i=0; i< P->m; i++) {
       P->A[i] = (float *)malloc(P->n * sizeof(float));
  }
  multiply(P, A, B);
  return 0;
}
