/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:37:13 by chris             #+#    #+#             */
/*   Updated: 2023/08/28 15:00:08 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) {

    std::cout << GREEN << "ScavTrap Default Constructor called" << RESET << std::endl;

    name = "defaultName";
    hit = 100;
    energy = 50;
    attackDamage = 20;
    return;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {

    std::cout << GREEN << "ScavTrap Parametric Constructor called " << RESET;
    std::cout << B_GRAY << ITAL << "(instance -> [" << name << "])\n" << RESET << NORM <<std::endl;
   
    hit = 100;
    energy = 50;
    attackDamage = 20;

    return;
}

ScavTrap::ScavTrap( ScavTrap const & src ) {

    std::cout << GREEN << "ScavTrap Copy Constructor called" << RESET << std::endl;
    
    name = src.name;
    hit = src.hit;
    energy = src.energy;
    attackDamage = src.attackDamage;

    return;

}

ScavTrap::~ScavTrap( void ) {

    std::cout << B_GRAY << ITAL << name << RED <<" ScavTrap Destructor called" << RESET << NORM << std::endl;

    return;

}

ScavTrap & ScavTrap::operator=( ScavTrap const & rhs ) {

    std::cout << GREEN << "ScavTrap Assignment operator called\n" << RESET << std::endl;

    name = rhs.name;
    hit = rhs.hit;
    energy = rhs.energy;
    attackDamage = rhs.attackDamage;

    return *this;

}

void ScavTrap::attack( const std::string& target ) {

    if ( energy > 0 && hit > 0 ) {

        energy--;
        if ( energy <= 0 )
            energy = 0;
        std::cout << B_YELLOW <<  "ScavTrap "<< name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << RESET << std::endl;
        std::cout << ITAL B_GRAY"\t\t\t\t" << name << " (hit[" << hit << "] energy[" << energy << "])\n" << NORM << std::endl;
    }
    else {
        if ( hit == 0 )
            std::cout << RED << "ScavTrap "<< name << " cannot attack cause hit is 0" << RESET << std::endl;
        if ( energy == 0 )
            std::cout << RED << "ScavTrap "<< name << " cannot attack cause energy is 0" << RESET << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

void ScavTrap::guardGate( void ) {

    std::cout << B_ORANGE << "\nGuard Gate ! ***************************************" << RESET << std::endl;
    std::cout << B_CYAN << "    " << "ScavTrap " << name << " is now in Gate Keeper mode... " << RESET << std::endl;
    std::cout << B_RED << "    Don't mess with " << name << " !!!" << RESET << std::endl;
    std::cout << ORANGE << "****************************************************\n" << std::endl;

}

void ScavTrap::printValues( void ) const{

    std::cout << B_ORANGE << name << B_GRAY << ITAL << " ScavTrap" << RESET << std::endl;
    std::cout << B_BLUE << "hit[";
    std::cout << B_ORANGE << hit;
    std::cout << B_BLUE << "] energy[";
    std::cout << B_ORANGE << energy;
    std::cout << B_BLUE << "] attackDamage[";
    std::cout << B_ORANGE << attackDamage;
    std::cout << B_BLUE << "]" << RESET << std::endl;
    std::cout << B_GRAY << "----------------------------------------------" << RESET << std::endl;

}
