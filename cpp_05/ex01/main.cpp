/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:31:44 by chris             #+#    #+#             */
/*   Updated: 2023/08/19 18:55:52 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"




void test1( void ) {

    Bureaucrat franck( "Franck", 26 );
    
    Form form1( "Form1", 25, 58 );

    std::cout << form1 << std::endl;

    franck.signForm( form1 );

    Form form2 = form1;

    std::cout << form2 << std::endl;


        
}

int main() {

    
    test1();
    // test2();
    

    


    return 0;
}