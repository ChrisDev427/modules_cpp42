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
# include <iomanip>
# include <fstream>
# include <sstream>
# include <ctime>       
# include <locale>        
# include <map>
# include <string>
# include <stdexcept>
# include <algorithm>
# include "policeColor.hpp"

void fillMap( std::map<std::string, double> & map );
void getCompareInput(std::map<std::string, double> & map,  std::ifstream & ifs );
void valueComp( std::map<std::string, double> & map, std::string date, double value );
bool isDateValid( const std::string & dateStr );
bool isArgValid( const std::string & strValue );
void printMap( std::map<std::string, double> map );
void findDate( std::map<std::string, double> & map, std::map<std::string, double>::const_iterator & iter, std::string toFind );

#endif /************************************************************* BITCOINEXCHANGE_HPP*/