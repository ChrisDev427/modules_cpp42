/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 08:58:57 by chris             #+#    #+#             */
/*   Updated: 2023/07/24 18:23:10 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>


int main() {

    std::string string = "HI THIS IS BRAIN";
    std::string* stringPTR = &string;
    std::string& stringREF = string;

    std::cout << "string address    = " << &string << std::endl;
    std::cout << "stringPTR         = " << stringPTR << std::endl;
    std::cout << "stringREF address = " << &stringREF << std::endl << std::endl;

    std::cout << "string    = " << string << std::endl;
    std::cout << "stringPTR = " << *stringPTR << std::endl;
    std::cout << "stringREF = " << stringREF << std::endl;

    return 0;
}