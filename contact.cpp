#ifndef _contact
#define _contact
#include <string>
#include <iostream>
#include "contact.h"
using namespace std;
Contact::Contact() {
    id = "";
    isim = "";
    soyisim = "";
    cepno = "";
    isno = "";
}

Contact::Contact(string id, string isim, string soyisim, string cepno, string isno) {
    this->id = id;
    this->isim = isim;
    this->soyisim = soyisim;
    this->cepno = cepno;
    this->isno = isno;
}

Contact::~Contact() {

}

// Contact sınıfının getter metotları.
string Contact::getid() {
    return id;
}

string Contact::getisim() {
    return isim;
}

string Contact::getsoyisim() {
    return soyisim;
}

string Contact::getcepno() {
    return cepno;
}

string Contact::getisno() {
    return isno;
}
// Contact sınıfının getter metotları.

void Contact::print_contact() { // Kişinin bilgilerini yazdırır.
    cout << "ID: " << id << endl;
    cout << "Adi: " << isim << endl;
    cout << "Soyadi: " << soyisim << endl;
    cout << "Cep Numarasi: " << cepno << endl;
    cout << "Is numarasi: " << isno << endl;
    cout << endl;
} 

string Contact::tostring() {
    return id + " " + isim + " " + soyisim + " " + cepno + " " + isno;
}

void Contact::setisim(string isim) {
    this->isim = isim;
}

#endif