/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:37:36 by chris             #+#    #+#             */
/*   Updated: 2023/08/28 14:58:09 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) {

    std::cout << GREEN << "ClapTrap Default Constructor called\n" << RESET << std::endl;

    _name = "default_name";
    _hit = 10;
    _energy = 10;
    _attackDamage = 0;

    return;

}

ClapTrap::ClapTrap( std::string name ) : _name( name ) {

    std::cout << GREEN << "ClapTrap Parametric Constructor called " << RESET;
    std::cout << B_GRAY << ITAL << "(instance -> [" << _name << "])" << RESET << NORM <<std::endl;
    
    _hit = 10;
    _energy = 10;
    _attackDamage = 0;

    return;
}

ClapTrap::ClapTrap( ClapTrap const & src ) {

    std::cout << GREEN << "ClapTrap Copy Constructor called\n" << RESET << std::endl;
    
    _name = src._name;
    _hit = src._hit;
    _energy = src._energy;
    _attackDamage = src._attackDamage;

    return;

}

ClapTrap::~ClapTrap( void ) {

    std::cout << B_GRAY << ITAL << _name << RED <<" ClapTrap Destructor called\n" << RESET << NORM << std::endl;

    return;

}

ClapTrap & ClapTrap::operator=( ClapTrap const & rhs ) {

    std::cout << GREEN << "ClapTrap Assignment operator called\n" << RESET << std::endl;

    _name = rhs._name;
    _hit = rhs._hit;
    _energy = rhs._energy;
    _attackDamage = rhs._attackDamage;

    return *this;

}

void ClapTrap::attack( const std::string& target ) {

    if ( _energy > 0 && _hit > 0 ) {

        _energy--;
        if ( _energy <= 0 )
            _energy = 0;
        std::cout << B_YELLOW <<  "ClapTrap "<< _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
        std::cout << ITAL B_GRAY"\t\t\t\t" << _name << " (hit[" << _hit << "] energy[" << _energy << "])\n" << NORM << std::endl;
    }
    else {
        if ( _hit == 0 )
            std::cout << RED << "ClapTrap "<< _name << " cannot attack cause hit is 0" << RESET << std::endl;
        if ( _energy == 0 )
            std::cout << RED << "ClapTrap "<< _name << " cannot attack cause energy is 0" << RESET << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

void ClapTrap::takeDamage( unsigned int amount ) {

    if ( _hit > 0 && _hit > 0 ) {

        _hit -= amount;
        if ( _hit <= 0 )
            _hit = 0;
        std::cout << B_YELLOW << "ClapTrap "<< _name << " took " << amount << " damages" << RESET << std::endl;
        std::cout << ITAL B_GRAY"\t\t\t\t" << _name << " (hit[" << _hit << "] energy[" << _energy << "])\n" << NORM << std::endl;

    }
    else {
        if ( _hit == 0 )
            std::cout << RED << "ClapTrap "<< _name << " cannot take more damages cause hit is 0" << RESET << std::endl;
        if ( _energy == 0 )
            std::cout << RED << "ClapTrap "<< _name << " cannot take more damages cause energy is 0" << RESET << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

void ClapTrap::beRepaired( unsigned int amount ) {

    if ( _hit > 0 && _energy > 0 ) {
        
        std::cout << B_YELLOW << "ClapTrap "<< _name << " repairs [-1 energy] [+" << amount << " hits]" << RESET << std::endl;
        _hit += amount;
        _energy--;
        if ( _energy <= 0 )
            _energy = 0;
        std::cout << ITAL B_GRAY"\t\t\t\t" << _name << " (hit[" << _hit << "] energy[" << _energy << "])\n" << NORM << std::endl;
    }
    else {
        if ( _hit == 0 )
            std::cout << RED << "ClapTrap "<< _name << " cannot repairs cause hit is 0" << RESET << std::endl;
        if ( _energy == 0 )
            std::cout << RED << "ClapTrap "<< _name << " cannot repairs cause energy is 0" << RESET << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

void ClapTrap::printValues( void ) const{

    std::cout << B_ORANGE << _name << B_GRAY << ITAL << " ClapTrap" << RESET << std::endl;
    std::cout << B_BLUE << "hit[";
    std::cout << B_ORANGE << _hit;
    std::cout << B_BLUE << "] energy[";
    std::cout << B_ORANGE << _energy;
    std::cout << B_BLUE << "] attackDamage[";
    std::cout << B_ORANGE << _attackDamage;
    std::cout << B_BLUE << "]" << RESET << std::endl;
    std::cout << B_GRAY << "----------------------------------------------" << RESET << std::endl;

}