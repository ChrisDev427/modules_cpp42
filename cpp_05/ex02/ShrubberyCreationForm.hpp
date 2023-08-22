/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:41:11 by chris             #+#    #+#             */
/*   Updated: 2023/08/21 19:05:58 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

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


        // virtual std::string getName( void ) const;
        // virtual int         getGradeSign( void ) const;
        // virtual int         getGradeExec( void ) const;
        // virtual bool        getSigned( void ) const;
        // virtual std::string getFormState( bool state ) const;

        // virtual void setName( std::string name );
        // virtual void setGradeSign( int sign );
        // virtual void setGradeExec( int exec );
        // virtual void setFormState( bool state ) const;

        // virtual void        beSigned( Bureaucrat & ref );

    

};


#endif /******************************************************* ShrubberyCreationForm_HPP*/