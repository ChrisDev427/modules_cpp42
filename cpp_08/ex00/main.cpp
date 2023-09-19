/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:04:22 by chris             #+#    #+#             */
/*   Updated: 2023/09/19 09:48:44 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main( int ac, char** av )
{
    (void)av;
    if ( ac == 1 ) {

        size_t size = 20;
        int a = 2;
        
        std::vector<int> array;
    
        for ( size_t i = 0; i < size; i++ ) {
            array.push_back(a);
            a *= 2;
        }
    
        for ( size_t i = 0; i < array.size(); i++ ) {
            std::cout << B_GRAY IT << "array[" << i << "] [" << array[i] << "] " << RESET ST << std::endl;
        }
    
        try { easyfind( array, 12 ); }
        catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }
        try { easyfind( array, 64 ); }
        catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }
        try { easyfind( array, 128 ); }
        catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }
        try { easyfind( array, 4096 ); }
        catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }
        try { easyfind( array, 1289 ); }
        catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }
    }
    else {
        std::cerr << RED "Error: no args needed" << RESET << std::endl;
        return -1;
    }

    return 0;
}