/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:30:56 by chris             #+#    #+#             */
/*   Updated: 2023/07/25 12:02:04 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB {

public:

    HumanB( std::string name );
    ~HumanB();

    void    attack( void );
    void    setWeapon( Weapon& ref );

private:

    Weapon* weapon;
    std::string name;
};

#endif /*HUMANB_HPP*/