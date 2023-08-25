#include "common_structures.h"

#include <cmath>

Vector3D::Vector3D(double x, double y, double z) : x_(x), y_(y), z_(z) {}

double Vector3D::get_x() const { return x_; }
double Vector3D::get_y() const { return y_; }
double Vector3D::get_z() const { return z_; }

Vector3D Curve::CalculatePoint(double t, double x_coef, double y_coef,
                               double z_coef) const {
  double x = x_coef * std::cos(t);
  double y = y_coef * std::sin(t);
  double z = z_coef * t / (2 * M_PI);
  return Vector3D(x, y, z);
}

Vector3D Curve::CalculateDerivative(double t, double x_coef, double y_coef,
                                    double z_coef) const {
  double dx_dt = -x_coef * std::sin(t);
  double dy_dt = y_coef * std::cos(t);
  double dz_dt = z_coef / (2 * M_PI);
  return Vector3D(dx_dt, dy_dt, dz_dt);
}
