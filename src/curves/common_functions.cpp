#include "common_functions.h"

#include <cmath>

Vector3D CalculateCircleEllipseHelixePoint(double t, double x_coef,
                                           double y_coef, double z_coef) {
  double x = x_coef * std::cos(t);
  double y = y_coef * std::sin(t);
  double z = z_coef * t / (2 * M_PI);
  return Vector3D(x, y, z);
}

Vector3D CalculateCircleEllipseHelixeDerivative(double t, double x_coef,
                                                double y_coef, double z_coef) {
  double dx_dt = -x_coef * std::sin(t);
  double dy_dt = y_coef * std::cos(t);
  double dz_dt = z_coef / (2 * M_PI);
  return Vector3D(dx_dt, dy_dt, dz_dt);
}
