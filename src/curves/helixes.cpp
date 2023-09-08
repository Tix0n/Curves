#include "helixes.h"

#include <cmath>

Helixes::Helixes(double radius, double verticalStep)
    : radius_(radius), verticalStep_(verticalStep) {}

Vector3D Helixes::GetPoint(double t) const {
  return CalculateCircleEllipseHelixePoint(t, radius_, radius_, verticalStep_);
}

Vector3D Helixes::GetFirstDerivative(double t) const {
  return CalculateCircleEllipseHelixeDerivative(t, radius_, radius_,
                                                verticalStep_);
}
