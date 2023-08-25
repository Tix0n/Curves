#include "ellipse.h"

#include <cmath>

Ellipse::Ellipse(double semi_major_axis, double semi_minor_axis)
    : semi_major_axis_(semi_major_axis), semi_minor_axis_(semi_minor_axis) {}

Vector3D Ellipse::GetPoint(double t) const {
  return CalculatePoint(t, semi_major_axis_, semi_minor_axis_, 0.0);
}

Vector3D Ellipse::GetFirstDerivative(double t) const {
  return CalculateDerivative(t, semi_major_axis_, semi_minor_axis_, 0.0);
}
