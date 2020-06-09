#ifndef _contact_h
#define _contact_h
#include <string>

class Contact {
    private:
        std::string id;
        std::string isim;
        std::string soyisim;
        std::string cepno;
        std::string isno;
    public:
        Contact(std::string,std::string,std::string,std::string,std::string);
        Contact();
        ~Contact();
        std::string getid();
        std::string getisim();
        std::string getsoyisim();
        std::string getcepno();
        std::string getisno();
        std::string tostring();
        void setisim(std::string);
        void print_contact();
};


#endif