/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:27:45 by chris             #+#    #+#             */
/*   Updated: 2023/09/21 07:59:50 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string findDataBase( void ) {
    
    DIR *directory = opendir(".");
    if ( !directory ) {
        std::cerr << "Error: open current directory impossible" << std::endl;
        exit ( EXIT_FAILURE );
    }
    struct dirent *entry = NULL;
    std::string     tmp;
    
    while ( (entry = readdir(directory)) ) {
        
        if ( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, ".." ) != 0) {
            tmp = entry->d_name;
            if ( tmp.find_last_of('.') != std::string::npos ) {
                tmp = tmp.substr(tmp.find_last_of('.') );
            }
            
            if ( tmp == ".csv" ) {
                
                closedir(directory);
                return entry->d_name;
            }
        }
    }
    std::cerr << RED "Error: file '.csv' not found" << RESET << std::endl;
    exit ( EXIT_FAILURE );
}

void checkArgFile( char* str ) {

    std::string file = str;
    if ( file.find_last_of('.') != std::string::npos ) {
        file = file.substr(file.find_last_of('.') );
        if ( ( file != ".txt" ) ) {
            throw std::invalid_argument ( RED "Error: arg extension file must be '.txt'" );
        }
    }
    else { throw std::invalid_argument ( RED "Error: arg file: no extension" ); }
}

void fillMap( std::map<std::string, double> & map ) {

    size_t lineNb = 0;
    std::string line, tmp;
    std::string inputDataBase = findDataBase();
    std::ifstream file ( inputDataBase.c_str() );
    if (!file.is_open()) {
        throw std::ifstream::failure ( RED "Error: could not find .csv file" );
    }

    while ( std::getline(file, line) ) {

        lineNb++;
        if (( lineNb == 1 && line == "date,exchange_rate" ) || ( line.size() == 0 )) { continue; }
        else if ( lineNb == 1 && line != "date,exchange_rate" ) {
            std::cerr << RED "Error: .csv file: line: " << lineNb << " -> ";
            throw std::invalid_argument ( "bad input" );
        }
        if ( line.find(',') != std::string::npos ) {
            tmp = line;
            line.resize(line.find(','));
            if ( isDateValid(line) ) {
                tmp = tmp.substr(tmp.find(',') +1);
                if ( !isArgValid( tmp ) ) {
                    std::cerr << RED "Error: .csv file: line: " << lineNb << " -> ";
                    throw std::invalid_argument ( "invalid value" );
                }
                map[line] = atof(tmp.c_str());
            }
            else {
                std::cerr << RED "Error: .csv file: line: " << lineNb << " -> ";
                throw std::invalid_argument ( "invalid date" );
            }
            tmp.clear();
            line.clear();
        }
        else {
            std::cerr << RED "Error: .csv file: line: " << lineNb << " -> ";
            throw std::invalid_argument ( "bad input" );
        }
    }
    if ( map.size() == 0 ) { throw std::invalid_argument ( RED "Error: empty data base" ); }
    file.close();
}

void getCompareInput( std::map<std::string, double> & map,  std::ifstream & ifs ) {

    std::string date, value, tmp;
    size_t      lineNb = 0;
    double      dbValue;
    
    while ( std::getline(ifs, date) ) {
        lineNb++;
        if (( lineNb == 1 && date == "date | value" ) || ( date.size() == 0 )) { continue; }
        else if ( lineNb == 1 && date != "date | value" ) {
            std::cerr << RED "Error: input file: line: " << lineNb << " -> ";
            throw std::invalid_argument ( "bad input" );
        }
        tmp = date;
        if ( date.find('|') != std::string::npos ) {
            date.resize( date.find_first_of(' ') );
            value = tmp.substr(tmp.find('|') +1);
        }
        if ( !isArgValid( value ) || !isDateValid( date ) ) {
            std::cerr << RED "Error: bad input => " RESET << IT B_GRAY << tmp << RESET ST << std::endl;
        }
        else {
            dbValue = atof(value.c_str());
            valueComp( map, date, dbValue );
        }
    }
    if ( lineNb < 2 ) { throw std::invalid_argument ( RED "Error: arg file is empty" ); }
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
