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

// 일자 불러오기
tm Account::getRegidate() const{
	return this->regiDate;
}

// 가상 일자(년도)
void Account::setYear(int year){
	this->regiDate.tm_year = year;
}

// 가상 일자(월)
void Account::setMonth(int month){
	this->regiDate.tm_mon = month;
}

// 가상 일자(일)
void Account::setDay(int day){
	this->regiDate.tm_mday = day;
}

// 가상 일자(시간)
void Account::setHour(int hour){
	this->regiDate.tm_hour = hour;
}

// 가상 일자(분)
void Account::setMin(int min){
	this->regiDate.tm_min = min;
}

// 가상 일자(초)
void Account::setSec(int sec){
	this->regiDate.tm_sec = sec;
}

// 카테고리 출력
std::string Account::getCategory() const{
	return this->category;
}

// 출금액 출력
int Account::getWithdrawal() const{
	return this->withdrawalMoney;
}

// 입금액 출력
int Account::getDisposite() const{
	return this->disposalMoney;
}

// 잔액 출력
int Account::getBalance() const{
	return this->balanceMoney;
}

// 비고 출력
std::string Account::getRemarks() const{
	return this->remarks;
}

// 지점 출력
std::string Account::getBranch() const{
	return this->branch;
}

// 항목 설정
void Account::setCategory(std::string category){
	this->category = category;
}

// 가상 일자(찾으신 금액)
void Account::setWithdrawal(int money){
	this->withdrawalMoney = money;
}

// 가상 일자(맡기신 금액)
void Account::setDisposite(int money){
	this->disposalMoney = money;
}

// 가상 일자(잔액)
void Account::setBalance(int money){
	this->balanceMoney = money;
}

// 가상 일자(비고)
void Account::setRemarks(std::string remarks){
	this->remarks = remarks;
}

// 가상 일자(지점)
void Account::setBranch(std::string branch){
	this->branch = branch;
}

