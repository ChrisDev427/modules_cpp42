/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:37:13 by chris             #+#    #+#             */
/*   Updated: 2023/08/03 15:53:50 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "FragTrap.hpp"

FragTrap::FragTrap( void ) {

    std::cout << GREEN << "FragTrap Default Constructor called" << RESET << std::endl;
    // hit = 100;
    // energy = 100;
    // attackDamage = 30;
    return;
}

FragTrap::FragTrap( std::string sName ) : ClapTrap(sName) {

    std::cout << GREEN << "FragTrap Parametric Constructor called " << RESET;
    std::cout << B_GRAY << ITAL << "(instance -> [" << sName << "])\n" << RESET << NORM <<std::endl;
    // name = sName;
    // hit = 100;
    // energy = 100;
    // attackDamage = 30;

    ClapTrap::hit = 100;
    ClapTrap::energy = 100;
    ClapTrap::attackDamage = 30;

    hitTmp = ClapTrap::hit;
    // energyTmp = ClapTrap::energy;
    attackDamageTmp = ClapTrap::attackDamage;
    return;
}

FragTrap::FragTrap( FragTrap const & src ) {

    std::cout << GREEN << "FragTrap Copy Constructor called" << RESET << std::endl;
    *this = src;

    return;

}

FragTrap::~FragTrap( void ) {

    std::cout << B_GRAY << ITAL << name << RED <<" FragTrap Destructor called" << RESET << NORM << std::endl;

    return;

}

FragTrap & FragTrap::operator=( FragTrap const & rhs ) {

    std::cout << GREEN << "FragTrap Assignment operator called\n" << RESET << std::endl;

    hit = rhs.getValue( "hit" );
    energy = rhs.getValue( "energy" );
    attackDamage = rhs.getValue( "attackDamage" );

    return *this;

}

int FragTrap::getValue( const std::string value ) const{

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

void FragTrap::printValues( void ) const{

    std::cout << B_ORANGE << name << B_GRAY << ITAL << " FragTrap" << RESET << std::endl;
    std::cout << B_BLUE << "hit[";
    std::cout << B_ORANGE << hit;
    std::cout << B_BLUE << "] energy[";
    std::cout << B_ORANGE << energy;
    std::cout << B_BLUE << "] attackDamage[";
    std::cout << B_ORANGE << attackDamage;
    std::cout << B_BLUE << "]" << RESET << std::endl;
    std::cout << B_GRAY << "----------------------------------------------" << RESET << std::endl;

}
// void FragTrap::attack( const std::string& target ) {

//     if ( energy > 0 && hit > 0 ) {

//         std::cout << B_YELLOW <<  "FragTrap "<< name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << RESET << std::endl;
//         this->energy--;
//         std::cout << ITAL B_GRAY"\t\t\t\t" << name << " (hit[" << hit << "] energy[" << energy << "])\n" << NORM << std::endl;
//         if ( energy <= 0 )
//             energy = 0;
//     }
//     else {
//         if ( hit == 0 )
//             std::cout << RED << "FragTrap "<< name << " has no more hit" << RESET << std::endl;
//         if ( energy == 0 )
//             std::cout << RED << "FragTrap "<< name << " has no more energy" << RESET << std::endl;
//     }
//     std::this_thread::sleep_for(std::chrono::microseconds(400000));
// }

void FragTrap::highFivesGuys( void ) {

    std::cout << B_ORANGE << "\nHighFivesGuys ! ************************************" << RESET << std::endl;
    std::cout << B_CYAN << "    FragTrap " << name << "\n    is asking for a high fives !!!" << RESET << std::endl;
    std::cout << ORANGE << "****************************************************\n" << std::endl;



}

// void FragTrap::takeDamage( unsigned int amount ) {

//     if ( _hit > 0 && _energy > 0 ) {

//         std::cout << B_YELLOW << "FragTrap "<< _name << " took " << amount << " damages from someone" << RESET << std::endl;
//         _hit -= amount;
//         std::cout << ITAL B_GRAY"\t\t\t\t" << _name << " (hit[" << _hit << "] energy[" << _energy << "])\n" << NORM << std::endl;

//         if ( _hit <= 0 )
//             _hit = 0;
//     }
//     else {
//         if ( _hit == 0 )
//             std::cout << RED << "FragTrap "<< _name << " has no more hit" << RESET << std::endl;
//         if ( _energy == 0 )
//             std::cout << RED << "FragTrap "<< _name << " has no more energy" << RESET << std::endl;
//     }
//     std::this_thread::sleep_for(std::chrono::microseconds(400000));
// }

// void FragTrap::beRepaired( unsigned int amount ) {

//     if ( _hit > 0 && _energy > 0 ) {
        
//         std::cout << B_YELLOW << "FragTrap "<< _name << " repairs [-" << amount << " energy] [+" << amount << " hits]" << RESET << std::endl;
//         _hit += amount;
//         _energy -= amount;
//         std::cout << ITAL B_GRAY"\t\t\t\t" << _name << " (hit[" << _hit << "] energy[" << _energy << "])\n" << NORM << std::endl;
//         if ( _energy <= 0 )
//             _energy = 0;
//     }
//     else {
//         if ( _hit == 0 )
//             std::cout << RED << "FragTrap "<< _name << " has no more hit" << RESET << std::endl;
//         if ( _energy == 0 )
//             std::cout << RED << "FragTrap "<< _name << " has no more energy" << RESET << std::endl;
//     }
//     std::this_thread::sleep_for(std::chrono::microseconds(400000));
// }

