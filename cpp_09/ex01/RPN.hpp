/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:02:12 by chris             #+#    #+#             */
/*   Updated: 2023/09/19 18:15:18 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <fstream>
# include <sstream>    
# include <stack>
# include <stdexcept>

class RPN {

private:
    RPN( void );
    RPN( RPN const & src );
    RPN & operator=( RPN const & rhs ); 

    std::stack<int>     _stk;
   
    bool    _isSign ( char c );  
    int     _calculate( std::string & str, int nb1, int nb2 );
    void    _handleStack( char *str );

public:

    RPN( char* av );
    ~RPN( void );

};
#endif /************************************************************* RPN_HPP*/