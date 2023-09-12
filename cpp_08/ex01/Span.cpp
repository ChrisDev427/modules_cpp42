

#include "Span.hpp"

Span::Span( void ) : _n(0) {
    std::cout << GREEN "Default Constructor called" << RESET << std::endl;
}

Span::Span( unsigned int n ) : _n(n) {

    std::cout << GREEN "Parametric Constructor called" << RESET << std::endl;
}

Span::Span( Span const & src ) : _n( src._n ), _array( src._array ) {
    std::cout << GREEN "Copy Constructor called" << RESET << std::endl; 
}

Span::~Span( void ) { std::cout << RED "Destructor called" << RESET << std::endl; }

Span & Span::operator=( Span const & rhs ) {

    std::cout << GREEN "Assignment operator called" << std::endl;
    
    _array.clear();
    _array = rhs._array;
    return *this;
}

void Span::arrayCheck( void ) {

    if ( _array.empty() ) { throw std::logic_error("Std::except: shortestSpan: [empty array] "); }
    if ( _array.size() == 1 ) { throw std::logic_error("Std::except: shortestSpan: [array size is 1] "); }
}

void Span::addNumber( int value ) {

    try {
        if ( _array.size() < _n ) { _array.push_back( value ); }
        else { throw std::logic_error("Std::except: size max reached"); }
    }
    catch ( std::exception& e) { std::cerr << B_RED << e.what() << RESET << std::endl; }
}

void Span::addSequence( unsigned int n ) {

    std::srand(time(NULL));
    std::vector<int>::iterator it = _array.end();
    size_t sizeLeft = _n - _array.size();
    
    size_t toInsert;
    if ( n > sizeLeft ) { toInsert = sizeLeft; }
    else  { toInsert = n; }

    int tmp[toInsert];
    for ( size_t i = 0; i < toInsert; i++ ) { tmp[i] = rand() % 1000 - 500; }
    _array.insert( it, tmp , tmp+toInsert );
  
    try { if ( n > sizeLeft ) { throw std::logic_error("Std::except: size max reached"); } }
    catch ( std::exception& e) { std::cerr << B_RED << e.what() << RESET << std::endl; }
}


int long Span::shortestSpan( void ) {

    try { arrayCheck(); }
    catch ( std::exception& e ) { std::cerr << B_RED << e.what() << RESET; return -1; }

    int long ret = abs(_array[0] - _array[1]);
    for ( size_t i = 0; i < _array.size(); i++ ) {
        for ( size_t j = 0; j < _array.size(); j++ ) {
            if ( abs(_array[i] - _array[j]) != 0 && abs(_array[i] - _array[j]) < ret ) {
                ret = abs(_array[i] - _array[j]);
            }
        } 
    }
    return ret;
}

int long Span::longestSpan( void ) {

    try { arrayCheck(); }
    catch ( std::exception& e ) { std::cerr << B_RED << e.what() << RESET; return -1; }
    
    int long min = _array[0];
    int long max = _array[0];
    for ( size_t i = 0; i < _array.size(); i++ ) {
        if ( _array[i] < min ) { min = _array[i];}
        if ( _array[i] > max ) { max = _array[i];}
    }
    return ( max - min );
}

void Span::clearArray( void ) { _array.clear(); }


void Span::print( std::string instName ) {

    std::cout << B_CYAN "print -> [" << instName << "]" << RESET << std::endl;
    if ( _array.size() == 0 ) { std::cout << GRAY IT << "Empty array" << RESET ST << std::endl; return; }
    for ( size_t i = 0; i < _array.size(); i++ ) {
        std::cout << GRAY IT << "array[" << i << "] = " << B_CYAN << _array[i] << RESET << std::endl;
    }
    std::cout << RESET ST << std::endl;
}
