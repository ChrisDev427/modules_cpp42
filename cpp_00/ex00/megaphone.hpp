/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:08:17 by chris             #+#    #+#             */
/*   Updated: 2023/08/15 17:41:51 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEGAPHONE_HPP
# define MEGAPHONE_HPP
# include <iostream>
# include <string>

class Mega {

public:

    Mega( void );
    ~Mega(void);

    void    toUpper(std::string & str);
    void    megaphone( int ac, std::string args[] );

};

#endif /******************************************************  MEGAPHONE_HPP */