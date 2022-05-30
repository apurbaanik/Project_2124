/*
    Name: Anik Barua
    Recitation: rec09.cpp
    Date: 04-01-2022
*/

#include <iostream>
#include <vector>
using namespace std;

class PrintedMaterial {
public:
    PrintedMaterial(unsigned number) : numberOfPages(number) {}
    //virtual void displayNumPages() const { cout << numberOfPages << endl; }
    virtual void displayNumPages() const = 0; //pure virtual
private:
    unsigned numberOfPages;
};

void PrintedMaterial::displayNumPages() const {
    cout << numberOfPages << endl;
}

class Magazine : public PrintedMaterial {
public:
    Magazine(unsigned number) : PrintedMaterial(number) {}
    void displayNumPages() const {
        cout << "Magazine object -\nNumber of pages: ";
        PrintedMaterial::displayNumPages();
        cout << "=====================================\n";
    }
private:
};

class Book : public PrintedMaterial {
public:
    Book(unsigned number) : PrintedMaterial(number) {}
private:
};

class TextBook : public Book {
public:
    TextBook(unsigned numPages, unsigned numIndxPgs) : Book(numPages), numOfIndexPages(numIndxPgs) {}
    void displayNumPages() const {
        cout << "TextBook object -\nPages: ";
        PrintedMaterial::displayNumPages();
        cout << "Index pages: ";
        cout << numOfIndexPages << endl;
        cout << "=====================================\n";
    }
private:
    unsigned numOfIndexPages;
};

class Novel : public Book {
public:
    Novel(unsigned number) : Book(number) {}
    void displayNumPages() const {
        cout << "Novel object -\nNumber of pages: ";
        PrintedMaterial::displayNumPages();
        cout << "=====================================\n";
    }
private:
};

// generic function
void displayNumberOfPages(const PrintedMaterial& material) {
    material.displayNumPages();
}

// tester/modeler code
int main() {
    TextBook text(5430, 23);
    Novel novel(213);
    Magazine mag(6);

    cout << "Using the dot member operator to display its number of pages:\n\n";
    text.displayNumPages();
    novel.displayNumPages();
    mag.displayNumPages();

    // Attempts to create objects that we don't want to be able to create (Abstract Class)
    /*
    cout << "\nA PrintedMaterial material object!\n";
    PrintedMaterial pm(2345);
    pm.displayNumPages();
    pm = text; // like putting a Textbook into a PrintedMaterial
    pm.displayNumPages();
    */

    cout << "\nUsing PrintedMaterial* to \"store\" a TextBook object\n";
    cout << "Now with the virtual mechanism involved\n\n";
    // should work now that the virtual mechanism is being invoked
    PrintedMaterial* pmPtr;
    pmPtr = &text; 
    pmPtr->displayNumPages();

    // print some stuff by calling a generic function
    cout << "\nUse a generic function for printing\n\n";
    displayNumberOfPages(mag);
    displayNumberOfPages(novel);
    displayNumberOfPages(text);

    // vector for all the createable objects
    cout << "\nNow we'll use a container. Yea!!!\n\n";
    vector<PrintedMaterial*> printedMaterials;
    printedMaterials.push_back(&text);
    printedMaterials.push_back(&novel);
    printedMaterials.push_back(&mag);

    for(size_t i = 0; i < printedMaterials.size(); ++i){
        printedMaterials[i]->displayNumPages();
        cout << "\n";
    }

    for(PrintedMaterial* printedMatPtr : printedMaterials){
        printedMatPtr->displayNumPages();
        cout << "\n";
    }
}