#include "registrar.h"
#include "course.h"
#include "student.h"

#include <string>
#include <iostream>
using namespace std;

namespace BrooklynPoly {
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
}