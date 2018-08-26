/*
 *  Bank.h
 *  Filename: Bank.h
 *  Created on: 2018. 8. 21.
 *  Author: Dodo( rabbit.white at daum dot net )
 *  Version: 0.2
 *	Description:
 */

#ifndef BANK_H_
#define BANK_H_

const int PRINT_EXIT_PROCESS = 0;
const int PRINT_TITLE_FRONT = 1;
const int PRINT_TITLE_BACK = 2;
const int PRINT_BANK_INQUIRY = 3;

class Bank{

private:
	std::string directory;
	std::string filename;

	void title(int choose);
	void printView(int choose);

public:
	int run();
	std::string getDirectories() const;
	std::string getFilename() const;
	void setDirectories(std::string directory);
	void setFilename(std::string filename);
};

#endif /* BANK_H_ */
