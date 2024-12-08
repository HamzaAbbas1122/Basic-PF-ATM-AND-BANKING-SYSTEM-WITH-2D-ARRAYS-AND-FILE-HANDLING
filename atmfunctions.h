
//
#include<iostream>
#include<fstream>
#include<string>
#include <ctime> //for the time function
#include<iomanip> // to handle the precision of decimal points in the function total bank balance
#include<sstream> //to convert int to  string data type
#include <limits> // setw and limit used in time function
#include <windows.h> // to control the console


using namespace std;

char user[100][5][50] = { 0 };//50 represents the number of characters that can be stored in taht particular column

int account[100][6] = { 0 };

int transactions[100][3] = { 0 };

int usercount = 0;



//A FUCNTION TO PRODUCE BEEP SOUND
void sound() {
	Beep(1000,1500); // 1000 Hz frequency, 1500 ms duration
}

//Afunction to Encrypt pin
int  encryption_of_pin(int pin) {
	int encryptpin = 0;
	encryptpin = (pin * 7) + 3;
	return encryptpin;
}


//A FUNCTION TO DECRYPT PIN
int decryption_of_pin(int pin) {
	int decryptpin = 0;
	decryptpin = (pin - 3) / 7;
	return decryptpin;
}

//A FUNCTION TO GET THE CURRENT TIME AND DATE OF TRANSACTION
string getcurrenttime() {
	time_t now = time(0);

	tm localTime;
	localtime_s(&localTime, &now);

	ostringstream timeStream;
	timeStream << (1900 + localTime.tm_year) << "-"
		<< setw(2) << setfill('0') << (1 + localTime.tm_mon) << "-"
		<< setw(2) << setfill('0') << localTime.tm_mday << "   | Time : "
		<< setw(2) << setfill('0') << localTime.tm_hour << ":"
		<< setw(2) << setfill('0') << localTime.tm_min << ":"
		<< setw(2) << setfill('0') << localTime.tm_sec;

	return timeStream.str();
}

void intro() {
	cout << endl << endl << endl << endl << endl;
	cout << "\033[31m*******************************************************************************************************************************************\033[0m" << endl << "\033[32m        ***************************************************************************************************************************        \033[0m" << endl << "        \033[33m    *******************************************************************************************************************           \033[0m " << endl << "              \033[34m  ***********************************************************************************************************              \033[0m  " << endl << "       \033[35m             ***************************************************************************************************            \033[0m        " << endl;
	cout << endl << endl << endl << endl;

	cout << "            \033[36m                         ****************************************" << endl;
	cout << "            \033[31m -----```~~~~~~>>>>\033[0m      *          WELCOME TO BAJWA BANK       *    \033[31m <<<<-----```~~~~~~\033[0m" << endl;
	cout << "                                     ****************************************\033[0m";
	cout << endl << endl << endl << endl;
	cout << "\033[31m      \033[35m              ***************************************************************************************************         \033[0m           " << endl << "       \033[34m         ***********************************************************************************************************             \033[0m   " << endl << " \033[33m           *******************************************************************************************************************     \033[0m       " << endl << "\033[32m        ***************************************************************************************************************************  \033[0m      " << endl << "\033[31m*******************************************************************************************************************************************\033[0m" << endl;

	Sleep(7000); //3000MS = 5 SEC


	system("cls"); //TO CLEAR SCREEN�AFTER�5�SEC
}


//A FUNCTION TO MAKE A ERROR RECORD
void error(string s) {
	ofstream errorfile("errorf.txt", ios::app);
	errorfile << s << endl;
	errorfile.close();
}

//A FUNCTION TO CONVERT INT TO STRING

template <typename T> // T is a placeholder for a type
string to_string(int num)
{

	string result = "";
	bool isNegative = false;

	// Check if the number is negative
	if (num < 0) {
		isNegative = true;
		num = -num; // Make it positive for processing
	}

	// Extract digits and construct the string
	do {
		int digit = num % 10;         // Get the last digit
		result = char(digit + '0') + result; // Convert digit to char and prepend
		num /= 10;                    // Remove the last digit
	} while (num > 0);

	// Add negative sign if needed
	if (isNegative) {
		result = '-' + result;
	}

	return result;
}

//A FUNCTION TO MAKE SESSION REPORT OR ACTIVITIES REPORT

void session(string s) {

	ofstream sessionfile("sessioninfo.txt", ios::app);
	sessionfile << s << endl;
	sessionfile.close();
}

//A FUNCTION PUSH ALL THE DATA FROM ARRAYS TO FILES FOR PERMANENT STORAGE

void arraytofile() {

	//WRITING DATA INTO FILES
	ofstream userfile("users.txt");
	ofstream accountfile("accounts.txt");

	if (userfile.is_open() && accountfile.is_open()) {

		for (int i = 0; i < usercount; i++) {

			userfile << user[i][0] << " "
				<< user[i][1] << " "
				<< user[i][2] << " "
				<< user[i][3] << " "
				<< user[i][4] << endl;
		}

		for (int i = 0; i < usercount; i++) {

			accountfile << account[i][0] << " "
				<< account[i][1] << " "
				<< account[i][2] << " "
				<< account[i][3] << " "
				<< account[i][4] << " "
				<< account[i][5] << endl;
		}


		userfile.close();
		accountfile.close();


	}

	else {

		cout << "���>>>    Error in file opening    <<<���" << endl;
		sound();
		string error0 = "error in file opening of array to file function";
		error(error0);
	}
}

//A FUNCTION TO DISPLAY USER INFO AS REQUESTED BY ADMIN

void userinfo() {
	cout << "\033[32m************************************************************************************************************************************** \033[0m " << endl << endl << endl;
	string cnic;

	cout << "\033[36mENTER THE USER CNIC:    \033[0m ";
	cin >> cnic;
	cout << endl;
	bool cnac = false;//to check whether teh user exits or not

	for (int i = 0; i < usercount; i++) {

		if (cnic == user[i][1]) {
			cnac = true;
			cout << "\033[33m_\033[0m \033[32mACCOUNT VERIFIED \033[0m \033[33m_\033[0m" << endl;

			cout << "\033[1;34m  NAME:          \033[1;31m" << user[i][0] << "\033[0m" << endl;
			cout << "\033[1;33m  CNIC:          \033[1;31m" << user[i][1] << "\033[0m" << endl;
			cout << "\033[1;32m  DATE OF BIRTH: \033[1;31m" << user[i][2] << "\033[0m" << endl;
			cout << "\033[1;36m  EMAIL:         \033[1;31m" << user[i][3] << "\033[0m" << endl;
			cout << "\033[1;35m  PHONE NUMBER:  \033[1;31m" << user[i][4] << "\033[0m" << endl;
			string s1;

			string v = user[i][0];
			string k = to_string(account[i][2]);

			s1 = "USER " + v + " WITH USER ID " + k + " IS LOGGED IN BY ADMIN FOR USER INFO"; //ADDING TO SESSION REPORT

			session(s1);

		}
	}

	if (cnac == false) {
		string error17;
		error17 = "no user found";
		error(error17);
		cout << " \033[31mNO SUCH USER FOUND\033[0m" << endl;
		sound();
	}
}

//TO CHECK FOR USER ACCOUNT INFORMATION
void accoutinfo() {

	int cardid;
	cout << "\033[31mENTER THE USER CARD ID\033[0m:     ";
	cin >> cardid;
	bool cnoc = false;//TO CHECK WHTHER CARD ID EXITS OR NOT

	for (int i = 0; i < usercount; i++) {
		if (cardid == account[i][1]) {
			cout << "\033[33m_\033[0m \033[34mACCOUNT VERIFIED\033[0m \033[33m_\033[0m" << endl;
			cnoc = true;
			cout << "\033[1;34m  TYPE:      \033[1;31m" << account[i][0] << "\033[0m" << endl;
			cout << "\033[1;33m  CARD ID:   \033[1;31m" << account[i][1] << "\033[0m" << endl;
			cout << "\033[1;36m  USER ID:   \033[1;31m" << account[i][2] << "\033[0m" << endl;
			cout << "\033[1;35m  PIN:       \033[1;31m" << account[i][3] << "\033[0m" << endl;
			cout << "\033[1;32m  BALANCE:   \033[1;31m" << account[i][4] << "\033[0m" << endl;
			cout << "\033[1;31m  STATUS:    \033[1;31m" << account[i][5] << "\033[0m" << endl;

			string s2;

			string v = user[i][0];

			string k = to_string(account[i][2]);

			s2 = "USER " + v + " WITH USER ID  " + k + "IS LOGGED IN BY ADMIN FOR ACCOUNST INFORMATION";//for session report 

			session(s2);
		}
	}

	if (cnoc == false) {
		string error19;
		error19 = "no user found";
		error(error19);
		cout << " \033[31mNO SUCH USER FOUND\033[0m" << endl;
		sound();
	}
}

//A FUNCTION TO ACTIVATE OR BLOCK USER
void status() {

	int userIndex = 0;

	int choice = 0; // Initialize with an invalid value

	cout << "\033[35mENTER THE USER INDEX:\033[0m ";
	cin >> userIndex;

	// Validate user index

	if (userIndex < 0 || userIndex >= usercount) {
		cout << "\033[1;31m------------------------------------\033[0m" << endl;
		cout << "\033[1;31m|       INVALID USER INDEX         |\033[0m" << endl;
		cout << "\033[1;31m------------------------------------\033[0m" << endl;
		sound(); // Play error sound
		string errorLog = "Invalid user index entered: " + to_string(userIndex);
		error(errorLog); // Log error
	}

	// STATUS PANEL
	cout << "     \033[1;34m----------------------------------------\033[0m" << endl;
	cout << "     \033[1;33m|      PRESS 1 FOR ACTIVATION           |\033[0m" << endl;
	cout << "     \033[1;34m----------------------------------------\033[0m" << endl;
	cout << "     \033[1;36m|      PRESS 0 FOR BLOCKING USER        |\033[0m" << endl;
	cout << "     \033[1;34m----------------------------------------\033[0m" << endl;
	cout << "     \033[1;32mEnter your choice: \033[0m";
	cin >> choice;

	if (choice == 1) { // Activate user
		if (account[userIndex][5] == 1) {
			cout << "\033[1;33m------------------------------------\033[0m" << endl;
			cout << "\033[1;35m|       USER ALREADY ACTIVE         |\033[0m" << endl;
			cout << "\033[1;33m------------------------------------\033[0m" << endl;
		}
		else {
			account[userIndex][5] = 1; // Update user status to active
			cout << "\033[1;32m------------------------------------\033[0m" << endl;
			cout << "\033[1;37m|          USER ACTIVATED           |\033[0m" << endl;
			cout << "\033[1;32m------------------------------------\033[0m" << endl;


			string ext = user[userIndex][0];
			string ext1 = user[userIndex][1];

			string logMessage = "USER " + ext +
				" WITH USER ID " + ext1 +
				" IS ACTIVATED BY ADMIN.";
			session(logMessage); // Log activation in the session
		}
	}
	else if (choice == 0) { // Block user
		if (account[userIndex][5] == 0) {
			cout << "\033[1;32m------------------------------------\033[0m" << endl;
			cout << "\033[1;36m|          USER ALREADY BLOCKED          |\033[0m" << endl;
			cout << "\033[1;32m------------------------------------\033[0m" << endl;
		}
		else
			account[userIndex][5] = 0; // Update user status to blocked
		cout << "\033[1;31m------------------------------------\033[0m" << endl;
		cout << "\033[1;35m|          USER BLOCKED            |\033[0m" << endl;
		cout << "\033[1;31m------------------------------------\033[0m" << endl;

		string ext = user[userIndex][0];
		string ext1 = user[userIndex][1];

		string logMessage = "USER " + ext +
			" WITH USER ID " + ext1 +
			" IS BLOCKED BY ADMIN.";
		session(logMessage); // Log blocking in the session
	}
	else {
		cout << "\033[1;31m------------------------------------\033[0m" << endl;
		cout << "\033[1;31m|        INVALID CHOICE            |\033[0m" << endl;
		cout << "\033[1;31m------------------------------------\033[0m" << endl;
		sound(); // Play error sound



		string errorLog = "Invalid admin choice entered: " + to_string(choice);
		error(errorLog); // Log error
	}

	// Write updated account information back to file
	arraytofile();
}

//A FUNCTION CHECK TOTAL BALANCE IN BANK

void totalbalance() {

	long  double sum = 0;

	for (int i = 0; i < usercount; i++) {

		sum = sum + account[i][4];

	}

	cout << "\033[35mTOTAL AMOUNT IN BANK=\033[0m \033[31m" << fixed << setprecision(4) << sum << "\033[0m" << endl;// i used it to correctly dispLAYy balance

	//FIXED SETPRECISION TO FIX AND  SPECIFY NUMBER OF DECIMAL PLACES

	session("Total bank balance checked by admin");

}
void filetoarray() {

	ifstream userfile("users.txt");
	ifstream accountfile("accounts.txt");

	if (userfile.is_open() && accountfile.is_open()) {

		usercount = 0;

		while (userfile >> user[usercount][0] >> user[usercount][1] >> user[usercount][2] >> user[usercount][3] >> user[usercount][4]) {
			usercount++;
		}

		int count = 0;

		while (accountfile >> account[count][0] >> account[count][1] >> account[count][2] >> account[count][3] >> account[count][4] >> account[count][5]) {
			count++;
		}


		userfile.close();
		accountfile.close();

	}

	else {

		cout << " \033[31mERROR IN FILE TO ARRAY FUNCTION\033[0m" << endl;

		string error9 = "invalid id choice";
		error(error9);

	}



}
//A FUNCTION TO WRITE ALL THE DATA FROM TEMPORARY FILES TO ORIGINAL FILES AND TO CREATE BACKUP FILES CONTAINING ORIGINAL DATA

void filetofile() {

	ofstream userfile("users.txt");
	ofstream accountfile("accounts.txt");
	ofstream transfile("transactions.txt");

	ifstream tempu("tempu.txt");
	ifstream tempt("tempt.txt");
	ifstream tempa("tempa.txt");

	string recovery;

	if (userfile.is_open() && accountfile.is_open() && transfile.is_open() && tempu.is_open() && tempt.is_open() && tempa.is_open()) {

		while (getline(tempu, recovery)) { //FOR READING FROM TEMPORARY USER FILE

			userfile << recovery << endl;

		}

		while (getline(tempa, recovery)) { //FOR READING FROM TEMPORARY ACCOUNT FILE

			accountfile << recovery << endl;

		}

		while (getline(tempt, recovery)) { //FOR READING FROM TEMPORARY TRANSACTION FILE

			transfile << recovery << endl;
		}

		userfile.close();
		accountfile.close();
		transfile.close();

		tempu.close();
		tempt.close();
		tempa.close();

		filetoarray();
		arraytofile();
	}
	else {

		sound();
		cout << "\033[1;31mFiles not openend correctly in file to file \033[0m";
		string error21 = "Files not openend correctly in file to file";
		error(error21);
	}
}

//A FUNCTION TO DELETE USER  

void deleteuser() {

	int cardid = 0;

	string cnic;

	int userid = 0;

	cout << "\033[31m**************\033[0m  \033[34m ENTER THE DETAILS OF USER \033[0m  \033[31m ***************\033[0m" << endl;
	cout << "\033[35mENTER THE \033[0m\033[32mUSER ID:\033[0m ";
	cin >> userid;
	cout << endl << endl;
	cout << "\033[35mENTER THE \033[0m\033[32mCARD ID:\033[0m ";
	cin >> cardid;
	cout << endl << endl;
	cout << "\033[35mENTER THE \033[0m\033[32mCNIC:\033[0m ";
	cin >> cnic;
	cout << endl << endl;


	ifstream userfile("users.txt");
	ifstream accountfile("accounts.txt");
	ifstream transfile("transactions.txt"); //original files 

	ofstream delfile("delete.txt", std::ios::app);

	ofstream tempu("tempu.txt");
	ofstream tempt("tempt.txt");
	ofstream tempa("tempa.txt"); //back up files

	bool found1 = false;
	bool found2 = false;
	bool found3 = false;

	if (userfile.is_open() && accountfile.is_open() && transfile.is_open() &&
		tempu.is_open() && delfile.is_open() && tempt.is_open() && tempa.is_open()) {

		string del;

		while (getline(userfile, del)) {

			if (del.find(cnic) != string::npos) {

				found1 = true;
				delfile << del << endl;

			}

			else {

				tempu << del << endl;
			}

		}
		while (getline(accountfile, del)) {

			if (del.find(to_string(cardid)) != string::npos) {

				found2 = true;
				delfile << del << endl;
			}
			else {
				tempa << del << endl;
			}
		}

		while (getline(transfile, del)) {

			if (del.find(to_string(userid)) != string::npos) {
				found3 = true;
				delfile << del << endl;
			}
			else {

				tempt << del << endl;
			}
		}


		if (found1 == false && found2 == false) {
			cout << " \033[31mNO SUCH USER FOUND\033[0m" << endl;
			error("No such found");
		}

		if (found1 == true && found2 == true) {

			usercount--;
			cout << "       \033[36m        -----------------------------------------------" << endl;
			cout << "            |  \033[0m       \033[35m   USER DELETED SUCCESSFULLY  \033[0m    \033[36m      |" << endl;
			cout << "               -----------------------------------------------\033[0m" << endl;

			sound();
			string session1 = "USER ID: " + to_string(userid) + " DELETED BY ADMIN";
			session(session1);

			userfile.close();
			accountfile.close();
			transfile.close();
			delfile.close();
			tempu.close();
			tempt.close();
			tempa.close();


			filetofile();
		}

	}
	else {
		cout << "\033[31mError: Files not opened correctly in deleteuser.\033[0m" << endl;
		sound();
		string error22 = "Error: Files not opened correctly in deleteuser.";
		error(error22);
	}
}


//A FUNCTION FOR ERROR REPORT

void errorinfo() {
	cout << "     \033[34m            ----------------------------------------------------" << endl;
	cout << "                |\033[0m        \033[33m    ERROR REPORT GENERATING......    \033[0m  \033[34m     |" << endl;
	cout << "                 ----------------------------------------------------\033[0m" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "         \033[35m       -----------------------------------------------" << endl;
	cout << "               |      \033[0m  \033[36m      PLEASE WAIT......     \033[0m       \033[35m    |" << endl;
	cout << "                -----------------------------------------------\033[0m" << endl;

	Sleep(3000);
	system("cls");

	session("error report checked by admin");

	cout << "                \033[31m        ------------------------" << endl;
	cout << "                       |   \033[0m   \033[36m ERROR REPORT \033[0m \033[31m   |" << endl;
	cout << "                        ------------------------\033[0m" << endl;

	string err;

	ifstream errorfile("errorf.txt");

	if (errorfile.is_open()) {

		while (getline(errorfile, err)) {

			cout << err << endl;
		}
		errorfile.close();
	}

	else
	{
		cout << "\033[31mError file not opened\033[0m" << endl;
		sound();
		string error23 = "Error file not opened";
		error(error23);
	}
}

//A FUNCTION TO DISPLAY INFORMATION OF DELETED USERS

void delinfo() {

	cout << "     \033[33m      ---------------------------------------------------------" << endl;
	cout << "          |   \033[0m   \033[34m    DELETED USERS REPORT GENERATING....  \033[0m    \033[33m      |" << endl;
	cout << "           ---------------------------------------------------------\033[0m" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "                 \033[36m       -----------------------------------------------" << endl;
	cout << "                       |  \033[0m   \033[35m         PLEASE WAIT.........    \033[0m \033[36m        |" << endl;
	cout << "                        -----------------------------------------------\033[0m" << endl;
	Sleep(3000);
	system("cls");

	cout << "               \033[35m                ------------------------" << endl;
	cout << "                              |\033[0m \033[36mDELETED USERS REPORT \033[0m \033[35m |" << endl;
	cout << "                               ------------------------\033[0m" << endl;

	session("Deleted users info checked by admin");

	string dell;


	ifstream delfile("delete.txt");

	if (delfile.is_open()) {

		while (getline(delfile, dell)) {
			cout << dell << endl;
		}

		delfile.close();
	}

	else
	{
		cout << "\033[31mDelete file not opened\033[0m" << endl;
		sound();
		string error25 = "delete file not opened";
		error(error25);
	}
}

//A FUNCTION FOR SESSION REPORT

void sessioninfo() {
	cout << "       \033[34m                ----------------------------------------------------" << endl;
	cout << "                      | \033[0m     \033[33m      SESSION REPORT GENERATING...... \033[0m \033[34m       |" << endl;
	cout << "                       ----------------------------------------------------\033[0m" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "       \033[33m                 -----------------------------------------------" << endl;
	cout << "                              |   \033[0m      \033[34m      PLEASE WAIT..........  \033[0m  \033[33m       |" << endl;
	cout << "                               -----------------------------------------------\033[0m" << endl;
	Sleep(3000);
	system("cls");
	cout << "             \033[35m                        ----------------------------------" << endl;
	cout << "                                    |    \033[0m    \033[36m  SESSION REPORT \033[0m  \033[35m       |" << endl;
	cout << "                                     ----------------------------------\033[0m" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	session("Activities checked by admin");
	string sessions;

	ifstream sessionfile("sessioninfo.txt");

	if (sessionfile.is_open()) {

		while (getline(sessionfile, sessions)) {
			cout << sessions << endl;
		}
		sessionfile.close();

	}

	else
	{
		cout << "\033[31mSession file not opened\033[0m" << endl;
		sound();

		string error24 = "session file not opened";
		error(error24);
	}
}

//A FUCNTION TO DEPOSIT CHEQUE IN USER ACCOUNT 

void chequedeposit() {

	int index = 0;
	int amount;
	int userid;

	cout << endl;

	cout << " \033[35mEnter the user index for cheque deposit:  \033[0m  ";
	cin >> index;
	cout << endl;
	cout << endl;
	cout << " \033[35mEnter the user id for cheque deposit:  \033[0m   ";
	cin >> userid;
	cout << endl;
	cout << endl;

	cout << " \033[35mEnter the cheque amount to deposit into user account:    \033[0m";
	cin >> amount;
	cout << endl;
	cout << endl;
	while (amount < 0) {
		sound();
		cout << "\033[31mInvalid Amount\033[0m ... \033[mPlease Try Again" << endl;
		error("invalid chque amount");
	}
	if (userid == account[index][2]) {

		cout << "\033[35mTRANSFERRING AMOUNT....\033[0m" << endl;

		Sleep(2000);

		account[index][4] += amount;


		cout << "\033[35mCHEQUE AMOUNT\033[0m \033[31m" << amount << " \033[0m \033[35mTRANSFERRED TO\033[0m \033[31m " << user[index][0] << "\033[0m \033[35mWITH USER ID\033[0m \033[31m " << account[index][2] << "\033[0m" << endl;

		//TO WRITE IT ALSO TO USERS TRANSACTION

		ofstream transfile("transactions.txt", ios::app);//NOT TO OVERWRITE

		transfile << "User Id" << account[index][2] << " | Cheque Deposited to " << user[index][0] << " | Amount: " << amount << " By ADMIN ON " << " | Date " << getcurrenttime() << endl;

		transfile.close();

		arraytofile();
	}
	else {
		cout << endl;
		cout << "NO USER FOUND" << endl;
		sound();
		error("invalid user id");
	}
}

// USER ACCOUNT CREATION

void useraccountcreation() {


	cout << "         \033[36m ENTER\033[0m \033[35mFULL NAME\033[0m \033[36mOF USER\033[0m:         ";
	cin.ignore();
	cin.getline(user[usercount][0], 50);

	// Check if the name contains digits
	bool hasDigit = false;
	do {
		hasDigit = false;
		for (int i = 0; user[usercount][0][i] != '\0'; i++) {
			if (isdigit(user[usercount][0][i])) { // Check if character is a digit
				hasDigit = true;
				break;
			}
		}

		if (hasDigit) {
			sound();
			cout << "         \033[31mINVALID INPUT\033[0m....\033[36m FULL NAME SHOULD NOT CONTAIN DIGITS. PLEASE TRY AGAIN: \033[0m" << endl;
			cin.getline(user[usercount][0], 50);
		}
	} while (hasDigit);

	cout << endl << endl;
	cout << "         \033[36m ENTER\033[0m \033[35m USERS CNIC\033[0m \033[36m(13 DIGITS)\033[0m          ";
	cin.getline(user[usercount][1], 50);
	cout << endl << endl;
	while (strlen(user[usercount][1]) != 13) {
		sound();
		string error14 = "invalid cnic";
		error(error14);

		cout << "            \033[31mINVALID INPUT\033[0m....\033[36mENTER USERS CNIC (13 DIGITS)\033[0m         ";
		cin.getline(user[usercount][1], 50);
		cout << endl;
	}

	cout << "          \033[36mENTER\033[0m \033[35mUSER DATE OF BIRTH\033[0m           ";
	cin.getline(user[usercount][2], 50);
	cout << endl << endl;
	while (strlen(user[usercount][2]) != 8) {
		sound();
		string error14 = "invalid date of birth";
		error(error14);

		cout << "            \033[31mINVALID INPUT\033[0m....\033[36mENTER 8 DIGITS OF Date Of Birth\033[0m          ";
		cin.getline(user[usercount][2], 50);
	}

	cout << "          \033[36mENTER \033[0m\033[35mUSER PHONE NUMBER\033[0m\033[35m(11 DIGITS)\033[0m            ";
	cin >> user[usercount][3];
	cout << endl << endl;
	while (strlen(user[usercount][3]) != 11) {
		sound();
		cout << "            \033[31mINVALID INPUT\033[0m....\033[36mENTER PHONE NUMBER (11 DIGITS)\033[0m         ";

		string error15 = "invalid number";
		error(error15);
		cin.ignore();

		cin.getline(user[usercount][3], 50);
		cout << endl;
	}

	cout << "        \033[36m  ENTER\033[0m \033[35mUSER EMAIL\033[0m            ";
	cin.ignore();
	cin.getline(user[usercount][4], 50);
	cout << endl << endl;
	bool atrate = false;
	bool dot = false;

	for (int i = 0; user[usercount][4][i] != '\0'; i++) {
		if (user[usercount][4][i] == '@') {
			atrate = true;
		}
		if (user[usercount][4][i] == '.') {
			dot = true;
		}
	}

	while (atrate == false || dot == false) {
		sound();
		cout << "\033[31mINVALID EMAIL\033[0m....\033[36m ENTER EMAIL AGAIN:\033[0m     ";

		string error16 = "invalid email";
		error(error16);

		cin.getline(user[usercount][4], 50);
		cout << endl << endl;
		atrate = false;
		dot = false;

		for (int i = 0; user[usercount][4][i] != '\0'; i++) {
			if (user[usercount][4][i] == '@') {
				atrate = true;
			}
			if (user[usercount][4][i] == '.') {
				dot = true;
			}
		}
	}


	cout << "          \033[36mENTER THE\033[0m \033[35mACCOUNT TYPE\033[0m " << endl;
	cout << endl << endl;

	cout << "  \033[35m        PRESS\033[0m \033[31m1\033[0m \033[35mFOR SAVING \033[0m" << endl;
	cout << "  \033[36m        -----------------------------------\033[0m" << endl;
	cout << "  \033[35m        PRESS\033[0m \033[31m2\033[0m \033[35mFOR CURRENT \033[0m" << endl;

	cout << "                 "; cin >> account[usercount][0];
	cout << endl << endl;

	while (account[usercount][0] != 1 && account[usercount][0] != 2) {
		error("INVALID CHOICE");
		cout << "\033[35mINVALID TYPE CHOICE.\033[0m" << endl;
		sound();

		cout << "  \033[35m        PRESS\033[0m \033[31m1\033[0m \033[35mFOR SAVING \033[0m" << endl;
		cout << "  \033[36m        -----------------------------------\033[0m" << endl;
		cout << "  \033[35m        PRESS\033[0m \033[31m2\033[0m \033[35mFOR CURRENT \033[0m" << endl;
		cin >> account[usercount][0];
	}
	cout << endl;
	account[usercount][1] = 1000 + usercount + rand()%1000+3;//card id

	account[usercount][2] = 2000 + usercount + rand()%1000+3;//user account  id

	

	cout << "                 ............\033[33mTHANK YOU FOR THE DETAILS:\033[0m.........." << endl;
	cout << endl;
	Sleep(1000);
	system("cls");
	Sleep(500);
	cout << "                             \033[36mGENERATING USER ACCOUNT INFORMATION...........\033[0m" << endl;
	Sleep(3000);
	system("cls");
	cout << "|\033[35m USER CARD =\033[0m    \033[31m  " << account[usercount][1] << "\033[0m" << endl;
	cout << "\033[32m----------------------------------------------\033[0m" << endl;

	cout << "|\033[35m USER ACCOUNT ID = \033[0m \033[31m" << account[usercount][2] << " \033[0m" << endl;
	cout << "\033[32m----------------------------------------------\033[0m" << endl;

	long long int pin = 0;


	cout << "          \033[36mENTER THE\033[0m \033[31m4\033[0m \033[36mDIGIT\033[0m \033[35mPIN\033[0m \033[36mFOR ACCOUNT CREATION\033[0m           ";
	cin >> pin;
	cout << endl << endl;
	while (pin < 1000 || pin > 9999) {
		error("INVALID PIN");
		cout << "      \033[31mINVALID PIN\033[0m...\033[36mENTER THE 4 DIGIT PIN FOR ACCOUNT CREATION: \033[0m";
		sound();

		cin >> pin;
	}

	long long int confirmpin = 0;

	cout << "          \033[36mRE-ENTER THE\033[0m \033[31m4\033[0m \033[36mDIGIT\033[0m \033[35mPIN\033[0m \033[36mFOR ACCOUNT CREATION\033[0m           ";

	cin >> confirmpin;

	while (pin != confirmpin) {

		cout << "         \033[31mPIN MISMATCHED\033[0m" << endl;

		error("PIN MISMATCHED");

		cout << "          \033[36mRE-ENTER THE\033[0m \033[31m4\033[0m \033[36mDIGIT\033[0m \033[35mPIN\033[0m \033[36mFOR ACCOUNT CREATION\033[0m           ";
		sound();
		cin >> confirmpin;
		cout << endl << endl;
		while ((confirmpin < 1000 || confirmpin > 9999)) {
			cout << "     \033[31mINVALID INPUT\033[0m....\033[36mRE - ENTER THE\033[0m \033[31m4\033[0m \033[36mDIGIT\033[0m \033[35mPIN\033[0m \033[36mFOR ACCOUNT CREATION\033[0m           ";

			sound();
			cin.ignore();
			cin >> confirmpin;
			cout << endl;
		}
	}

	if (pin == confirmpin) {

		account[usercount][3] = encryption_of_pin(pin);

	}
	cout << endl;
	cout << endl;
	cout << "       \033[36m  ENTER THE\033[0m \033[35mINITIAL DEPOSIT\033[0m \033[35m( Atleast 10000 PKR )\033[0m  "<<endl;
	cin >> account[usercount][4];
	cout << endl << endl;
	while (account[usercount][4] < 10000) {
		sound();
		cout << "   \033[31mINVALID INPUT\033[0m...\033[36m  ENTER THE\033[0m \033[35mINITIAL DEPOSIT\033[0m \033[35m(Atleast 10000 PKR)\033[0m ";

		cin >> account[usercount][4];
		cout << endl << endl;
		error("INVALID INPUT");
	}

	ofstream transfile("transactions.txt", ios::app);

	if (transfile.is_open()) {
		transfile << "User ID " << account[usercount][2] << " made the first deposit of " << account[usercount][4] << " by admin" << endl;
		transfile.close();
	}

	else {
		cout << "\033[31mError opening transactions file!\033[0m" << endl;
		sound();
		error("Error opening transactions file!");
	}

	cout << "                      ~~~~~~~~~~>> ...THANKYOU FOR YOUR PATIENCE...  <<~~~~~~~~~~~" << endl << endl;
	account[usercount][5] = 1;

	string logMessage1 = "USER " + string(user[usercount][0]) +
		" WITH USER ID " + to_string(account[usercount][1]) +
		" CREATED  BY ADMIN.";
	session(logMessage1); // ACCOUNT CREATED in the session

	Sleep(1000);
	system("cls");
	cout << "     \033[35m          --------------------------------------------------" << endl;
	cout << "              |    \033[0m \033[36m       ACCOUNT CREATED SUCCESSFULLY \033[0m  \033[35m       |\033[0m" << endl;
	cout << "      \033[31m         --------------------------------------------------\033[0m" << endl;
	cout << "      \033[35m        |  \033[0m  \033[36m        USER STATUS : ACTIVE     \033[0m  \033[35m           |" << endl;
	cout << "               --------------------------------------------------\033[0m" << endl;
	cout << "       \033[34m             -----------------------------------------------" << endl;
	cout << "                   |  \033[0m  \033[33m      PLEASE SAVE THE FOLLOWING:  \033[0m  \033[34m       |" << endl;
	cout << "                    -----------------------------------------------\033[0m" << endl;

	Sleep(1000);
	cout << "     \033[36m    --------------------------------------------------" << endl;
	cout << "       |\033[0m \033[35mUSER CARD =  \033[0m  \033[31m  " << account[usercount][1] << "  \033[0m   \033[36m        |\033[0m" << endl;
	cout << "   \033[36m    |\033[0m \033[35mUSER ACCOUNT ID =\033[0m \033[31m" << account[usercount][2] << "   \033[0m   \033[36m      |" << endl;
	cout << "         --------------------------------------------------\033[0m" << endl;
	usercount++;
	arraytofile();
}




//A FUNCTION FOR ADMIN CONTROL

void adminpanel() {


	int choice;
	int prove;
	cout << "    \033[34m                                      *********************************\033[0m" << endl;
	cout << "     \033[33m                                     *          ADMIN PANEL          *\033[0m" << endl;
	cout << "     \033[34m                                     *********************************\033[0m" << endl;
	cout << endl;

	cout << "                    \033[35mENTER THE BANK SECRET CODE TO GET ACCESS: \033[0m    ";
	cin >> prove;
	cout << endl << endl;
	if (prove == 1122) {

		session("ADMIN LOGGED IN");

		do {
			system("cls");
			cout << "\033[31m************************************************************************************************************************\033[0m" << endl;

			cout << "    \033[34m                                       *********************************\033[0m" << endl;
			cout << "     \033[33m                                      *     ADMIN PANEL ACTIVATING    *\033[0m" << endl;
			cout << "     \033[34m                                      *********************************\033[0m" << endl;

			cout << endl;
			Sleep(3000);
			system("cls");
			cout << "\033[31m***********************************************************************************************************************************\033[0m" << endl;

			cout << "    \033[34m                                             *********************************\033[0m" << endl;
			cout << "            \033[34m********************************* \033[33m   *      ADMIN PANEL ACTIVATED    *\033[34m  ***********************************\033[30m" << endl;
			cout << "            \033[34m                                     *********************************\033[0m" << endl;
			cout << endl;
			//ADMIN PANEL
			cout << "   \033[35m------------------------------------------------                        ----------------------------------------------\033[0m" << endl;
			cout << "   \033[35m|        \033[36mPRESS 1 FOR USER INFORMATION         \033[35m|                         |       \033[36mPRESS 2 FOR USER ACCOUNT INFORMATION\033[35m|\033[0m" << endl;
			cout << "   \033[35m------------------------------------------------                        ----------------------------------------------\033[0m" << endl;
			cout << endl;
			cout << "   \033[35m------------------------------------------------                         ---------------------------------------\033[0m" << endl;
			cout << "   \033[35m|     \033[36mPRESS 3 FOR ACTIVATE OR BLOCK A USER      \033[35m|                       |  \033[36mPRESS 4 TO CHECK TOTAL SAVNIGS IN BANK  \033[35m|\033[0m" << endl;
			cout << "   \033[35m------------------------------------------------                         ---------------------------------------\033[0m" << endl;
			cout << endl;
			cout << "   \033[35m-----------------------------------------------                           --------------------------------------\033[0m" << endl;
			cout << "   \033[35m|        \033[36mPRESS 5 TO DELETE A USER            \033[35m|                          |  \033[36mPRESS 6 FOR ERROR REPORTS FOR AUDIT   \033[35m|\033[0m" << endl;
			cout << "   \033[35m-----------------------------------------------                           --------------------------------------\033[0m" << endl;
			cout << endl;
			cout << "   \033[35m------------------------------------------------                          ---------------------------------------\033[0m" << endl;
			cout << "   \033[35m|       \033[36mPRESS 7 FOR DATA OF DELETED USERS       \033[35m|                       |  \033[36mPRESS 8 FOR ACTIVITY REPORT FOR AUDIT \033[35m|\033[0m" << endl;
			cout << "   \033[35m------------------------------------------------                           --------------------------------------\033[0m" << endl;
			cout << endl;
			cout << "   \033[35m-------------------------------------------                               ---------------------------------------\033[0m" << endl;
			cout << "   \033[35m|         \033[36mPRESS 9 FOR CHEQUE DEPOSIT     \033[35m|                              |  \033[36mPRESS 10 FOR USER ACCOUNT CREATION     \033[35m|\033[0m" << endl;
			cout << "   \033[35m-------------------------------------------                               ---------------------------------------\033[0m" << endl;
			cout << endl;
			cout << "                                   \033[35m-------------------------------------------------------\033[0m" << endl;
			cout << "                                  |          \033[36mPRESS 11 FOR RETURN TO MAIN MENU             \033[35m|\033[0m" << endl;
			cout << "                                   \033[35m-------------------------------------------------------\033[0m" << endl;
			cout << endl;
			cout << endl;



			cin >> choice;
			cout << endl;
			if (choice < 1 || choice > 11) {
				string error4 = "invalid admin choice";
				error(error4);
			}
			while (choice < 1 || choice > 11) {
				sound();
				cout << "     \033[31mINVALID CHOICE.PLEASE CHOOSE AGAIN\033[0m";
				cout << endl;
				cin >> choice;
			}
			if (choice == 1) {
				system("cls");
				userinfo();

			}
			if (choice == 2) {
				system("cls");
				accoutinfo();
			}
			if (choice == 3) {
				system("cls");
				status();
			}
			if (choice == 4) {
				system("cls");
				totalbalance();
			}
			if (choice == 5) {
				system("cls");
				deleteuser();
			}
			if (choice == 6) {
				system("cls");
				errorinfo();
			}
			if (choice == 7) {
				system("cls");
				delinfo();
			}
			if (choice == 8) {
				system("cls");
				sessioninfo();
			}
			if (choice == 9) {
				system("cls");
				chequedeposit();
			}
			if (choice == 10) {
				system("cls");
				useraccountcreation();
			}

			if (choice != 11) {
				int y;
				cout << endl << endl << endl;
				cout << "     \033[93mTo perform Another Operation PRESS: \033[0m  (\"\033[91m 1 \033[0m\" for \"\033[93m YES \033[0m\" and \"\033[91m 0 \033[0m\" for \"\033[93m NO \033[0m\")";
				cin >> y;
				cout << endl << endl;

				while (y < 0 || y > 1) {
					cout << "INVALID CHOICE. PLEASE TRY AGAIN" << endl;
					sound();
					cin >> y;
				}

				if (y == 0) {
					system("cls");
					cout << endl;
					cout << endl;
					sound();
					sound();
					cout << "    \033[35mTHANK YOU SIRE\033[0m \033[33mADMIN.SHIFTING CONTROL TO \033[0m\033[34mMAIN MENU\033[0m....." << endl << endl << endl << endl;
					break;
				}
			}
			if (choice == 11) {
				system("cls");
				sound();
				sound();
				cout << endl;
				cout<<endl;
				cout << "SHIFTING TO MAIN MENU....." << endl;
				break;
			}

		} while (choice != 11);
	}
	else {

		string error18;
		error18 = "no admin found";
		error(error18);
		sound();
		system("cls");
		cout << " YOUR ARE NOT AN ADMIN. ILLEGEAL ATTEMPT." << endl;
		sound(), sound(), sound();
		Sleep(2000);
	}

}
void withdraw(int index) {

	cout << "\033[33m ENTER THE AMOUNT YOU WANT TO WITHDRAW :      \033[0m";

	cin >> transactions[index][0];


	if (transactions[index][0] < 0) {

		string error13 = "\033[31minvalid withdraw amount\033[0m";
		error(error13);
	}

	while (transactions[index][0] < 0) {

		cout << "\033[31mINVALID INPUT\033[0m......\033[36mPLEASE ENTER AMOUNT AGAIN.\033[0m      ";
		sound();
		cin >> transactions[index][0];
		cout << endl;
	}

	if (transactions[index][0] > 0 && transactions[index][0] <= account[index][4]) {

		cout << "\033[34mTHE AMOUNT\033[0m \033[31m " << transactions[index][0] << "\033[0m \033[34mHAS BEEN WITHDRAWAN\033[0m " << endl;
		account[index][4] = account[index][4] - transactions[index][0];

		ofstream transfile("transactions.txt", ios::app);

		transfile << "mUser id" << account[index][2] << " | Withdraw by " << user[index][0] << " | Amount: " << transactions[index][0] << " | Date " << getcurrenttime() << endl;

		transfile.close();

		arraytofile();
	}
	else {

		cout << "\033[31mWITHDRAW REQUEST NOT APPROVED\033[0m" << endl;

		string error19 = "withdraw request not approved";
		error(error19);
	}


}
void deposit(int index) {
	cout << "\033[33m ENTER THE AMOUNT YOU WANT TO DEPOSIT :      \033[0m";
	cin >> transactions[index][1];
	if (transactions[index][1] < 0) {
		string error10 = "invalid amount";
		error(error10);
	}

	while (transactions[index][1] < 0) {
		cout << "    \033[31mINVALID INPUT\033[0m......\033[36mPLEASE ENTER AMOUNT AGAIN.\033[0m    ";
		cin >> transactions[index][1];
		cout << endl;
	}
	if (transactions[index][1] > 0) {

		cout << "     \033[34mTHE AMOUNT\033[0m \033[31m " << transactions[index][1] << "\033[0m \033[34mHAS BEEN WITHDRAWAN\033[0m " << endl;
		account[index][4] = account[index][4] + transactions[index][1];

		ofstream transfile("transactions.txt", ios::app);
		if (transfile.is_open()) {
			transfile << "User Id " << account[index][2] << " | Deposited by " << user[index][0] << " | Amount: " << transactions[index][1]
				<< " | Date: " << getcurrenttime() << endl;
			transfile.close();
		}
		else {
			cout << "Error opening transactions file!" << endl;
		}
		arraytofile();
	}

}


//A FUNCTION FOR FUNDS TRANSFER

void fundstransfer(int index) {

	int cardid;

	cout << "    \033[32mENTER THE RECEIVER CARD ID FOR FUNDS TRANSFER\033[0m    ";
	cin >> cardid;
	cout << endl;
	cout << "    \033[32mENTER THE AMOUNT YOU WANT TRANSFER\033[0m               ";
	cin >> transactions[index][2];
	cout << endl << endl;
	if (transactions[index][2] < 0) {
		string error10 = "invalid balance";
		error(error10);
	}
	while (transactions[index][2] < 0) {

		cout << "     \033[31mINVALID INPUT\033[0m......\033[36mPLEASE ENTER AMOUNT AGAIN.\033[0m     ";
		cin >> transactions[index][2];
		cout << endl;
	}

	if (transactions[index][2] <= account[index][4]) {

		bool cardf = false;

		for (int i = 0; i < usercount; i++) {

			if (account[i][1] == cardid) {

				cardf = true;
				account[i][4] = account[i][4] + transactions[index][2];

				cout << "\033[34mTHE AMOUNT\033[0m \033[31m " << transactions[index][2] << "\033[0m \033[34mHAS BEEN WITHDRAWAN\033[0m " << endl;
				account[index][4] = account[index][4] - transactions[index][2];

				ofstream transfile("transactions.txt", ios::app);

				transfile << "user id |" << account[index][2] << "fund transfer from " << user[index][0] << "| to card id" << account[i][1] << " | amount: " << transactions[index][2] << " | Date: " << getcurrenttime() << endl;
				transfile << "user id |" << account[i][2] << "has received funds from " << user[index][0] << "| to his card id" << account[index][1] << " | amount: " << transactions[index][2] << " | Date: " << getcurrenttime() << endl;
				transfile.close();
				arraytofile();


			}
		}
		if (cardf == false) {
			cout << "\033[31mNO CARD ID FOUND\033[0m" << endl;
			string error9 = "no card id found";
			error(error9);
		}
	}
	else {
		cout << " \033[31mINSUFFICIENT BALANCE\033[0m" << endl;
		string error11 = "insufficient balance";
		error(error11);
	}


}
int login() {
	int pin, id, confirmpin;
	int index = -1;
	bool loginsuccess = false;

	cout << "\033[32m*******************************************************************************************************************************************\033[0m" << endl;
	cout << "\033[1;36m" << "     ENTER USER ID:   " << "\033[0m";
	cin >> id;
	cout << endl;
	cout << "\033[1;36m" << "     ENTER YOUR PIN:  " << "\033[0m";
	cin >> pin;
	cout << endl;

	for (int i = 0; i < usercount; i++) {

		if (id == account[i][2] && pin == decryption_of_pin(account[i][3])) {

			if (account[i][5] == 0) {
				sound();
				cout << "\033[1;34m" << "                     ------------------------------------------------ " << "\033[0m" << endl;
				cout << "\033[1;31m" << "                    |               YOUR ACCOUNT IS BLOCKED          |" << "\033[0m" << endl;
				cout << "\033[1;34m" << "                     ------------------------------------------------ " << "\033[0m" << endl;
				string blockedLog = "Blocked user with ID " + to_string(id) + " attempted to login.";
				session(blockedLog);
				return index;
			}
			index = i;
			loginsuccess = true;
			cout << "\033[1;34m" << "                         ------------------------------------------------" << "\033[0m" << endl;
			cout << "\033[1;34m" << "                        |               LOGGING YOU IN........           |" << "\033[0m" << endl;
			cout << "\033[1;34m" << "                         ------------------------------------------------" << "\033[0m" << endl;
			cout << endl;
			Sleep(1500);
			system("cls");
			cout << endl << endl << endl << endl << endl << endl << endl << endl;
			cout << "\033[1;34m" << "                          ------------------------------------------------" << "\033[0m" << endl;
			cout << "\033[1;33m" << "                         |                LOGIN SUCCESSFUL                |" << "\033[0m" << endl;
			cout << "\033[1;34m" << "                          ------------------------------------------------" << "\033[0m" << endl;
			Sleep(1000);
			cout << endl;
			system("cls");
			cout << "\033[1;34m" << "                    ------------------------------------------------" << endl;
			cout << "                    |\033[0m \033[1;33mWELCOME " << user[i][0] << " ! ACCOUNT OPENED\033[0m \033[1;34m|" << "" << endl;
			cout << "                    ------------------------------------------------" << "\033[0m" << endl;
			cout << endl;
			cout << "\033[32m*******************************************************************************************************************************************\033[0m" << endl;

			Sleep(5000);

			string s4;
			string v = user[i][0];
			string k = to_string(account[i][1]);
			s4 = "User " + v + "With user Id " + k + " is logged in";
			session(s4); // Log successful login
			break;
		}
	}
	if (!loginsuccess) {
		sound();
		cout << "\033[1;31m" << "INVALID INPUT\033[0m...\033[33m BETTER LUCK NEXT TIME" << "\033[0m" << endl; // Red text  

		string errorLog = "Invalid PIN, user ID, or the account is blocked.";
		error(errorLog);
	}

	return index;
}

void transactionhistory(int index) {

	ifstream transfile("transactions.txt");

	if (!transfile.is_open()) {

		cout << " \033[31mError while opening transactions file.\033[0m" << endl;
		sound();
		return;
	}

	string line;
	bool found = false;
	int userId = account[index][2];

	cout << "TRANSACTION HISTORY OF USER ID:  " << userId << endl;

	while (getline(transfile, line))
	{

		if (line.find(to_string(userId)) != string::npos)
		{
			cout << line << endl;
			found = true;
		}
	}

	if (!found) {
		sound();
		cout << "\033[31mNO TRANSACTION HISTORY AVAILABLE.\033[0m" << endl;
		string error20 = "No transaction history found for this user.";
		error(error20);
	}

	transfile.close();
}
//A FUNCTION FOR CHECK BALANCE
void checkbalance(int index) {

	cout << "                \033[33m  PLEASE WAIT................\033[0m  " << endl;
	cout << "           -----------------------------------------------" << endl;
	Sleep(3000);
	system("cls");

	cout << "    \033[36m  -----------------------------------------------" << endl;
	cout << "    |\033[0m \033[35m YOUR BALANCE =  \033[0m \033[31m " << account[index][4] << "\033[0m \033[36m |" << endl;
	cout << "      -----------------------------------------------\033[0m" << endl;
	cout << endl;

	string s5;
	string v = user[index][0];
	string k = to_string(account[index][1]);

	s5 = "User " + v + "With user Id " + k + " demanded balance check";
	session(s5);
}

//A FUNCTION FOR PIN UPDATE

void updatepin()
{

	int pin = 0;
	int id;
	int card_id;

	cout << "   \033[33mENTER YOUR\033[0m \033[31mUSER ID\033[0m \033[33mTO CHANGE THE PIN\033[0m:      ";
	cin >> id;
	cout << endl << endl;
	cout << "   \033[33mENTER YOUR\033[0m \033[31mCARD ID\033[0m \033[33mTO CHANEG THE PIN\033[0m:        ";
	cin >> card_id;
	cout << endl << endl;

	bool idfound = false;;

	for (int i = 0; i < usercount; i++)
	{

		if (account[i][2] == id && account[i][1] == card_id)
		{
			cout << "\033[34m  ID CORRECT\033[0m" << endl;
			idfound = true;
			cout << "  \033[36mENTER THE NEW PIN\033[0m:     ";
			cin >> pin;
			cout << endl << endl;
			if (pin < 1000 || pin > 9999) {
				string error12 = " \033[31minvalid new pin\033[0m ";
				error(error12);
			}

			while (pin < 1000 || pin > 9999) {
				sound();

				cout << "    \033[31mINVALID PIN\033[0m...\033[36mPLEASE ENTER 4 DIGIT PIN\033[0m ";

				cin >> pin;
				cout << endl;
			}

			int confirmpin = 0;

			cout << "    \033[31mRE-ENTER\033[0m \033[36mTHE 4 DIGIT PIN TO CONFIRM FOR ACCOUNT CREATION\033[0m     ";

			cin >> confirmpin;
			cout << endl << endl;
			while (pin != confirmpin) {

				cout << "    \033[31mPIN MISMATCHED\033[0m" << endl;

				error("PIN MISMACHTED");

				cout << "    \033[31mINVALID INPUT\033[0m... \033[36mRE-ENTER THE 4 DIGIT PIN TO CONFIRM FOR ACCOUNT CREATION = \033[0m      ";
				sound(), sound(), sound();
				cin >> confirmpin;
				cout << endl;
				while (confirmpin < 1000 || confirmpin > 9999) {

					cout << "    \033[31mINVALID INPUT\033[0m... \033[31mREENTER THE 4 DIGIT PIN TO CONFIRM FOR ACCOUNT CREATION = \033[0m     ";
					sound();
					cin.ignore();
					cin >> confirmpin;
					cout << endl << endl;
				}
			}
			account[i][3] = encryption_of_pin(confirmpin);

			cout << "          \033[34m      -----------------------------------------------" << endl;
			cout << "               |  \033[33m          PIN CHANGED SUCCESSFULLY   \033[34m        |" << endl;
			cout << "                -----------------------------------------------\033[0m" << endl;
			cout << endl << endl << endl;

			string s4;
			string v = user[i][0];
			string k = to_string(account[i][1]);
			s4 = "User " + v + "With user Id " + k + " is logged in";
			session(s4);
			arraytofile();

			break;
		}
	}
	if (idfound == false)
	{
		cout << "    \033[31mNO ID FOUND\033[0m" << endl;
		sound();
		string error8 = "invalid id choice";
		error(error8);
	}
}

