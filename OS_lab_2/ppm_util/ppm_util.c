void writePPM(matrix img, char name[]){
    FILE *fp;

    //"output.ppm" for default
    char* filename = name;

    //open a file for output
    fp = fopen(filename,"wb");
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
