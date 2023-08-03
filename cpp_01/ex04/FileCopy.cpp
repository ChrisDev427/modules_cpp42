/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileCopy.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:36:15 by chris             #+#    #+#             */
/*   Updated: 2023/08/02 11:33:07 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileCopy.hpp"
#include "utils.hpp"

FileCopy::FileCopy( char *file, char *str1, char *str2 ) : s1(str1), s2(str2), _outFileName(file) {

    if ( s1.length() == 0 )
        error( "second arg is invalid", NULL );
    if ( s1 == s2 )
        error( "args 2 & 3 must be different", NULL );

    _outFileName += ".replace";
    ifs = OpenRead( file );
    ofs = OpenWrite( _outFileName );
   
    
}

FileCopy::~FileCopy( void ) {


}

std::ifstream    FileCopy::OpenRead( const char *file ) {

    std::ifstream   ifs(file);
    if ( !ifs ) {

        error( file, "no file match found" );

    }
    return ifs;

}

std::ofstream    FileCopy::OpenWrite( std::string fileName ) {

    std::ofstream   ofs( fileName );
    if ( !ofs ) {

        error( fileName, "Unable to open the file." );

    }
    return ofs;


}

void    FileCopy::fileCopy( std::ifstream&   inFile, std::ofstream&   outFile ) {

    std::string line;
    while ( std::getline( inFile, line ) ) {

        size_t pos = 0;
        while ( ( pos = line.find(this->s1, pos)) != std::string::npos ) {
            line.erase( pos, s1.length() );
            line.insert( pos, s2 );
            pos += s2.length();
        }

        outFile << line << std::endl;           
    }

}
