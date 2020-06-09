#ifndef _program_h
#define _program_h
#include "contact.h"
#include "buffer.h"

class Program {
    private:
        SortedBuffer buffer;
        int status;
    public:
        Program();
        ~Program();
        void readFile(std::string);
        void writeFile(std::string);
        void add_contact(Contact);
        void remove_contact(std::string);
        void list_contacts();
        void modify_contact(std::string);
        void search_contact(std::string);
};

#endif