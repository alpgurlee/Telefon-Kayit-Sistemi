#ifndef _program
#define _program
#include "program.h"
#include "contact.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

Program::Program() {
    status = 0;
}

Program::~Program() {
}

void Program::add_contact(Contact new_contact) {
    for(int i = 0; i < buffer.getsize(); i++) {
        if(buffer[i].getid() == new_contact.getid()) {
            cout << "Bu ID'ye sahip bir kisi bulunmaktadir. Lutfen baska bir ID giriniz." << endl;
            return;
        }
    }
    buffer.add(new_contact);
}

void Program::remove_contact(string id) { // TODO
    for(int i = 0; i < buffer.getsize(); i++) {
        if(id == buffer[i].getid()) {
            buffer.remove(i);
            return;
        }
    }
    cout << "Bu ID'ye kayitli bir kisi bulunamadi." << endl;
}

void Program::readFile(string filename) {
    ifstream file(filename); // Dosyayı aç
    if(!(file.is_open())) { // Dosya adinin dogru olup olmadigini kontrol eder. Eger dosya acilamadiysa programi kapatir.
        cout << "Dosya acilamadi." << endl;
        exit(0);
    }
    string id, isim, soyisim, cepno, isno;
    while(file >> id >> isim >> soyisim >> cepno >> isno) { // Dosyanın sonuna gelesiye kadar satır satır oku.
        Contact newcontact(id, isim, soyisim, cepno, isno); // Yeni contact oluştur ve buffera ekle.
        buffer.add(newcontact); // Dosyayı kapat
    }
    file.close();
}

void Program::writeFile(string filename) {
    ofstream file;
    file.open(filename); // Dosyayi ac
    for(int i = 0; i < buffer.getsize(); i++) { // Her satira bir kayit yazdir.
        file << buffer[i].tostring() << endl;
    }
    file.close();
}

void Program::list_contacts() {
    buffer.sort();
    cout << "Mevcut kayit sayisi: " << buffer.getsize() << endl;
    cout << "-------------------------" << endl;
    for(int i = 0; i < buffer.getsize(); i++) {
        buffer[i].print_contact();
    }
    cout << "-------------------------" << endl;
}

void Program::modify_contact(string id) {
    for(int i = 0; i < buffer.getsize(); i++) {
        if(buffer[i].getid() == id) {
            string id, isim, soyisim, cepno, isno;
            cout << "ID'yi giriniz: ";
            cin >> id;
            cout << "Isim giriniz: ";
            cin >> isim;
            cout << "Soyadi giriniz: ";
            cin >> soyisim;
            cout << "Cep numarasi giriniz: ";
            cin >> cepno;
            cout << "Is numarasini giriniz: ";
            cin >> isno;
            Contact newcontact = Contact(id, isim, soyisim, cepno, isno);
            buffer[i] = newcontact;
            return;
        }
    }
    cout << "Bu ID'ye kayitli bir kisi bulunmamaktadir." << endl;
}

void Program::search_contact(string type) {
    if(type == "id") {
        string id;
        cout << "Kisinin ID'sini giriniz: ";
        cin >> id;
        for(int i = 0; i < buffer.getsize(); i++) {
            if(buffer[i].getid() == id) {
                buffer[i].print_contact();
                return;
            }
        }
        cout << "Bu ID'ye kayitli bir kisi bulunmamaktadir." << endl;
    }
    else if(type == "isim") {
        string isim;
        cout << "Kisinin ismini giriniz: ";
        cin >> isim;
        for(int i = 0; i < buffer.getsize(); i++) {
            if(buffer[i].getisim() == isim) {
                buffer[i].print_contact();
                return;
            }
        }
        cout << "Bu isimde bir kisi bulunmamaktadir." << endl;
    }
    else if(type == "soyisim") {
        string soyisim;
        cout << "Kisinin soyadini giriniz: ";
        cin >> soyisim;
        for(int i = 0; i < buffer.getsize(); i++) {
            if(buffer[i].getsoyisim() == soyisim) {
                buffer[i].print_contact();
                return;
            }
        }
        cout << "Bu soyadli bir kisi bulunmamaktadir." << endl;
    }
    else if(type == "cepno") {
        string cepno;
        cout << "Kisinin ismini giriniz: ";
        cin >> cepno;
        for(int i = 0; i < buffer.getsize(); i++) {
            if(buffer[i].getcepno() == cepno) {
                buffer[i].print_contact();
                return;
            }            
        }
        cout << "Bu cep numarasina sahip bir kisi bulunmamaktadir." << endl;
    }
    else if(type == "isno") {
        string isno;
        cout << "Kisinin is numarasini giriniz: ";
        cin >> isno;
        for(int i = 0; i < buffer.getsize(); i++) {
            if(buffer[i].getisno() == isno) {
                buffer[i].print_contact();
                return;
            }
        }
        cout << "Bu is numarasina sahip bir kisi bulunmamaktadir." << endl;
    }
    else {
        cout << "Yanlis parametre girdiniz. Lutfen uygun bir parametre giriniz. " << endl;
    }
}


#endif