/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:38:27 by chris             #+#    #+#             */
/*   Updated: 2023/08/27 21:08:32 by chris            ###   ########.fr       */
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
    virtual ~DiamondTrap( void );

    DiamondTrap & operator=( DiamondTrap const & rhs );

    void        printValues( void ) const;
    void        whoAmI( void );


private:

    std::string name;

};


#endif /**********************************************************DIAMONDTRAP_HPP*/