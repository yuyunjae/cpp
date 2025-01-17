#include "Account.hpp"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account() {}

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0) {
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";created\n";
  _nbAccounts++;
  _totalAmount += initial_deposit;
}

Account::~Account() {
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";closed\n";
  _nbAccounts--;
  _totalAmount -= this->_amount;
  _totalNbDeposits -= this->_nbDeposits;
  _totalNbWithdrawals -= this->_nbWithdrawals;
}

int Account::getNbAccounts(void) { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::displayAccountsInfos() {
  _displayTimestamp();
  std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
            << ";deposits:" << _totalNbDeposits
            << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
  if (deposit > 0) {
    (this->_nbDeposits)++;
    _totalNbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << this->_amount << ";deposit:" << deposit
              << ";amount:" << this->_amount + deposit
              << ";nb_deposits:" << this->_nbDeposits << std::endl;
    this->_amount += deposit;
    _totalAmount += deposit;
  }
}

bool Account::makeWithdrawal(int withdrawal) {
  if (withdrawal > 0) {
    (this->_nbWithdrawals)++;
    _totalNbWithdrawals++;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << this->_amount << ";withdrawal:";
    this->_amount -= withdrawal;
    if (checkAmount() < 0) {
      (this->_nbWithdrawals)--;
      _totalNbWithdrawals--;
      this->_amount += withdrawal;
      return false;
    }
    std::cout << withdrawal << ";amount:" << this->_amount
              << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    _totalAmount -= withdrawal;
    return true;
  }
  return false;
}

int Account::checkAmount(void) const {
  if (this->_amount < 0) std::cout << "refused\n";
  return this->_amount;
}

void Account::displayStatus() const {
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";deposits:" << this->_nbDeposits
            << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
  std::time_t now_t =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  std::tm *local_time = localtime(&now_t);
  std::cout << std::put_time(local_time, "[%Y%m%d_%H%M%S] ");
}
