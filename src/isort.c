#include "isort.h"

int less(int a, int b){

  return (a<b) ? 1 : 0 ;

}

void swap(int* a,int* b){

  int c = *a;

  *a = *b;

  *b = c;

}

void isort(int * arr, int l, int h){

  for(int i = l; i< h; i++){

    for(int j = i; j > l && less(arr[j], arr[j-1]); j-- )swap(&arr[j], &arr[j-1]);

  }

}
