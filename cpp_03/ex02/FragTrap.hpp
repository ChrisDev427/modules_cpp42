/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:38:27 by chris             #+#    #+#             */
/*   Updated: 2023/08/01 15:20:06 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <thread>

class FragTrap : ClapTrap {

public:

    FragTrap( void );
    FragTrap( std::string sName );
    FragTrap( FragTrap const & src );
    ~FragTrap( void ); virtual

    FragTrap & operator=( FragTrap const & rhs );

    void attack(const std::string& target);
    void highFivesGuys( void );

    int getValue( std::string value ) const;


};


#endif /**********************************************************FRAGTRAP_HPP*/