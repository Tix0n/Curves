#ifndef SRC_ELLIPSE_H_
#define SRC_ELLIPSE_H_

#include "common_structures.h"

class Ellipse : public Curve {
 public:
  Ellipse(double semi_major_axis, double semi_minor_axis);
  Vector3D GetPoint(double t) const override;
  Vector3D GetFirstDerivative(double t) const override;

 private:
  double semi_major_axis_, semi_minor_axis_;
};

#endif  // SRC_ELLIPSE_H_
