#include <uncertain_value/ast.hpp>

#include <ostream>

creation::creation(const double& value, const double& error)
	: value_(value), error_(error) {}

void creation::to_string(std::ostream& os, const std::string& indent,
						 const std::string&) const {
	os << indent << "creation ( " << value_ << " ± " << error_ << " )\n";
}

std::ostream& operator<<(std::ostream& os,
						 const double_children_node_type& node_type) {
	switch (node_type) {
		case double_children_node_type::PLUS:
			os << "plus";
			break;
		case double_children_node_type::MINUS:
			os << "minus";
			break;
		case double_children_node_type::TIMES:
			os << "times";
			break;
		case double_children_node_type::DIVIDE:
			os << "divide";
			break;
		case double_children_node_type::PLUS_EQUALS:
			os << "plus_equals";
			break;
		case double_children_node_type::MINUS_EQUALS:
			os << "minus_equals";
			break;
		case double_children_node_type::TIMES_EQUALS:
			os << "times_equals";
			break;
		case double_children_node_type::DIVIDE_EQUALS:
			os << "divide_equals";
			break;
	};
	return os;
}

negate::negate(const std::shared_ptr<node>& inner) : inner_(inner) {}

void negate::to_string(std::ostream& os, const std::string& indent,
					   const std::string& continuation_indent) const {
	inner_->to_string(os, continuation_indent + "┌─",
					  continuation_indent + "  ");
	os << indent << "negate\n";
}

absolute_value::absolute_value(const std::shared_ptr<node>& inner)
	: inner_(inner) {}

void absolute_value::to_string(std::ostream& os, const std::string& indent,
							   const std::string& continuation_indent) const {
	inner_->to_string(os, continuation_indent + "┌─",
					  continuation_indent + "  ");
	os << indent << "absolute_value\n";
}
