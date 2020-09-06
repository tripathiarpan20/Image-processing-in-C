#include "ppm_util.h"
#include <string.h>


/* TODO
implement readPPM
implement 'main' files
Makefile

*/

ppm* readPPM (char* name)
{
  char str[16];
  ppm *img; FILE *fp;
  int c,max;
  
  fp = fopen(name,"rb");
  if(!fp){
	       fprintf(stderr,"Unable to open file\n");
	       exit(1);
         }
  fgets(str,sizeof(str),fp);
  if(str[0]!='P' || str[1]! = '3') 
  {
    fprintf(stderr,"invalid format\n, image is not p3");
  	}
 img = (ppm*)malloc(sizeof(ppm));
 c = getc(fp);
 while(c == '#')
 {
  while(getc(fp)!='\n');
  c = getc(fp);
  ungetc(c,fp);
  fscanf(fp,"%d %d",&img->m,&img->n);
  fscanf(fp,"%d",&max);
  while(fgetc(fp)!='\n');
  img->A = (pixel**)malloc(sizeof(pixel*)*img->m);
  for(int i =0;i< img->m; i++)
  {
   img->A+i = (pixel*)malloc(sizeof(pixel)*img->n);
  }
  
  for(int i =0;i< img->m; i++)
  {
   for(int j =0;j< img->n; j++)
   {
     fscanf(fp,"%d %d %d ",&img->A[i][j].R,&img->A[i][j].G,&img->A[i][j].B);
   }
  }
  
  fclose(fp);
  return img;
 }





























void writePPM(ppm *img, char* name){
    FILE *fp;

    //"output.ppm" for default
    char* filename = strcat(name,".ppm");
    char* out_folder = "../outputs/";
    
    //open a file for output
    fp = fopen(strcat(out_folder, filename),"wb");
    if(!fp){
        printf("Oops! Unable to open the file '%s' \n",filename);
        exit(1);
    }

    //write the header of the file
    //image format
    fprintf(fp,"P3\n");

    //image size
    fprintf(fp,"%d %d\n",img->m,img->n);

    //rgb color depth
    fprintf(fp,"%d\n",MAX_RGB_VALUE);

    //printing the pixel values
    for(int i = 0 ; i < img->m ; i++){
        for(int j = 0 ; j < img->n ; j++){
           fprintf(fp,"%d %d %d ",img->A[i][j].R,img->A[i][j].G,img->A[i][j].B);
        }
        fprintf(fp,"\n");
    }

    //fwrite(img->A,sizeof(pixel),3*img->m * img->n,fp);

    //closing the file
    fclose(fp);

}
