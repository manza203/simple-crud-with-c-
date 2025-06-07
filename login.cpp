#include <iostream>
#include <string>

using namespace std;
struct datalogin{
  string nama;
  string password;
};
void login(int role){
  datalogin data;
  cout << "selamat datang di program pergudangan toko makmur " << endl;
  cout << "================================================= " << endl;
  cout << "menu login " << endl;
  cout << "1. sebagai Consignor (penitip barang)" << endl;
  cout << "2. sebagai Consignee (pemilik toko)" << endl;
  cout << "================================================= " << endl;
  cout << "masukkan pilihan anda (1/2) : ";
  cin >> role;
  switch (role){
    case 1
      
      cout << "nama : ";
      cin >> data.nama[n];
      cout << "password : ";
      cin >> data.password[n];

  }
  

}

int main(){

  return 0;
}