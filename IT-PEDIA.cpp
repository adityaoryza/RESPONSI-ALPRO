#include <iostream>
#include <fstream>
using namespace std;
// DEKLARASI CLASS
class IT_PEDIA{
	public:
		void input();
		void output();
	private:
		float diskon = 1;
		int pass, saldo, jumlah[100], harga[100], i, total[100], totalsemua = 0, asuransi = 0, ongkir = 30000, eks;
		string user, nama, barang[100], alamat, dsc = "-";
		char pil;
};
// INPUT SECTION
void IT_PEDIA::input(){
    // MENU DAN LOGIN PAGE
	MENU:
	cout << "===================== IT-PEDIA =====================" << endl;
    cout << " MENYEDIAKAN SEMUA KEBUTUHAN GADGET KOMPUTER ANDA!!!" << endl;
	loginpage:
	cout << "Masukkan Username : "; 
	cin >> user;
	cout << "Masukkan Password : "; 
	cin >> pass;
	if(user == "oryza429" && pass == 2100018401){
		nama = "Aditya Oryza Mahendra";
		saldo = 5000000;
	}
	else if(user == "shantika69" && pass == 2100018386){
		nama = "Shantika Adila Putri";
		saldo = 5000000;
	}
	else{
		cout << "=========================================================" << endl;
		cout << "Username atau password salah!" << endl;
		cout << "Silahkan Masukan Kembali Username dan " << endl;
		cout << "=========================================================" << endl;
		goto loginpage;
	}
    // ACCOUNT DETAIL AND SALDO
    system("cls");
	cout << "========================================== [DETAIL AKUN DAN SALDO ANDA] ============================================" << endl;
	cout << "Nama  \t\t\t: " << nama << endl;
	cout << "Saldo yang anda miliki\t: Rp." << saldo << endl;
	cout << "=============================================== IT-PEDIA =================================================" << endl;
	cout << "========================================== BARANG READY STOCK ============================================" << endl;
	cout << "1. MONITOR\t-> 2JT" << endl;
	cout << "2. MOUSE\t-> 1JT" << endl;
	cout << "3. KEYBOARD\t-> 1JT" << endl;
	cout << "4. MOUSEPAD\t-> 200RB" << endl;
	cout << "===================== PILIHLAH BARANG KEBUTUHAN ANDA DAN DAPATKAN VOUCHER HINGGA 10% ======================" << endl;
	cout << "====================== dan dapatkan gratis ongkir dengan minimal pembelian 50ribu =========================" << endl;
	cout << " voucher tersedia( s&k berlaku!):" << endl;
	cout << "1. Diskon 2%  (> Rp.100,000)" << endl;
	cout << "2. Diskon 5%  (> Rp.500,000)" << endl;
	cout << "3. Diskon 10% (> Rp.1,000,000)" << endl;
	cout << "===========================================================================================================" << endl;
	i = 1;
	while(true){
		cout << " KETIKKAN NAMA BARANG PILHAN ANDA\t: "; 
		cin >> barang[i];
		cout << " KETIKKAN HARGA BARANG YANG DIPILIH\t: Rp."; 
        cin >> harga[i];
		cout << " JUMLAH BARANG YANG DIBELI\t\t: "; 
        cin >> jumlah[i];
		cout << " \n\nBARANG BERHASIL DITAMBAHKAN KE KERANJANG BELANJAAN ANDA!!!!"; 
		cout << " TAMBAHKAN PRODUK LAINNYA? (y/t) : "; 
        cin >> pil;
		if (pil != 'y'){
			break;
		}
		i++;
	}
    // HITUNG TOTAL SEMENTARA 
    for (int j = 1; j <= i; j++){
		total[j] = harga[j] * jumlah[j];
	}
	for (int j = 1; j <= i; j++){
		totalsemua += total[j];
	}
	cout << "==========================================================================================================" << endl;	
	cout << "TOTAL BELANJA ANDA = Rp." << totalsemua << endl;
	if (totalsemua >= 100000 && totalsemua <= 499999){
		cout << "ANDA MENDAPATKAN VOUCHER DISKON" << endl; 
		cout << "Gunakan voucher diskon 2%? (y/t) : "; 
        cin >> pil;
		if (pil == 'y'){
			diskon = 0.98;
      dsc = "2%";
		}
	}
	else if (totalsemua >= 500000 && totalsemua <= 999999){
        cout << "ANDA MENDAPATKAN VOUCHER DISKON" << endl; 
		cout << "Gunakan voucher diskon 5%? (y/t) : "; 
        cin >> pil;
		if (pil == 'y'){
			diskon = 0.95;
      dsc = "5%";
		}
	}
	else if (totalsemua >= 1000000){
        cout << "ANDA MENDAPATKAN VOUCHER DISKON" << endl; 
		cout << "Gunakan voucher diskon 10%? (y/t) : "; 
        cin >> pil;
		if (pil == 'y'){
			diskon = 0.9;
      dsc = "10%";
		}
	}
    totalsemua = totalsemua * diskon;		
	cout << "TOTAL ANDA MENJADI = Rp." << totalsemua << endl;
    // SECTION PENGIRIMAN
    system("cls");
	cout << "==================== PILIHLAH EKSPEDISI SESUAI KEBUTUHAN ANDA!! ====================" << endl;
	cout << "EKSPEDISI MITRA IT-PEDIA: " << endl;
	cout << "1. Instant-Sameday (GOJEK)" << endl;
	cout << "2. Reguler-Estimasi 3 Hari (JNE,JNT,SICEPAT)" << endl;
	cout << "====================================================================================" << endl;
	cout << "PENGIRIMAN PULAU JAWA? (y/t) : "; 
    cin >> pil;
	if(pil == 'y'){
		ongkir = 20000;
	}
	cin.ignore();
	cout << "ALAMAT DETAIL ANDA\t: "; 
    getline(cin, alamat);
	pilih:
	cout << "PILIH JENIS PENGIRIMAN!\t: "; 
    cin >> eks;
	switch (eks){
		case 1 :
            cout << "ANDA MEMILIH JENIS PENGIRIMAN INSTANT-SAMEDAY!" << endl;	
			ongkir = ongkir * 1.5;
			break;
		case 2 :
            cout << "ANDA MEMILIH JENIS PENGIRIMAN REGULER!" << endl;	
			break;
		default :
			cout << "Pilihan tidak tersedia!" << endl;
            cout << "====================================================================================" << endl;

			goto pilih;
	}
    	cout << "====================================================================================" << endl;

	if (totalsemua >= 50000){

		cout << "ANDA MENDPATKAN GRATIS ONGKIR!!"; 
		cout << "Gunakan voucher gratis ongkir? (y/t) = "; 
        cin >> pil;
		if(pil == 'y'){
			ongkir = 0;
		}
	}
	cout << "Biaya ongkir anda terpotong menjadi = Rp." << ongkir << endl;
	cout << "PENGAMANAN TAMBAHAN DENGAN ASURANSI(Rp.2,500)? (y/t) : "; 
    cin >> pil;
	if (pil == 'y'){
		asuransi = 2500;
	}
	totalsemua = totalsemua + asuransi;
	totalsemua = totalsemua + ongkir;
	cout << "TOTAL BELANJA ANDA : Rp." << totalsemua << endl;
	if(totalsemua > saldo){
		cout << "=========================================================" << endl;
		cout << "SALDO ANDA TIDAK CUKUP!" << endl;
        cin.ignore();
		getchar();
    diskon = 1; totalsemua = 0; asuransi = 0; ongkir = 30000; dsc = "-";
		goto MENU;
	}
	totalsemua = totalsemua + asuransi;
	totalsemua = totalsemua + ongkir;
    // ENDING SECTION
    system("cls");
  cout << "PESANAN ANDA AKAN SEGERA KAMI PROSES, MOHON LAKUKAN CEK RESI BERKALA!!" << endl;
  cout << "======================================================================" << endl;
}
// OUTPUT SECTION
void IT_PEDIA::output(){
  ofstream out;
  out.open("IT-PEDIA STORE NOTE.txt");
  out << "====================== TERIMAKASIH TELAH BERBELANJA DI IT-PEDIA =====================" << endl;
  out << "========================= BERIKUT RINCIAN DETAIL PESANAN ANDA =======================" << endl;
  out << "Nama pembeli   : " << nama << endl;
  out << "Alamat pembeli : " << alamat << endl;
  out << "======================= BARANG YANG ANDA TAMBAHKAN KE KERANJANG =====================" << endl;
  for (int j = 1; j <= i; j++){
    out << barang[j] << "   " << jumlah[j] << " x Rp." << harga[j] << " = Rp." << total[j] << endl;
  }
  out << "=====================================================================================" << endl;
  out << "Diskon   = " << dsc << endl;
  out << "Ongkir   = Rp." << ongkir << endl;
  out << "Asuransi = Rp." << asuransi << endl;
  out << "=====================================================================================" << endl;
  out << "Total pembayaran : Rp." << totalsemua << endl;
  out << "SISA SALDO ANDA  : Rp." << saldo-totalsemua << endl;
  out << "=====================================================================================" << endl;
}
int main(){
	IT_PEDIA HASIL;
	HASIL.input();
	HASIL.output();
	return 0;
}

