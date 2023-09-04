/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 08:27:31 by chris             #+#    #+#             */
/*   Updated: 2023/09/04 10:39:15 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include "policeColor.hpp"

class Base {

public:

    virtual ~Base( void );

};
Base *  generate(void);
void    identify(Base* p);
void    identify(Base& p);

#endif /************************************************************* BASE_HPP*/
