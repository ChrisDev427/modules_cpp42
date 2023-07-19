/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:08:15 by chris             #+#    #+#             */
/*   Updated: 2023/07/19 11:50:27 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "megaphone.hpp"

Mega::Mega(int argc, char **tab) {

    Mega::charTabToVector(argc, tab);
    for (std::vector<std::string>::size_type i = 0; i < Mega::arg.size(); i++)
        Mega::trimSpaces(Mega::arg[i]);
    Mega::vectorToString();
    Mega::UpperStr(Mega::str);
    return;
}

Mega::~Mega(void) {
    
    return;
}

void    Mega::UpperStr(std::string str) {
    
    for (std::string::iterator it = str.begin(); it != str.end(); ++it)
        for (std::size_t i = 0; i < str.length(); ++i)
            Mega::str[i] = std::toupper(str[i]);
}

void    Mega::charTabToVector(int argc, char **tab) {

    for (int i = 1; i < argc; ++i)
        Mega::arg.push_back(tab[i]);

    return;
}

void Mega::vectorToString(void) {

    std::ostringstream oss;
    for (std::vector<std::string>::size_type i = 0;  i < Mega::arg.size(); ++i)
        oss << Mega::arg[i] << " ";
    Mega::str = oss.str();
    Mega::trimSpaces(Mega::str);

    return;
}

void    Mega::trimSpaces(std::string& str) {
    
    std::size_t start = str.find_first_not_of(" \t\r");
    if (start != std::string::npos)
        str = str.substr(start);

    std::size_t end = str.find_last_not_of(" \t\r");
    if (end != std::string::npos)
        str = str.substr(0, end +1);
}
