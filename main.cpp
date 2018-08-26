/*
 * main.cpp
 *
 * Created on: 2018. 8. 21.
 * Author: whitedodo(rabbit.white at daum dot net)
 */

#include <iostream>
#include <windows.h>
#include "Common.h"

using namespace std;

int condition;
DWORD WINAPI MyBank(LPVOID lpParam);

int main(void)
{
    DWORD dwThreadId = 1;
    DWORD dwThrdParam = 1;

    condition = 1;

    HANDLE hThread = CreateThread(NULL, 0, MyBank, &dwThrdParam, 0, &dwThreadId);

    cout << "The thread ID:" << dwThreadId << endl;

    if(hThread == NULL){
        cout << "CreateThread() failed, error : " << GetLastError() << endl;
    }
    else{
    	cout << "CreateThread() is OK!" << endl;
    	MyBank( (LPVOID) dwThreadId);
    }

    if(CloseHandle(hThread) != 0){
        cout << "Handle to thread closed successfully." << endl;
    }

    return 0;
}

DWORD WINAPI MyBank(LPVOID lpParam)
{
	std::string directories = "C:\\Users\\article\\Desktop";
	std::string filename = "type1-1.csv";

	int status = -1;
	Bank bank;

	bank.setDirectories(directories);
	bank.setFilename(filename);
	status = bank.run();

    cout << "The parameter: "<< *(DWORD*)lpParam << endl;

    return status;
}
