#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "cPerson.h"
#include "../Librarys/cDate.h"
#include "../Librarys/stringo.h"
#include "cGlobal.h"

using namespace std;

class cClient : public cPerson
{
private:

	enum enMode
	{
		enEmpty = 0,
		enUpdate = 1,
		enAddNew = 2,
	};

	enMode _mode;
	string _accountNumber;
	string _pinCode;
	double _balance;
	bool _MarkForDeleting = false;


	// struct transferClient
	struct stTransClient
	{
		string accountNum;
		double balance;
	};

	//-------------------[ Private Methods ]-------------------//
	struct stTransfer;


	static cClient _convertLinetoClientObject(string line)
	{
		vector<string> clientData = stringo::split(line, "#//#");
		return cClient(enUpdate, clientData[0], clientData[1], clientData[2], clientData[3], clientData[4], clientData[5], stod(clientData[6]));
	}
	static cClient _getEmptyClientObject()
	{
		return cClient(enEmpty, "", "", "", "", "", "", 0);
	}
	static string _covertClientObjecttoLine(cClient client, string sep = "#//#")
	{
		string line = "";
		line += client.firstName + sep;
		line += client.lastName + sep;
		line += client.email + sep;
		line += client.phone + sep;
		line += client.accountNumber + sep;
		line += client.pinCode + sep;
		line += to_string(client.balance);

		return line;
	}
	static vector<cClient> _loadClientsDataFromFile(string path = "../data/Clients.txt", string sep = "#//#")
	{
		vector<cClient> _clientsData;
		fstream file;
		file.open(path, ios::in);
		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				cClient client = _convertLinetoClientObject(line);
				_clientsData.push_back(client);
			}
			file.close();
		}
		return _clientsData;
	}
	static void _saveClienttoFile(string lineData, string path = "../data/Clients.txt")
	{
		fstream file;
		file.open(path, ios::app);

		if (file.is_open())
		{
			file << lineData << endl;
			file.close();
		}
	}
	static void _saveClientsDataToFile(vector<cClient> _clientsDate)
	{
		fstream file;
		file.open("../data/Clients.txt", ios::out);
		
		if (file.is_open())
		{
			string line;

			for (cClient client : _clientsDate)
			{
				if (client._MarkForDeleting == false)
				{
					line = _covertClientObjecttoLine(client);
					file << line << endl;
				}
				
			}
			file.close();
		}
	}
	// transfer operations
	static string _covertTransferOperationtoLine(stTransfer transferInfo,string sep = "#//#")
	{
		string line = "";
		line += transferInfo.date + sep;
		line += transferInfo.clientFrom.accountNum + sep;
		line += transferInfo.clientTo.accountNum + sep;
		line += to_string(transferInfo.amount) + sep;
		line += to_string(transferInfo.clientFrom.balance) + sep;
		line += to_string(transferInfo.clientTo.balance) + sep;
		line += transferInfo.user;

		return line;
	}
	static void _saveTransferOperationtoFile(string lineData, string path = "../data/TransferLogs.txt")
	{
		fstream file;
		file.open(path, ios::out|ios::app);

		if (file.is_open())
		{
			file << lineData << endl;
			file.close();
		}
	}
	stTransfer _getTransferOp(cClient clientTo, double amount)
	{
		stTransfer trans;
		trans.amount = amount;
		trans.clientFrom.accountNum = accountNumber;
		trans.clientTo.accountNum = clientTo.accountNumber;
		trans.clientFrom.balance = balance;
		trans.clientTo.balance = clientTo.balance;
		trans.date = cDate::convertDatetoString(cDate()) + " - " + cDate::getClock();
		trans.user = currentUser.userName;

		return trans;
	}
	static stTransfer _convertLinetoTransLog(string line)
	{
		vector<string> transline = stringo::split(line, "#//#");
		stTransfer transLog;

		transLog.date = transline[0];
		transLog.clientFrom.accountNum = transline[1];
		transLog.clientTo.accountNum = transline[2];
		transLog.amount = stod(transline[3]);
		transLog.clientFrom.balance = stod(transline[4]);
		transLog.clientTo.balance = stod(transline[5]);
		transLog.user= transline[6];

		return transLog;
	}
	static vector<stTransfer> _loadTransferLogsFromFile(string path = "../data/TransferLogs.txt", string sep = "#//#")
	{
		vector<stTransfer> _TransLogs;
		fstream file;
		file.open(path, ios::in);
		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				stTransfer transLog = _convertLinetoTransLog(line);
				_TransLogs.push_back(transLog);
			}
			file.close();
		}
		return _TransLogs;
	}

	void _update()
	{
		vector<cClient> _clientsData = _loadClientsDataFromFile();

		for(cClient & client : _clientsData)
		{
			if (client.accountNumber == accountNumber)
			{
				client = *this;
				break;
			}
		}

		_saveClientsDataToFile(_clientsData);
	}
	void _addNewClient()
	{
		_saveClienttoFile(_covertClientObjecttoLine(*this));
	}

public:
	
	// parameterized constructor
	cClient(enMode mode, string firstName, string lastName, string email, string phone, string accountNumber, string pinCode, double balance) : cPerson(firstName, lastName, email, phone)
	{
		_mode = mode;
		_accountNumber = accountNumber;
		_pinCode = pinCode;
		_balance = balance;
	}

	// properties setters
	void setPinCode(string pinCode)
	{
		_pinCode = pinCode;
	}
	void setBalance(double balance)
	{
		_balance = balance;
	}


	// properties getters
	string getAccountNumber()
	{
		return _accountNumber;
	}	
	string getPinCode()
	{
		return _pinCode;
	}
	double getBalance()
	{
		return _balance;
	}

	__declspec(property(get = getPinCode, put = setPinCode)) string pinCode;
	__declspec(property(get = getBalance, put = setBalance)) double balance;
	__declspec(property(get = getAccountNumber)) string accountNumber;

	

	// struct to transfer infos
	struct stTransfer
	{
		string date;
		stTransClient clientFrom;
		stTransClient clientTo;
		double amount;
		string user;
	};
	
	//-------------------[ Methods ]-------------------//
	
	//return true if a client is empty or false is not.
	bool isEmpty()
	{
		return (_mode == enMode::enEmpty);
	}
	enum enSave { svFaildEmptyObject = 0, svSuccefully = 1, svFaildClientExist = 2 };
	enSave save()
	{
		switch (_mode)
		{
		case enMode::enEmpty:
			return enSave::svFaildEmptyObject;

		case enMode::enUpdate:
			_update();
			return enSave::svSuccefully;

		case enMode::enAddNew:

			if (isClientExist(accountNumber))
			{
				return enSave::svFaildClientExist;
			}
			else
			{
				_addNewClient();
				_mode = enMode::enUpdate;
				return enSave::svSuccefully;
			}
		}
	}
	// delete client from data base
	bool _delete()
	{
		vector<cClient> clientsData = _loadClientsDataFromFile();

		for (cClient& client : clientsData)
		{
			if (client.accountNumber == _accountNumber)
			{
				client._MarkForDeleting = true;
				break;
			}
		}
		_saveClientsDataToFile(clientsData);
		*this = _getEmptyClientObject();
		return true;
	}
	// deposit amount
	bool deposit(double amount)
	{
		if (amount > 0)
		{
			_balance += amount;
			save();
			return true;
		}
		return false;
	}
	// withdraw amount
	bool withdraw(double amount)
	{
		if (amount < _balance)
		{
			_balance -= amount;
			save();
			return true;
		}
		return false;
	}

	// transfer
	bool transfer(double amount, cClient & distanceClient)
	{
		if (amount < balance && accountNumber != distanceClient.accountNumber)
		{
			this->withdraw(amount);
			distanceClient.deposit(amount);

			// save transfer to file log
			_saveTransferOperationtoFile(_covertTransferOperationtoLine(_getTransferOp(distanceClient, amount)));
			return true;
		}
		else
		{
			return false;
		}
	}


	//-------------------[ Static Methods ]-------------------//
	// return client if found or return empty client is not found.
	static cClient find(string accountNum)
	{
		fstream file("../data/Clients.txt",ios::in);
		
		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				cClient client = _convertLinetoClientObject(line);
				if (client.accountNumber == accountNum)
				{
					file.close();
					return client;
				}
			}
		}
		return _getEmptyClientObject();
	}
	// return client if found or return empty client is not found.
	static cClient find(string accountNum, string pinCode)
	{
		cClient client = cClient::find(accountNum);
		if (client.pinCode == pinCode)
			return client;
		return _getEmptyClientObject();
	}
	// return true if client is exist or false is not.
	static bool isClientExist(string accountNum)
	{
		cClient client = cClient::find(accountNum);
		return (!client.isEmpty());
	}
	// create new client in data base
	static cClient addNewClient(string accountNum)
	{
		return cClient(enAddNew, "", "", "", "", accountNum, "", 0);
	}
	// return all clients in database
	static vector<cClient> getClients()
	{
		return _loadClientsDataFromFile();
	}
	// return total account balances
	static double getTotalBalances()
	{
		vector<cClient> clientData = _loadClientsDataFromFile();

		double total = 0;
		for (cClient& client : clientData)
		{
			total += client.balance;
		}
		return total;
	}
	// return all transfer operations in database
	static vector<stTransfer> getTransferLogs()
	{
		return _loadTransferLogsFromFile();
	}
	
	
	//-------------------[Print Methods ]-------------------//
	// print client data
	/*
	void print()
	{
		// empty client
		if (isEmpty())
		{
			cout << "\nThis client not have any information to print ):" << endl;
			return;
		}
		
		cout << "\n-------------------------------------------------\n";
		cout << "         ["+ fullName() + "'s Info]              ";
		cout << "\n-------------------------------------------------\n";
		cout << "\nFirstName   : " << firstName;
		cout << "\nLastName    : " << lastName;
		cout << "\nFullName    : " << fullName();
		cout << "\nEmail       : " << email;
		cout << "\nPhone       : " << phone;
		cout << "\nAccount No  : " << accountNumber;
		cout << "\nPinCode     : " << pinCode;
		cout << "\nBalance     : " << balance << endl;
	}
	*/
};

