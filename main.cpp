#include <iostream>
#include <string>
#include "program.h"
#include "contact.h"

using namespace std;

void printMenu() { // Menüyü yazdirir.
    cout << "1-Kayit Ekle" << endl;
    cout << "2-Kayit Sil" << endl;
    cout << "3-Kayit modifiye etme" << endl;
    cout << "4-Kayit Arama " << endl;
    cout << "5-Kayitlari goster" << endl;
    cout << "Yapmak istediginiz islemin numarasini giriniz. Programdan cikmak icin 0 giriniz.";
}

Contact create_contact() { // Yeni bir kayit olusturur.
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
    Contact newcontact = Contact(id, isim,soyisim, cepno, isno);
    return newcontact;
}

int main() 
{
    Program program = Program(); // Program objesi
    string filename;
    cout << "Kayitlarin tutuldugu dosya adini giriniz. (Ornek: telefon.txt) : ";
    cin >> filename;
    program.readFile(filename);
    int input;
    cout << "Telefon rehberi programina hos geldiniz." << endl;
    while(true) {
        printMenu();
        cin >> input;
        if(input == 0) {
            break;
        }
        else if(input == 1) { // Kisi ekleme
            Contact newcontact = create_contact();
            program.add_contact(newcontact);
        }
        else if(input == 2) { // Kisi silme
            string id;
            cout << "Silmek istediginiz kisinin ID'sini giriniz: ";
            cin >> id;
            program.remove_contact(id);
        }
        else if(input == 3) { // Kisi degistirme
            string id;
            cout << "Degistirmek istediginiz kisinin ID'sini giriniz: ";
            cin >> id;
            program.modify_contact(id);    
        }
        else if(input == 4) { // Kisi arama
            string type;
            cout << "Kisiyi hangi parametre ile aramak istersiniz ? (id, isim, soyisim, cepno, isno)" << endl;
            cin >> type;
            program.search_contact(type);
        }
        else if(input == 5) { // Kisileri listele
            program.list_contacts();
        }
    }

 
  
    program.writeFile(filename);
    return 0;
}