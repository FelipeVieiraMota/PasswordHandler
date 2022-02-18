/**
 * 
 * Linux Version 1.0 
 * 
 * I created this wrench to help to deal with my passwords.
 * I have several of passwords and I need to organize and access quickly them
 * 
 */

#include <iostream>
#include <fstream>
#include <fstream>
#include <stdlib.h>
#include <curses.h>
#include <sstream>
#include <errno.h>
#include <stdio_ext.h>
#include "FileHandler.h"
#include <string.h>
#include <cstring>
using namespace std;

const string FILE_NAME = "/home/felipe/Passwords/PasswordManagerFiles/Passwords.txt";
const int MAX_SIZE = 255;

bool FileHandler::searchPatterns(void){
	system("clear");
	string currentLine;
    string byTitle = "Title: ";
	ifstream file;
    char wordToSearch[MAX_SIZE];
    bool found = false;
	cout<<"--------------------------------------------------"<<endl;	
	cout<<"Search in Title"<<endl;
	cout<<"--------------------------------------------------"<<endl;
	cin.getline(wordToSearch,MAX_SIZE);
	cout<<"--------------------------------------------------"<<endl;
	cout<<endl;
    cout<<endl;
    cout<<endl;
	file.open(FILE_NAME);
    if(!file.is_open()){
        cout<<"ERROR TO OPEN THE FILE. IT CAN BE CORRUPTED OR IT DOESN'T EXISTIS!";
    }else{
        cout<<"--------------------------------------------------"<<endl;	
		cout<<"Result"<<endl;
		cout<<"--------------------------------------------------"<<endl;
        while(!file.eof()){
            getline(file,currentLine);
            if (currentLine != "" && 
                currentLine != "########################################" &&
                currentLine.find("Title: ") != string::npos
            ){

                string lowerCase = wordToSearch;
                lowerCase[0] = tolower(lowerCase[0]);

                string uppercase = wordToSearch;
                uppercase[0] = toupper(uppercase[0]);

                if( currentLine.find(uppercase) != string::npos || currentLine.find(lowerCase) != string::npos ){
                    cout<<currentLine<<endl;
                    getline(file,currentLine);
                    getline(file,currentLine);
                    cout<<currentLine<<endl;
                    getline(file,currentLine);
                    cout<<currentLine<<endl;
                    getline(file,currentLine);
                    cout<<currentLine<<endl;                                        
                    found = true;
                }
            }
        }

        if (!found){
            cout<<"Password not found!"<<endl;
        }
    }
  	file.close();
    getchar();
    return found;
}

void FileHandler::author(void){
    system("clear");
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"About"<<endl;
    cout<<"------------------------------------------------------------"<<endl;                
    cout<<"Powered by Felipe Mota"<<endl;
    cout<<"email: felipevieiramota@gmail.com"<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    getchar();
    system("clear");
}

string FileHandler::stringValidation(void){	    
	int i=0;
	char var[255];
	char parameter;
	string result;
	__fpurge(stdin); 
	//Para limpar o buffer em Windows, use: fflush(stdin)
	//Para limpar o buffer em Linux, use: __fpurge(stdin)
	std::cin.getline(var,255);
	parameter = var [0];
	result = var;
	return result;
}

void FileHandler::getAllPasswords(void) {
    system("clear");
  	ifstream fileToOpen;
  	string line;
  	fileToOpen.open(FILE_NAME);
	if(!fileToOpen.is_open()){
  	    cout<<"File corrupted.";
	}else{
		system("clear");
		while(!fileToOpen.eof()){
  			getline(fileToOpen,line);
  			cout << line <<endl;
		}
	}
  	fileToOpen.close();
    getchar();
}

int FileHandler::createNewPassword(void){
    system("clear");
    string line;
    ifstream fileToOpen;
	char op;
    string title;
    string username;
    string password;
    string details;

	cout<<"Title: ";
    title = stringValidation();
    cout<<endl;

    cout<<"User: ";
    username = stringValidation();
    cout<<endl;

    cout<<"Password: ";
    password = stringValidation();
    cout<<endl;

    cout<<"Details: ";
    details  = stringValidation();
    cout<<endl;

	do{
		cout << "Do you really want to procede with these data? (y/n) : ";cin >> op;
	}while(op!= 'N' && op!= 'Y' && op!= 'n' && op!= 'y');

    if(op == 'Y' ||op == 'y') {
        // Open target file in the end of file EOF.
    	ofstream outPutFile;
		outPutFile.open(FILE_NAME,ios::app);
		outPutFile<<endl;
		outPutFile<<endl;
        outPutFile<<"########################################"<<endl;
        outPutFile<<"Title: "<<title<<endl;
        outPutFile<<"########################################"<<endl;
        outPutFile<<"User: "<<username<<endl;
        outPutFile<<"Password: "<<password<<endl;
        outPutFile<<"Details: "<<details<<endl;
        outPutFile<<"########################################"<<endl;
        outPutFile<<endl;
		outPutFile<<endl;
        outPutFile.close();
    }

    return EXIT_SUCCESS;
}

void FileHandler::openFile(void){
    ifstream file;
  	file.open(FILE_NAME);
  	if(!file.is_open())
  		cout<<"File corrupted or not found.";
  	else
  		system("cat /home/felipe/Passwords/PasswordManagerFiles/Passwords.txt");
  	file.close();
}

void FileHandler::call(void) {
    char op;
    do{	
        system("clear");
        do{
            system("clear");
            cout<<endl;
            cout<<"------------------------------------------------------------"<<endl;
            cout<<" Password Handler [A]bout "                                  <<endl;
            cout<<"------------------------------------------------------------"<<endl;
            cout<<" [1] - Save new passoword 			         			   "<<endl;
            cout<<" [2] - Get all passwords 			         			   "<<endl;
            cout<<" [3] - Search patterns 			         			       "<<endl;
            cout<<" [0] - Exit      			         			           "<<endl;
            cout<<"------------------------------------------------------------"<<endl;
            cout<<"*****************  Powered by Felipe Mota  *****************"<<endl;
            cout<<"------------------------------------------------------------"<<endl<<endl;
            __fpurge(stdin);
			cout<<" Option : ";op = getchar();
            __fpurge(stdin);
        }
        while(op=='\n');
		cout<<endl;
		switch(op){
			case '1':{ createNewPassword(); } break;
			case '2':{ getAllPasswords(); } break;
			case '3':{ searchPatterns(); } break;
            case 'A':{ author(); } break;
            case 'a':{ author(); } break;
		}
    }
    while (op!='0');
    system("clear");
}

int main(int argc, char const *argv[]){
    FileHandler handler;
    handler.call();
    return EXIT_SUCCESS;
}