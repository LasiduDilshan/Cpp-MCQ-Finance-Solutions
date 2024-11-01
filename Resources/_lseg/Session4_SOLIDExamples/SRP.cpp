// SRP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class  Student
{
private:
    int id;
    string name;
    int age;
    string email;
    int marks[9];

    string dburl;
    string emailpassword;
public:
    Student(int id, string name, int age, string email): id(id), name(name), age(age), email(email)
    {
        

    }
    string getName() { return name; }
    int getId() { return id;  }
    int getAge() { return age; }

    void save() {
        cout << "Save called" << endl;
        //create db connection
        //code to save to DB
    }

    void sendEmail(string toemail, string content)
    {
        cout << "Send email called" << endl;
        //create smtp connection
        //send email
    }
};

int main()
{
    Student student(1,"John",23, "john@gmail.com");

    student.save();
    student.sendEmail("warne@gmail.com", "Hi, How are you");

    
}

