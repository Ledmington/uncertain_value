#include <uncertain_value/ast.hpp>

#include <ostream>

creation::creation(const double& value, const double& error)
	: value_(value), error_(error) {}

void creation::to_string(std::ostream& os, const std::string& indent,
						 const std::string&) const {
	os << indent << "creation ( " << value_ << " ± " << error_ << " )\n";
}

plus::plus(const std::shared_ptr<node>& lhs, const std::shared_ptr<node>& rhs)
	: lhs_(lhs), rhs_(rhs) {}

void plus::to_string(std::ostream& os, const std::string& indent,
					 const std::string& continuation_indent) const {
	os << indent << "plus\n";
	lhs_->to_string(os, continuation_indent + "├─", continuation_indent + "│ ");
	rhs_->to_string(os, continuation_indent + "└─", continuation_indent + "  ");
}

minus::minus(const std::shared_ptr<node>& lhs, const std::shared_ptr<node>& rhs)
	: lhs_(lhs), rhs_(rhs) {}

void minus::to_string(std::ostream& os, const std::string& indent,
					  const std::string& continuation_indent) const {
	os << indent << "minus\n";
	lhs_->to_string(os, continuation_indent + "├─", continuation_indent + "│ ");
	rhs_->to_string(os, continuation_indent + "└─", continuation_indent + "  ");
}

times::times(const std::shared_ptr<node>& lhs, const std::shared_ptr<node>& rhs)
	: lhs_(lhs), rhs_(rhs) {}

void times::to_string(std::ostream& os, const std::string& indent,
					  const std::string& continuation_indent) const {
	os << indent << "times\n";
	lhs_->to_string(os, continuation_indent + "├─", continuation_indent + "│ ");
	rhs_->to_string(os, continuation_indent + "└─", continuation_indent + "  ");
}

divide::divide(const std::shared_ptr<node>& lhs,
			   const std::shared_ptr<node>& rhs)
	: lhs_(lhs), rhs_(rhs) {}

void divide::to_string(std::ostream& os, const std::string& indent,
					   const std::string& continuation_indent) const {
	os << indent << "divide\n";
	lhs_->to_string(os, continuation_indent + "├─", continuation_indent + "│ ");
	rhs_->to_string(os, continuation_indent + "└─", continuation_indent + "  ");
}

plus_equals::plus_equals(const std::shared_ptr<node>& base,
						 const std::shared_ptr<node>& increment)
	: base_(base), increment_(increment) {}

void plus_equals::to_string(std::ostream& os, const std::string& indent,
							const std::string& continuation_indent) const {
	os << indent << "plus_equals\n";
	base_->to_string(os, continuation_indent + "├─",
					 continuation_indent + "│ ");
	increment_->to_string(os, continuation_indent + "└─",
						  continuation_indent + "  ");
}

minus_equals::minus_equals(const std::shared_ptr<node>& base,
						   const std::shared_ptr<node>& increment)
	: base_(base), increment_(increment) {}

void minus_equals::to_string(std::ostream& os, const std::string& indent,
							 const std::string& continuation_indent) const {
	os << indent << "minus_equals\n";
	base_->to_string(os, continuation_indent + "├─",
					 continuation_indent + "│ ");
	increment_->to_string(os, continuation_indent + "└─",
						  continuation_indent + "  ");
}

times_equals::times_equals(const std::shared_ptr<node>& base,
						   const std::shared_ptr<node>& increment)
	: base_(base), increment_(increment) {}

void times_equals::to_string(std::ostream& os, const std::string& indent,
							 const std::string& continuation_indent) const {
	os << indent << "times_equals\n";
	base_->to_string(os, continuation_indent + "├─",
					 continuation_indent + "│ ");
	increment_->to_string(os, continuation_indent + "└─",
						  continuation_indent + "  ");
}

divide_equals::divide_equals(const std::shared_ptr<node>& base,
							 const std::shared_ptr<node>& increment)
	: base_(base), increment_(increment) {}

void divide_equals::to_string(std::ostream& os, const std::string& indent,
							  const std::string& continuation_indent) const {
	os << indent << "divide_equals\n";
	base_->to_string(os, continuation_indent + "├─",
					 continuation_indent + "│ ");
	increment_->to_string(os, continuation_indent + "└─",
						  continuation_indent + "  ");
}

negate::negate(const std::shared_ptr<node>& inner) : inner_(inner) {}

void negate::to_string(std::ostream& os, const std::string& indent,
					   const std::string& continuation_indent) const {
	os << indent << "negate\n";
	inner_->to_string(os, continuation_indent + "└─",
					  continuation_indent + "  ");
}
