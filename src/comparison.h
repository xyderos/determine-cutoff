#include "qsort.h"
#include "msort.h"
#include <time.h>

typedef struct __res {

  int CUTOFF;

  double timeDiff;

}results_t;

static inline int* generateArray(unsigned int, unsigned int);

static inline void writeToFile(const char* const,const results_t* const, unsigned int);

