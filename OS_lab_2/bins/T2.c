#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

void main() {
  char input[30];
  char output[30];
  scanf("%s",input);
  scanf("%s",output);
  //make shell files that writes "input.ppm\noutput.ppm\n" into scan.txt
  //for default case, user input into scan.txt for prepare command

  
  //TODO: replace the function with 'func_name("../input/input.ppm")
  ppm* inp = readPPM(input);

  //TODO: In the "prepare_main.c", this "transforms" are is supposed to be
  //a double pointer that 
  char* transforms[] = ["blur"];

  //TODO: implement a 'list transforms' command in make file that shows all
  //the files in transforms folder
  ppm* result;
  //looping through the transforms and applying on the image
  for (int i=0; i<1; i++) {
    if(strcmpi(transforms[i],"grayscale") == 0) {
      ppm* result = //grayscale function by pavan
    }
    else if(strcmpi(transforms[i],"blur")==0) {
      ppm* result= //blurring function by me
    }
    inp = result;
  }
  //The transform functions would have exceptions that occur for wrong inputs
  
  //Fuction to write a 'ppm' or 'matrix' structure into 'outputs/output.ppm'
  writePPM(inp,output);


}
