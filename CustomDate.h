/*
 *  CustomDate.h
 *
 *  Created on: 2018. 8. 21.
 *  Author: Dodo( rabbit.white at daum dot net)
 */

#pragma once
#define interface class

#ifndef CUSTOMDATE_H_
#define CUSTOMDATE_H_

interface CustomDate{

public:
	virtual void setYear(int year) = 0;
	virtual void setMonth(int month) = 0;
	virtual void setDay(int day) = 0;
	virtual void setHour(int hour) = 0;
	virtual void setMin(int min) = 0;
	virtual void setSec(int sec) = 0;

};


#endif /* CUSTOMDATE_H_ */
