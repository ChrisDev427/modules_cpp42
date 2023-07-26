/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:30:48 by chris             #+#    #+#             */
/*   Updated: 2023/07/25 12:03:23 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include <string>
# include "Weapon.hpp"


class HumanA {

public:

    HumanA( std::string name, Weapon& ref );
    ~HumanA( void );

    void    attack( void );

private:

    Weapon&     weapon;
    std::string name;

};

#endif /*HUMANA_HPP*/