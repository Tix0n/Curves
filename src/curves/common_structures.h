#ifndef SRC_COMMON_STRUCTURES_H_
#define SRC_COMMON_STRUCTURES_H_

class Vector3D {
 public:
  Vector3D(double x, double y, double z);

  double get_x() const;
  double get_y() const;
  double get_z() const;

 private:
  double x_;
  double y_;
  double z_;
};

class Curve {
 public:
  virtual ~Curve() {}
  virtual Vector3D GetPoint(double t) const = 0;
  virtual Vector3D GetFirstDerivative(double t) const = 0;

 protected:
  Vector3D CalculatePoint(double t, double x_coef, double y_coef,
                          double z_coef) const;
  Vector3D CalculateDerivative(double t, double x_coef, double y_coef,
                               double z_coef) const;
};
#endif  // SRC_COMMON_STRUCTURES_H_
