/*
 *  bank.cpp
 *  Filename: Bank.cpp
 *  Created on: 2018. 8. 21.
 *  Author: Dodo( rabbit.white at daum dot net )
 *  Version: 0.2
 *	Description:
 */


#include <iostream>
#include <windows.h>
#include "Common.h"

using namespace std;

void Bank::title(int choose){

    time_t curr;
    struct tm *d;
    curr = time(NULL);
    d = localtime(&curr);

	if ( choose == PRINT_TITLE_FRONT ){

	    cout << d->tm_year + 1900 << "-" << d->tm_mon + 1 << "-" << d->tm_mday << " ";
	    cout << d->tm_hour << ":" << d->tm_min << ":" << d->tm_sec;
	    cout << endl;
		cout << "|";
	    cout.fill('-');
	    cout.width(67);
		cout << "|";
		cout << endl;
		cout << "|";
		cout.fill(' ');
		cout.width(10);
		cout << "������(Depositor):";
		cout.fill(' ');
		cout.width(10);
		cout << "O O O";
		cout.fill(' ');
		cout.width(19);
		cout << "|";
		cout.fill(' ');
		cout.width(5);
		cout << "�ΰ�";
		cout.fill(' ');
		cout.width(5);
		cout << "|";
		cout.fill(' ');
		cout.width(10);
		cout << "|" << endl;
		cout << "|  ���¹�ȣ: OOO-OOOO-OOOOOO";
		cout.fill(' ');
		cout.width(39);
		cout << "|  �Ǵ�   |         |";
		cout << endl;
		cout << "|  ��������: ���� ����� ����";
		cout.fill(' ');
		cout.width(38);
		cout << "|  ����   |        |";
		cout << endl;
		cout << "|";
		cout.fill(' ');
		cout.width(66);
		cout << "|  ����    |        |";
		cout << endl;
		cout << "|  OO����";
		cout.fill(' ');
		cout.width(58);
		cout << "|  ����  |          |";
		cout << endl;
		cout << "|";
	    cout.fill('-');
	    cout.width(67);
		cout << "|";
		cout << endl;
	}
	else if ( choose == PRINT_TITLE_BACK ){

	}
	else if ( choose == PRINT_EXIT_PROCESS ){
	    cout << d->tm_year + 1900 << "-" << d->tm_mon + 1 << "-" << d->tm_mday << " ";
	    cout << d->tm_hour << ":" << d->tm_min << ":" << d->tm_sec;
	    cout << endl;
		cout << "--------------------------------------------------------------";
		cout << endl;
		cout << "|     �ý����� �����ϰ� �ֽ��ϴ�. ��ø� ��ٷ��ּ���.            |";
		cout << endl;
		cout << "|     (Shutting down system. Please wait a moment.)          |";
		cout << endl;
		cout << "--------------------------------------------------------------";
		cout << endl;
	}

}

void Bank::printView(int select){

	if ( select == PRINT_TITLE_FRONT ||
		 select == PRINT_TITLE_BACK ||
		 select == PRINT_EXIT_PROCESS){
		this->title(select);
	}

	if ( select == PRINT_BANK_INQUIRY ){

		UtilIO utilIO;
		std::string directory = this->getDirectories();
		std::string filename = this->getFilename();

		utilIO.setDirectories( directory );
		vector<Account>* vecAccount = utilIO.csvReader( filename );

		int i = 1;
		int max = vecAccount->size();

		while ( i < max ){
			Account account = vecAccount->at(i);
			tm tmDate = account.getRegidate();

			cout << account.getId();
			cout.fill(' ');
			cout.width(25);
			cout << tmDate.tm_year << "-";
			cout << tmDate.tm_mon << "-";
			cout << tmDate.tm_mday;
			cout.fill(' ');
			cout.width(25);
			cout << account.getCategory();
			cout.fill(' ');
			cout.width(25);
			cout << account.getWithdrawal();
			cout.fill(' ');
			cout.width(25);
			cout << account.getDisposite();
			cout.fill(' ');
			cout.width(25);
			cout << account.getBalance();
			cout.fill(' ');
			cout.width(25);
			cout << account.getRemarks();
			cout.fill(' ');
			cout.width(25);
			cout << account.getBranch();

			cout << endl;
			i++;
		}

	} // end of if

	system("pause");
}

int Bank::run(){

	int select = 1;

	while ( select ){

		cout << "�޴��� �����ϼ���(Select a menu:):";
		cin >> select;

		// ���
		this->printView(select);
		system("cls");

		// Ż��
		if ( select == 0 ){
			this->printView( PRINT_EXIT_PROCESS );
			return 0;
		}
	}

	return -1;
}

// ���丮�� getter
std::string Bank::getDirectories() const{
	return this->directory;
}

// ���ϸ� getter
std::string Bank::getFilename() const{
	return this->filename;
}

// ���͸� ���� setter
void Bank::setDirectories(std::string directory){
	this->directory = directory;
}

// ���ϸ� setter
void Bank::setFilename(std::string filename){
	this->filename = filename;
}
