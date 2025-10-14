#pragma once

#include <cstdint>

enum class node_type : std::uint8_t {
	ASSIGNMENT
};

class node {
   public:
   private:
	node_type type_;
};
