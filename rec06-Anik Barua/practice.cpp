#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int* ptr = new int(17);
delete ptr;

const vector<Person*>& vc;
string name;
while (reader >> name) {
    Person* p = new Person(name);
    vc[i].push_back(p); //vc[i] is a pointer so use the arrow operator
}

Vorlon(const string& aName) : myName(aName) {} // non primitive types

Copy gets called -
Vorlon v3(v1);
Vorlon v4 = v1;
void someFunc(Vorlon x) {} //pass by value
Vorlon anotherFunc() {
   Vorlon a; 
   return a; // returns by value
}

void simpleFunction (const Vorlon& fred) {
   fred.display();  // Compilation error.
}
so make the display const 
void display() const {cout << "Displaying a Vorlon named " << myName << endl;} // Finally, we did it right!!!

/////Copy control
class SimpleClass {
public:
    SimpleClass() { 
        p = new int(17); 
    }
private:
    int* p;
}; 

//destructor
~SimpleClass (delete p);

//copy constructor gets called when
1. SomeClass a;
   SomeClass b(a);
2. SomeClass a;
   SomeClass b = a;
3. void someFunc(SomeClass passedByValue) {}
4. SomeClass anotherFunc () { 
    SomeClass returnedByValue; 
    return returnedByValue;
     }

// takes constant reference
 SimpleClass(const SimpleClass& rhs) {
   p = new int;  // Allocate
   *p = *rhs.p;  // Initialize (well, actually "set").
 }

// copy assignment
== check for self-assignment.
1.get rid of things the object already has
2.replace them with new things
3. copy over the values from the object on the "right-hand side" to the "left-hand side".
== return the right thing

SimpleClass& operator=(const SimpleClass& rhs) {
    (this != &rhs){
        delete p; // Free up resources (as needed) delete what you have now
        p = new int; // Allocate new resources (as needed)
        *p = *rhs.p; // Copy over all data
    }
    return *this //return the derefernce
}

// pointer vector
// when you have vector of pointers
vector<Person*> stooges;

for (size_t i = 0; i < stooges.size(); ++i) {
	delete stooges[i];
}
stooges.clear();

//======================================================================
//Dynamic array
new int[10]

int* p = new int[10]

if it was to be an array of int pointers the our variable would be defined and initialized as:

int** p = new int*[10]

int* p = new int[10];
    delete [] p;

//======================================================================

//
Vector(const Vector& rhs) : size(rhs.size), capacity(rhs.capacity) {  // Work in progress
    data = new int[capacity];
    for(size_t i = 0; i < size; ++i){
        data[i] = rhs.data[i];
    }
}

Vector& operator=(const Vector& rhs) {
    if(this != &rhs){
        delete [] data;
        data = new int[rhs.capacity];
        for(size_t i = 0; i < size; ++i){
        data[i] = rhs.data[i];
        }
        size = rhs.size;
        capacity = rhs.capacity;
    }
    return *this;
}

// friend class
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

    return os; //return os 
}


const string& getName() const {
	return name;
 }

vs

void eating() const {
	cout << name << " eating\n";
    }

    // for const variable
    const int p = 8;
    int* x = &p; // compiler error
    use const int* x = &p;

    // constant item pointer needs to point at constant item
    // What kind of pointer can point at a constant item?
    const int z = 100;
    //z = 200; // not allowed, of course;
    const int* r = &z;
    //    *r = 100;

    // const pointers
    const int* p = &x; // p can only have 17 you cannot chnage 17 // you cannot chnage the value of p
    int* const q = &x; // you can chnage where q is pointing to but can chnage its actiual value

//getter
const string& getName() const { return name; }
int getValue() const { return *p; }
please return a non primitive reference 

(*rhs.spouse).name == rhs.spouse->name

Thing(int x){
    p = new int(x);
}
~Thing(){ delete p;}

Thing(const Thing& thing){
    p = new int(*thing.p);
}

// aThing.operator=(anotherThing);
Thing& operator=(const Thing& rhs){
    if(this != &thing){
        delete p;
        p = new int(*thing.p);
    }
    return *this;
}

Thing(int x, const string& foo) : foo(foo) { p = new int(x); }
~Thing(){ delete p;}
Thing(const Thing& rhs) : foo(rhs.foo) {
    p = new int(*rhs.p);
}
Thing& operator=(const Thing& rhs){
    if(this != &rhs){
        delete p;
        p = new int(*rhs.p);
        foo = rhs.foo;
    }
    return *this;
}

ostream& operator<<(ostream& os, const Thing& thing){
    os << thing.foo << ", " << *thing.p << endl;
    return os;
}


do nothing checks for your copy control exists or not  

vector//

Vector(cont Vector& vec): theSize(vec.theSize), theCapacity(vec.theCapacity){
    data = new int[theCapacity];
    for(size_t i = 0; i < theSize; i++){
        data[i] = vec.data[i];
    }
}

Vector& operator=(const Vector& rhs){
    if(this != &rhs){
        delete [] data; // data holds an array
        theSize = rhs.theSize;
        theCapacity = rhs.theCapacity;
        for(size_t i = 0; i < theSize; i++){
             data[i] = rhs.data[i];
        }
    }
    return *this;
}





/* struct Bike{
    string model;
    int cc;
};

int main(){
    int i = 2;
    int const &r = i;
    Bike bike;
    cout << bike.cc << endl;
} */
/*
struct Thing {
    vector<int> stuff;
};

void fill(ifstream& reader, vector<Thing>& things){
    int word;
     Thing vec;
    while(reader >> word){
        //cout << word << endl;
        for(size_t i = 0; i < 8; ++i){
            vec.stuff.push_back(word);
        }
        things.push_back(vec);
    }
}

/* 
int totalstuff(const vector<Thing>& things){
return 9;
} */

/*
int main(){
    ifstream ifs("things.txt");
    vector<Thing> things;
    fill(ifs, things);
    ifs.close();

    cout << things.size() << endl;

    for(size_t i = 0; i < things.size(); ++i){
        for(size_t j = 0; j < 8; ++j){
            things[i].stuff.at(j);
        }
    }
    
    //cout << "Total stuff:" << totalstuff(things) << endl;
}
*/