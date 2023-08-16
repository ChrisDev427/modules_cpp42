/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileCopy.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:36:11 by chris             #+#    #+#             */
/*   Updated: 2023/08/16 10:13:26 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILECOPY_HPP
# define FILECOPY_HPP
# include <string>
# include <iostream>
# include <fstream>

class FileCopy {

public:

    FileCopy( char *file, char *str1, char *str2 );
    ~FileCopy( void );
    
    std::string s1;
    std::string s2;

    std::ifstream   ifs;
    std::ofstream   ofs;

    void            fileCopy( std::ifstream&   inFile, std::ofstream&   outFile );
private:

   
    std::string     _outFileName;
    std::ifstream   OpenRead( const char *file );
    std::ofstream   OpenWrite( std::string fileName );

};





#endif /*FILECOPY_HPP*/