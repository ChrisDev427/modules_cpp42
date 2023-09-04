/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:29:13 by chris             #+#    #+#             */
/*   Updated: 2023/09/04 12:29:18 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>
# include <cstdlib>
# include <stdexcept>
# include <cmath>
# include <climits>
#include <float.h>

class ScalarConverter {

private:
    ScalarConverter( void );
    ScalarConverter( ScalarConverter const & src );
    ~ScalarConverter( void ); virtual
    ScalarConverter & operator=( ScalarConverter const & rhs );
public:
    static void convert ( std::string & input );
};

#endif /************************************************** SCALARCONVERTER_HPP*/