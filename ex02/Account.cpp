/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:18:44 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/07 14:11:16 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <cstdio>



int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void)
{
}

Account::~Account(void)
{
	//	loging the account deletion.
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "ammount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t		raw_time;
	struct tm	*current_time;
	char		buff[80];

	time(&raw_time);
	current_time = localtime(&raw_time);
	strftime(buff, 80, "[%Y%m%d_%H%M%S]", current_time);
	std::cout << buff << " ";
}

Account::Account(int initial_deposit)
{
	//	seting up the object.
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	//	loging the account creation.
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "ammount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

int		Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int		Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int		Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int		Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "acconuts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals();
	std::cout << std::endl;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "ammount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawls:" << _nbWithdrawals;
	std::cout << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_ammount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";

	_amount += deposit;
	_totalAmount += deposit;
	std::cout << "ammount:" << _amount << ";";

	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
}

int		Account::checkAmount(void) const
{
	return (_amount);
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_ammount:" << _amount << ";";
	if (_amount < withdrawal)
	{
		std::cout << "withdrawal:refused:" << std::endl;
		return (false);
	}
	std::cout << "withdrawal:" << withdrawal << ";";
	
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals += 1;
	_totalNbWithdrawals	+= 1;
	
	std::cout << "ammount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _amount << std::endl;
	return (true);
}

