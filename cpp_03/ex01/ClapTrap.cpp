/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:37:13 by chris             #+#    #+#             */
/*   Updated: 2023/08/01 14:21:43 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) {

    std::cout << GREEN << "ClapTrap Default Constructor called" << RESET << std::endl;
    name = "default_name";
    hit = 10;
    energy = 10;
    attackDamage = 0;

    return;

}

ClapTrap::ClapTrap( std::string cName ) : name( cName ) {

    std::cout << GREEN << "ClapTrap Parametric Constructor called " << RESET;
    std::cout << B_GRAY << ITAL << "(instance -> [" << name << "])" << RESET << NORM <<std::endl;
    hit = 10;
    energy = 10;
    attackDamage = 0;

    return;
}

ClapTrap::ClapTrap( ClapTrap const & src ) {

    std::cout << GREEN << "ClapTrap Copy Constructor called" << RESET << std::endl;
    *this = src;

    return;

}

ClapTrap::~ClapTrap( void ) {

    std::cout << B_GRAY << ITAL << name << RED <<" ClapTrap Destructor called" << RESET << NORM << std::endl;

    return;

}

ClapTrap & ClapTrap::operator=( ClapTrap const & rhs ) {

    std::cout << GREEN << "ClapTrap Assignment operator called\n" << RESET << std::endl;

    this->hit = rhs.getValue( "hit" );
    this->energy = rhs.getValue( "energy" );
    this->attackDamage = rhs.getValue( "attackDamage" );

    return *this;

}

int ClapTrap::getValue( const std::string value ) const{

    if ( value == "hit" )
        return hit;
    if ( value == "energy" )
        return energy;
    if ( value == "attackDamage" )
        return attackDamage;
    else
        std::cout << "Error: getValue() value not found" << std::endl;

    return 0;
}

void ClapTrap::attack( const std::string& target ) {

    if ( this->energy > 0 && this->hit > 0 ) {

        std::cout << B_YELLOW <<  "ClapTrap "<< name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << RESET << std::endl;
        this->energy--;
        std::cout << ITAL B_GRAY"\t\t\t\t" << name << " (hit[" << hit << "] energy[" << energy << "])\n" << NORM << std::endl;
        if ( energy <= 0 )
            energy = 0;
    }
    else {
        if ( hit == 0 )
            std::cout << RED << "ClapTrap "<< name << " has no more hit" << RESET << std::endl;
        if ( energy == 0 )
            std::cout << RED << "ClapTrap "<< name << " has no more energy" << RESET << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::microseconds(400000));
}

void ClapTrap::takeDamage( unsigned int amount ) {

    if ( hit > 0 && energy > 0 ) {

        std::cout << B_YELLOW << "ClapTrap "<< name << " took " << amount << " damages from someone" << RESET << std::endl;
        hit -= amount;
        std::cout << ITAL B_GRAY"\t\t\t\t" << name << " (hit[" << hit << "] energy[" << energy << "])\n" << NORM << std::endl;

        if ( hit <= 0 )
            hit = 0;
    }
    else {
        if ( hit == 0 )
            std::cout << RED << "ClapTrap "<< name << " has no more hit" << RESET << std::endl;
        if ( energy == 0 )
            std::cout << RED << "ClapTrap "<< name << " has no more energy" << RESET << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::microseconds(400000));
}

void ClapTrap::beRepaired( unsigned int amount ) {

    if ( hit > 0 && energy > 0 ) {
        
        std::cout << B_YELLOW << "ClapTrap "<< name << " repairs [-" << amount << " energy] [+" << amount << " hits]" << RESET << std::endl;
        hit += amount;
        energy -= amount;
        std::cout << ITAL B_GRAY"\t\t\t\t" << name << " (hit[" << hit << "] energy[" << energy << "])\n" << NORM << std::endl;
        if ( energy <= 0 )
            energy = 0;
    }
    else {
        if ( hit == 0 )
            std::cout << RED << "ClapTrap "<< name << " has no more hit" << RESET << std::endl;
        if ( energy == 0 )
            std::cout << RED << "ClapTrap "<< name << " has no more energy" << RESET << std::endl;
    
    std::this_thread::sleep_for(std::chrono::microseconds(400000));
}
}
