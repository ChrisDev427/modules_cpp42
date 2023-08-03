/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:37:36 by chris             #+#    #+#             */
/*   Updated: 2023/08/01 10:37:37 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) {

    std::cout << GREEN << "Default Constructor called\n" << RESET << std::endl;
    _name = "default_name";
    _hit = 10;
    _energy = 10;
    _attackDamage = 0;

    return;

}

ClapTrap::ClapTrap( std::string name ) : _name( name ) {

    std::cout << GREEN << "Parametric Constructor called " << RESET;
    std::cout << B_GRAY << ITAL << "(instance -> [" << _name << "])" << RESET << NORM <<std::endl;
    _hit = 10;
    _energy = 10;
    _attackDamage = 0;

    return;
}

ClapTrap::ClapTrap( ClapTrap const & src ) {

    std::cout << GREEN << "Copy Constructor called\n" << RESET << std::endl;
    *this = src;

    return;

}

ClapTrap::~ClapTrap( void ) {

    std::cout << B_GRAY << ITAL << _name << RED <<" Destructor called\n" << RESET << NORM << std::endl;

    return;

}

ClapTrap & ClapTrap::operator=( ClapTrap const & rhs ) {

    std::cout << GREEN << "Assignment operator called\n" << RESET << std::endl;

    this->_hit = rhs.getValue( "_hit" );
    this->_energy = rhs.getValue( "_energy" );
    this->_attackDamage = rhs.getValue( "_attackDamage" );

    return *this;

}

int ClapTrap::getValue( const std::string value ) const{

    if ( value == "_hit" )
        return _hit;
    if ( value == "_energy" )
        return _energy;
    if ( value == "_attackDamage" )
        return _attackDamage;
    else
        std::cout << "Error: getValue() value not found" << std::endl;

    return 0;
}

void ClapTrap::attack( const std::string& target ) {

    if ( this->_energy > 0 && this->_hit > 0 ) {

        std::cout << B_YELLOW <<  "ClapTrap "<< _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
        this->_energy--;
        std::cout << ITAL B_GRAY"\t\t\t\t" << _name << " (hit[" << _hit << "] energy[" << _energy << "])\n" << NORM << std::endl;
        if ( _energy <= 0 )
            _energy = 0;
    }
    else {
        if ( _hit == 0 )
            std::cout << RED << "ClapTrap "<< _name << " has no more hit" << RESET << std::endl;
        if ( _energy == 0 )
            std::cout << RED << "ClapTrap "<< _name << " has no more energy" << RESET << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::microseconds(400000));
}

void ClapTrap::takeDamage( unsigned int amount ) {

    if ( _hit > 0 && _energy > 0 ) {

        std::cout << B_YELLOW << "ClapTrap "<< _name << " took " << amount << " damages from someone" << RESET << std::endl;
        _hit -= amount;
        std::cout << ITAL B_GRAY"\t\t\t\t" << _name << " (hit[" << _hit << "] energy[" << _energy << "])\n" << NORM << std::endl;

        if ( _hit <= 0 )
            _hit = 0;
    }
    else {
        if ( _hit == 0 )
            std::cout << RED << "ClapTrap "<< _name << " has no more hit" << RESET << std::endl;
        if ( _energy == 0 )
            std::cout << RED << "ClapTrap "<< _name << " has no more energy" << RESET << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::microseconds(400000));
}

void ClapTrap::beRepaired( unsigned int amount ) {

    if ( _hit > 0 && _energy > 0 ) {
        
        std::cout << B_YELLOW << "ClapTrap "<< _name << " repairs [-" << amount << " energy] [+" << amount << " hits]" << RESET << std::endl;
        _hit += amount;
        _energy -= amount;
        std::cout << ITAL B_GRAY"\t\t\t\t" << _name << " (hit[" << _hit << "] energy[" << _energy << "])\n" << NORM << std::endl;
        if ( _energy <= 0 )
            _energy = 0;
    }
    else {
        if ( _hit == 0 )
            std::cout << RED << "ClapTrap "<< _name << " has no more hit" << RESET << std::endl;
        if ( _energy == 0 )
            std::cout << RED << "ClapTrap "<< _name << " has no more energy" << RESET << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::microseconds(400000));
}

