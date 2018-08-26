/*
 *  UtilIO.cpp
 *
 *  Created on: 2018. 8. 21.
 *  Author: Dodo( rabbit.white at daum dot net)
 */

#include <iostream>
#include "Common.h"

using namespace std;

std::string UtilIO::getDirectories() const{
	return this->directories;
}

void UtilIO::setDirectories(std::string directories){
	this->directories = directories;
}

std::vector<Account>* UtilIO::csvReader(std::string filename){

	//csv ���Ͼȿ� �ִ� �����͸� �о vector�� �����Ѵ�.
	std::vector<std::string> csv_read_row(std::istream &file, char delimiter);

	std::vector<Account>* account = new vector<Account>();
	Account* createAccount = NULL;

	std::string realfile = this->getDirectories();
	realfile.append("\\");
	realfile.append(filename);

    //ifstream�� ������ �а� ���ִ� �Լ��ν� ifstream (���ϸ� or ���)
    ifstream file(realfile);

    if (file.fail())  //���� bad() �Լ��� ���� �ϸ�..
    {
        cout << "�ش� ��ο� ��ġ�ϴ� ������ �������� �ʽ��ϴ�." << endl;
    }

    int rowCount = -1;
    int year = -1, month = -1, day = -1;

    while(file.good()) //eof, bad, fail �Լ��� ������ ���� ��ȯ�� ������..
    {
        std::vector<std::string> row = this->csv_read_row(file, ',');

		for( int i = 0, leng = row.size(); i < leng; i++ ){
		//	cout << "[" << row[i] << "]" << "\t"; //�˸°� ���

			if ( i == 0 )
			{
				createAccount = new Account();
			}

			std::string tmpData = row[i];

			if ( ( i + 1) == leng ){
				rowCount++;
				createAccount->setId( rowCount );
				account->push_back(*createAccount);
			}

			switch ( i ){
				// ����
				case 0:

					if ( rowCount >= 0 ){
						if ( tmpData.size() > 1 ){
							year = atoi(tmpData.substr(0, 4).c_str());
							month = atoi(tmpData.substr(5, 2).c_str());
							day = atoi(tmpData.substr(8, 2).c_str());
						}
						if ( tmpData.size() > 1 ){
							if( year != -1 ){ createAccount->setYear(year); year = -1; }
							if( month != -1 ){ createAccount->setMonth(month); month = -1; }
							if( day != -1 ){ createAccount->setDay(day); day = -1; }
						}
					}

					break;

				// �׸��
				case 1:
					if ( rowCount >= 0 ){
						createAccount->setCategory(tmpData);
					}
					break;

				// ã���� �ݾ�
				case 2:
					if ( rowCount >= 0 ){
						int money = atoi(tmpData.c_str());
						createAccount->setDisposite(money);
					}

					break;

				// �ñ� �ݾ�
				case 3:
					if ( rowCount >= 0 ){
						int money = atoi(tmpData.c_str());
						createAccount->setWithdrawal(money);
					}

					break;

				// �ܾ�
				case 4:
					if ( rowCount >= 0 ){
						int money = atoi(tmpData.c_str());
						createAccount->setBalance(money);
					}

					break;
				// ���
				case 5:
					if ( rowCount >= 0 ){
						createAccount->setRemarks(tmpData);
					}
					break;

				// ����
				case 6:
					if ( rowCount >= 0 ){
						createAccount->setBranch(tmpData);
					}
					break;

			} // end of switch

		}

    }

    file.close(); //���� ����� �Ϸ� �� �ݾ��ش�.

    return account;

}

std::vector<std::string> UtilIO::csv_read_row(std::istream &file, char delimiter)
{
    stringstream ss;
    bool inquotes = false;
    vector<string> row;//relying on RVO

    while(file.good())
    {
        char c = file.get();

        if (!inquotes && c=='"')
        {
            inquotes=true;
        }
        else if (inquotes && c=='"')
        {
            if ( file.peek() == '"')
            {
                ss << (char)file.get();
            }
            else
            {
                inquotes=false;
            }
        }
        else if (!inquotes && c==delimiter)
        {
            row.push_back( ss.str() );
            ss.str("");
        }
        else if (!inquotes && (c=='\r' || c=='\n') )
        {
            if(file.peek()=='\n') {
            	file.get();
            }

            row.push_back( ss.str() );
            return row;
        }
        else
        {
            ss << c;
        }

    }

}
