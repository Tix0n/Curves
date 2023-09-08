#include "circle.h"

#include <cmath>

Circle::Circle(double radius) : radius_(radius) {}

Vector3D Circle::GetPoint(double t) const {
  return CalculateCircleEllipseHelixePoint(t, radius_, radius_, 0.0);
}

Vector3D Circle::GetFirstDerivative(double t) const {
  return CalculateCircleEllipseHelixeDerivative(t, radius_, radius_, 0.0);
}

double Circle::get_radius() const { return radius_; }

void Circle::set_radius(double radius) { radius_ = radius; }
