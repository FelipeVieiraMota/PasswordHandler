#include <iostream>
using namespace std;

void saveNewPassword(void){}

void getAllPasswords(void){}

void openFile(void){}

void closeFile(void){}

void mainScreen(void) {
    system("clear");
    cout<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    cout<<" Password Handler [A]bout "                                  <<endl;
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"[1] - Save new passoword 			         			   "<<endl;
    cout<<"[2] - Get all passwords 			         			       "<<endl;
    cout<<"[3] - Search by patterns 			         			   "<<endl;
    cout<<"[0] - Exit      			         			               "<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"*****************  Powered by Felipe Mota  *****************"<<endl;
    cout<<"------------------------------------------------------------"<<endl<<endl;
}

int main(int argc, char const *argv[])
{
    mainScreen();
    return 0;
}