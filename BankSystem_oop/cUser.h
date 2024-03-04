#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "../Librarys/stringo.h"
#include "../Librarys/cDate.h"
#include "../Librarys/cUtil.h"
#include "cPerson.h"


class cUser : public cPerson
{
private:
	enum eMode
	{
		eEmptyUserObject = 0, eUpdateUser = 1, eAddNewUser = 2
	};

	eMode _mode;
	string _userName;
	string _password;
	int _permissions;
	static const short _key = 12;
	bool _MarkForDeleting = false;

	//===============================================================//
	//							Private Method						 //
	
	// encryption and decryption
	static string _encrypt(string en)
	{
		return cUtil::encrypt(en, _key);
	}
	static string _decrypt(string de)
	{
		return cUtil::decrypt(de, _key);
	}
	
	struct stUserLog; // forward declaration
	// create empty user object
	static cUser _emptyUserObject()
	{
		return cUser(eEmptyUserObject, "", "", "", "", "", "", 0);
	}
	// convert line to user object
	static cUser _convertLinetoUserObject(string line, string sep = "#//#")
	{
		vector<string> UsersData = stringo::split(line, "#//#");
		return cUser(eUpdateUser, UsersData[0], UsersData[1], UsersData[2], UsersData[3], _decrypt(UsersData[4]), _decrypt(UsersData[5]), stoi(UsersData[6]));

	}
	// convert line to stUserLogs 
	static stUserLog _convertLinetoUserLogs(string line, string sep = "#//#")
	{
		vector<string> userLog = stringo::split(line, "#//#");
		stUserLog record;
		record.dateTime = userLog[0];
		record.userName = _decrypt(userLog[1]);
		record.password = _decrypt(userLog[2]);
		record.permission = stoi(userLog[3]);

		return record;
	}
	// convert user to line
	static string _convertUsertoLine(cUser user, string sep = "#//#")
	{
		string line = "";
		line += user.firstName + sep;
		line += user.lastName + sep;
		line += user.email + sep;
		line += user.phone + sep;
		line += _encrypt(user.userName) + sep;
		line += _encrypt(user.password) + sep;
		line += to_string(user.permissions);
		return line;
	}
	// loading user data from databeas
	static vector<cUser> _loadUsersDataFromFile(string path = "../data/Users.txt", string sep = "#//#")
	{
		vector<cUser> _UsersData;
		fstream file;
		file.open(path, ios::in);
		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				cUser user = _convertLinetoUserObject(line);
				_UsersData.push_back(user);
			}
			file.close();
		}
		return _UsersData;
	}
	// loading user logs from databeas
	static vector<stUserLog> _loadUserLogsFromFile(string path = "../data/UserLogs.txt", string sep = "#//#")
	{
		vector<stUserLog> _usersLogs;
		fstream file;
		file.open(path, ios::in);
		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				 stUserLog record = _convertLinetoUserLogs(line);
				_usersLogs.push_back(record);
			}
			file.close();
		}
		return _usersLogs;
	}
	// save users data to file
	static void _saveUsersDataToFile(vector<cUser>& usersDats, string path = "../data/Users.txt")
	{
		fstream file;
		file.open(path, ios::out);
		
		if (file.is_open())
		{
			string line = "";
			for (cUser user : usersDats)
			{
				if (user._MarkForDeleting == false)
				{
					line = _convertUsertoLine(user);
					file << line << endl;

				}
			}
		}
		file.close();
	}
	// save user data to file
	static void _saveUsertoFile(string lineData, string path = "../data/Users.txt")
	{
		fstream file;
		file.open(path, ios::out|ios::app);

		if (file.is_open())
		{
			file << lineData << endl;
			file.close();
		}
	}



	// update user date
	void _update()
	{
		vector<cUser> usersDate = _loadUsersDataFromFile();
		for (cUser& user : usersDate)
		{
			if (user.userName == userName)
			{
				user = *this;
				break;
			}
		}
		_saveUsersDataToFile(usersDate);
	}
	// add new user
	void _addNewUser()
	{
		_saveUsertoFile(_convertUsertoLine(*this));
	}

public:
	// parameterize constructor
	cUser(eMode mode,string firstName, string lastName, string email, string phone, string userName, string password, int permissions): cPerson(firstName,lastName,email,phone)
	{
		_mode = mode;
		_userName = userName;
		_password = password;
		_permissions = permissions;
	}

	// properties setters
	void setUserName(string userName)
	{
		_userName = userName;
	}
	void setPassword(string password)
	{
		_password = password;
	}
	void setPermissions(int permissions)
	{
		_permissions = permissions;
	}

	// properties getters
	string getUserName()
	{
		return _userName;
	}
	string getPassword()
	{
		return _password;
	}
	int getPermissions()
	{
		return _permissions;
	}

	__declspec(property(get = getUserName)) string userName;
	__declspec(property(get = getPassword, put = setPassword)) string password;
	__declspec(property(get = getPermissions, put = setPermissions)) int permissions;

	// struct UserLogs
	struct stUserLog
	{
		string userName;
		string password;
		string dateTime;
		int permission;
	};

	// =====================================================================//
	//								Methods   
	
	// return true if user is empty or false 
	bool isEmpty()
	{
		return (_mode == eMode::eEmptyUserObject);
	}

	enum eSave
	{
		eSvFaildEmptyObj = 0, eSvSuccessfully = 1, eSvUserExist = 2,
	};
	// save data
	eSave save()
	{
		switch (_mode)
		{
		case cUser::eEmptyUserObject:
			return eSvFaildEmptyObj;
			break;

		case cUser::eUpdateUser:
			_update();
			return eSvSuccessfully;

			break;
		case cUser::eAddNewUser:
			if (isExist(userName))
			{
				return eSvUserExist;
			}
			else
			{
				_addNewUser();
				_mode = eMode::eUpdateUser;
				return eSave::eSvSuccessfully;
			}
			break;
		default:
			break;
		}
	}
	// delete user from data base
	bool _delete()
	{
		vector<cUser> usersData = _loadUsersDataFromFile();

		for (cUser& user : usersData)
		{
			if (user.userName == _userName)
			{
				user._MarkForDeleting = true;
				break;
			}
		}
		_saveUsersDataToFile(usersData);
		*this = _emptyUserObject();
		return true;
	}

	// enum permissions
	enum ePermissions
	{
		eAll = -1, pListClinets = 1, pAddClient = 2, pDeleteClient = 4, pUpdateClient = 8,
		pFindClient = 16, pTrnasaction = 32 , pMangeUsers = 64,
	};
	// check  user permissions
	bool checkPermissions(ePermissions pagePermission)
	{
		if (this->permissions == ePermissions::eAll)
			return true;
		
		if((this->permissions & pagePermission) == pagePermission)
			return true;
		else
			return false;
	}

	// save user login to filelogs
	void registerLogin()
	{
		fstream file("../data/UserLogs.txt", ios::out|ios::app);
		if (file.is_open())
		{
			file << cDate::convertDatetoString(cDate()) << " - ";
			file << cDate::getClock() << "#//#" << _encrypt(this->userName);
			file << "#//#" << _encrypt(this->password) << "#//#" << this->permissions << endl;
			file.close();
		}
	}

	// =====================================================================//
	// 							 Static Methods   
	
	// initialize file paht
	//static void fileName(string filePath, string sep)
	//{
	//	_filePath = filePath;
	//	_seperator = sep;
	//}

	// find user by userName
	static cUser find(string userName)
	{
		vector<cUser> usersData = _loadUsersDataFromFile();
		for (cUser user : usersData)
		{
			if (user.userName == userName)
			{
				return user;
			}
		}
		return _emptyUserObject();
	}
	// find user by userName and password
	static cUser find(string userName, string password)
	{
		vector<cUser> usersData = _loadUsersDataFromFile();
		for (cUser &user : usersData)
		{
			if (user.userName == userName && user.password == password)
			{
				return user;
			}
		}
		return _emptyUserObject();
	}
	// return if user is found or not
	static bool isExist(string userName)
	{
		cUser user = find(userName);
		return (!user.isEmpty());
	}
	// add new user
	static cUser addNewUser(string userName)
	{
		return cUser(eAddNewUser, "","","","",userName,"",0);
	}
	// return all users in database
	static vector<cUser> getUsers()
	{
		return _loadUsersDataFromFile();
	}

	// return all userLogs in database
	static vector<stUserLog> getUserLogs()
	{
		return _loadUserLogsFromFile();
	}
};

