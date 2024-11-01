#include <iostream>
#include <string>
#include <memory>

class Student
{
public:
	Student(const std::string& name)
		: m_name(name)
	{
		std::cout << "Created Student: " << m_name << std::endl;
	}

	virtual ~Student()
	{
		std::cout << "Deleted Student: " << m_name << std::endl;
	}

	void print() 
    {
        std::cout << "This is " << m_name << std::endl;
    }

private:
	const std::string m_name;
};


int main()
{
	{
		std::shared_ptr<Student> student2;
		{
			std::shared_ptr<Student> student1 = std::make_shared<Student>("Student 1");
			std::cout << "reference count : student1 (" << student1.use_count() << "), student2 (" << student2.use_count() << ")" << std::endl;
			student2 = student1;
            std::cout << "reference count : student1 (" << student1.use_count() << "), student2 (" << student2.use_count() << ")" << std::endl;
		}
        student2->print();
        std::cout << "reference count : student2 (" << student2.use_count() << ")" << std::endl;
			
        std::shared_ptr<Student> student3 = std::make_shared<Student>("Student 3");
	}
	
	std::cin.get();
}
