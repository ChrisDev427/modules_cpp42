/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:02:12 by chris             #+#    #+#             */
/*   Updated: 2023/09/08 18:27:15 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <ctime>       
# include <locale>        
# include <map>
# include <string>
# include <stdexcept>
# include <algorithm>
# include "policeColor.hpp"


typedef struct  s_data {

    std::map<std::string, double> dataFile;
    
    
}               t_data;

void fillMap( t_data* ptr );
void getCompareInput( t_data* ptr,  std::ifstream & ifs );
void valueComp( t_data* ptr, std::string date, double value );

void printMap( std::map<std::string, double> map );
std::map<std::string, double>::const_iterator findDate( std::map<std::string, double> map, std::string toFind );
bool isDateValid(const std::string& dateStr);

#endif /************************************************************* BITCOINEXCHANGE_HPP*/