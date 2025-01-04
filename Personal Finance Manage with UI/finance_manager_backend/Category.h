#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>

class Category {
public:
    Category(std::string name = "Miscellaneous");
    std::string getName() const;

private:
    std::string name;
};

#endif // CATEGORY_H
