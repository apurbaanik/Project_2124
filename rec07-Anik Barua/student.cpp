#include "course.h"
#include "student.h"
using namespace std;

namespace BrooklynPoly {
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
}