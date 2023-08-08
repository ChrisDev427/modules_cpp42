/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:37:13 by chris             #+#    #+#             */
/*   Updated: 2023/08/01 15:02:39 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) {

    std::cout << GREEN << "ScavTrap Default Constructor called" << RESET << std::endl;
    name = "default_name";
    hit = 100;  
    energy = 50;
    attackDamage = 20;

    return;

}

ScavTrap::ScavTrap( std::string sName ) {

    std::cout << GREEN << "ScavTrap Parametric Constructor called " << RESET;
    std::cout << B_GRAY << ITAL << "(instance -> [" << sName << "])" << RESET << NORM <<std::endl;
    name = sName;
    hit = 100;
    energy = 50;
    attackDamage = 20;

    return;
}

ScavTrap::ScavTrap( ScavTrap const & src ) {

    std::cout << GREEN << "ScavTrap Copy Constructor called" << RESET << std::endl;
    *this = src;

    return;

}

ScavTrap::~ScavTrap( void ) {

    std::cout << B_GRAY << ITAL << name << RED <<" ScavTrap Destructor called" << RESET << NORM << std::endl;

    return;

}

ScavTrap & ScavTrap::operator=( ScavTrap const & rhs ) {

    std::cout << GREEN << "ScavTrap Assignment operator called\n" << RESET << std::endl;

    hit = rhs.getValue( "hit" );
    energy = rhs.getValue( "energy" );
    attackDamage = rhs.getValue( "attackDamage" );

    return *this;

}

int ScavTrap::getValue( const std::string value ) const{

    if ( value == "hit" )
        return hit;
    else if ( value == "energy" )
        return energy;
    else if ( value == "attackDamage" )
        return attackDamage;
    else
        std::cout << "Error: getValue(): '" << value << "' value not found ";

    return -1;
}

void ScavTrap::attack( const std::string& target ) {

    if ( energy > 0 && hit > 0 ) {

        std::cout << B_YELLOW <<  "ScavTrap "<< name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << RESET << std::endl;
        this->energy--;
        std::cout << ITAL B_GRAY"\t\t\t\t" << name << " (hit[" << hit << "] energy[" << energy << "])\n" << NORM << std::endl;
        if ( energy <= 0 )
            energy = 0;
    }
    else {
        if ( hit == 0 )
            std::cout << RED << "ScavTrap "<< name << " has no more hit" << RESET << std::endl;
        if ( energy == 0 )
            std::cout << RED << "ScavTrap "<< name << " has no more energy" << RESET << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::microseconds(400000));
}

void ScavTrap::guardGate( void ) {

    std::cout << B_ORANGE << name << " is now in Gate Keeper mode... " << RESET;
    std::cout << B_MAGENTA << "Don't mess with " << name << " !\n" << RESET << std::endl;


}

// void ScavTrap::takeDamage( unsigned int amount ) {

//     if ( _hit > 0 && _energy > 0 ) {

//         std::cout << B_YELLOW << "ScavTrap "<< _name << " took " << amount << " damages from someone" << RESET << std::endl;
//         _hit -= amount;
//         std::cout << ITAL B_GRAY"\t\t\t\t" << _name << " (hit[" << _hit << "] energy[" << _energy << "])\n" << NORM << std::endl;

//         if ( _hit <= 0 )
//             _hit = 0;
//     }
//     else {
//         if ( _hit == 0 )
//             std::cout << RED << "ScavTrap "<< _name << " has no more hit" << RESET << std::endl;
//         if ( _energy == 0 )
//             std::cout << RED << "ScavTrap "<< _name << " has no more energy" << RESET << std::endl;
//     }
//     std::this_thread::sleep_for(std::chrono::microseconds(400000));
// }

// void ScavTrap::beRepaired( unsigned int amount ) {

//     if ( _hit > 0 && _energy > 0 ) {
        
//         std::cout << B_YELLOW << "ScavTrap "<< _name << " repairs [-" << amount << " energy] [+" << amount << " hits]" << RESET << std::endl;
//         _hit += amount;
//         _energy -= amount;
//         std::cout << ITAL B_GRAY"\t\t\t\t" << _name << " (hit[" << _hit << "] energy[" << _energy << "])\n" << NORM << std::endl;
//         if ( _energy <= 0 )
//             _energy = 0;
//     }
//     else {
//         if ( _hit == 0 )
//             std::cout << RED << "ScavTrap "<< _name << " has no more hit" << RESET << std::endl;
//         if ( _energy == 0 )
//             std::cout << RED << "ScavTrap "<< _name << " has no more energy" << RESET << std::endl;
//     }
//     std::this_thread::sleep_for(std::chrono::microseconds(400000));
// }
