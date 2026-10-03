#include <iostream>
using namespace std;

string sayur[] = { "Bayam", "Kangkung", "Sawi", "Wortel", "Brokoli" };
int harga[] = { 5000, 6000, 7000, 8000, 9000 };
int stock[] = { 10, 20, 30, 40, 50 };
int dompet = 100000;

int keranjang[5][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};

void pembelian() {
	cout << endl;
	cout << "Pembelian Sayur" << endl;
	cout << "List Sayur" << endl;
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ". " << sayur[i] << " - Rp" << harga[i] << " - Stock: " << stock[i] << endl;
	}
	cout << "Apakah anda ingin membeli sayur? (y/n): ";
	char pilihan;
	cin >> pilihan;
	if (pilihan == 'y') {
		cout << endl;
		cout << "Masukkan nomor sayur yang ingin dibeli: ";
		int nomor;
		cin >> nomor;
		cout << "Masukkan jumlah sayur yang ingin dibeli: ";
		int jumlah;
		cin >> jumlah;
		if (jumlah > stock[nomor - 1]) {
			cout << "Stock tidak cukup!" << endl << endl;
		}
		else {
			keranjang[nomor - 1][0] += jumlah;
			keranjang[nomor - 1][1] += harga[nomor - 1] * jumlah;
			stock[nomor - 1] -= jumlah;
			cout << "Berhasil menambahkan " << jumlah << " " << sayur[nomor - 1] << " ke keranjang." << endl<< endl;
		}
	}
	else if (pilihan == 'n') {
		cout << "Kembali ke menu utama." << endl<< endl;
	}
	else {
		cout << "Pilihan tidak valid!" << endl << endl;
	}
}

void Mkeranjang() {
	cout << endl;
	cout << "Keranjang Belanja" << endl;
	for (int i = 0; i < 5; i++) {
		if (keranjang[i][0] > 0) {
			cout << sayur[i] << " - Jumlah: " << keranjang[i][0] << " - Total: Rp" << keranjang[i][1] << endl;
		}
	}
	cout << endl;
	cout << "1. Tambahkan belanjaan" << endl;
	cout << "2. Hapus belanjaan" << endl;
	cout << "3. Kembali ke menu utama" << endl;
	cout << "Pilihan menu: ";
	int pilihan;
	cin >> pilihan;

	switch (pilihan) {
	case 1: {
		cout << endl;
		cout << "List Sayur" << endl;
		for (int i = 0; i < 5; i++) {
			cout << i + 1 << ". " << sayur[i] << " - Rp" << harga[i] << " - Stock: " << stock[i] << endl;
		}
		cout << "Masukkan nomor sayur yang ingin ditambahkan/diedit: ";
		int nomor;
		cin >> nomor; 

		cout << "Masukkan jumlah sayur yang ingin dibeli: ";
		int jumlah;
		cin >> jumlah;

		if (jumlah > stock[nomor - 1]) {
			cout << "Stock tidak cukup!" << endl << endl;
		}
		else {
			keranjang[nomor - 1][0] += jumlah;
			keranjang[nomor - 1][1] += harga[nomor - 1] * jumlah;
			stock[nomor - 1] -= jumlah;
			cout << "Berhasil menambahkan " << jumlah << " " << sayur[nomor - 1] << " ke keranjang." << endl<< endl;
		}
		break;
	} 

	case 2: {
		cout << "Masukkan nomor sayur yang ingin dihapus: ";
		int nomorHapus;
		cin >> nomorHapus;

		cout << "Apakah anda yakin ingin menghapus " << keranjang[nomorHapus - 1][0] << " " << sayur[nomorHapus - 1] << " dari keranjang? (y/n): ";
		char konfirmasi;
		cin >> konfirmasi;

		if (konfirmasi == 'y' || konfirmasi == 'Y') { 
			stock[nomorHapus - 1] += keranjang[nomorHapus - 1][0];
			keranjang[nomorHapus - 1][0] = 0;
			keranjang[nomorHapus - 1][1] = 0;
			cout << "Berhasil menghapus " << sayur[nomorHapus - 1] << " dari keranjang." << endl<< endl;
		}
		break;
	} 

	case 3:
		cout << "Kembali ke menu utama." << endl<< endl;
		break;
	}
}

void checkout() {
	cout << endl;
	int total = 0;
	cout << "Checkout" << endl;
	for (int i = 0; i < 5; i++) {
		if (keranjang[i][0] > 0) {
			cout << sayur[i] << " - Jumlah: " << keranjang[i][0] << " - Total: Rp" << keranjang[i][1] << endl;
		}
	}
	cout << "apakah anda ingin melanjutkan checkout? (y/n): ";
	char pilihan;
	cin >> pilihan;
	if (pilihan == 'n') {
		cout << "Kembali ke menu utama." << endl<< endl;
		return;
	}
	else {
		cout << "Melanjutkan checkout..." << endl<< endl;
	}
	for (int i = 0; i < 5; i++) {
		total += keranjang[i][1];
	}
	if (total > dompet) {
		cout << "Dompet tidak cukup!" << endl << endl;
	}
	else {
		dompet -= total;
		cout << "Berhasil checkout! Sisa dompet: " << dompet << endl<< endl;
		for (int i = 0; i < 5; i++) {
			keranjang[i][0] = 0;
			keranjang[i][1] = 0;
		}
	}
}

int main() {
	bool program = 1;
	while (program) {
		cout << "Dompet: " << dompet << endl;
		cout << "1. Pembelian" << endl;
		cout << "2. Keranjang" << endl;
		cout << "3. Checkout" << endl;
		cout << "4. Exit" << endl;
		cout << "Pilih menu: ";
		int pilihan;
		cin >> pilihan;
		switch (pilihan) {
		case 1:
			pembelian();
			break;
		case 2:
			Mkeranjang();
			break;
		case 3:
			checkout();
			break;

		case 4:
			program = 0;
			break;
		}
	}
	return 0;
}