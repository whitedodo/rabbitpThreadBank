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

	// ���� �ҷ�����
	tm getRegidate() const;

	// ��ȣ
	int getId() const;
	void setId(int id);

	// ���� ����
	virtual void setYear(int year);
	virtual void setMonth(int month);
	virtual void setDay(int day);
	virtual void setHour(int hour);
	virtual void setMin(int min);
	virtual void setSec(int sec);

	// ī�װ�, ���, �Ա�, �ܾ�, ���, ����
	std::string getCategory() const;
	int getWithdrawal() const;
	int getDisposite() const;
	int getBalance() const;
	std::string getRemarks() const;
	std::string getBranch() const;

	// ��ī��Ʈ ��� ���
	void setCategory(std::string category);
	void setWithdrawal(int money);
	void setDisposite(int money);
	void setBalance(int money);
	void setRemarks(std::string remarks);
	void setBranch(std::string branch);

};



#endif /* ACCOUNT_H_ */
