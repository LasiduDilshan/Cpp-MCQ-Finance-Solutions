#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <list>
#include <memory>

class Employee
{
public:
	Employee() {}
	virtual ~Employee() {}

	virtual void calculateSalary() = 0;
};

class FullTimeEmployee : public Employee
{
public:
	FullTimeEmployee() {}
	virtual ~FullTimeEmployee() {}

	void calculateSalary() override /*final also available*/
	{
		std::cout << "FullTimeEmployee - Salary calculation logic" << std::endl;
	}
};

class PartTimeEmployee : public Employee
{
public:
	PartTimeEmployee() {}
	virtual ~PartTimeEmployee() {}

	void calculateSalary() override /*final also available*/
	{
		std::cout << "PartTimeEmployee - Salary calculation logic" << std::endl;
	}
};

class BaseEmployeeFactory 
{
public:
	virtual std::unique_ptr<Employee> createEmployee(std::string type) = 0;
};

class EmployeeFactory : public BaseEmployeeFactory
{
public:
	std::unique_ptr<Employee> createEmployee(std::string type) override
	{
		if (type == "FullTime")
		{
			return std::make_unique<FullTimeEmployee>();
		}
		else if (type == "PartTime")
		{
			return std::make_unique<PartTimeEmployee>();
		}
		else
		{
			std::cerr << "Unknown type" << std::endl;
			return nullptr;
		}
	}
};

int main()
{
	std::list<std::unique_ptr<Employee>> employees;
	std::unique_ptr<BaseEmployeeFactory> factory = std::make_unique<EmployeeFactory>();
	employees.push_back(std::move(factory->createEmployee("FullTime")));
	employees.push_back(std::move(factory->createEmployee("PartTime")));

	for (auto& employee : employees)
	{
		employee->calculateSalary();
	}

	std::cin.get();
}

