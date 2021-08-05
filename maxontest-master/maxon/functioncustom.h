#ifndef FUNCTIONCUSTOM_H
#define FUNCTIONCUSTOM_H

#include "math.h"

void
project_point_on_segment (double p[3],
                          double A[3],
                          double B[3],
                          double s[3]);


void
project_force_on_direction (double g[3],
                            double p[3],
                            double s[3],
                            double f[3]);


#endif // FUNCTIONCUSTOM_H
