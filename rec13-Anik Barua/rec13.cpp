/*
    Name: Anik Barua
    Subject: rec13: STL
    Date: 04-29-2022
*/

#include <iostream>
#include <fstream>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <string>      // task 21
#include <set>         // task 22
#include <map>         // task 23
using namespace std;

void printListIter(const list <int>& lc) {
    for (list<int>::const_iterator l = lc.begin(); l != lc.end(); ++l) {
	    cout << *l << " ";
    }
    cout << endl;
}

void printListRangedFor(const list <int>& lc) {
    for(int x : lc){
        cout << x << " ";
    }
    cout << endl;
}

void printListAuto(const list <int>& lc) {
    for (auto l = lc.begin(); l != lc.end(); ++l) {
	    cout << *l << " ";
        ++l;
    }
    cout << endl;
}

list<int>::const_iterator myFind(const list <int>& lc, int target) {
    for (list<int>::const_iterator p = lc.begin(); p != lc.end(); ++p) {
	    if (*p == target) return p;
    }
    return lc.end();
}

list<int>::const_iterator myFindAuto(const list <int>& lc, int target) {
    for (auto p = lc.begin(); p != lc.end(); ++p) {
	    if (*p == target) return p;
    }
    return lc.end();
}

bool isEven(int n) { 
    return n % 2 == 0; 
}

class IsEven {
public:
    bool operator() (int n) { 
        return n % 2 == 0; 
    }
};

list<int>::iterator ourFind(list<int>::iterator start, list<int>::iterator stop, int target){
    cout << "Using ourFind method" << endl;
    for(list<int>::iterator p = start; p != stop; ++p) {
        if(*p == target) return p;
    }
    return stop;
}

template <typename T, typename U>
T ourFind(T start, T stop, U target) {
    cout << "Using ourFind template method" << endl;
    for (T p = start; p != stop; ++p) {
	    if (*p == target) return p;
    }
    return stop;
}


int main() {
    // 1. Create a vector with some values and display using ranged for
    cout << "Task 1:\n";
    vector<int> vec {4,3,2,6,5,7};

    for(int x : vec){
        cout << x << " ";
    }

    cout << "\n=======\n";

    // 2. Initalize a list as a copy of values from the vector
    cout << "Task 2:\n";
    list<int> lc(vec.begin(), vec.end());

    for (int x : lc) {
        cout << x << " ";
    }

    cout << "\n=======\n";

    // 3. Sort the original vector.  Display both the vector and the list
    cout << "Task 3:\n";
    sort(vec.begin(), vec.end());

    for(int x : vec){
        cout << x << " ";
    }
    cout << endl;

    for (int i : lc) {
        cout << i << " ";
    }

    cout << "\n=======\n";

    // 4. print every other element of the vector. ASSUMING the length is odd.
    cout << "Task 4:\n";
    for(size_t i = 0; i < vec.size(); i+=2) {
        cout << vec[i] << " ";
    }

    cout << "\n=======\n";

    // 5. Attempt to print every other element of the list using the
    //    same technique.
    cout << "Task 5:\n";
    // for(size_t i = 0; i < lc.size(); i+=2) {
    //     cout << lc[i] << " ";
    // }

    cout << "\n=======\n";

    //
    // Iterators
    //

    // 6. Repeat task 4 using iterators.  Do not use auto;
    cout << "Task 6:\n";
    for (vector<int>::iterator p = vec.begin(); p != vec.end(); p = p + 2) {
	    cout << *p << " ";
    }

    cout << "\n=======\n";

    // 7. Repeat the previous task using the list.  Again, do not use auto.
    //    Note that you cannot use the same simple mechanism to bump
    //    the iterator as in task 6.
    cout << "Task 7:\n";
    for (list<int>::iterator l = lc.begin(); l != lc.end(); l++) {
	    cout << *l << " ";
        l++;
    }

    cout << "\n=======\n";

    // 8. Sorting a list
    cout << "Task 8:\n";
    lc.sort();
    for (list<int>::iterator l = lc.begin(); l != lc.end(); ++l) {
	    cout << *l << " ";
    }
    cout << "\n=======\n";

    // 9. Calling the function to print the list
    cout << "Task 9:\n";
    printListIter(lc);

    cout << "=======\n";

    // 10. Calling the function that prints the list, using ranged-for
    cout << "Task 10:\n";
    printListRangedFor(lc);

    cout << "=======\n";

    //
    // Auto
    //

    // 11. Calling the function that, using auto, prints alterate
    // items in the list
    cout << "Task 11:\n";
    printListAuto(lc);

    cout << "=======\n";

    // 12.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 12:\n";

    auto itr1 = myFind(lc,4);
    (itr1 != lc.end()) ? cout << "Found: " << *itr1 << endl : cout << "Not found!" << endl;

    auto itr2 = myFind(lc,9);
    (itr2 != lc.end()) ? cout << "Found: " << *itr2 << endl : cout << "Not found!" << endl;
    
    cout << "=======\n";

    // 13.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 13:\n";

    auto itr3 = myFindAuto(lc,5);
    (itr3 != lc.end()) ? cout << "Found: " << *itr3 << endl : cout << "Not found!" << endl;

    auto itr4 = myFindAuto(lc,1);
    (itr4 != lc.end()) ? cout << "Found: " << *itr4 << endl : cout << "Not found!" << endl;

    cout << "=======\n";

    //
    // Generic Algorithms
    //

    // 14. Generic algorithms: find
    cout << "Task 14:\n";
    auto x = find(lc.begin(), lc.end(), 7);
    (x != lc.end()) ? cout << "Found: " << *x << endl : cout << "Not found!" << endl;

    cout << "=======\n";

    // 15. Generic algorithms: find_if
    cout << "Task 15:\n";
    auto x1 = find_if(lc.begin(), lc.end(), isEven);

    if(isEven(*x1)) {
        cout << "Found the even number: " << *x1 << endl;
    } else {
        cout << "No even number found!"<< endl;
    }
    cout << "=======\n";

    // 16. Functor
    cout << "Task 16:\n";
    //IsEven testForEven; // functor
    auto where = find_if(lc.begin(), lc.end(), IsEven());
    (where != lc.end()) ? cout << "Found the even number: " << *where << endl : cout << "Not Found" << endl;

    cout << "=======\n";
    
    // 17. Lambda
    cout << "Task 17:\n";
    auto where2 = find_if(lc.begin(), lc.end(), [] (int n) { return n % 2 == 0; });
    (where2 != lc.end()) ? cout << "Found the even number: " << *where2 << endl : cout << "Not Found" << endl;

    cout << "=======\n";

    // 18. Generic algorithms: copy to an array
    cout << "Task 18:\n";
    int* arr = new int[lc.size()];
    copy(lc.begin(), lc.end(), arr);

    for(size_t i = 0; i < lc.size(); ++i){
        cout << arr[i] << " ";
    }
    cout << endl;

    auto where3 = find(arr, arr+lc.size(), 4);
    (where3 != arr+lc.size()) ? cout << "Found the even number: " << *where3 << endl : cout << "Not Found" << endl;

    delete [] arr;

    cout << "=======\n";

    //
    // Templated Functions
    //

    // 19. Implement find as a function for lists
    cout << "Task 19:\n";
    list<int>::iterator tmp1 = ourFind(lc.begin(), lc.end(), 5);
    (tmp1 != lc.end()) ? cout << "Found the even number: " << *tmp1 << endl : cout << "Not Found" << endl;

    cout << "=======\n";
    
    // 20. Implement find as a templated function
    cout << "Task 20:\n";
    auto tmp2 = ourFind(vec.begin(), vec.end(), 3);
    (tmp2 != vec.end()) ? cout << "Found the even number: " << *tmp2 << endl : cout << "Not Found" << endl;

    cout << "=======\n";

    //
    // Associative collections
    //

    // 21. Using a vector of strings, print a line showing the number
    //     of distinct words and the words themselves.
    cout << "Task 21:\n";
    ifstream textStream("pooh-nopunc.txt");
    if (!textStream) {
	    cerr << "failed to open pooh-nopunc\n";
	    exit(1);
    }

    vector <string> vec2;
    string token;
    while (textStream >> token) {
        if(find(vec2.begin(), vec2.end(), token) == vec2.end()) {
            vec2.push_back(token);
        }
    }

    textStream.close();
    textStream.clear();

    cout << "Size: " << vec2.size() << endl;
    cout << "Contents: ";
    for(size_t i = 0; i < vec2.size(); ++i) {
        cout << vec2[i] << " ";
    }
    cout << endl;

    cout << "\n=======\n";

    // 22. Repeating previous step, but using the set
    cout << "Task 22:\n";
    ifstream textStream2("pooh-nopunc.txt");
    if (!textStream2) {
	    cerr << "failed to open pooh-nopunc\n";
	    exit(1);
    }

    set <string> mySet;
    string token2;
    while (textStream2 >> token2) {
        mySet.insert(token2);
    }
    textStream2.close();

    cout << "Size of set: " << mySet.size() << endl;
    cout << "Set contents: ";
    for(set<string>::iterator setItr = mySet.begin(); setItr != mySet.end(); setItr++) {
        cout << *setItr << " ";
    }
    cout << endl;

    cout << "=======\n";

    // 23. Word co-occurence using map
    cout << "Task 23:\n";
    ifstream textStream3 ("pooh-nopunc.txt");
    if (!textStream3) {
	    cerr << "failed to open pooh-nopunc\n";
	    exit(1);
    }

    map<string, vector<int>> wordMap;
    string token3;
    int counter = 0;
    while (textStream3 >> token3) {
        wordMap[token3].push_back(counter);
        counter++;
    }
    textStream3.close();

    cout << "Size of wordMap: " << wordMap.size() << endl;
    cout << "Map contents: ";
    for(const auto& mapItr : wordMap) {
        cout << mapItr.first << " ";
        for(size_t i = 0; i < mapItr.second.size() ; ++i) {
            cout << mapItr.second[i] << " ";
        }
        cout << endl;
    }
    cout << "=======\n";
}

