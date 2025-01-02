#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <stdexcept>
# include <numeric>
# include <iterator>

class Span {
private:
	std::vector<int>  _numbers;
	unsigned int      _maxSize;

public:
	Span(unsigned int N);
	Span(Span const &src);
	~Span();
	
	Span &operator=(Span const &rhs);
	
	void addNumber(int number);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
	
	template<typename Iterator>
	void addRange(Iterator begin, Iterator end) {
		if (_numbers.size() + std::distance(begin, end) > _maxSize)
			throw std::out_of_range("L'ajout de cette plage dépasserait la taille maximale");
		_numbers.insert(_numbers.end(), begin, end);
	}
};

#endif