/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:41:11 by chris             #+#    #+#             */
/*   Updated: 2023/08/22 12:20:55 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"


class Intern {

    public:

        Intern( void );
        Intern( Intern const & src );
        virtual ~Intern( void );

        Intern & operator=( Intern const & rhs );

        AForm*  makeForm( std::string formName, std::string formTarget );

};

#endif /******************************************************* INTERN_HPP*/