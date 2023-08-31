/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:53:11 by chris             #+#    #+#             */
/*   Updated: 2023/08/30 10:05:20 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <iostream>
# include <string>
# include "policeColor.hpp"

class IMateriaSource {

public:

    virtual ~IMateriaSource() {}
    virtual void        learnMateria(AMateria* m) = 0;
    virtual AMateria*   createMateria(std::string const & type) = 0;

};


#endif /****************************** IMATERIASOURCE_HPP */