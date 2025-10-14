#include <uncertain_value/nominal_uncertain_value.hpp>

#include <iomanip>
#include <iostream>

int main() {
	constexpr double base = 0.99;
	constexpr size_t exponent = 256;

	std::cout << "Computing " << base << " ^ " << exponent << "\n";
	std::cout << "\n";

	nominal_uncertain_value normal_result(1.0, 0.0);
	for (size_t i = 0; i < exponent; i++) {
		normal_result *= nominal_uncertain_value(base);
	}

	std::cout << "Normal exponentiation: " << std::setprecision(20)
			  << normal_result << "\n";

	nominal_uncertain_value fast_result(1.0, 0.0);
	{
		nominal_uncertain_value base_val(base);
		size_t exp = exponent;
		while (exp > 0) {
			if (exp % 2 == 1) {
				fast_result *= base_val;
			}
			base_val *= base_val;
			exp /= 2;
		}
	}

	std::cout << "Fast exponentiation  : " << std::setprecision(20)
			  << fast_result << "\n";

	std::cout << "std::pow()           : " << std::setprecision(20)
			  << std::pow(base, exponent) << "\n";

	return 0;
}