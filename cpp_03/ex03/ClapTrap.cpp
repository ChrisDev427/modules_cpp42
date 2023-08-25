/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:37:13 by chris             #+#    #+#             */
/*   Updated: 2023/08/25 16:06:20 by chris            ###   ########.fr       */
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

ClapTrap::ClapTrap( std::string cName ) : name( cName ) {

    std::cout << GREEN << "ClapTrap Parametric Constructor called " << RESET;
    std::cout << B_GRAY << ITAL << "(instance -> [" << name << "])\n" << RESET << NORM <<std::endl;
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

    this->hit = rhs.hit; //rhs.getValue( "hit" );
    this->energy = rhs.energy; //rhs.getValue( "energy" );
    this->attackDamage = rhs.attackDamage; //rhs.getValue( "attackDamage" );

    return *this;

}

std::string ClapTrap::getName( void ) const{

    return name;
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

// int ClapTrap::getValue( const std::string value ) const{

//     if ( value == "hit" )
//         return hit;
//     if ( value == "energy" )
//         return energy;
//     if ( value == "attackDamage" )
//         return attackDamage;
//     else
//         std::cout << "Error: getValue() value not found" << std::endl;

//     return 0;
// }

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
            std::cout << RED << "ClapTrap "<< name << " attacks has no more hit" << RESET << std::endl;
        if ( energy == 0 )
            std::cout << RED << "ClapTrap "<< name << " attacks has no more energy" << RESET << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::microseconds(400000));
}

void ClapTrap::takeDamage( unsigned int amount ) {

    if ( this->hit > 0 && this->energy > 0 ) {

        std::cout << B_YELLOW << "ClapTrap "<< name << " took " << amount << " damages" << RESET << std::endl;
        this->hit -= amount;
        std::cout << ITAL B_GRAY"\t\t\t\t" << name << " (hit[" << hit << "] energy[" << energy << "])\n" << NORM << std::endl;

        if ( this->hit <= 0 )
            this->hit = 0;
    }
    else {
        if ( hit == 0 )
            std::cout << RED << "ClapTrap "<< name << " takeDamage has no more hit" << RESET << std::endl;
        if ( energy == 0 )
            std::cout << RED << "ClapTrap "<< name << " takeDamage has no more energy" << RESET << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::microseconds(400000));
}

void ClapTrap::beRepaired( unsigned int amount ) {

    if ( hit > 0 && energy > 0 ) {
        
        std::cout << B_YELLOW << "ClapTrap "<< name << " repairs [-1 energy] [+" << amount << " hits]" << RESET << std::endl;
        hit += amount;
        energy--;
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
