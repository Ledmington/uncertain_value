#pragma once

#include <ostream>

class node {
   public:
	virtual void to_string(std::ostream& os,
						   const std::string& indent) const = 0;
};

class creation : public node {
   public:
	creation(const double& value, const double& error);

	void to_string(std::ostream& os, const std::string& indent) const override;

   private:
	double value_;
	double error_;
};

class plus_equals : public node {
   public:
	plus_equals(const node& base, const node& increment);

	void to_string(std::ostream& os, const std::string& indent) const override;

   private:
	const node& base_;
	const node& increment_;
};
