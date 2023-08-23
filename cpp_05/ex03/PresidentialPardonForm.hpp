/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:41:11 by chris             #+#    #+#             */
/*   Updated: 2023/08/22 12:21:11 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <stdexcept>
# include <fstream>
# include <ctime>


class AForm;

class PresidentialPardonForm : virtual public AForm {

    public:

    

        PresidentialPardonForm( void );
        PresidentialPardonForm( std::string const target );
        PresidentialPardonForm( PresidentialPardonForm const & src );
        virtual ~PresidentialPardonForm( void );

        PresidentialPardonForm & operator=( PresidentialPardonForm const & rhs );

        virtual void        execute( Bureaucrat const & executor ) const ;


};

#endif /******************************************************* PRESIDENTIALPARDONFORM_HPP*/