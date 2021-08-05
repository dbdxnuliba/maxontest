#include "functioncustom.h"


// Compute the projection of a point 'p' onto a segment
// defined by two points 'A' and 'B'.
//
// Projection is returned in point 's'.

void
project_point_on_segment (double p[3],
                          double A[3],
                          double B[3],
                          double s[3])
{
  double Ap[3];
  double AB[3];
  double dir[3];

  // compute relevant vectors
  for (int i=0; i<3; i++) {
    AB[i] = B[i] - A[i];
    Ap[i] = p[i] - A[i];
  }

  // compute segment norm, return if too small
  double norm = sqrt (AB[0]*AB[0] + AB[1]*AB[1] + AB[2]*AB[2]);
  if (norm <= 1e-6) {
    for (int i=0; i<3; i++) s[i] = p[i];
    return;
  }

  // compute segment direction unit vector
  for (int i=0; i<3; i++) dir[i] = AB[i] / norm;

  // compute projection ratio
  double proj = Ap[0]*dir[0] + Ap[1]*dir[1] + Ap[2]*dir[2];

  // compute point projection on segment
  if      (proj < 0.0)  for (int i=0; i<3; i++) s[i] = A[i];
  else if (proj > norm) for (int i=0; i<3; i++) s[i] = B[i];
  else                  for (int i=0; i<3; i++) s[i] = A[i]+proj*dir[i];
}



// compute the projection of a force 'g' onto a direction
// defined by two points 'p' and 's'.
//
// Projection is returned in force 'f'.

void
project_force_on_direction (double g[3],
                            double p[3],
                            double s[3],
                            double f[3])
{
  double ps[3];
  double dir[3];

  // compute unit direction vector, return if norm is too small
  for (int i=0; i<3; i++) ps[i] = s[i] - p[i];
  double norm = sqrt (ps[0]*ps[0] + ps[1]*ps[1] + ps[2]*ps[2]);
  if (norm < 1e-6) {
    for (int i=0; i<3; i++) f[i] = 0.0;
    return;
  }
  for (int i=0; i<3; i++) dir[i] = ps[i]/norm;

  // compute force projection
  double proj = g[0]*dir[0] + g[1]*dir[1] + g[2]*dir[2];
  for (int i=0; i<3; i++) f[i] = proj * dir[i];
}

