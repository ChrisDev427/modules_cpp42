/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:41:11 by chris             #+#    #+#             */
/*   Updated: 2023/08/22 12:20:55 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <stdexcept>
# include <fstream>

class AForm;

class ShrubberyCreationForm : virtual public AForm {

    public:

    

        ShrubberyCreationForm( void );
        ShrubberyCreationForm( std::string const target );
        ShrubberyCreationForm( ShrubberyCreationForm const & src );
        virtual ~ShrubberyCreationForm( void );

        ShrubberyCreationForm & operator=( ShrubberyCreationForm const & rhs );

        virtual void        execute( Bureaucrat const & executor ) const ;


};

#endif /******************************************************* SHRUBBERYCREATIONFORM_HPP*/