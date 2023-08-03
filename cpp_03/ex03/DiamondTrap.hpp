/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:38:27 by chris             #+#    #+#             */
/*   Updated: 2023/08/03 15:55:37 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"


class DiamondTrap : public virtual FragTrap, public virtual ScavTrap {

public:

    DiamondTrap( void );
    DiamondTrap( std::string name );
    DiamondTrap( DiamondTrap const & src );
    ~DiamondTrap( void ); virtual

    DiamondTrap & operator=( DiamondTrap const & rhs );

    int         getValue( std::string value ) const;
    void        printValues( void ) const;

    void        whoAmI( void );


private:

    std::string _name;

};


#endif /**********************************************************DIAMONDTRAP_HPP*/