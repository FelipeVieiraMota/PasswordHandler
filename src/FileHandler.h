
#ifndef FileHandler_H 
#define FileHandler_H
#include <sstream>
using namespace std;
/**
 * FileHeader V 1.0
 * */
class FileHandler {
    public: 
        void call(void);
        void author(void);
        void openFile(void);
        void cleanString(string & pricipal, const string & elementToErase);
        void getAllTitlesOnGedit();
        void getAllTitlesOnConsole();
        bool searchPatterns(void);
        void getCompleteInformations(void);
        int createNewPassword(void);
        string stringValidation(void);
};
#endif