/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:36:11 by chris             #+#    #+#             */
/*   Updated: 2023/07/26 08:46:33 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <string>
# include <iostream>
# include <fstream>

class Harl {

public:

    Harl( void );
    ~Harl( void );

    std::string levels[4];
    void    complain( std::string level );

private:

    void        ( Harl::*_ptr[4] )(void);

    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
    
};

#endif /*HARL_HPP*/