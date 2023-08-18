/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:41:11 by chris             #+#    #+#             */
/*   Updated: 2023/08/18 19:04:26 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>

class Form {

    public:

        class gradeExcept : public std::exception {

            public:

                gradeExcept( const char* type ) throw();
                ~gradeExcept( void ) throw();

                virtual const char* what() const throw();

            private:

                const char* _errorType;
        };

     //----------------------------------------------------------------------------

        Form( void );
        Form( std::string const name, int const gradeSign, int const gradeExec );
        Form( Form const & src );
        virtual ~Form( void );

        Form & operator=( Form const & rhs );

        std::string getName( void ) const;
        int         getGradeSign( void ) const;
        int         getGradeExec( void ) const;
        bool        getSigned( void ) const;
        std::string getFormState( bool state ) const;

        void        beSigned( Bureaucrat & ref );

        

    private:

        int const           _gradeSign;
        int const           _gradeExec;
        bool                _signed;
        std::string const   _name;
        std::string         _reason;

};

std::ostream & operator<<( std::ostream & o, Form const & i );

#endif /******************************************************* FORM_HPP*/