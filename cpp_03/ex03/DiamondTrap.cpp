/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:37:13 by chris             #+#    #+#             */
/*   Updated: 2023/08/03 17:17:18 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap( void ) {

    std::cout << GREEN << "DiamondTrap Default Constructor called" << RESET << std::endl;
    
    name = "defaultName";
    hit = 100;
    energy = 50;
    attackDamage = 30;
    
    return;
}

DiamondTrap::DiamondTrap( std::string dName ) : ClapTrap(dName + "_clap_name"), FragTrap(dName), ScavTrap(dName), _name( dName ) {

    std::cout << GREEN << "DiamondTrap Parametric Constructor called " << RESET;
    std::cout << B_GRAY << ITAL << "(instance -> [" << dName << "])\n" << RESET << NORM <<std::endl;
    
    FragTrap::hit = FragTrap::hitTmp;
    FragTrap::attackDamage = FragTrap::attackDamageTmp;
        
    return;
}

DiamondTrap::DiamondTrap( DiamondTrap const & src ) {

    std::cout << GREEN << "DiamondTrap Copy Constructor called" << RESET << std::endl;
    *this = src;

    return;

}

DiamondTrap::~DiamondTrap( void ) {

    std::cout << B_GRAY << ITAL << _name << RED <<" DiamondTrap Destructor called" << RESET << NORM << std::endl;

    return;

}

DiamondTrap & DiamondTrap::operator=( DiamondTrap const & rhs ) {

    std::cout << GREEN << "DiamondTrap Assignment operator called\n" << RESET << std::endl;

    FragTrap::hit = rhs.getValue( "hit" );
    ScavTrap::energy = rhs.getValue( "energy" );
    FragTrap::attackDamage = rhs.getValue( "attackDamage" );

    return *this;

}

int DiamondTrap::getValue( const std::string value ) const{

    if ( value == "hit" )
        return FragTrap::hit;
    else if ( value == "energy" )
        return ScavTrap::energy;
    else if ( value == "attackDamage" )
        return FragTrap::attackDamage;
    else
        std::cout << "Error: getValue(): '" << value << "' value not found ";

    return -1;
}

void DiamondTrap::printValues( void ) const{

    std::cout << B_ORANGE << name << B_GRAY << ITAL << " DiamondTrap" << RESET << std::endl;
    std::cout << B_BLUE << "hit[";
    std::cout << B_ORANGE << hit;
    std::cout << B_BLUE << "] energy[";
    std::cout << B_ORANGE << energy;
    std::cout << B_BLUE << "] attackDamage[";
    std::cout << B_ORANGE << attackDamage;
    std::cout << B_BLUE << "]" << RESET << std::endl;
    std::cout << B_GRAY << "----------------------------------------------" << RESET << std::endl;

}

void DiamondTrap::whoAmI( void ) {

    std::cout << B_ORANGE << "\nWho Am I ? *****************************************" << RESET << std::endl;
    std::cout << B_CYAN << "    I am : " << B_GRAY << ITAL << _name << NORM << B_CYAN << " from DiamondTrap" << std::endl;
    std::cout << B_CYAN << "    Sub-Object : " << B_GRAY << ITAL << ClapTrap::name << NORM << B_CYAN << " from ClapTrap" << RESET << std::endl;
    std::cout << ORANGE << "****************************************************\n" << std::endl;

}