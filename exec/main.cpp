#include <uncertain_value/nominal_uncertain_value.hpp>

#include <iostream>

int main() {
	nominal_uncertain_value a(1.0, 1e-3);
	nominal_uncertain_value b(2.0, 0.02);
	nominal_uncertain_value c(3.0, 0.02);
	nominal_uncertain_value d(4.0, 0.02);
	nominal_uncertain_value e(5.0, 0.02);
	nominal_uncertain_value f(6.0, 0.02);
	nominal_uncertain_value g(7.0, 0.02);

	nominal_uncertain_value x =
		(a + b) / (c - d) * (e + (a * b)) + 1.0 / (-f) - std::abs(g);

	std::cout << x << "\n";
	std::cout << x.tree() << "\n";

	return 0;
}