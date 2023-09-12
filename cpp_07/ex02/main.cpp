/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:04:22 by chris             #+#    #+#             */
/*   Updated: 2023/09/12 07:38:21 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#define MAX_VAL 750


void myTest( void ) {

    std::cout << BLUE << "\nCreating instance 'numbers' of Array ************************" << RESET << std::endl;
    Array<int> numbers(10);

    int* mirror = new int[10];
   
    std::cout << BLUE << "\nInit numbers array and mirror array ************************" << RESET << std::endl;
    for (int i = 0; i < 10; i++)
    {
        const int value = 42;
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << BLUE << "\nPrint numbers ************************" << RESET << std::endl;
    numbers.print();
    std::cout << BLUE << "\nPrint mirror *************************" << RESET << std::endl;
    for (int i = 0; i < 10; i++) { std::cout << B_GRAY << "mirror tab = " << mirror[i] << RESET << std::endl; }
    
    
    std::cout << BLUE << B_ORANGE"\nScope{} in **********************************************" << RESET << std::endl;
    {
        Array<int> tmp;
        tmp = numbers;
        Array<int> test(tmp);

        std::cout << BLUE << "\nPrint tmp ****************************" << RESET << std::endl;
        tmp.print();
        std::cout << BLUE << "\nPrint test ***************************" << RESET << std::endl;
        test.print();

        std::cout << BLUE << "\nChange value *************************" << RESET << std::endl;
        for (int i = 0; i < 10; i++) { tmp[i] = 1234; }
        for (int i = 0; i < 10; i++) { test[i] = 5678; }

        std::cout << BLUE << "\nPrint tmp ****************************" << RESET << std::endl;
        tmp.print();
        std::cout << BLUE << "\nPrint test ***************************" << RESET << std::endl;
        test.print();

        std::cout << BLUE << "\ntest = tmp ***************************" << RESET << std::endl;
        test = tmp;

        std::cout << BLUE << "\nPrint tmp ****************************" << RESET << std::endl;
        tmp.print();
        std::cout << BLUE << "\nPrint test ***************************" << RESET << std::endl;
        test.print();

    }
    std::cout << BLUE << B_ORANGE"\nScope{} out *********************************************" << RESET << std::endl;

    std::cout << BLUE << "\nPrint numbers ************************" << RESET << std::endl;
    numbers.print();


    std::cout << BLUE << "\ntry -2 & 10 **************************" << RESET << std::endl;
    try { numbers[-2] = 0; }
    catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    try { numbers[10] = 0; }
    catch(const std::exception& e) { std::cerr << e.what() << '\n'; }


    std::cout << BLUE << "\nPrint numbers ************************" << RESET << std::endl;
    numbers.print();

    std::cout << BLUE << "\nChange value to 21 *******************" << RESET << std::endl;
    for (int i = 0; i < 10; i++) { numbers[i] = 21; }

    std::cout << BLUE << "\nPrint numbers ************************" << RESET << std::endl;
    numbers.print();
    delete [] mirror;
}

void subjectTest( void ) {

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    
}

int main(int, char**)
{
    myTest();
    // subjectTest();

    return 0;
}