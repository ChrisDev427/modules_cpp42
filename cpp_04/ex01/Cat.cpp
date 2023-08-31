/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:40 by chris             #+#    #+#             */
/*   Updated: 2023/08/30 08:49:29 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) {

    std::cout << B_GREEN << "Cat -> Default Constructor called" << RESET << std::endl;
    type = "Cat";
    _ptr = new Brain();

    return;
}

Cat::Cat( Cat const & src ) {

    std::cout << B_GREEN << "Cat -> Copy Constructor called" << RESET << std::endl;
    
    this->type = src.type;
    this->_ptr = new Brain();

    std::cout << B_GRAY << "Cat -> deep copy of array ideas" << RESET << std::endl;

    for ( int i = 0; i < 100; i++ ) {
        
        if ( src._ptr->ideas[i] ) {

            this->_ptr->ideas[i] = new std::string;
            *this->_ptr->ideas[i] = *src._ptr->ideas[i];
        }
    }

    return;
}

Cat::~Cat( void ) {

    std::cout << B_RED << "Cat -> Destructor called" << RESET << std::endl;

    
    for ( int i = 0; i < 100; i++ ) {

        if ( _ptr->ideas[i] ) {

            std::cout << GRAY << "Cat -> deleting string [" << i << "] " << " of array ideas" << RESET << std::endl;
            delete _ptr->ideas[i];
        }
    }
    std::cout << GRAY << "Cat -> deleting Brain* _ptr" << RESET << std::endl;
    delete _ptr;

    return;
}

Cat & Cat::operator=( Cat const & rhs ) {

    std::cout << B_GREEN << "Cat -> Assignment operator called" << RESET << std::endl;
    this->type = rhs.type;
   
    std::cout << B_GRAY << "Dog -> deep copy of array ideas" << RESET << std::endl;

    for ( int i = 0; i < 100; i++ ) {
        
        if ( rhs._ptr->ideas[i] ) {

            this->_ptr->ideas[i] = new std::string;
            *this->_ptr->ideas[i] = *rhs._ptr->ideas[i];
        }
    }
    return *this;
}

std::string Cat::getType( void ) const {

    return this->type;
}

void Cat::setPtr( std::string str ) const{

    std::cout << B_GRAY << "Cat -> Alloc & Write each string of array ideas" << RESET << std::endl;
    
    for ( int i = 0; i < 100; i++ ) {

        _ptr->ideas[i] = new std::string;
        *_ptr->ideas[i] = str;
    }
}

void Cat::printArray( void ) const {

    std::cout << B_ORANGE << "Cat printArray" << RESET << std::endl;
    for ( int i = 0; i < 100; i++ ) {

        if ( _ptr->ideas[i] )
            std::cout << BLUE << "[" << i << "] " << *_ptr->ideas[i] << RESET << std::endl;
        else
            std::cout << BLUE << "[" << i << "] " << ITAL << RED << "Null" << RESET << std::endl;
            
    }
}


void Cat::makeSound() const{

    std::cout << B_CYAN << type << " says: Miaou Miaou Miaou..." << RESET << std::endl;

}
