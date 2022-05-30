/*
    Name: Anik Barua
    Subject: rec14
    Date: 05-06-2022
*/

#include <iostream>
#include <vector>  
using namespace std;

struct Node {
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};

void printList(Node* p) {
    if (p != nullptr) {
	cout << p->data << ' ' ;
	printList(p->next);
    }
}

Node* buildList(const vector<int>& vals) {
    Node* head = nullptr;
    for (size_t i = vals.size(); i > 0; --i) {
        head = new Node(vals[i-1], head);
    }
    return head;
}

bool binaryEvenCheck(int n) {
    if (n < 2) {
        return n == 0;
    }
    if(binaryEvenCheck(n/2)) {
        return n % 2 == 0;
    } else {
        return n % 2 == 1;
    }
}

Node* sumList(Node* lhs, Node* rhs){
    if (rhs == nullptr && lhs == nullptr) return nullptr;
    if (rhs == nullptr) return new Node(lhs->data, sumList(lhs->next, nullptr));
    if (lhs == nullptr) return new Node(rhs->data, sumList(nullptr, rhs->next));
    Node* result = new Node(lhs->data+rhs->data, sumList(lhs->next, rhs->next));
    return result;
}

struct TNode {
  TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr) : data(data), left(left), right(right) {}
  int data;
  TNode *left, *right;
};

int max(TNode* root) {
    if(root == nullptr) throw invalid_argument("Passed in an empty tree!");
    int result = root->data;
    if(root->right != nullptr) {
        if(max(root->right) > result) {
            result = root->right->data;
        }
    }
    if(root->left != nullptr) {
        if(max(root->left) > result) {
            result = root->left->data;
        }
    }
    return result;
}

bool palindrome(char* s, int length) {
    if(length == 1) return true;
    if(s[0] == s[length-1]) return palindrome(s+1,length-2);
    return false;
}

int towers(int n, char start, char target, char spare) {
    int count = 0;
    if (n == 0) {
        return 0;
    } else {
        count+=towers(n-1, start, spare, target);
        ++count;
        count+=towers(n-1, spare, target, start);
    }
    return count;
}

void mystery(int n) { 
   if (n > 1) { 
      cout << 'a'; 
      mystery(n/2); 
      cout << 'b'; 
      mystery(n/2); 
   } 
   cout << 'c'; 
}

// int baseThree (int val){
//     if(val == 0) return val;
//     return 10*baseThree(val/3) + (val%3);
// }



struct TernNode { 
    TernNode(int data = 0, TernNode *left = nullptr, TernNode *mid = nullptr, TernNode *right = nullptr) : data(data), left(left), mid(mid), right(right) {}
    int data; 
    TernNode* left;
    TernNode* right;
    TernNode* mid;
}; // a ​ternary​ tree

int min(TernNode* root) {
    if(root == nullptr) throw invalid_argument("Passed in an empty tree!"); //base

    int result = root->data; // storing result

    // recursive for right
    if(root->right != nullptr) {
        if(min(root->right) < result) {
            result = root->right->data;
        }
    }

    // recursive for left
    if(root->left != nullptr) {
        if(min(root->left) < result) {
            result = root->left->data;
        }
    }

    // recursive for mid
    if(root->mid != nullptr) {
        if(min(root->mid) < result) {
            result = root->mid->data;
        }
    }
    return result;
}

// int convert(int number,int base){
//     if(number == 0 || base==10)
//         return number;

//     return (number % base) + 10*convert(number / base, base);
// }

void baseThree (int val){
    if(val == 0) {
        result val;
    }
    return 10*baseThree(val/3) + (val%3);
}

int main() {
    baseThree(11);
    // cout << convert(111,3) << endl;
    TernNode a(9), b(2), c(4), d(8, &a, &b,&c);
    cout << "Minimum value in a binary tree: " << min(&d) << endl;

    // cout << "Task 1" << endl;
    // cout << "Binary even check for 2 - " << boolalpha << binaryEvenCheck(2) << endl;
    // cout << "Binary even check for 15 - " << boolalpha << binaryEvenCheck(15) << endl;

    // cout << "\nTask 2" << endl;
    // Node* myList1 = buildList({1, 1, 2});
    // Node* myList2 = buildList({1, 1, 2, 8});
    // Node* newList = sumList(myList1, myList2);
    // cout << "List 1: ";
    // printList(myList1);
    // cout << "\nList 2: ";
    // printList(myList2);
    // cout << "\nResult: ";
    // printList(newList);
    // cout << endl;

    // cout << "\nTask 3" << endl;
    // TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
    // try {
    //     cout << "Maximum value in a binary tree: " << max(&f) << endl;
    // } catch (out_of_range& ex) {
    //     cerr << "Caught an out_of_range exception: " << ex.what() << endl;
    // }

    // cout << "\nTask 4" << endl;
    // cout << "racecar is a palindrome? ";
    // char s[] = "racecar";
    // if (palindrome(s, 7)) { 
    //     cout << "Yes!\n"; 
    // } else {
    //     cout << "No!\n";
    // }

    // cout << "mom is a palindrome? ";
    // char s1[] = "mom";
    // if (palindrome(s1, 3)) { 
    //     cout << "Yes!\n"; 
    // } else {
    //     cout << "No!\n";
    // }

    // cout << "car is a palindrome? ";
    // char s2[] = "car";
    // if (palindrome(s2, 3)) { 
    //     cout << "Yes!\n"; 
    // } else {
    //     cout << "No!\n";
    // }

    // cout << "\nTask 5" << endl;
    // cout << "towers(1, 'a', 'b', 'c'): " << towers(1, 'a', 'b', 'c') << endl;
    // cout << "towers(2, 'a', 'b', 'c'): " << towers(2, 'a', 'b', 'c') << endl;
    // cout << "towers(3, 'a', 'b', 'c'): " << towers(3, 'a', 'b', 'c') << endl;
    // cout << "towers(4, 'a', 'b', 'c'): " << towers(4, 'a', 'b', 'c') << endl;
    // cout << "towers(5, 'a', 'b', 'c'): " << towers(5, 'a', 'b', 'c') << endl;
    // cout << "towers(6, 'a', 'b', 'c'): " << towers(6, 'a', 'b', 'c') << endl;
    // cout << "towers(7, 'a', 'b', 'c'): " << towers(7, 'a', 'b', 'c') << endl;
    // cout << "towers(8, 'a', 'b', 'c'): " << towers(8, 'a', 'b', 'c') << endl;
    // cout << "towers(9, 'a', 'b', 'c'): " << towers(9, 'a', 'b', 'c') << endl;
    // cout << "towers(10, 'a', 'b', 'c'): " << towers(10, 'a', 'b', 'c') << endl;

    // cout << "\nTask 6" << endl;
    // mystery(2);
    // cout << endl;
}