#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Student class definition
class Student {
private:
    int id;
    std::string name;
    int age;
    std::string course;

public:
    // Constructor
    Student(int id, std::string name, int age, std::string course)
        : id(id), name(name), age(age), course(course) {}

    // Getter and Setter methods
    int getId() { return id; }
    std::string getName() { return name; }
    int getAge() { return age; }
    std::string getCourse() { return course; }

    void setName(std::string name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    void setCourse(std::string course) { this->course = course; }

    // Display student information
    void display() {
        std::cout << "ID: " << id << ", Name: " << name
                  << ", Age: " << age << ", Course: " << course << std::endl;
    }
};

// StudentDatabase class definition
class StudentDatabase {
private:
    std::vector<Student> students;

public:
    // Add a new student
    void addStudent(Student student) {
        students.push_back(student);
    }

    // Display all students
    void displayAll() {
        for (auto& student : students) {
            student.display();
        }
    }

    // Search for a student by ID
    Student* searchById(int id) {
        for (auto& student : students) {
            if (student.getId() == id) {
                return &student;
            }
        }
        return nullptr;
    }

    // Update student information
    void updateStudent(int id, std::string name, int age, std::string course) {
        Student* student = searchById(id);
        if (student != nullptr) {
            student->setName(name);
            student->setAge(age);
            student->setCourse(course);
        } else {
            std::cout << "Student not found!" << std::endl;
        }
    }

    // Delete a student by ID
    void deleteStudent(int id) {
        students.erase(std::remove_if(students.begin(), students.end(),
            [id](Student& s) { return s.getId() == id; }),
            students.end());
    }
};

// Main function
int main() {
    StudentDatabase db;
    int choice, id, age;
    std::string name, course;

    while (true) {
        std::cout << "\nStudent Data Management System\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Display All Students\n";
        std::cout << "3. Search Student by ID\n";
        std::cout << "4. Update Student\n";
        std::cout << "5. Delete Student\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter ID: ";
            std::cin >> id;
            std::cout << "Enter Name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Enter Age: ";
            std::cin >> age;
            std::cout << "Enter Course: ";
            std::cin.ignore();
            std::getline(std::cin, course);
            db.addStudent(Student(id, name, age, course));
            break;
        case 2:
            db.displayAll();
            break;
        case 3:
            std::cout << "Enter ID: ";
            std::cin >> id;
            {
                Student* student = db.searchById(id);
                if (student != nullptr) {
                    student->display();
                } else {
                    std::cout << "Student not found!" << std::endl;
                }
            }
            break;
        case 4:
            std::cout << "Enter ID: ";
            std::cin >> id;
            std::cout << "Enter Name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Enter Age: ";
            std::cin >> age;
            std::cout << "Enter Course: ";
            std::cin.ignore();
            std::getline(std::cin, course);
            db.updateStudent(id, name, age, course);
            break;
        case 5:
            std::cout << "Enter ID: ";
            std::cin >> id;
            db.deleteStudent(id);
            break;
        case 6:
            std::cout << "Exiting...\n";
            return 0;
        default:
            std::cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
