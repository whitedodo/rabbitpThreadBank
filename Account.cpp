/*
 *  Account.cpp
 *  Filename: Account.cpp
 *  Created on: 2018. 8. 21.
 *  Author: Dodo( rabbit.white at daum dot net )
 *  Version: 0.2
 *	Description:
 */

#include <iostream>
#include <string>
#include <time.h>
#include <ctime>
#include "CustomDate.h"
#include "Account.h"

using namespace std;


Account::Account(){ // @suppress("Class members should be properly initialized")
	this->id = -1;
	this->balanceMoney = -1;
}

Account::~Account(){


}

// getter id
int Account::getId() const{
	return this->id;
}

// setter id
void Account::setId(int id){
	this->id = id;
}

// ���� �ҷ�����
tm Account::getRegidate() const{
	return this->regiDate;
}

// ���� ����(�⵵)
void Account::setYear(int year){
	this->regiDate.tm_year = year;
}

// ���� ����(��)
void Account::setMonth(int month){
	this->regiDate.tm_mon = month;
}

// ���� ����(��)
void Account::setDay(int day){
	this->regiDate.tm_mday = day;
}

// ���� ����(�ð�)
void Account::setHour(int hour){
	this->regiDate.tm_hour = hour;
}

// ���� ����(��)
void Account::setMin(int min){
	this->regiDate.tm_min = min;
}

// ���� ����(��)
void Account::setSec(int sec){
	this->regiDate.tm_sec = sec;
}

// ī�װ� ���
std::string Account::getCategory() const{
	return this->category;
}

// ��ݾ� ���
int Account::getWithdrawal() const{
	return this->withdrawalMoney;
}

// �Աݾ� ���
int Account::getDisposite() const{
	return this->disposalMoney;
}

// �ܾ� ���
int Account::getBalance() const{
	return this->balanceMoney;
}

// ��� ���
std::string Account::getRemarks() const{
	return this->remarks;
}

// ���� ���
std::string Account::getBranch() const{
	return this->branch;
}

// �׸� ����
void Account::setCategory(std::string category){
	this->category = category;
}

// ���� ����(ã���� �ݾ�)
void Account::setWithdrawal(int money){
	this->withdrawalMoney = money;
}

// ���� ����(�ñ�� �ݾ�)
void Account::setDisposite(int money){
	this->disposalMoney = money;
}

// ���� ����(�ܾ�)
void Account::setBalance(int money){
	this->balanceMoney = money;
}

// ���� ����(���)
void Account::setRemarks(std::string remarks){
	this->remarks = remarks;
}

// ���� ����(����)
void Account::setBranch(std::string branch){
	this->branch = branch;
}

