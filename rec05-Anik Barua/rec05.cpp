/*
  Name: Anik Barua
  Date: 02-25-2022
  rec05.cpp
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Section{
     friend ostream& operator<<(ostream& os, const Section& section);
public:
     Section(const string& name, const string& day, int time) : name(name), time(day, time) {}
     
     //destructor
     ~Section() { 
          cout << "Section " << name << " is being deleted" << endl;
          for(size_t i = 0; i < record.size(); ++i){
               cout << "Delecting " << record[i]->getName() << endl;
               delete record[i]; 
          } 
     }
     // copy constructor
     Section(const Section& rhs) : name(rhs.name), time(rhs.time) {  
          for(size_t i = 0; i < rhs.record.size(); ++i){
               record.push_back(new StudentRecord(*rhs.record[i]));
          }
     }

     class TimeSlot{
          friend ostream& operator<<(ostream& os, const Section::TimeSlot& time);
          public:
          TimeSlot(const string& day, int time) : day(day), time(time) {}
          private:
          string day;
          int time;
     };
     
     class StudentRecord{
          friend ostream& operator<<(ostream& os, const Section::StudentRecord& record);
     public:
          StudentRecord(const string& name) : name(name), grades(14, -1){}
          void addGrade(int grade, int position){
               grades[position-1] = grade;
          }

          const string& getName() const {
               return name;
          }

     private:
          string name;
          vector<int> grades;
     };

     void addStudent(const string& studentName){
           record.push_back(new StudentRecord(studentName));
     }

     void addGrade(const string& name, int grade, int position){
          for(size_t i = 0; i < record.size(); ++i){
               if(name == record[i]->getName()){
                    record[i]->addGrade(grade, position);
               }
          }
     }

private:
     string name;
     TimeSlot time;
     vector<StudentRecord*> record;
};

class LabWorker{
     friend ostream& operator<<(ostream& os, const LabWorker& labworker);
     public:
     LabWorker(const string& name) : name(name), section(nullptr){}
     void addSection(Section& newSection){
          section = &newSection;
     }
     void addGrade(const string& name, int grade, int position){
          if(section != nullptr){
               section->addGrade(name, grade, position);
          }
     }

     private:
     string name;
     Section *section;
};


// Test code
void doNothing(Section sec) { cout << sec << endl; }

int main() {

    cout << "Test 1: Defining a section\n";
    Section secA2("A2", "Tuesday", 16);
    cout << secA2 << endl;

    cout << "\nTest 2: Adding students to a section\n";
    secA2.addStudent("John");
    secA2.addStudent("George");
    secA2.addStudent("Paul");
    secA2.addStudent("Ringo");
    cout << secA2 << endl;

    cout << "\nTest 3: Defining a lab worker.\n";
    LabWorker moe( "Moe" );
    cout << moe << endl;

    cout << "\nTest 4: Adding a section to a lab worker.\n";
    moe.addSection( secA2 );
    cout << moe << endl;

    cout << "\nTest 5: Adding a second section and lab worker.\n";
    LabWorker jane( "Jane" );
    Section secB3( "B3", "Thursday", 11 );
    secB3.addStudent("Thorin");
    secB3.addStudent("Dwalin");
    secB3.addStudent("Balin");
    secB3.addStudent("Kili");
    secB3.addStudent("Fili");
    secB3.addStudent("Dori");
    secB3.addStudent("Nori");
    secB3.addStudent("Ori");
    secB3.addStudent("Oin");
    secB3.addStudent("Gloin");
    secB3.addStudent("Bifur");
    secB3.addStudent("Bofur");
    secB3.addStudent("Bombur");
    jane.addSection( secB3 );
    cout << jane << endl;

    cout << "\nTest 6: Adding some grades for week one\n";
    moe.addGrade("John", 17, 1);  
    moe.addGrade("Paul", 19, 1);  
    moe.addGrade("George", 16, 1);  
    moe.addGrade("Ringo", 7, 1);  
    cout << moe << endl;

    cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
    moe.addGrade("John", 15, 3);  
    moe.addGrade("Paul", 20, 3);  
    moe.addGrade("Ringo", 0, 3);  
    moe.addGrade("George", 16, 3);  
    cout << moe << endl;

    cout << "\nTest 8: We're done (almost)! \nWhat should happen to all "
         << "those students (or rather their records?)\n";

    cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, "
         << "then make sure the following call works:\n";
    doNothing(secA2);
    cout << "Back from doNothing\n\n";

} // main

ostream& operator<<(ostream& os, const Section::StudentRecord& record){
     os << "Name: " << record.name << ", Grades: ";
     for(size_t i = 0; i < record.grades.size(); ++i){
          os << record.grades[i] << " ";
     }
     return os;
}

ostream& operator<<(ostream& os, const Section::TimeSlot& time){
     os << "Day: " << time.day << ", Start time: ";
     if(time.time > 12){
          os << time.time - 12 << "pm";
     } else {
          os << time.time << "am";
     }
     return os;
}

ostream& operator<<(ostream& os, const Section& section) { 
     os << "Section: " << section.name << ", Time slot: [" << section.time << "] Students: ";
     if(section.record.empty()){
          os << "None";
     } else {
          os << "\n";
          for(size_t i = 0; i < section.record.size(); ++i){
               os << *(section.record[i]) << endl;
          }
     }

    return os;
}

ostream& operator<<(ostream& os, const LabWorker& labworker){
     if(labworker.section == nullptr){
          os << labworker.name << " does not have a section" << endl;
     } else {
          os << labworker.name << " has " << *(labworker.section);
     }
     return os;
}
