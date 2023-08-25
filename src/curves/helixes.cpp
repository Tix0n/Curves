#include "helixes.h"

#include <cmath>

Helixes::Helixes(double radius, double verticalStep)
    : radius_(radius), verticalStep_(verticalStep) {}

Vector3D Helixes::GetPoint(double t) const {
  return CalculatePoint(t, radius_, radius_, verticalStep_);
}

Vector3D Helixes::GetFirstDerivative(double t) const {
  return CalculateDerivative(t, radius_, radius_, verticalStep_);
}
