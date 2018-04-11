#ifndef DEFAULTS_H_
#define DEFAULTS_H_

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define ERROR(x) if (errno != 0) { perror(x); return EXIT_FAILURE; }

#define DATA_PATH_PREFIX "/home/niklas/programming/c++/eclipse-workspace/cKompaktKurs/src/data/"

#endif /* DEFAULTS_H_ */
