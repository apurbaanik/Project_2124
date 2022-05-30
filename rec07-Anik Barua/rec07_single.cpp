/*
  Name: Anik Barua
  rec07_starter.cpp
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student;

class Course {
    friend ostream& operator<<(ostream& os, const Course& rhs);
public:
    // Course methods needed by Registrar
    Course(const string& courseName);
    const string& getName() const;
    bool addStudent(Student* student);
    void removeStudentsFromCourse(); 
private:
    string name;
    vector<Student*> students;
};

class Student {
    friend ostream& operator<<(ostream& os, const Student& rhs);
public:
    // Student methods needed by Registrar
    Student(const string& name);
    const string& getName() const;
    bool addCourse(Course*);
    // Student method needed by Course
    void removedFromCourse(Course*);

private:
    string name;
    vector<Course*> courses;
};

class Registrar {
    friend ostream& operator<<(ostream& os, const Registrar& rhs);
public:
    Registrar();
    bool addCourse(const string& course);
    bool addStudent(const string& student);
    bool enrollStudentInCourse(const string& studentName, const string& courseName);
    bool cancelCourse(const string& courseName);
    void purge();

private:
    size_t findStudent(const string&) const;
    size_t findCourse(const string&) const;

    vector<Course*> courses;
    vector<Student*> students;
};

int main() {

    Registrar registrar;

    cout << "No courses or students added yet\n";
    cout << registrar << endl;
     
    cout << "AddCourse CS101.001\n";
    registrar.addCourse("CS101.001");
    cout << registrar << endl;

    cout << "AddStudent FritzTheCat\n";
    registrar.addStudent("FritzTheCat");
    cout << registrar << endl;

    cout << "AddCourse CS102.001\n";
    registrar.addCourse("CS102.001");
    cout << registrar << endl;

    cout << "EnrollStudentInCourse FritzTheCat CS102.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS102.001");
    cout << "EnrollStudentInCourse FritzTheCat CS101.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS101.001");
    cout << registrar << endl;

    cout << "EnrollStudentInCourse Bullwinkle CS101.001\n";
    cout << "Should fail, i.e. do nothing, "
         << "since Bullwinkle is not a student.\n";
    registrar.enrollStudentInCourse("Bullwinkle", "CS101.001");
    cout << registrar << endl;

    cout << "CancelCourse CS102.001\n";
    registrar.cancelCourse("CS102.001");
    cout << registrar << endl;
   
    /*
    // [OPTIONAL - do later if time]
    cout << "ChangeStudentName FritzTheCat MightyMouse\n";
    registrar.changeStudentName("FritzTheCat", "MightyMouse");
    cout << registrar << endl;  

    cout << "DropStudentFromCourse MightyMouse CS101.001\n";
    registrar.dropStudentFromCourse("MightyMouse", "CS101.001");
    cout << registrar << endl;  

    cout << "RemoveStudent FritzTheCat\n";
    registrar.removeStudent("FritzTheCat");
    cout << registrar << endl;  
    */

    cout << "Purge for start of next semester\n";
    registrar.purge();
    cout << registrar << endl;
}

// Student
Student::Student(const string& name): name(name){}

const string& Student::getName() const {
    return name;
}
bool Student::addCourse(Course* course){
    for(size_t i = 0; i < this->courses.size(); ++i){
        if(this->courses[i] == course){
            return false;
        }
    }
    courses.push_back(course);
    return true;
}

void Student::removedFromCourse(Course* course){
    for(size_t i = 0; i < courses.size(); ++i){
        if(course == courses[i]){
            for (size_t index = i; index < courses.size() - 1; ++index) 
            {
                courses[index] = courses[index + 1];
            }
            courses.pop_back(); //removing it from the vector
            break;
        }
    }
}

ostream& operator<<(ostream& os, const Student& rhs){
    os << rhs.name << ": ";
    if(rhs.courses.size() > 0){
        for(size_t i = 0; i < rhs.courses.size(); ++i){
            os << rhs.courses[i]->getName() << " ";
        }
    } else {
         cout << "No Courses";
    }
    return os;
}

// Course 
Course::Course(const string& courseName): name(courseName){}

const string& Course::getName() const{
    return name;
}

bool Course::addStudent(Student* student){
    for(size_t i = 0; i < students.size(); ++i){
        if(students[i] == student){
            return false;
        }
    }
    students.push_back(student);
    return true;
}

void Course::removeStudentsFromCourse(){
    for(size_t i = 0; i < students.size(); ++i){
        students[i]->removedFromCourse(this);
    }
}

ostream& operator<<(ostream& os, const Course& rhs){
    os << rhs.name << ": ";
    if(rhs.students.size() > 0){
        for(size_t i = 0; i < rhs.students.size(); ++i){
            os << rhs.students[i]->getName() << " ";
        }
    } else {
        cout << "No Students";
    }
    return os;
}

// Registrar
Registrar::Registrar(){}

bool Registrar::addCourse(const string& course){
    size_t courseLocation = findCourse(course);
    if(courseLocation == courses.size()){
        Course* myCourse = new Course(course);
        courses.push_back(myCourse);
        return true;
    }
    return false;
}

bool Registrar::addStudent(const string& student){
    size_t studentLocation = findStudent(student);
    if(studentLocation == students.size()){
        Student* myStudent = new Student(student);
        students.push_back(myStudent);
        return true;
    }
    return false;
}

bool Registrar::enrollStudentInCourse(const string& studentName, const string& courseName){
    size_t studentLocation = findStudent(studentName);
    size_t courseLocation = findCourse(courseName);
    if(studentLocation == students.size() || courseLocation == courses.size()){
        return false;
    }
    courses[courseLocation]->addStudent(students[studentLocation]);
    students[studentLocation]->addCourse(courses[courseLocation]);
    return true;
}

bool Registrar::cancelCourse(const string& courseName){
    size_t courseLocation = findCourse(courseName);
    if(courseLocation == courses.size()){
        return false;
    }
    courses[courseLocation]->removeStudentsFromCourse();
    delete courses[courseLocation];

    for (size_t index = courseLocation; index < courses.size()-1; ++index) 
    {
        courses[index] = courses[index + 1];
    }
    courses.pop_back();

     return true;
}

void Registrar::purge(){
    for(size_t i = 0; i < students.size(); ++i){
        delete students[i];
    }
    for(size_t j = 0; j < courses.size(); ++j){
        delete courses[j];
    }
    courses.clear();
    students.clear();
}

size_t Registrar::findStudent(const string& name) const{
    for(size_t i = 0; i < students.size(); ++i){
        if(name == students[i]->getName()){
            return i;
        }
    }
    return students.size();
}

size_t Registrar::findCourse(const string& course) const{
    for(size_t i = 0; i < courses.size(); ++i){
        if(course == courses[i]->getName()){
            return i;
        }
    }
    return courses.size();
}

ostream& operator<<(ostream& os, const Registrar& rhs){
    os << "Registrar's Report" << endl;
    os << "Courses: " << endl;
    if(rhs.courses.size() > 0){
        for(size_t i = 0; i < rhs.courses.size(); ++i){
            os << *rhs.courses[i] << endl;
        }
    }
    os << "Students:" << endl;
    if(rhs.students.size() > 0){
        for(size_t i = 0; i < rhs.students.size(); ++i){
            os << *rhs.students[i] << endl;
        }
    }
    return os;
}