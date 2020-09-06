ppm* rgbtograyscale (ppm* A)
{
   int i,j,k;
   ppm *ret= (ppm *)malloc(sizeof(ppm));
     
   ret->m = A->m;
    
   ret->n = A->n;
     
   ret->pxl = (pixel **)malloc(ret->m * sizeof(pixel *));
   for(i=0;i<ret->m;i++)
   {
    ret->pxl[i] = (pixel*)malloc(ret->n*sizeof(pixel));
   }
     
   matrix P,Q,R;
     
   P  = (matrix)malloc(sizeof(struct matrix_t));
   Q  = (matrix)malloc(sizeof(struct matrix_t));
   P->m = 1;
   P->n = 3;
   Q->m = 3;
   Q->n = 3;

   P->A = (float**)malloc(sizeof(float*)*P->m);
   for(i=0;i<P->m;i++)
   {
     P->A[i] = (float*)malloc(sizeof(float)*P->n);
   }
    
   Q->A = (float**)malloc(sizeof(float*)*Q->m);
   for(i=0;i<Q->m;i++)
   {
     Q->A[i] = (float*)malloc(sizeof(float)*Q->n);
   }
   
   R = (matrix)malloc(sizeof(struct matrix_t));
   R->m = 1;
   R->n = 3;
   R->A = (float**)malloc(sizeof(float*)*R->m);
   for(i=0;i<R->m;i++)
   {
     R->A[i] = (float*)malloc(sizeof(float)*R->n);
   } 
   
   for(i =0;i<3;i++)
      Q->A[0][i]=0.3;
   for(i =0;i<3;i++)
      Q->A[1][i]=0.59;
   for(i =0;i<3;i++)
     Q->A[2][i]=0.11;
   
   for(i=0;i<A->m;i++)
   {
    for(j=0;j<A->n;j++)
    {
     
      P->A[0][0]= A->A[i][j].R;
      P->A[0][1]= A->A[i][j].G;
      P->A[0][2]= A->A[i][j].B;
      multiply(R,P,Q);
      ret->pxl[i][j].R = R->A[0][0];
      ret->pxl[i][j].G = R->A[0][1];
      ret->pxl[i][j].B = R->A[0][2];
     }
    }
    return ret;
  }
