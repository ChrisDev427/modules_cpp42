/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:41:11 by chris             #+#    #+#             */
/*   Updated: 2023/08/18 08:42:17 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

class Bureaucrat {

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

        Bureaucrat( void );
        Bureaucrat( std::string const name, int grade );
        Bureaucrat( Bureaucrat const & src );
        virtual ~Bureaucrat( void );

        Bureaucrat & operator=( Bureaucrat const & rhs );

        std::string getName( void ) const;
        int         getGrade( void ) const;

        void        incremGrade( void );
        void        decremGrade( void );

    private:

        int                 _grade;
        std::string const   _name;

};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & i );

#endif /******************************************************* BUREAUCRAT_HPP*/