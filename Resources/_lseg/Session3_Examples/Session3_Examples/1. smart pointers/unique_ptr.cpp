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
        std::unique_ptr<Student> student1 = std::make_unique<Student>("Student 1");
        
        {
            std::unique_ptr<Student> student2 = std::make_unique<Student>("Student 2");
        }

		student1->print();
        // std::unique_ptr<Student> student3 = student1; // not allowed
        
        
        // std::unique_ptr<Student> student3 = std::move(student1);

        // if (student1.get() == nullptr)
        // {
        //     std::cout << "student1 is null" << std::endl;
        // }
        // student3->print();
    }
	
	std::cin.get();
}
