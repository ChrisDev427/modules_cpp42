/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:23 by chris             #+#    #+#             */
/*   Updated: 2023/08/30 08:49:20 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Dog.hpp"

Dog::Dog( void ) {

    std::cout << B_GREEN << "Dog -> Default Constructor called" << RESET << std::endl;
    
    type = "Dog";
    _ptr = new Brain();

    return;
}

Dog::Dog( Dog const & src ) {

    std::cout << B_GREEN << "Dog -> Copy Constructor called" << RESET << std::endl;

    this->type = src.type;
    this->_ptr = new Brain();

    std::cout << B_GRAY << "Dog -> deep copy of array ideas" << RESET << std::endl;

    for ( int i = 0; i < 100; i++ ) {
        
        if ( src._ptr->ideas[i] ) {

            this->_ptr->ideas[i] = new std::string;
            *this->_ptr->ideas[i] = *src._ptr->ideas[i];
        }
    }

    return;
}

Dog::~Dog( void ) {

    std::cout << B_RED << "Dog -> Destructor called" << RESET << std::endl;

    for ( int i = 0; i < 100; i++ ) {

        if ( _ptr->ideas[i] ) {
            std::cout << GRAY << "Dog -> deleting string [" << i << "] " << " of array ideas" << RESET << std::endl;
            delete _ptr->ideas[i];
        }
    }
    std::cout << GRAY << "Dog -> deleting Brain* _ptr" << RESET << std::endl;
    delete _ptr;

    return;
}

Dog & Dog::operator=( Dog const & rhs ) {

    std::cout << B_GREEN << "Dog -> Assignment operator called" << RESET << std::endl;
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

std::string Dog::getType( void ) const {

    return this->type;
}

void Dog::setPtr( std::string str ) const{

    std::cout << B_GRAY << "Dog -> Alloc & Write each string of array ideas" << RESET << std::endl;
    
    for ( int i = 0; i < 100; i++ ) {

        _ptr->ideas[i] = new std::string;
        *_ptr->ideas[i] = str;
    }
}

void Dog::printArray( void ) const {

    std::cout << B_ORANGE << "Dog printArray" << std::endl;
    for ( int i = 0; i < 100; i++ ) {

        if ( _ptr->ideas[i] )
            std::cout << BLUE << "[" << i << "] " << *_ptr->ideas[i] << RESET << std::endl;
        else
            std::cout << BLUE << "[" << i << "] " << ITAL << RED << "Null" << RESET << std::endl;
    }
}

void Dog::makeSound() const{

    std::cout << B_CYAN << type << " says: Wouaf Wouaf Wouaf..." << RESET << std::endl;

}
