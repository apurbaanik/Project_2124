/*
    Title: testRational.cpp
	Author: Anik Barua
	Version: 1.0
	Date: 03-25-2022
	CS2124
	Implement the class Rational, so that the following program works.
 */

#include <iostream>
#include <string>

// If time allows use separate compilation, otherwise just define the
// class below with the methods / functions defined after main.
#include "Rational.h"

using namespace std;

// If time allows after implementing separate compilation, then wrap
// the class in a namespace.
// using namespace CS2124;

class Rational {
    friend ostream& operator<<(ostream& os, const Rational& rhs);
    friend istream& operator>>(istream& input, Rational& rhs);
    friend bool operator==(const Rational& lhs, const Rational& rhs);
    friend bool operator<(const Rational& lhs, const Rational& rhs);
public:
    Rational(int numerator = 0, int denominator = 1);
    Rational& operator+=(const Rational& rhs);
    Rational& operator++();
    Rational operator++(int dummy);
    void normalize();
    explicit operator bool() const;
private:
    int numerator;
    int denominator;
};

// Class prototypes
int greatestCommonDivisor(int x, int y);
bool operator!=(const Rational& lhs, const Rational& rhs);
bool operator<(const Rational& lhs, const Rational& rhs);
bool operator<=(const Rational& lhs, const Rational& rhs);
bool operator>(const Rational& lhs, const Rational& rhs);
bool operator>=(const Rational& lhs, const Rational& rhs);
Rational operator+(const Rational& lhs, const Rational& rhs);
Rational& operator--(Rational& lhs);
Rational operator--(Rational& lhs, int dummy);

int main() {
    Rational a, b;
    cout << "Input a rational number, e.g. 6/9.\n";
    cout << "a: ";
    cin >> a;

    cout << "Input a rational number, e.g. 6/9.\n";
    cout << "b: ";
    cin >> b;
    const Rational one = 1;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "one = " << one << endl;
    cout << "a += b: " << (a += b) << endl;	// Implement as member
    cout << "a = " << a << endl;
    
    // Implement + as non-member, but not a friend
    cout << "a + one: " << (a + one) << endl;
    cout << "a == one: " << boolalpha << (a == one) << endl;
    
    
    // How does this manage to work?
    // It does NOT require writing another == operator. 
    cout << "1 == one: " << boolalpha << (1 == one) << endl;
    
    // Do not implement as friend.
    cout << "a != one: " << boolalpha << (a != one) << endl;

    
    cout << "a = " << a << endl;
    cout << "++a = " << (++a) << endl;
    cout << "a = " << a << endl;
    cout << "a++ = " << (a++) << endl;
    cout << "a = " << a << endl;
    cout << "--a = " << (--a) << endl;
    cout << "a = " << a << endl;
    cout << "a-- = " << (a--) << endl;
    cout << "a = " << a << endl;

    cout << "++ ++a = " << (++ ++a) << endl;
    cout << "a = " << a << endl;
    cout << "-- --a = " << (-- --a) << endl;
    cout << "a = " << a << endl;

    cout << "a++ ++ = " << (a++ ++) << endl;
    cout << "a = " << a << endl;

    // Even though the above example, (a++ ++), compiled, the
    // following shouldn't.
    // But some compiler vendors might let it...  Is your compiler
    // doing the right thing?
    //cout << "a-- -- = " << (a-- --) << endl;
    cout << "a = " << a << endl;


    // Should report that 1 is true
    if (Rational(1)) {
        cout << "1 is true" << endl;
    } else {
        cout << "1 is false" << endl;
    } 

    // Should report that 0 is false
    if (Rational(0)) {
        cout << "0 is true" << endl;
    } else {
        cout << "0 is false" << endl;
    } 

    cout << "Comparisons\n";
    Rational twoFifths(2, 5);
    Rational threeHalves(3, 2);
    Rational minusFive(-5);
    cout << twoFifths << " < " << threeHalves << " : " 
         << (twoFifths < threeHalves) << endl;
    cout << twoFifths << " <= " << 1 << " : " << (twoFifths <= 1) << endl;
    cout << threeHalves << " < " << twoFifths << " : "
         << (threeHalves < twoFifths) << endl;
    cout << threeHalves << " > " << threeHalves << " : "
         << (threeHalves > threeHalves) << endl;
    cout << threeHalves << " >= " << threeHalves << " : "
         << (threeHalves >= threeHalves) << endl;
    cout << minusFive << " >= " << threeHalves << " : "
         << (minusFive >= threeHalves) << endl;
}

//Rational class
Rational::Rational(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
    normalize();
}

Rational& Rational::operator++() {
    numerator+=denominator;
    normalize();
    return *this;
}

Rational& Rational::operator+=(const Rational& rhs) {
    numerator = (numerator * rhs.denominator) + (rhs.numerator * denominator);
    denominator *= rhs.denominator;
    normalize();
	return *this;
}

Rational Rational::operator++(int dummy) {
    Rational original(*this);
    ++(*this);
    return original;
}

void Rational::normalize(){
    if(denominator < 0){
        numerator = -numerator;
        denominator = -denominator;
    }
    int gcd = greatestCommonDivisor(abs(numerator), denominator);
    if(gcd != 0){
        numerator = numerator/gcd;
        denominator = denominator/gcd;
    }
}

Rational::operator bool() const {
	return numerator != 0;
}

// op<< as a friend
ostream& operator<<(ostream& os, const Rational& rhs) {
    os << rhs.numerator;
    if (rhs.denominator > 1) {
        os << '/';
        os << rhs.denominator; 
    }
    return os;
}

// op>> as a friend
istream& operator>>(istream& input, Rational& rhs) {
    char c;
    input >> rhs.numerator >> c >> rhs.denominator;
    rhs.normalize();
    return input;
}

//non-member functions
int greatestCommonDivisor(int x, int y) {
        while (y != 0) {
            int temp = x % y;
            x = y;
            y = temp;
        }
        return x;
}

bool operator==(const Rational& lhs, const Rational& rhs) {
    return lhs.numerator == rhs.numerator && lhs.denominator == rhs.denominator;
}

bool operator!=(const Rational& lhs, const Rational& rhs) {
    return !(lhs == rhs);
}

bool operator<(const Rational& lhs, const Rational& rhs) {
    int totalNum1 = lhs.numerator * rhs.denominator;
    int totalNum2 = lhs.denominator * rhs.numerator;
    return totalNum1 < totalNum2;
}

bool operator>(const Rational& lhs, const Rational& rhs) {
    return !(lhs<=rhs);
}

bool operator<=(const Rational& lhs, const Rational& rhs) {
    return lhs < rhs || lhs == rhs;
}

bool operator>=(const Rational& lhs, const Rational& rhs) {
    return !(lhs < rhs);
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    Rational result = lhs;
    result += rhs;
    return result;
}

Rational& operator++() {
    numerator+=denominator;
    return *this;
}

// --i;
// operator--(i);
Rational& operator--(Rational& lhs) {
    lhs+=Rational(-1);
    return lhs;
}

// If method the call is i.operator--();

// i--;
// operator--(i,0);
Rational operator--(Rational& lhs, int dummy) {
    Rational result = lhs;
    lhs+=Rational(-1);
    return result;
}