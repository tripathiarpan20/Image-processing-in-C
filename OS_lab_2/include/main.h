#include <stdlib.h>
#include <stdin.h>

typedef struct Pixel{
  int R;
  int G;
  int B;
}pixel;

typedef struct ppm{
  int m;
  int n;
  int mag_num;
  //magic number, i.e, max possile value of any R,G,B from anypixel
  pixel **img;
}jpeg;

struct matrix_t {
  int m;
  int n;
  float **A;
};
typedef struct matrix_t * matrix;

/*
**A = (float **)malloc(m * sizeof(int *)); 
    for (i=0; i<m; i++) 
         arr[i] = (int *)malloc(n * sizeof(int));  
*/



/*Our transforms would take 'ppm' structure as input and give either 'ppm'
structure or 'matrix' structure as output (ppm for ops like blurring,
matrix for ops like grayscale conversion).*/

/*



char** listof_transforms; //for the 'prepare' command, in order to allow the user to type in the transforms to be applied

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




//The functions in 'mathlib.c' would take pointers to matrices as input and
//work on them.
