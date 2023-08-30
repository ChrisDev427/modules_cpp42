/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:37:13 by chris             #+#    #+#             */
/*   Updated: 2023/08/28 13:38:26 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) {

    std::cout << GREEN << "ClapTrap Default Constructor called" << RESET << std::endl;
    name = "defaultName";
    hit = 10;
    energy = 10;
    attackDamage = 0;
    
    return;
}

ClapTrap::ClapTrap( std::string name ) : name( name ) {

    std::cout << GREEN << "ClapTrap Parametric Constructor called " << RESET;
    std::cout << B_GRAY << ITAL << "(instance -> [" << name << "])\n" << RESET << NORM <<std::endl;
    hit = 10;
    energy = 10;
    attackDamage = 0;

    return;
}

ClapTrap::ClapTrap( ClapTrap const & src ) {

    std::cout << GREEN << "ClapTrap Copy Constructor called" << RESET << std::endl;

    name = src.name;
    hit = src.hit;
    energy = src.energy;
    attackDamage = src.attackDamage;

    return;
}

ClapTrap::~ClapTrap( void ) {

    std::cout << B_GRAY << ITAL << name << RED <<" ClapTrap Destructor called" << RESET << NORM << std::endl;

    return;
}

ClapTrap & ClapTrap::operator=( ClapTrap const & rhs ) {

    std::cout << GREEN << "ClapTrap Assignment operator called\n" << RESET << std::endl;

    name = rhs.name;
    hit = rhs.hit;
    energy = rhs.energy;
    attackDamage = rhs.attackDamage;

    return *this;
}

void ClapTrap::attack( const std::string& target ) {

    if ( energy > 0 && hit > 0 ) {

        energy--;
        if ( energy <= 0 )
            energy = 0;
        std::cout << B_YELLOW <<  "ClapTrap "<< name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << RESET << std::endl;
        std::cout << ITAL B_GRAY"\t\t\t\t" << name << " (hit[" << hit << "] energy[" << energy << "])\n" << NORM << std::endl;
    }
    else {
        if ( hit == 0 )
            std::cout << RED << "ClapTrap "<< name << " cannot attack cause hit is 0" << RESET << std::endl;
        if ( energy == 0 )
            std::cout << RED << "ClapTrap "<< name << " cannot attack cause energy is 0" << RESET << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

void ClapTrap::takeDamage( unsigned int amount ) {

    if ( hit > 0 && hit > 0 ) {

        hit -= amount;
        if ( hit <= 0 )
            hit = 0;
        std::cout << B_YELLOW << "ClapTrap "<< name << " took " << amount << " damages" << RESET << std::endl;
        std::cout << ITAL B_GRAY"\t\t\t\t" << name << " (hit[" << hit << "] energy[" << energy << "])\n" << NORM << std::endl;

    }
    else {
        if ( hit == 0 )
            std::cout << RED << "ClapTrap "<< name << " cannot take more damages cause hit is 0" << RESET << std::endl;
        if ( energy == 0 )
            std::cout << RED << "ClapTrap "<< name << " cannot take more damages cause energy is 0" << RESET << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

void ClapTrap::beRepaired( unsigned int amount ) {

    if ( hit > 0 && energy > 0 ) {
        
        std::cout << B_YELLOW << "ClapTrap "<< name << " repairs [-1 energy] [+" << amount << " hits]" << RESET << std::endl;
        hit += amount;
        energy--;
        if ( energy <= 0 )
            energy = 0;
        std::cout << ITAL B_GRAY"\t\t\t\t" << name << " (hit[" << hit << "] energy[" << energy << "])\n" << NORM << std::endl;
    }
    else {
        if ( hit == 0 )
            std::cout << RED << "ClapTrap "<< name << " cannot repairs cause hit is 0" << RESET << std::endl;
        if ( energy == 0 )
            std::cout << RED << "ClapTrap "<< name << " cannot repairs cause energy is 0" << RESET << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

void ClapTrap::printValues( void ) const{

    std::cout << B_ORANGE << name << B_GRAY << ITAL << " ClapTrap" << RESET << std::endl;
    std::cout << B_BLUE << "hit[";
    std::cout << B_ORANGE << hit;
    std::cout << B_BLUE << "] energy[";
    std::cout << B_ORANGE << energy;
    std::cout << B_BLUE << "] attackDamage[";
    std::cout << B_ORANGE << attackDamage;
    std::cout << B_BLUE << "]" << RESET << std::endl;
    std::cout << B_GRAY << "----------------------------------------------" << RESET << std::endl;

}