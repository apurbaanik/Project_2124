/*
  rec01_start.cpp
  spring 2022
  Anik Barua
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// Task 15. Function to display a vector of ints
void displayVector(const vector<int>& x){
  for (int read  : x) {
      cout << read << " ";
    }
    cout << "\n";
}

// Task 16. Function to modify the vector, using indices
void doubleValueVector(vector<int>& x){
  for (size_t i = 0; i < x.size(); ++i) {
      x[i] = x[i]*2;
    }
}

// Task 17. Function to modify the vector, using a ranged for
void doubleValueVector2(vector<int>& x){
    for (int& val : x) {
      val = val*2;
    }
}

//
// main
//
int main() { // Yes, it has to have an int for the return type
    //
    // Output
    //

    // Task 1. Printing hello ...  No use of "using namespace"
    std::cout << "Hello cs2124!\n";


    // Task 2  Printing hello ...  Using "using namespace"
    cout << "Hello cs2124!\n";

    //
    // Types and variables
    //

    // Task 3  Displaying uninitialized variable
    int x;
    cout << "x: " << x << endl;

    // Task 4 Use the sizeof function to see the size in bytes of
    //        different types on your machine.
    int y = 17;
    int z = 2000000017;
    double pie = 3.14159;

    cout << "sizeof(x): " << sizeof(x) << endl;
    cout << "sizeof(y): " << sizeof(y) << endl;
    cout << "sizeof(z): " << sizeof(z) << endl;
    cout << "sizeof(pie): " << sizeof(pie) << endl;

    // Task 5  Attempt to assign the wrong type of thing to a variable
    //x = “felix”; //Gives an Compilation error

    //
    // Conditions
    //

    // Task 6  Testing for a range
    if (y >= 10 && y <= 20) {
      cout << "Yes, y is between 10 and 20" << endl;
    } else {
      cout << "No, y is not between 10 and 20" << endl;
    }

    //
    // Loops and files
    //

    // Task 7  Looping, printing values 10 to 20 inclusive

    // First with a for loop
    for (size_t i = 10; i <= 20; ++i) {
      cout << i << ' ';
    } 
    cout << "\n";

    // Then with a while loop
    int num1 = 10;
    while (num1 <= 20){
      cout << num1 << ' ';
      ++num1;
    }
    cout << "\n";


    // Finally with a do-while loop
    int num2 = 10;
    do {
    cout << num2 << ' ';
    ++num2;
    } while (num2 <= 20);
    cout << "\n";

    // Task 8  Looping to successfully open a file, asking user for the name
    ifstream ifs;
    do {
    ifs.close();
    cout << "Filename? ";
    string value;
    cin >> value;
    ifs.open(value);
    } while(!ifs);

    // Task 9  Looping, reading file word by "word".
    string something;
    while (ifs >> something) {
      cout << something << endl; 
    }
    ifs.close();

    // Task 10 Open a file of integers, read it in, and display the sum.
    ifstream reader("integers.txt");
    if (!reader) {
      cerr << "Failed to open integers.txt)";
      exit(1);
    } 

    int integer;
    int sum = 0;
    while (reader >> integer) {
      sum = sum + integer;
    }
    reader.close();
    cout << "Sum : " << sum << endl;

    // Taks 11 Open and read a file of integers and words. Display the sum.
    ifstream reader2("mixed.txt");
    if (!reader2) {
      cerr << "Failed to open mixed.txt)";
      exit(1);
    } 

    int integer2;
    int sum2 = 0;
    while (reader2 >> integer2) {
      sum2 = sum2 + integer2;
    }
    reader2.close();
    cout << "Sum : " << sum2 << endl;

    //
    // Vectors
    //

    // Task 12 Filling a vector of ints
    vector<int> vectorOfInts;

    int evenInt = 10;

    while (evenInt <= 100){
      vectorOfInts.push_back(evenInt);
      evenInt = evenInt + 2;
    }

    // Task 13 Displaying the vector THREE times
    //         a) using the indices,
    for (size_t i = 0; i < vectorOfInts.size(); ++i) {
      cout << vectorOfInts[i] << " ";
    }
    cout << "\n";

    //         b) using a "ranged for"
    for (int read1  : vectorOfInts) {
      cout << read1 << " ";
    }
    cout << "\n";

    //         c) using indices again but backwards
    for (size_t i = vectorOfInts.size(); i > 0; --i) { 
      cout << vectorOfInts[i-1] << " ";
    }
    cout << "\n";

    // Task 14. Initialize a vector with the primes less than 20. 
    vector<int> vectorOfPrimes{2, 3, 5, 7, 11, 13, 17, 19};
    for (int read2  : vectorOfPrimes) {
      cout << read2 << " ";
    }
    cout << "\n";

    //
    // Functions
    //
    
    // Task 15  Function to print a vector
    displayVector(vectorOfPrimes);


    // Task 16  Function to double the values in a vector
    doubleValueVector(vectorOfPrimes);
    displayVector(vectorOfPrimes);

    // Task 17  Function to double the values in a vector, using a ranged for 
    doubleValueVector2(vectorOfPrimes);
    displayVector(vectorOfPrimes);
}
