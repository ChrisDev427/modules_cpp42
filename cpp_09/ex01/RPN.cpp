/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:27:45 by chris             #+#    #+#             */
/*   Updated: 2023/09/19 18:21:17 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN( void ) {}
RPN::RPN( char* av ) {

    _handleStack( av );
}
RPN::RPN( RPN const & src )  {
    (void)src;
    return;
}
RPN::~RPN( void ) {  }
RPN & RPN::operator=( RPN const & rhs ) {
    (void)rhs;
    return *this;
}

int RPN::_calculate( std::string & str, int nb1, int nb2 ) {

    if ( !_isSign( str[0] ) ) { throw std::invalid_argument("Error"); }

    return  (str == "*") ? nb1 * nb2 :
            (str == "-") ? nb1 - nb2 :
            (str == "+") ? nb1 + nb2 :
            (str == "/") ? nb1 / nb2 : 0;
}

bool RPN::_isSign( char c ) {

    if ( c != '+' && c != '-' && c != '*' && c != '/' )
        return false;
    return true;
}

void printStack( std::stack<int> stk ) {

    std::stack<int> stkTmp;
    std::cout << "STACK" << std::endl;
    while ( !stk.empty() ) {
        std::cout << stk.top() << std::endl;
        stkTmp.push( stk.top() );
        stk.pop();
    }
    while ( !stkTmp.empty() ) {
        stk.push( stkTmp.top() );
        stkTmp.pop();
    }
    std::cout << "--------------" << std::endl;
}

void RPN::_handleStack( char *str ) {
    
    std::string line;
    std::istringstream iss(str);
    int a, tmp;
    while ( getline( iss, line, ' ' ) ) {

        if ( line.empty() ) { continue; }
        if (( line.size() != 1 ) && ( !isdigit(line[0]) || !_isSign(line[0]) )) { throw std::invalid_argument("Error"); }
        else {

            std::istringstream iss2(line);
            if ( iss2 >> tmp ) { // while is digit pushing numbers on stack
                _stk.push(tmp);
                iss2.clear();
            }
            else if ( _stk.size() > 1 ) { // if a sign: '+', '-', '*', '/' is reached

                a = _stk.top();
                _stk.pop();
                _stk.top() = _calculate( line, _stk.top(), a );
            }
            else { throw std::invalid_argument("Error"); }
            // printStack( _stk );
        }
    }
    if ( _stk.size() == 1 ) {
        std::cout << _stk.top() << std::endl;
    }
    else { throw std::invalid_argument("Error: incomplete expression");}
}
