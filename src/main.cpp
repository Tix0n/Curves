#include <omp.h>

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <memory>
#include <random>
#include <vector>

#include "./curves/circle.h"
#include "./curves/common_structures.h"
#include "./curves/ellipse.h"
#include "./curves/helixes.h"

std::vector<std::shared_ptr<Curve>> CreateContainer();
void OutputData(const std::vector<std::shared_ptr<Curve>>& curves, double t);
std::vector<std::shared_ptr<Circle>> FilterCircles(
    const std::vector<std::shared_ptr<Curve>>& curves);
double CalculateSumOfRadii(const std::vector<std::shared_ptr<Circle>>& circles);

int main() {
  // Populate a container of objects of these types created in random manner
  // with random parameters.
  std::vector<std::shared_ptr<Curve>> curves = CreateContainer();

  //  Print coordinates of points and derivatives.
  std::cout << "3 point" << std::endl;
  double t = M_PI / 4;
  OutputData(curves, t);

  //  Populate a second container that would contain only circles from the first
  //  container.
  std::vector<std::shared_ptr<Circle>> circles = FilterCircles(curves);

  // Sort container in the ascending order of circles’ radii.
  std::sort(
      circles.begin(), circles.end(),
      [](const std::shared_ptr<Circle>& a, const std::shared_ptr<Circle>& b) {
        return a->get_radius() < b->get_radius();
      });

  //  Calculating the total sum of radii using parallel calculations
  std::cout << "6 and 8 points" << std::endl;
  double sum_rad = CalculateSumOfRadii(circles);
  std::cout << "sum radius=" << sum_rad << std::endl;

  return 0;
}

std::vector<std::shared_ptr<Curve>> CreateContainer() {
  std::vector<std::shared_ptr<Curve>> curves;

  std::random_device rand;
  std::mt19937 gen(rand());

  std::uniform_int_distribution<int> num_curves_dist(1, 25);
  std::uniform_int_distribution<int> curve_type_dist(0, 2);
  std::uniform_real_distribution<double> radius_dist(1.0, 100.0);
  std::uniform_real_distribution<double> axis_dist(1.0, 100.0);
  std::uniform_real_distribution<double> vertical_step_dist(1.0, 100.0);

  int num_curves = num_curves_dist(gen);

  curves.reserve(num_curves);

  for (int i = 0; i < num_curves; i++) {
    int curve_type = curve_type_dist(gen);

    if (curve_type == 0) {
      double radius = radius_dist(gen);
      curves.push_back(std::make_shared<Circle>(radius));
    } else if (curve_type == 1) {
      double semi_major_axis = axis_dist(gen);
      double semi_minor_axis = axis_dist(gen);
      curves.push_back(
          std::make_shared<Ellipse>(semi_major_axis, semi_minor_axis));
    } else if (curve_type == 2) {
      double radius = radius_dist(gen);
      double vertical_step = vertical_step_dist(gen);
      curves.push_back(std::make_shared<Helixes>(radius, vertical_step));
    }
  }
  return curves;
}

void OutputData(const std::vector<std::shared_ptr<Curve>>& curves, double t) {
  for (const auto& figure : curves) {
    Vector3D point = figure->GetPoint(t);
    Vector3D derivative = figure->GetFirstDerivative(t);

    if (typeid(*figure) == typeid(Circle)) {
      std::cout << "Curve type: Circle\n";
    } else if (typeid(*figure) == typeid(Ellipse)) {
      std::cout << "Curve type: Ellipse\n";
    } else if (typeid(*figure) == typeid(Helixes)) {
      std::cout << "Curve type: Helixes\n";
    }

    std::cout << "Point: (" << point.get_x() << ", " << point.get_y() << ", "
              << point.get_z() << ")\n";
    std::cout << "Derivative: (" << derivative.get_x() << ", "
              << derivative.get_y() << ", " << derivative.get_z() << ")\n";

    std::cout << std::endl;
  }
}

std::vector<std::shared_ptr<Circle>> FilterCircles(
    const std::vector<std::shared_ptr<Curve>>& curves) {
  std::vector<std::shared_ptr<Circle>> circles;
  circles.reserve(curves.size() / 3);

  for (const auto& curve : curves) {
    if (auto circle = std::dynamic_pointer_cast<Circle>(curve)) {
      circles.push_back(circle);
    }
  }
  return circles;
}

double CalculateSumOfRadii(
    const std::vector<std::shared_ptr<Circle>>& circles) {
  double sum_rad = 0;

#pragma omp parallel for reduction(+ : sum_rad)
  for (std::size_t i = 0; i < circles.size(); i++) {
    sum_rad += circles[i]->get_radius();
  }

  return sum_rad;
}
