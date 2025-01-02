#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <algorithm>

int main() {
    {
        std::cout << "Test de base:" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    {
        std::cout << "\nTest avec 10000 nombres:" << std::endl;
        Span sp = Span(10000);
        std::vector<int> v(10000);
        std::srand(std::time(NULL));
        std::generate(v.begin(), v.end(), std::rand);
        sp.addRange(v.begin(), v.end());
        
        std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
    }

    {
        std::cout << "\nTest avec une list:" << std::endl;
        Span sp = Span(5);
        std::list<int> lst;
        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(3);
        lst.push_back(4);
        lst.push_back(5);
        
        sp.addRange(lst.begin(), lst.end());
        std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
    }

    {
        std::cout << "\nTest des exceptions:" << std::endl;
        Span sp = Span(1);
        try {
            sp.addNumber(5);
            sp.addNumber(3);
        }
        catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        Span sp2 = Span(1);
        try {
            sp2.addNumber(5);
            std::cout << sp2.shortestSpan() << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }

    return 0;
}