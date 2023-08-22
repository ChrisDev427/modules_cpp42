/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:41:11 by chris             #+#    #+#             */
/*   Updated: 2023/08/21 19:14:56 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <stdexcept>
# include "policeColor.hpp"

class Bureaucrat;

class AForm {

    public:

        class gradeExcept : public std::exception {

            public:

                gradeExcept( const char* type ) throw();
                virtual ~gradeExcept( void ) throw();

                virtual const char* what() const throw();

            private:

                const char* _errorType;
        };

     //----------------------------------------------------------------------------

        AForm( void );
        AForm( AForm const & src );
        virtual ~AForm( void );

        AForm & operator=( AForm const & rhs );

        virtual std::string       getName( void ) const;
        virtual std::string       getTarget( void ) const;
        virtual int               getGradeSign( void ) const;
        virtual int               getGradeExec( void ) const;
        virtual bool              getSigned( void ) const;
        virtual std::string       getFormState( bool state ) const;

        virtual void              setName( std::string name );
        virtual void              setTarget( std::string target );
        virtual void              setGradeSign( int sign );
        virtual void              setGradeExec( int exec );
        virtual void              setSigned( bool sign );

        virtual void        beSigned( Bureaucrat & ref );
        virtual void        checkAccess( Bureaucrat const & executor ) const;

        virtual void        execute( Bureaucrat const & executor ) const = 0;

        

    private:

        int const           _gradeSign;
        int const           _gradeExec;
        bool                _signed;
        std::string const   _name;
        std::string const   _target;

};

std::ostream & operator<<( std::ostream & o, AForm const & i );

#endif /******************************************************* AFORM_HPP*/