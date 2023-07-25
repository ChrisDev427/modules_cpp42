/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:30:48 by chris             #+#    #+#             */
/*   Updated: 2023/07/24 19:08:15 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include <string>
# include "Weapon.hpp"


class HumanA {

public:


    HumanA( void );
    ~HumanA( void );

    Weapon& weapon;
    std::string name;
    
    void    attack( void );


};

#endif /*HUMANA_HPP*/