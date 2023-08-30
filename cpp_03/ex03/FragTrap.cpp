/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:37:13 by chris             #+#    #+#             */
/*   Updated: 2023/08/28 08:37:52 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "FragTrap.hpp"

FragTrap::FragTrap( void ) {

    std::cout << GREEN << "FragTrap Default Constructor called" << RESET << std::endl;
    
    name = "defaultName";
    hit = 100;
    energy = 100;
    attackDamage = 30;
    hitTmp = hit;
    attackDamageTmp = attackDamage;
    return;
}

FragTrap::FragTrap( std::string sName ) : ClapTrap(sName) {

    std::cout << GREEN << "FragTrap Parametric Constructor called " << RESET;
    std::cout << B_GRAY << ITAL << "(instance -> [" << sName << "])\n" << RESET << NORM <<std::endl;
    
    hit = 100;
    energy = 100;
    attackDamage = 30;
    hitTmp = hit;
    attackDamageTmp = attackDamage;
    return;
}

FragTrap::FragTrap( FragTrap const & src ) {

    std::cout << GREEN << "FragTrap Copy Constructor called" << RESET << std::endl;

    name = src.name;
    hit = src.hit;
    energy = src.energy;
    attackDamage = src.attackDamage;
    hitTmp = hit;
    attackDamageTmp = attackDamage;

    return;

}

FragTrap::~FragTrap( void ) {

    std::cout << B_GRAY << ITAL << name << RED <<" FragTrap Destructor called" << RESET << NORM << std::endl;

    return;

}

FragTrap & FragTrap::operator=( FragTrap const & rhs ) {

    std::cout << GREEN << "FragTrap Assignment operator called\n" << RESET << std::endl;

    name = rhs.name;
    hit = rhs.hit;
    energy = rhs.energy;
    attackDamage = rhs.attackDamage;
    hitTmp = hit;
    attackDamageTmp = attackDamage;

    return *this;

}

void FragTrap::highFivesGuys( void ) {

    std::cout << B_ORANGE << "\nHighFivesGuys ! ************************************" << RESET << std::endl;
    std::cout << B_CYAN << "    FragTrap " << name << "\n    is asking for a high fives !!!" << RESET << std::endl;
    std::cout << ORANGE << "****************************************************\n" << std::endl;

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