#include "comparison.h"

static inline void writeToFile(const char* const name,const results_t* const results, unsigned int N){

  FILE *fd;

  fd = fopen(name, "w");

  unsigned int i= 0;

  for(;i<N; i++) fprintf(fd,"IT TOOK %lf TO SORT WITH CUTOFF AT %d \n", results[i].timeDiff, results[i].CUTOFF);

}

static inline int* generateArray(unsigned int N, unsigned int K){

  int* array = (int*)malloc(sizeof(int)*N);

  srand(time(NULL));

  for(auto unsigned int i = 0; i< N; i++)array[i] = rand()% K;

  return array;

}

int main(int argc, char** argv){

  if(argc != 3 ) return -1;

  unsigned int N = (unsigned int)atoi(argv[1]);

  unsigned int K = (unsigned int)atoi(argv[2]);

  int* array = generateArray(N,K);

  int* aux = (int*)calloc(N, sizeof(int));

  results_t* mergeSortResults =(results_t*)malloc(sizeof(results_t)*N);

  results_t* quickSortResults =(results_t*)malloc(sizeof(results_t)*N);

  results_t* results = (results_t*)malloc(sizeof(results_t));

  unsigned int i=0;

  clock_t t;

  int* tempArray;

  int* tempAux;

  for(;i< N; i++){

    tempArray = array;

    tempAux = aux;

    t = clock();

    msort(tempArray,tempAux, 0, N-1,i);

    t = clock() -t;

    double elapsedTime = ((double)t)/CLOCKS_PER_SEC;

    results->timeDiff = elapsedTime;

    results->CUTOFF = i;

    mergeSortResults[i] = *results;

  }

  i = 0;

  for(;i<N;i++){

    tempArray = array;

    t = clock();

    quicksort(tempArray,0, N-1, i);

    t = clock() - t;

    double elapsedTime = ((double)t)/CLOCKS_PER_SEC;

    results->timeDiff = elapsedTime;

    results->CUTOFF = i;

    quickSortResults[i] = *results;

  }

  writeToFile("mergeSortResults.txt",mergeSortResults, N);

  writeToFile("quickSortResults.txt",quickSortResults, N);

  free(array);

  free(aux);

  free(results);

  free(mergeSortResults);

  free(quickSortResults);

  return 0;

}
