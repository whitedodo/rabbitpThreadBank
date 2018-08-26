/*
 *  Account.h
 *  Filename: Account.h
 *  Created on: 2018. 8. 21.
 *  Author: Dodo( rabbit.white at daum dot net )
 *  Version: 0.2
 *	Description:
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

class Account : public CustomDate
{
private:
	int id;
	tm regiDate;
	std::string category;
	int withdrawalMoney;
	int disposalMoney;
	int balanceMoney;
	std::string remarks;
	std::string branch;

public:

	Account();
	~Account(); // @suppress("Class has a virtual method and non-virtual destructor")

	// 일자 불러오기
	tm getRegidate() const;

	// 번호
	int getId() const;
	void setId(int id);

	// 가상 일자
	virtual void setYear(int year);
	virtual void setMonth(int month);
	virtual void setDay(int day);
	virtual void setHour(int hour);
	virtual void setMin(int min);
	virtual void setSec(int sec);

	// 카테고리, 출금, 입금, 잔액, 비고, 지점
	std::string getCategory() const;
	int getWithdrawal() const;
	int getDisposite() const;
	int getBalance() const;
	std::string getRemarks() const;
	std::string getBranch() const;

	// 어카운트 출력 기능
	void setCategory(std::string category);
	void setWithdrawal(int money);
	void setDisposite(int money);
	void setBalance(int money);
	void setRemarks(std::string remarks);
	void setBranch(std::string branch);

};



#endif /* ACCOUNT_H_ */
