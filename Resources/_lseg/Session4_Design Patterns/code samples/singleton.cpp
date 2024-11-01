#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>

class Student
{
public:
	Student(const std::string& name) 
		: m_name(name)
	{
	}
	
	~Student() {}
private:
	const std::string m_name;
};

class StudentRegistry
{
public:
	static StudentRegistry& get() { return m_reg; }

	Student* find(const std::string name) { return nullptr; /*return student found*/ }
	void add(Student* student) {}

private:
	StudentRegistry() {}
	~StudentRegistry() {}

	static StudentRegistry m_reg;
};

StudentRegistry StudentRegistry::m_reg;

int main()
{
	auto& reg = StudentRegistry::get();
	auto student = reg.find("Student1");

	std::cin.get();
}
