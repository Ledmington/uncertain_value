#pragma once

#include <cstdint>
#include <memory>
#include <ostream>

class node {
   public:
	virtual void to_string(std::ostream& os, const std::string& indent,
						   const std::string& continuation_indent) const = 0;
};

class creation final : public node {
   public:
	creation(const double& value, const double& error);

	void to_string(std::ostream& os, const std::string& indent,
				   const std::string& continuation_indent) const override;

   private:
	double value_;
	double error_;
};

enum class double_children_node_type : std::uint8_t {
	PLUS,
	MINUS,
	TIMES,
	DIVIDE,
	PLUS_EQUALS,
	MINUS_EQUALS,
	TIMES_EQUALS,
	DIVIDE_EQUALS
};

std::ostream& operator<<(std::ostream& os,
						 const double_children_node_type& node_type);

template <double_children_node_type node_type>
class double_children_node final : public node {
   public:
	double_children_node(const std::shared_ptr<node>& lhs,
						 const std::shared_ptr<node>& rhs)
		: lhs_(lhs), rhs_(rhs) {}

	void to_string(std::ostream& os, const std::string& indent,
				   const std::string& continuation_indent) const override {
		os << indent << node_type << "\n";
		lhs_->to_string(os, continuation_indent + "├─",
						continuation_indent + "│ ");
		rhs_->to_string(os, continuation_indent + "└─",
						continuation_indent + "  ");
	}

   private:
	std::shared_ptr<node> lhs_;
	std::shared_ptr<node> rhs_;
};

class negate final : public node {
   public:
	negate(const std::shared_ptr<node>& inner);

	void to_string(std::ostream& os, const std::string& indent,
				   const std::string& continuation_indent) const override;

   private:
	std::shared_ptr<node> inner_;
};

class absolute_value final : public node {
   public:
	absolute_value(const std::shared_ptr<node>& inner);

	void to_string(std::ostream& os, const std::string& indent,
				   const std::string& continuation_indent) const override;

   private:
	std::shared_ptr<node> inner_;
};
