#include "main.h"
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
  
  char name1[100];
  strcpy(name1,name);
  strcat(name1,".ppm");
  char fullname[100];
  strcpy(fullname,"inputs/");
  strcat(fullname,name1);
  printf("Filename for readPPM fopen is: %s\n",fullname);
 
  fp = fopen(fullname,"r");
  if(!fp){
	       fprintf(stderr,"Unable to open inputted ppm file\n");
	       exit(1);
         }
  fgets(str,sizeof(str),fp);
  if((str[0]!='P') || (str[1]!= '3'))
  {
    fprintf(stderr,"invalid format\n, image is not p3");
  	}
 img = (ppm*)malloc(sizeof(ppm));
 c = getc(fp);
 while(c == '#')
 {
  while(getc(fp)!='\n');
  c = getc(fp);
 }
  ungetc(c,fp);
  fscanf(fp,"%d %d",&img->m,&img->n);
  fscanf(fp,"%d",&max);
  
  while(fgetc(fp)!='\n');
  img->pxl = (pixel**)malloc(sizeof(pixel*)*img->m);
  for(int i =0;i< img->m; i++)
  {
   *(img->pxl +i) = (pixel*)malloc(sizeof(pixel)*img->n);
  }
 
  for(int i =0;i< img->m; i++)
  {
   for(int j =0;j< img->n; j++)
   {
     fscanf(fp,"%d %d %d ",&img->pxl[i][j].R,&img->pxl[i][j].G,&img->pxl[i][j].B);
   }
  }
  fclose(fp);
  printf("readPPM successful\n");
  return img;
}


void writePPM(ppm *img, char* name){
    FILE *fp;
    
    char filename[100];
    
    strcpy(filename,name);    
    strcat(filename,".ppm");
   
    char* out_folder = "outputs/";
    char fullname[100];
    strcpy(fullname,out_folder);
    strcat(fullname,filename);
    
     printf("Filename for writePPM fopen is: %s\n",fullname);
    fp = fopen(fullname,"w");
    
    if(!fp){
        printf("Unable to open file %s\n",name);
        exit(1);
    }
    fprintf(fp,"P3\n");
    fprintf(fp,"%d %d\n",img->m,img->n);    
    fprintf(fp,"%d\n",255);
    for(int i = 0 ; i < img->m ; i++){
        for(int j = 0 ; j < img->n ; j++){
           fprintf(fp,"%d %d %d ",img->pxl[i][j].R,img->pxl[i][j].G,img->pxl[i][j].B);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);   
    printf("writePPM successful\n");
}
