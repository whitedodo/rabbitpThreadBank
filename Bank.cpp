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
		cout << "예금주(Depositor):";
		cout.fill(' ');
		cout.width(10);
		cout << "O O O";
		cout.fill(' ');
		cout.width(19);
		cout << "|";
		cout.fill(' ');
		cout.width(5);
		cout << "인감";
		cout.fill(' ');
		cout.width(5);
		cout << "|";
		cout.fill(' ');
		cout.width(10);
		cout << "|" << endl;
		cout << "|  계좌번호: OOO-OOOO-OOOOOO";
		cout.fill(' ');
		cout.width(39);
		cout << "|  또는   |         |";
		cout << endl;
		cout << "|  예금종류: 자유 입출금 통장";
		cout.fill(' ');
		cout.width(38);
		cout << "|  서명   |        |";
		cout << endl;
		cout << "|";
		cout.fill(' ');
		cout.width(66);
		cout << "|  수입    |        |";
		cout << endl;
		cout << "|  OO은행";
		cout.fill(' ');
		cout.width(58);
		cout << "|  증지  |          |";
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
		cout << "|     시스템을 종료하고 있습니다. 잠시만 기다려주세요.            |";
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

		cout << "메뉴를 선택하세요(Select a menu:):";
		cin >> select;

		// 출력
		this->printView(select);
		system("cls");

		// 탈출
		if ( select == 0 ){
			this->printView( PRINT_EXIT_PROCESS );
			return 0;
		}
	}

	return -1;
}

// 디렉토리명 getter
std::string Bank::getDirectories() const{
	return this->directory;
}

// 파일명 getter
std::string Bank::getFilename() const{
	return this->filename;
}

// 디렉터리 설정 setter
void Bank::setDirectories(std::string directory){
	this->directory = directory;
}

// 파일명 setter
void Bank::setFilename(std::string filename){
	this->filename = filename;
}
