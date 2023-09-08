#include "general_structures.h"

Vector3D::Vector3D(double x, double y, double z) : x_(x), y_(y), z_(z) {}

double Vector3D::get_x() const { return x_; }
double Vector3D::get_y() const { return y_; }
double Vector3D::get_z() const { return z_; }
