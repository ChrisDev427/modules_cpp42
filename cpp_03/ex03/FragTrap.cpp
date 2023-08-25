/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:37:13 by chris             #+#    #+#             */
/*   Updated: 2023/08/25 16:48:14 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "FragTrap.hpp"

FragTrap::FragTrap( void ) {

    std::cout << GREEN << "FragTrap Default Constructor called" << RESET << std::endl;
    
    name = "defaultName";
    hit = 100;
    energy = 100;
    attackDamage = 30;
    return;
}

FragTrap::FragTrap( std::string sName ) : ClapTrap(sName) {

    std::cout << GREEN << "FragTrap Parametric Constructor called " << RESET;
    std::cout << B_GRAY << ITAL << "(instance -> [" << sName << "])\n" << RESET << NORM <<std::endl;
    
    ClapTrap::hit = 100;
    ClapTrap::energy = 100;
    ClapTrap::attackDamage = 30;

    hitTmp = ClapTrap::hit;
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

    hit = rhs.hit; //rhs.getValue( "hit" );
    energy = rhs.energy;//rhs.getValue( "energy" );
    attackDamage = rhs.attackDamage;//rhs.getValue( "attackDamage" );

    return *this;

}

// int FragTrap::getValue( const std::string value ) const{

//     if ( value == "hit" )
//         return hit;
//     else if ( value == "energy" )
//         return energy;
//     else if ( value == "attackDamage" )
//         return attackDamage;
//     else
//         std::cout << "Error: getValue(): '" << value << "' value not found ";

//     return -1;
// }

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

void FragTrap::highFivesGuys( void ) {

    std::cout << B_ORANGE << "\nHighFivesGuys ! ************************************" << RESET << std::endl;
    std::cout << B_CYAN << "    FragTrap " << name << "\n    is asking for a high fives !!!" << RESET << std::endl;
    std::cout << ORANGE << "****************************************************\n" << std::endl;

}
