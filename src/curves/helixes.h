#ifndef SRC_HELIXES_H_
#define SRC_HELIXES_H_

#include "common_functions.h"
#include "general_structures.h"

class Helixes : public Curve {
 public:
  Helixes(double radius, double verticalStep);
  Vector3D GetPoint(double t) const override;
  Vector3D GetFirstDerivative(double t) const override;

 private:
  double radius_, verticalStep_;
};

#endif  // SRC_HELIXES_H_
