/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:41:11 by chris             #+#    #+#             */
/*   Updated: 2023/08/22 12:21:11 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <stdexcept>
# include <fstream>
# include <ctime>


class AForm;

class RobotomyRequestForm : virtual public AForm {

    public:

    

        RobotomyRequestForm( void );
        RobotomyRequestForm( std::string const target );
        RobotomyRequestForm( RobotomyRequestForm const & src );
        virtual ~RobotomyRequestForm( void );

        RobotomyRequestForm & operator=( RobotomyRequestForm const & rhs );

        virtual void        execute( Bureaucrat const & executor ) const ;


};

#endif /******************************************************* ROBOTOMYREQUESTFORM_HPP*/