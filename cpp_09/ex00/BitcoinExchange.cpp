/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:27:45 by chris             #+#    #+#             */
/*   Updated: 2023/09/19 17:31:16 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void fillMap( std::map<std::string, double> & map ) {

    std::ifstream file( "data.csv" );
    if (!file.is_open()) {
        std::cerr << "Error: could not find 'data.csv' file" << std::endl;
        return;
    }
    std::string line, tmp;
   
    while ( std::getline(file, line) ) {

        tmp = line;
        line.resize(line.find(','));
        if ( isDateValid(line) ) {
            tmp = tmp.substr(tmp.find(',') +1);
            map[line] = atof(tmp.c_str());
        }
        tmp.clear();
        line.clear();
    }
}

void getCompareInput( std::map<std::string, double> & map,  std::ifstream & ifs ) {

    std::string date, value, tmp;
    double      dbValue;
    std::getline(ifs, date);
    while ( std::getline(ifs, date) ) {

        if ( date.size() == 0 ) { continue; }
        tmp = date;
        if ( date.find('|') != std::string::npos ) {
            date.resize( date.find_first_of(' ') );
        }
        if ( tmp.find('|') != std::string::npos ) {
            value = tmp.substr(tmp.find('|') +1);
        }
        if ( !isArgValid( value ) ) {
            std::cerr << RED "Error: bad input => " RESET << IT B_GRAY << tmp << RESET ST << std::endl;
        }
        else if ( !isDateValid( date ) ) {
            std::cerr << RED "Error: bad input => " RESET << IT B_GRAY << date << RESET ST << std::endl;
        }
        else {
            dbValue = atof(value.c_str());
            valueComp( map, date, dbValue );
        }
    }
}

void valueComp( std::map<std::string, double> & map, std::string date, double value ) {

    if ( value < 0 ) { std::cerr << RED "Error: not a positive number." RESET << std::endl; return; }
    if ( value > 1000 ) { std::cerr << RED "Error: too large a number." RESET << std::endl; return; }

    std::map<std::string, double>::const_iterator it;
    findDate( map, it, date );
    std::cout << CYAN << date << YELLOW << " => " << value << " = " << it->second * value << RESET << std::endl;
}

void findDate( std::map<std::string, double> & map, std::map<std::string, double>::const_iterator & iter, std::string toFind ) {
    
    std::map<std::string, double>::const_iterator it = map.begin();
    std::map<std::string, double>::const_iterator ite = map.end();
    for (; it != ite; it++ ) {
       
        if ( toFind == it->first ) {
            iter = it;
        }
        if ( toFind < it->first ) {
            break;
        }
    }
    iter = --it;
}

bool isArgValid( const std::string & strValue ) {

    if ( std::count( strValue.begin(), strValue.end(), '.' ) > 1 || strValue.size() == 0 ) { return false; }
    int i = 0;
    while ( strValue[i] == ' ' ) { i++; }
    if ( strValue[i] == '-' ) { i++; }
    while ( strValue[i] ) {
        if ( !isdigit( strValue[i] ) ) {
            if ( strValue[i] != '.' && strValue[i] != ' ' ) { return false; }
        }
        i++;
    }
    return true;
}

bool isDateValid( const std::string & dateStr ) {
    
    if ( dateStr.size() != 10 ) { return false; }
    std::tm dateInfo = {};
    if ( strptime( dateStr.c_str(), "%Y-%m-%d", &dateInfo ) == NULL ) { return false; }
    int year = dateInfo.tm_year + 1900;
    int month = dateInfo.tm_mon + 1;
    int day = dateInfo.tm_mday;
    
    // Checking leap years
    int maxFev = 28;
    if ( month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        maxFev = 29;
    }
    if ( month == 2 && day > maxFev ) { return false; }
    
    return true;
}

void printMap( std::map<std::string, double> map ) {

    std::multimap<std::string, double>::const_iterator it = map.begin();
    std::multimap<std::string, double>::const_iterator ite = map.end();
    for (; it != ite; it++ ) {
        std::cout << it->first << " " << it->second << std::endl;
    }
}
