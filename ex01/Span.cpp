#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {
    _numbers.reserve(N);
}

Span::Span(Span const &src) : _numbers(src._numbers), _maxSize(src._maxSize) {
}

Span::~Span() {
}

Span &Span::operator=(Span const &rhs) {
    if (this != &rhs) {
        _numbers = rhs._numbers;
        _maxSize = rhs._maxSize;
    }
    return *this;
}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize)
        throw std::out_of_range("Impossible d'ajouter plus de nombres, le Span est plein");
    _numbers.push_back(number);
}

unsigned int Span::shortestSpan() const {
    if (_numbers.size() <= 1)
        throw std::runtime_error("Pas assez de nombres pour calculer un écart");
    
    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());
    
    std::vector<int> spans(sorted.size() - 1);
    std::adjacent_difference(sorted.begin(), sorted.end(), spans.begin());
    
    return static_cast<unsigned int>(*std::min_element(spans.begin() + 1, spans.end()));
}

unsigned int Span::longestSpan() const {
    if (_numbers.size() <= 1)
        throw std::runtime_error("Pas assez de nombres pour calculer un écart");
    
    std::vector<int>::const_iterator min = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator max = std::max_element(_numbers.begin(), _numbers.end());
    return static_cast<unsigned int>(*max - *min);
}