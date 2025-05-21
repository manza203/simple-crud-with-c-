#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct mahasiswa{
    int pk;
    string nama;
    string NIM;
    string jurusan;
};

// void loginOption();
int getOption();
void checkDatabase(fstream &file); 

void addDataMHS(fstream &file);

int main() {
    // loginOption();
    fstream file;
    mahasiswa mhs; //inisialisasi struct

    checkDatabase(file);
    int pilihan;
    string lanjut;
    enum option { tambah = 1, tampilkan, ubah, hapus, selesai };

    do {
        pilihan = getOption();

        switch (pilihan) {
            case tambah:
                cout << "tambahkan data\n";
                addDataMHS(file);
                break;
            case tampilkan:
                cout << "tampilkan data\n";
                break;
            case ubah:
                cout << "ubah data\n";
                break;
            case hapus:
                cout << "hapus data\n";
                break;
            case selesai:
                cout << "program selesai\n";
                break;
            default:
                cout << "pilihan tidak ditemukan\n";
                break;
        }
        if (pilihan != selesai) {
            cout << "apakah ingin lanjut? (y/n): ";
            cin >> lanjut;
            while(!(lanjut == "N" || lanjut == "n" || lanjut == "y" || lanjut == "Y")){
                cout << "masukkan pilihan yang sesuai \n";
                cout << "apakah ingin lanjut? (y/n): ";
                cin >> lanjut;
            }
        }

    } while ((lanjut == "y" || lanjut == "Y") && pilihan != selesai);

    cin.get();
    return 0;
}

void addDataMHS(fstream &file){
    mahasiswa inputMHS;
    cout << "Nama : ";
    getline(cin,inputMHS.nama);
    cout << "NIM : ";
    getline(cin,inputMHS.NIM);
    cout << "Jurusan : ";
    getline(cin,inputMHS.jurusan);
}

void checkDatabase(fstream &file){
    file.open("data.bin", ios::in | ios::out | ios::binary);

    if (file.is_open()){
        cout << "database ditemukan\n";
    }else{
        cout << "database tidak ditemukan, proses pembuatan database \n";
        file.close();
        file.open("data.bin", ios::trunc | ios::in | ios::out | ios::binary);
    }
}

int getOption() {
    int pilihan;
    system("cls");
    cout << "\nprogram CRUD Data Mahasiswa" << endl;
    cout << "==============================" << endl;
    cout << "1. tambah data\n";
    cout << "2. tampilkan data\n";
    cout << "3. ubah data\n";
    cout << "4. hapus data\n";
    cout << "5. selesai\n";
    cout << "==============================" << endl;
    cout << "pilih (1-5): ";
    cin >> pilihan;
    cin.ignore();
    return pilihan;
}
