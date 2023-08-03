/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:08:17 by chris             #+#    #+#             */
/*   Updated: 2023/07/31 11:14:03 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEGAPHONE_HPP
# define MEGAPHONE_HPP
# include <iostream>
# include <vector>
# include <sstream>
# include <string>

class Mega {

public:

    Mega(int argc, char **tab);
    ~Mega(void);

    std::string str;

private:

    std::vector<std::string> arg;
    
    void    UpperStr(std::string str);
    void    charTabToVector(int argc, char **tab);
    void    vectorToString(void);
    void    trimSpaces(std::string& str);
};

#endif /******************************************************  MEGAPHONE_HPP */