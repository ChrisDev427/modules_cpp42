/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:53:32 by chris             #+#    #+#             */
/*   Updated: 2023/09/04 12:29:25 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ) {

    // std::cout << "Default Constructor called" << std::endl;
   
    return;
}

ScalarConverter::ScalarConverter( ScalarConverter const & src ) {

    // std::cout << "Copy Constructor called" << std::endl;
    *this = src;

    return;
}

ScalarConverter::~ScalarConverter( void ) {

    // std::cout << "Destructor called" << std::endl;

    return;
}

ScalarConverter & ScalarConverter::operator=( ScalarConverter const & rhs ) {

    // std::cout << "Assignment operator called" << std::endl;
    if ( this != &rhs ) {}
    return *this;

}

bool isInteger( std::string & str ) {

    size_t i = 0;
    if (str[i] == '-' || str[i] == '+' ) { i++; }
    while ( str[i] ) {
        if (!std::isdigit(str[i])) {
            return false;
        }
        i++;
    } 
    return true;
}

bool isFloat( std::string & str ) {
    
    std::string const defLiterals[4] = { "inff", "+inff", "-inff", "nanf" };
    for ( int i = 0; i < 4; i++ ) {
        if ( str == defLiterals[i] ) { 
            str.erase( str.length() -1); 
            return true;
        }
    }
    if ( std::count( str.begin(), str.end(), '.' ) != 1 ) { return false; }
    if ( std::count( str.begin(), str.end(), 'f' ) != 1 ) { return false; }
    if ( str.back() != 'f' ) { return false; }
    size_t i = 0;
    if (str[i] == '-' || str[i] == '+' ) { i++; }
    while ( str[i] ) {

        if (!std::isdigit(str[i])) {

            if ( str[i] != '.' && str[i] != 'f' ) {
                return false;
            }
        }
        i++;
    } 
    str.erase( str.length() -1); 
    return true;
}

bool isDouble( std::string & str ) {

    std::string const defLiterals[4] = { "inf", "+inf", "-inf", "nan" };
    for ( int i = 0; i < 4; i++ ) {
        if ( str == defLiterals[i] ) {
            return true;
        }
    }
    if ( std::count( str.begin(), str.end(), '.' ) != 1 ) { return false; }
    if ( str.back() == 'f' ) { return false; }
    size_t i = 0;
    if (str[i] == '-' || str[i] == '+' ) { i++; }
    while ( str[i] ) {

        if (!std::isdigit(str[i])) {

            if ( str[i] != '.' ) {
                return false;
            }
        }
        i++;
    } 
    return true;
}

bool isChar( std::string & str ) {

    if ( str.length() != 1 ) { return false; }
    return true;
}

void ScalarConverter::convert ( std::string & input ) {

    long i;
    float f;
    double d;
    char c;
    int type = -1;
    bool (*funcTab[4])( std::string & str ) = { isInteger, isFloat, isDouble, isChar };
    std::string defLiterals[8] = { "inf", "inff","+inf", "-inf", "+inff", "-inff", "nan", "nanf" };
   
    for ( int i = 0; i < 4; i++ ) {
        if ( funcTab[i](input) ) {
            type = i;
            break;
        }
    }
    std::istringstream iss( input );
    switch ( type )
    {
    case -1:
        std::cerr << "Error: bad argument" << std::endl;
        return;
    case 0:
        iss >> i;
        f = static_cast<float>( i );
        d = static_cast<double>( i );
        c = static_cast<char>( i );
        break;
    case 1:
        iss >> f;
        i = static_cast<int>( f );
        d = static_cast<double>( f );
        c = static_cast<char>( f );
        break;
    case 2:
        iss >> d;
        f = static_cast<float>( d );
        i = static_cast<int>( d );
        c = static_cast<char>( d );
        break;
    case 3:
        c = input[0];
        i = static_cast<int>( c );
        f = static_cast<float>( c );
        d = static_cast<double>( c );
        break;
    }
    if ( i < 0 || i > 127 ) { std::cout << "char: impossible" << std::endl; }
    else if ( i >= 32 && i <= 126 ) { std::cout << "char: " << "'" << c << "'" << std::endl; }
    else  { std::cout << "char: Non displayable" << std::endl; }
    for ( int j = 0; j < 8; j++ ) {
        
        if ( input == defLiterals[j]  || i > INT_MAX || i < INT_MIN || f > INT_MAX || f < INT_MIN  ) {
            std::cout << "int: impossible" << std::endl;
            break;
        }
        else if ( j == 7 ) { std::cout << "int: " << i << std::endl; }
    }
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
