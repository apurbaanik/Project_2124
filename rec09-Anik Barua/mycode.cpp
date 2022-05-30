#include <iostream>
using namespace std;

class PrintedMaterial {
public:
    PrintedMaterial(unsigned numPages) : numOfPages(numPages) {}
    //virtual void displayNumPages() const { cout << numOfPages << endl; }
    virtual void displayNumPages() const = 0;
private:
    unsigned numOfPages;
};

void PrintedMaterial::displayNumPages() const {
    cout << numOfPages << endl;
}

class Magazine : public PrintedMaterial {
public:
    Magazine(unsigned numPages) : PrintedMaterial(numPages) {}
    void displayNumPages() const {
        cout << PrintedMaterial::displayNumPages() << endl;
    }
private:
};

class Book : public PrintedMaterial {
public:
    Book(unsigned numPages) : PrintedMaterial(numPages) {}
    void displayNumPages() const {
        cout << PrintedMaterial::displayNumPages() << endl;
    }
private:
};

class TextBook : public Book {
public:
    TextBook(unsigned numPages, unsigned numIndxPgs) : Book(numPages), numOfIndexPages(numIndxPgs)
    {}
    void displayNumPages() const {
	    cout << "Pages: ";
	    PrintedMaterial::displayNumPages();
	    cout << "Index pages: ";
	    cout << numOfIndexPages << endl; 
    }
private:
    unsigned numOfIndexPages;
};

class Novel : public Book {
public:
    Novel(unsigned numPages) : Book(numPages) {}
private:
};

void displayNumberOfPages(const PrintedMaterial& material){
    material.displayNumPages();
}

// tester/modeler code
int main() {
    TextBook text(5430, 23);
    Novel novel(213);
    Magazine mag(6);

    text.displayNumPages();
    novel.displayNumPages();
    mag.displayNumPages();
    cout << "===========\n";

    cout << "\nA PrintedMaterial material object!\n";
    PrintedMaterial pm(2345);
    pm.displayNumPages();

    cout << "\nA PrintedMaterial variable containing a TextBook value\n";
    pm = text; // like putting a Textbook into a PrintedMaterial
    pm.displayNumPages();

    cout << "\nUsing PrintedMaterial* to \"store\" a TextBook object\n";
    cout << "Now with the virtual mechanism involved\n";
    // should work now that the virtual mechanism is being invoked
    PrintedMaterial* pmPtr;
    pmPtr = &text;
    pmPtr->displayNumPages();

    // print some stuff by calling a generic function
    cout << "\nUse a generic function for printing\n";
    displayNumberOfPages(mag);
    displayNumberOfPages(novel);
    displayNumberOfPages(text);
}