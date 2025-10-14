#include <uncertain_value/nominal_uncertain_value.hpp>

#include <iomanip>
#include <iostream>
#include <vector>

template <typename T>
T sum(const std::vector<T>& v) {
	T s(0);
	for (size_t i = 0; i < v.size(); i++) {
		s += v[i];
	}
	return s;
}

template <typename T>
T stable_sum(const std::vector<T>& v) {
	// Kahan algorithm

	T s = 0;
	T c = 0;
	for (auto x : v) {
		const T y = x - c;
		const T t = s + y;
		c = (t - s) - y;
		s = t;
	}
	return s;
}

int main() {
	constexpr size_t N = 1000000;
	std::vector<nominal_uncertain_value> v(N, 1e-8);

	std::cout << "Standard sum: " << std::setprecision(20) << sum(v) << "\n";
	std::cout << "Stable sum  : " << std::setprecision(20) << stable_sum(v)
			  << "\n";
	std::cout << "Expected    : " << N * 1e-8 << "\n";

	return 0;
}
