#include "Category.h"

Category::Category(std::string name) : name(name) {}

std::string Category::getName() const {
    return name;
}
