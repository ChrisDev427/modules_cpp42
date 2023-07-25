/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 08:14:20 by chris             #+#    #+#             */
/*   Updated: 2023/07/22 09:02:37 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

// ************************************************************************** //
//                            Constructor/Destructor                          //
// ************************************************************************** //

Account::Account( int initial_deposit ) {

}

Account::~Account( void ) {

}

// ************************************************************************** //
//                            Static Member Functions                         //
// ************************************************************************** //

int	Account::getNbAccounts( void ) {

    return Account::_nbAccounts;

}


int	Account::getTotalAmount( void ) {

    return Account::_totalAmount;

}


int	Account::getNbDeposits( void ) {

    return Account::_totalNbDeposits;

}


int	Account::getNbWithdrawals( void ) {

    return Account::_totalNbWithdrawals ;

}

void	displayAccountsInfos( void ) {

    std::cout << "NbAccount : " << Account::getNbAccounts() << std::endl;
    std::cout << "TotalAmount : " << Account::getTotalAmount() << std::endl;
    std::cout << "NbDepositt : " << Account::getNbDeposits() << std::endl;
    std::cout << "NbWithdrawals : " << Account::getNbWithdrawals() << std::endl;

}


// ************************************************************************** //
//                            Member Functions                                //
// ************************************************************************** //

