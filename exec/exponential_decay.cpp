#include <uncertain_value/nominal_uncertain_value.hpp>

#include <iomanip>
#include <iostream>

int main() {
	constexpr double h = 1e-8;
	constexpr size_t max_iterations = 100'000'000;

	std::cout << "Solving y' = -y, y(0) = 1, y(1) = ?\n\n";

	{
		nominal_uncertain_value y(1.0);
		for (size_t i = 0; i < max_iterations; ++i) {
			y = y + h * (-y);
		}
		std::cout << "Numerically unstable method: " << std::setprecision(20)
				  << y << "\n";
	}

	{
		nominal_uncertain_value y(1.0);
		for (size_t i = 0; i < max_iterations; ++i) {
			y *= (1.0 - h);
		}
		std::cout << "Numerically stable method  : " << std::setprecision(20)
				  << y << "\n";
	}

	std::cout << "Expected                   : " << std::exp(-1) << "\n";

	return 0;
}