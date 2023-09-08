#ifndef SRC_CIRCLE_H_
#define SRC_CIRCLE_H_

#include "common_functions.h"
#include "general_structures.h"

class Circle : public Curve {
 public:
  Circle(double radius);
  Vector3D GetPoint(double t) const override;
  Vector3D GetFirstDerivative(double t) const override;

  double get_radius() const;
  void set_radius(double radius);

 private:
  double radius_;
};

#endif  // SRC_CIRCLE_H_
