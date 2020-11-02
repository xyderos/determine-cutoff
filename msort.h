#include "isort.h"

static inline void merge(int* arr, int* aux, int l, int m, int h){

  for (auto int i = l; i < h ; i++)aux[i] = arr[i];

  int i = l, j = m + 1;

  for(int k = l; k<= h; k++){

    if (i>m) arr[k] = aux[j++];

    else if(j > h) arr[k] = aux[i++];

    else if(less(aux[j], aux[i])) arr[k] = arr[j++];

    else arr[k] = aux[i++];
  }

}

static inline void msort(int* arr, int* aux, int l, int h, int c){

  if(h <= l + c){

    isort(arr, l, h);

    return;
  }

  int m = l + (h-l)/2;

  msort(arr,aux,l,m,c);

  msort(arr,aux,m+1,h,c);

  merge(arr,aux,l,m,h);

}
