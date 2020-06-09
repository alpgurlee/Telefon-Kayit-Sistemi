#ifndef _buffer_h
#define _buffer_h
#include "contact.h"

class Buffer {
    protected:
        Contact* buffer;
        int size;
        int max_size;
    public:
        Buffer();
        ~Buffer();
        void add(Contact);
        void remove(int);
        int getsize();
        Contact& operator[](int);
};

class SortedBuffer : public Buffer {
    public:
        SortedBuffer();
        ~SortedBuffer();
        void sort();
};


#endif