/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:27:45 by chris             #+#    #+#             */
/*   Updated: 2023/09/12 18:09:16 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "BitcoinExchange.hpp"

void fillMap( t_data* ptr ) {

    std::ifstream file( "data.csv" );
    if (!file.is_open()) {
        std::cerr << "Error: could not find 'data.csv' file" << std::endl;
        return;
    }
    std::string line, tmp;
    while ( std::getline(file, line) ) {

        tmp = line;
        line.resize(line.find(','));
        tmp = tmp.substr(tmp.find(',') +1);
        ptr->dataFile[line] = atof(tmp.c_str());
    }
    // printMap( ptr->dataFile );
}

void valueComp( t_data* ptr, std::string date, double value ) {

    if ( value < 0 ) { std::cerr << "Error: not a positive number." << std::endl; return; }
    if ( value > 1000 ) { std::cerr << "Error: too large a number." << std::endl; return; }
    if ( !isDateValid( date ) ) { std::cerr << "Error: bad input => " << date << std::endl; return; }

    std::map<std::string, double>::const_iterator it = findDate( ptr->dataFile, date );
    std::cout << date << it->second * value << std::endl;
}

void getCompareInput( t_data* ptr,  std::ifstream & ifs ) {

    std::string date, value, tmp;
    double      dbValue;
    std::getline(ifs, date);
    while ( std::getline(ifs, date) ) {

        tmp = date;
        if ( date.find('|') != std::string::npos ) {
            date.resize(date.find('|'));
        }
        if ( tmp.find('|') != std::string::npos ) {
            value = tmp.substr(tmp.find('|') +1);
            if ( value.size() > 5 || atof(value.c_str()) > 1000 ) {
                value = "1001";
            }
        }
        dbValue = atof(value.c_str());
        valueComp( ptr, date, dbValue );
        date.clear();
        tmp.clear();
        value.clear();
    }
}

std::map<std::string, double>::const_iterator findDate( std::map<std::string, double> map, std::string toFind ) {
    
    std::map<std::string, double>::const_iterator it = map.begin();
    std::map<std::string, double>::const_iterator ite = map.end();
    for (; it != ite; it++ ) {
       
        if ( toFind > it->first ) { continue; }
        if ( toFind < it->first ) { return std::prev(it); }
    }
    return it;
}

bool isDateValid(const std::string& dateStr) {
    
    std::istringstream iss(dateStr);
    std::tm dateInfo = {};
    iss >> std::get_time(&dateInfo, "%Y-%m-%d");
    if (iss.fail()) { return false; }

    int year = dateInfo.tm_year + 1900;
    int month = dateInfo.tm_mon + 1;
    int day = dateInfo.tm_mday;
    
    // Vérification des années bissextiles (février)
    int maxFev = 28;
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        maxFev = 29;
    }
    if ( day > maxFev ) { return false; }
    
    return true;
}

void printMap( std::map<std::string, double> map ) {

    std::multimap<std::string, double>::const_iterator it = map.begin();
    std::multimap<std::string, double>::const_iterator ite = map.end();
    for (; it != ite; it++ ) {
        std::cout << it->first << " " << std::fixed << std::setprecision(2) << it->second << std::endl;
    }
}
