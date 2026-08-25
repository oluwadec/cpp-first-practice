// C++ Reference Guide
// Compile: g++ -std=c++20 main.cpp -o textbook
// Run:     ./textbook

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <fstream>
#include <concepts>
#include <stdexcept>

void demonstrateBasics() {
    std::cout << std::endl << "1. BASICS" << std::endl;

    int age = 25;
    double pi = 3.14159;
    char grade = 'A';
    bool isCodingFun = true;

    const int MAX_USERS = 100;
    constexpr double G = 9.81;

    auto autoType = 42;

    std::cout << "Age: " << age
              << ", Pi: " << pi
              << ", Grade: " << grade << std::endl;

    std::cout << "Compile-time Constant G: " << G << std::endl;
    std::cout << "Coding fun: " << std::boolalpha << isCodingFun << std::endl;
    std::cout << "Maximum users: " << MAX_USERS << std::endl;
    std::cout << "Auto variable: " << autoType << std::endl;
}

void demonstrateControlFlow() {
    std::cout << std::endl << "2. CONTROL FLOW" << std::endl;

    int score = 85;

    if (score >= 90) {
        std::cout << "Grade: A" << std::endl;
    }
    else if (score >= 80) {
        std::cout << "Grade: B" << std::endl;
    }
    else {
        std::cout << "Grade: C or below" << std::endl;
    }

    int day = 2;

    switch (day) {
        case 1:
            std::cout << "Monday" << std::endl;
            break;

        case 2:
            std::cout << "Tuesday" << std::endl;
            break;

        default:
            std::cout << "Other day" << std::endl;
            break;
    }

    std::cout << "For loop count: ";

    for (int i = 0; i < 3; ++i) {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    int count = 2;

    while (count > 0) {
        --count;
    }

    std::cout << "While loop completed." << std::endl;
}

void addOneByValue(int val) {
    val += 1;
}

void addOneByRef(int& ref) {
    ref += 1;
}

void addOneByPointer(int* ptr) {
    if (ptr) {
        *ptr += 1;
    }
}

void demonstrateFunctionsAndPointers() {
    std::cout << std::endl << "3. FUNCTIONS & POINTERS" << std::endl;

    int num = 10;

    addOneByValue(num);
    std::cout << "After pass-by-value: "
              << num << " (Unchanged)" << std::endl;

    addOneByRef(num);
    std::cout << "After pass-by-reference: "
              << num << " (Incremented)" << std::endl;

    addOneByPointer(&num);
    std::cout << "After pass-by-pointer: "
              << num << " (Incremented via address)" << std::endl;

    int* ptr = &num;

    std::cout << "Memory Address: "
              << ptr
              << ", Dereferenced Value: "
              << *ptr << std::endl;
}

class Animal {
protected:
    std::string name;

public:
    Animal(std::string n) : name(n) {}

    virtual ~Animal() = default;

    virtual void makeSound() const = 0;
};

class Dog : public Animal {
private:
    std::string breed;

public:
    Dog(std::string n, std::string b)
        : Animal(n), breed(b) {}

    void makeSound() const override {
        std::cout << name << " (" << breed
                  << ") says: Woof!" << std::endl;
    }
};

void demonstrateOOP() {
    std::cout << std::endl << "4. OBJECT-ORIENTED PROGRAMMING" << std::endl;

    std::unique_ptr<Animal> myDog =
        std::make_unique<Dog>("Buddy", "Golden Retriever");

    myDog->makeSound();
}

void demonstrateSmartPointers() {
    std::cout << std::endl << "5. SMART POINTERS" << std::endl;

    std::unique_ptr<int> uPtr = std::make_unique<int>(100);

    std::cout << "Unique Pointer Value: "
              << *uPtr << std::endl;

    std::shared_ptr<int> sPtr1 =
        std::make_shared<int>(200);

    {
        std::shared_ptr<int> sPtr2 = sPtr1;

        std::cout << "Shared Count inside scope: "
                  << sPtr1.use_count() << std::endl;
    }

    std::cout << "Shared Count outside scope: "
              << sPtr1.use_count() << std::endl;
}

template <typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
T addNumbers(T a, T b) {
    return a + b;
}

void demonstrateTemplates() {
    std::cout << std::endl << "6. TEMPLATES & CONCEPTS" << std::endl;

    std::cout << "Template Max (Int): "
              << getMax(10, 20) << std::endl;

    std::cout << "Template Max (Double): "
              << getMax(5.5, 2.3) << std::endl;

    std::cout << "Constrained Add (C++20 Concept): "
              << addNumbers(15, 25) << std::endl;
}

void demonstrateSTL() {
    std::cout << std::endl << "7. STL CONTAINERS & ALGORITHMS" << std::endl;

    std::vector<int> numbers = {5, 2, 8, 1, 9};

    numbers.push_back(4);

    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a > b;
    });

    std::cout << "Sorted Vector (Descending): ";

    for (int num : numbers) {
        std::cout << num << " ";
    }

    std::cout << std::endl;
}

double divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero error!");
    }

    return a / b;
}

void demonstrateExceptions() {
    std::cout << std::endl << "8. EXCEPTION HANDLING" << std::endl;

    try {
        double result = divide(10.0, 0.0);

        std::cout << "Result: "
                  << result << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Caught exception: "
                  << e.what() << std::endl;
    }
}

int main() {
    std::cout << "C++ LANGUAGE COMPREHENSIVE EXECUTABLE TEXTBOOK"
              << std::endl;

    demonstrateBasics();
    demonstrateControlFlow();
    demonstrateFunctionsAndPointers();
    demonstrateOOP();
    demonstrateSmartPointers();
    demonstrateTemplates();
    demonstrateSTL();
    demonstrateExceptions();

    std::cout << std::endl
              << "END OF TEXTBOOK DEMO"
              << std::endl;

    return 0;
}