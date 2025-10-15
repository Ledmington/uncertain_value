#pragma once

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

// TODO: refactor plus, minus, times and divide into a common node
class plus final : public node {
   public:
	plus(const std::shared_ptr<node>& lhs, const std::shared_ptr<node>& rhs);

	void to_string(std::ostream& os, const std::string& indent,
				   const std::string& continuation_indent) const override;

   private:
	std::shared_ptr<node> lhs_;
	std::shared_ptr<node> rhs_;
};

class minus final : public node {
   public:
	minus(const std::shared_ptr<node>& lhs, const std::shared_ptr<node>& rhs);

	void to_string(std::ostream& os, const std::string& indent,
				   const std::string& continuation_indent) const override;

   private:
	std::shared_ptr<node> lhs_;
	std::shared_ptr<node> rhs_;
};

class times final : public node {
   public:
	times(const std::shared_ptr<node>& lhs, const std::shared_ptr<node>& rhs);

	void to_string(std::ostream& os, const std::string& indent,
				   const std::string& continuation_indent) const override;

   private:
	std::shared_ptr<node> lhs_;
	std::shared_ptr<node> rhs_;
};

class divide final : public node {
   public:
	divide(const std::shared_ptr<node>& lhs, const std::shared_ptr<node>& rhs);

	void to_string(std::ostream& os, const std::string& indent,
				   const std::string& continuation_indent) const override;

   private:
	std::shared_ptr<node> lhs_;
	std::shared_ptr<node> rhs_;
};

// TODO: refactor all the XXX_equals classes into a common one
class plus_equals final : public node {
   public:
	plus_equals(const std::shared_ptr<node>& base,
				const std::shared_ptr<node>& increment);

	void to_string(std::ostream& os, const std::string& indent,
				   const std::string& continuation_indent) const override;

   private:
	std::shared_ptr<node> base_;
	std::shared_ptr<node> increment_;
};

class minus_equals final : public node {
   public:
	minus_equals(const std::shared_ptr<node>& base,
				 const std::shared_ptr<node>& increment);

	void to_string(std::ostream& os, const std::string& indent,
				   const std::string& continuation_indent) const override;

   private:
	std::shared_ptr<node> base_;
	std::shared_ptr<node> increment_;
};

class times_equals final : public node {
   public:
	times_equals(const std::shared_ptr<node>& base,
				 const std::shared_ptr<node>& increment);

	void to_string(std::ostream& os, const std::string& indent,
				   const std::string& continuation_indent) const override;

   private:
	std::shared_ptr<node> base_;
	std::shared_ptr<node> increment_;
};

class divide_equals final : public node {
   public:
	divide_equals(const std::shared_ptr<node>& base,
				  const std::shared_ptr<node>& increment);

	void to_string(std::ostream& os, const std::string& indent,
				   const std::string& continuation_indent) const override;

   private:
	std::shared_ptr<node> base_;
	std::shared_ptr<node> increment_;
};
