/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:04:22 by chris             #+#    #+#             */
/*   Updated: 2023/09/06 11:55:16 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>
#include "policeColor.hpp"
#include "easyfind.hpp"

int main( void )
{
    size_t size = 20;
    int a = 2;
    int toFind = 64;
    std::vector<int> array;

    for ( size_t i = 0; i < size; i++ ) {
        array.push_back(a);
        a *= 2;
    }

    for ( size_t i = 0; i < array.size(); i++ ) {
        std::cout << B_GRAY IT << "array[" << i << "] [" << array[i] << "] " << RESET ST << std::endl;
    }

    try { easyfind( array, toFind ); }
    catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }
    
    // system("leaks prog");
    return 0;
}