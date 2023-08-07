/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 07:42:38 by chris             #+#    #+#             */
/*   Updated: 2023/08/05 18:49:18 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TEST_HPP
# define TEST_HPP

# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"
# include "Brain.hpp"
# include "policeColor.hpp"
# include <iostream>
# include <string>

void initTab(  const Animal* tab[], int size );
void initStrings( const Animal* tab[], int size );
void freeClassArray( const Animal* tab[], int size );

#endif /*************TEST_HPP*/
