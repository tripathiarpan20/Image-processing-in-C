#include <stdlib.h>
#include <stdin.h>

typedef struct matrix_t{
  int m;
  int n;
  float **A;
}matrix;

/*
**A = (float **)malloc(m * sizeof(int *)); 
    for (i=0; i<m; i++) 
         arr[i] = (int *)malloc(n * sizeof(int));  

*/

/* using: https://github.com/libjpeg-turbo/libjpeg-turbo/blob/master/wrppm.c
   for reading jpeg into ppm format*/



//This is the ppm imagethat would be used by the transforms 
//Once jpeg has been read, it won't be overwritten by the program

matrix jpeg_to_ppm_input;

//This would be used after applying all the desired transforms on the ppm image
matrix final_output;


char** listof_transforms; //for the 'prepare' command, in order to allow the user to type in the transforms to be applied

/*
if multiple transforms are chosen, we have to apply them one after another, i.e, A--> B --> C, where
B is obtained by applying transform_1 on A and C is obtained by applying transform_2 on B.
In the main modules, we would have to loop through all the transforms in order to get the desired image,
hence, in the for loop (in main module, used to apply the transforms), after applying one transform,
we have to resassign input as the output, i.e,

PSEUDOCODE:

matrix jpeg_to_ppm_input{
for transform in transforms_list:
     *output = transform (jpeg_to_ppm_input);
     *jpeg_to_ppm_input = *output;
}

 */




//These would be used by the transforms modules in order to change the input images
//We declare these as pointers because it is possible to just 'point' to the 'jpeg_to_ppm_input'
// matrix and 'final_output' matrix;

matrix* mathlib_input;
matrix* mathlib_output;
