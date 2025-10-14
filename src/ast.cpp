#include <uncertain_value/ast.hpp>

#include <ostream>

creation::creation(const double& value, const double& error)
	: value_(value), error_(error) {}

void creation::to_string(std::ostream& os, const std::string& indent) const {
	os << indent << "creation ( " << value_ << " ± " << error_ << " )\n";
}

plus_equals::plus_equals(const node& base, const node& increment)
	: base_(base), increment_(increment) {}

void plus_equals::to_string(std::ostream& os, const std::string& indent) const {
	os << indent << "plus_equals\n";
	base_.to_string(os, indent + "├─");
	increment_.to_string(os, indent + "└─");
}
