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

    std::shared_ptr<Student> m_friend;
    // std::weak_ptr<Student> m_friend;
private:
	const std::string m_name;
};


int main()
{
    {
		std::shared_ptr<Student> studentA = std::make_shared<Student>("Student A");
		std::shared_ptr<Student> studentB = std::make_shared<Student>("Student B");
		
		std::cout << "reference count : studentA (" << studentA.use_count() << "), studentB (" << studentB.use_count() << ")" << std::endl;
		studentA->m_friend = studentB;
		studentB->m_friend = studentA;

		std::cout << "reference count : studentA (" << studentA.use_count() << "), studentB (" << studentB.use_count() << ")" << std::endl;
	}
    
	{
		std::weak_ptr<Student> student2;
		{
			std::shared_ptr<Student> student1 = std::make_shared<Student>("Student 1");
            std::cout << "reference count : student1 (" << student1.use_count() << "), student2 (" << student2.use_count() << ")" << std::endl;
			student2 = student1;
            std::cout << "reference count : student1 (" << student1.use_count() << "), student2 (" << student2.use_count() << ")" << std::endl;
            
 
		}

        if (student2.expired())
        {
            std::cout << "student2 weak_ptr is expired\n";
        }

        // std::shared_ptr<Student> student3 = std::make_shared<Student>("Student 3");
	}
	
	std::cin.get();
}
