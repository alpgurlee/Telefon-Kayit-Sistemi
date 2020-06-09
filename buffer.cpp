#ifndef _buffer
#define _buffer
#include "buffer.h"
#include <iostream>
#include <algorithm>

using namespace std;

Buffer::Buffer() {
    max_size = 1;
    size = 0;
    buffer = new Contact[max_size];
}

Buffer::~Buffer() { // Destructor
    delete[] buffer;
}

int Buffer::getsize() {
    return size;
}

void Buffer::add(Contact new_contact) {
    if(size == max_size) { // Eğer buffer dolu ise yeni bir hafıza bloğu ayır.
        Contact* temp = buffer; // Bufferin eski adresini tutar.
        max_size *= 2; // Bufferin maksimum kapasitesini 2 katına çıkar.
        Contact* new_buffer = new Contact[max_size];
        for(int i = 0; i < size; i++) { // Eski bufferin içeriğini yeni buffera kopyalar.
            new_buffer[i] = buffer[i];
        }
        buffer = new_buffer;
        delete[] temp; // Eski bufferi siler.
    }
    buffer[size] = new_contact; // Yeni kişiyi ekle.
    size++;    
}

void Buffer::remove(int index) {
    for(int i = index; i < size-1; i++) {
        buffer[i] = buffer[i+1];
    }
    size--;
}

// Buffer sınıfının contactları tutan buffer arrayine direkt olarak ulaşabilmek için [] operatörünü aşırı yüklendi
Contact& Buffer::operator[](int index) { 
    if(index >= size || index < 0) {
        cout << "Array index out of bound." << endl;
        exit(0);
    }
    return buffer[index];
}

SortedBuffer::SortedBuffer() : Buffer() { // Ana sınıfın constructorunu çağırır.

}

void SortedBuffer::sort() { // Arrayi alfabetik olarak siralar. Bubble sort algoritmasını kullanır.
    for(int i = 0; i < getsize() - 1; i++) {
        for(int k = i+1; k < getsize(); k++) {
            if(buffer[i].getisim() > buffer[k].getisim()) {
                Contact temp = buffer[i];
                buffer[i] = buffer[k];
                buffer[k] = temp;
            }
        }
    }
}

SortedBuffer::~SortedBuffer() {
}

#endif