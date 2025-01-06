#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

void test_vector() {
    std::vector<int> numbers;
    for (int i = 0; i < 5; ++i) {
        numbers.push_back(i * 2); // [0, 2, 4, 6, 8]
    }
    
    std::cout << "Vector contains: ";
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    try {
        std::vector<int>::iterator it = easyfind(numbers, 4);
        std::cout << "Found value 4 at position: " << std::distance(numbers.begin(), it) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        std::vector<int>::iterator it = easyfind(numbers, 3); // This should throw
        std::cout << "Found value 3 at position: " << std::distance(numbers.begin(), it) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void test_list() {
    std::list<int> numbers;
    for (int i = 0; i < 5; ++i) {
        numbers.push_back(i); 
    }

    std::cout << "List contains: ";
    for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    try {
        std::list<int>::iterator it = easyfind(numbers, 3);
        std::cout << "Found value 3 in list at position: " << std::distance(numbers.begin(), it) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void test_deque() {
    std::deque<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    std::cout << "Deque contains: ";
    for (std::deque<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    try {
        std::deque<int>::iterator it = easyfind(numbers, 20);
        std::cout << "Found value 20 in deque at position: " << std::distance(numbers.begin(), it) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "Testing with vector:" << std::endl;
    test_vector();
    
    std::cout << "\nTesting with list:" << std::endl;
    test_list();
    
    std::cout << "\nTesting with deque:" << std::endl;
    test_deque();
    
    return 0;
}