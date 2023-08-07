/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 07:42:38 by chris             #+#    #+#             */
/*   Updated: 2023/08/07 10:14:51 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TEST_HPP
# define TEST_HPP

# include "A_Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"
# include "Brain.hpp"
# include "policeColor.hpp"
# include <iostream>
# include <string>

void initTab(  const A_Animal* tab[], int size );
void initStrings( const A_Animal* tab[], int size );
void freeClassArray( const A_Animal* tab[], int size );

#endif /*************TEST_HPP*/
