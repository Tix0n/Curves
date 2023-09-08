#ifndef SRC_COMMON_FUNCTIONS_H_
#define SRC_COMMON_FUNCTIONS_H_

#include "general_structures.h"

Vector3D CalculateCircleEllipseHelixePoint(double t, double x_coef,
                                           double y_coef, double z_coef);
Vector3D CalculateCircleEllipseHelixeDerivative(double t, double x_coef,
                                                double y_coef, double z_coef);

#endif  // SRC_COMMON_FUNCTIONS_H_
