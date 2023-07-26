/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:31:05 by chris             #+#    #+#             */
/*   Updated: 2023/07/25 12:03:44 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <string>

class Weapon {

public:

    Weapon( std::string type );
    ~Weapon( void );

    std::string&    getType( void );
    void            setType( std::string value );

private:

    std::string _type;

};

#endif /*WEAPON_HPP*/