/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:55:33 by chris             #+#    #+#             */
/*   Updated: 2023/08/30 10:03:34 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "IMateriaSource.hpp"
# include <iomanip>
# include <iostream>
# include <string>
# include "policeColor.hpp"

// class AMateria;
class ICharacter;



class MateriaSource : virtual public IMateriaSource {

public:

    MateriaSource( void );
    MateriaSource( MateriaSource const & src );
    virtual ~MateriaSource( void );

    MateriaSource & operator=( MateriaSource const & rhs );

    virtual void        learnMateria(AMateria* m);
    virtual AMateria*   createMateria(std::string const & type);

private:

    AMateria* _materiaLearned[4];

};

#endif /************************************************* MATERIASOURCE_HPP */