#include <uncertain_value/nominal_uncertain_value.hpp>

#include <iostream>

int main() {
	nominal_uncertain_value x(1.0, 1e-3);
	nominal_uncertain_value y(1.0, 1e-3);

	x += y;

	std::cout << x << "\n";
	std::cout << x.tree() << "\n";

	return 0;
}