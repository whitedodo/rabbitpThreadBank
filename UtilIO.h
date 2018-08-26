/*
 *  UtilIO.h
 *
 *  Created on: 2018. 8. 21.
 *  Author: Dodo( rabbit.white at daum dot net)
 */

#ifndef UTILIO_H_
#define UTILIO_H_

class UtilIO{

private:
	std::string directories;

public:
	std::string getDirectories() const;
	void setDirectories(std::string directories);
	std::vector<Account>* csvReader(std::string filename);
	std::vector<std::string> csv_read_row(std::istream &file, char delimiter);

};

#endif /* UTILIO_H_ */
