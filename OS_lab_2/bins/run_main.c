#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

void main() {
  FILE* inp_file;
  char input[30];
  char output[30];
  inp_file = fopen("inp.txt","rb");
  if(!inp_file){
	       fprintf(stderr,"There is no inp.txt file\n");
	       exit(1);
         }
  
  fscanf(inp_file,"%s\n",input);
  fscanf(inp_file,"%s\n",output);
  printf("Input ppm file name read by run_main from inp.txt is: %s\n",input);
  //make shell files that writes "input.ppm\noutput.ppm\n" into scan.txt
  //for default case, user input into scan.txt for prepare command

  
  //TODO: replace the function with 'func_name("../input/input.ppm")
  ppm* inp = readPPM(input);

  //TODO: In the "prepare_main.c", this "transforms" are is supposed to be
  //a double pointer that 
  char* transforms[] = {"grayscale" , "blur"};

  //TODO: implement a 'list transforms' command in make file that shows all
  //the files in transforms folder
  ppm* result = (ppm *) malloc(sizeof(ppm));
  
  printf("Beginning transformations\n");
  //looping through the transforms and applying on the image
  for (int i=0; i<2; i++) {
    if(strcmp(transforms[i],"grayscale") == 0) {
      ppm* result = rgbtograyscale(inp); //grayscale function by pavan
    }
    else if(strcmp(transforms[i],"blur")==0) {
      ppm* result = blur(inp); //blurring function by me
    }
    inp = result;
  }
  //The transform functions would have exceptions that occur for wrong inputs
  printf("Transforms successful\n");
  //Fuction to write a 'ppm' or 'matrix' structure into 'outputs/output.ppm'
  writePPM(inp,output);
  printf("Output ppm file by run_main is: %s\n",input);

}
