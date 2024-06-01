#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const int MAX_FILMS = 10;
const int MAX_TICKETS = 100;

// Array konstan dengan daftar film
string filmNames[MAX_FILMS] = {
    "Transformers: Rise Of The Beast\t",
    "Fast X                       \t",
    "Hello Ghost                    \t",
    "The Little Mermaid           \t",
    "How To Train Your Dragon     \t",
    "Uncharted                    \t",
    "Tenet                        \t",
    "Soukyuu No Fafner: Behind The Line\t",
    "Make My Day                   \t",
    "Suzume No Tojimori            \t"
};

int weekdayPrices[MAX_FILMS] = {60, 50, 75, 100, 120, 70, 80, 40, 65, 75};
int weekendPrices[MAX_FILMS] = {70, 60, 85, 110, 130, 80, 90, 50, 75, 85};

// Variabel untuk menyimpan data pembelian tiket
string purchasedFilmNames[MAX_TICKETS];
int purchasedPrices[MAX_TICKETS];
int purchasedQuantities[MAX_TICKETS];
string purchasedDays[MAX_TICKETS];
int ticketCount = 0;

int saldo = 0;

// Fungsi untuk memasukkan daftar film ke dalam file films.txt
void saveFilmsToFile() {
    ofstream file("films.txt");
    if (file.is_open()) {
        for (int i = 0; i < MAX_FILMS; ++i) {
            file << filmNames[i] << "," << weekdayPrices[i] << "," << weekendPrices[i] << "\n";
        }
        file.close();
    } else {
        cout << "Unable to open file films.txt" << endl;
    }
}

// Fungsi untuk memuat daftar film dari file films.txt
void loadFilmsFromFile() {
    system("cls");
    ifstream file("films.txt");
    if (file.is_open()) {
        string line;
        int index = 0;
        while (getline(file, line) && index < MAX_FILMS) {
            size_t pos1 = line.find(",");
            size_t pos2 = line.find(",", pos1 + 1);
            filmNames[index] = line.substr(0, pos1);
            weekdayPrices[index] = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
            weekendPrices[index] = stoi(line.substr(pos2 + 1));
            index++;
        }
        file.close();
    } else {
        cout << "Unable to open file films.txt" << endl;
    }
}

void printReceipt() {
    system("cls");
    ofstream receipt("strukSynema.txt");

    if (receipt.is_open()) {
        receipt << "\t\t========== Struk Pembelian Tiket Synema ==========\n\n";
        receipt << "======================================================================================\n";
        receipt << "JUDUL FILM\t\t\t\tJUMLAH\tHARGA SATUAN\tTOTAL HARGA\tHARI\n";
        receipt << "======================================================================================\n";

        cout << "\t\t========== Struk Pembelian Tiket Synema ==========\n\n";
        cout << "======================================================================================\n";
        cout << "JUDUL FILM\t\t\t\tJUMLAH\tHARGA SATUAN\tTOTAL HARGA\tHARI\n";
        cout << "======================================================================================\n";

        int total = 0;

        for (int i = 0; i < ticketCount; ++i) {
            receipt << purchasedFilmNames[i] << "\t" 
                    << purchasedQuantities[i] << "\t" 
                    << purchasedPrices[i] << "\t\t" 
                    << purchasedPrices[i] * purchasedQuantities[i] << "\t\t" 
                    << purchasedDays[i] << "\n";

            cout << purchasedFilmNames[i] << "\t" 
                 << purchasedQuantities[i] << "\t" 
                 << purchasedPrices[i] << "\t\t" 
                 << purchasedPrices[i] * purchasedQuantities[i] << "\t\t" 
                 << purchasedDays[i] << "\n";

            total += purchasedPrices[i] * purchasedQuantities[i];
        }

        receipt << "\n================================================\n";
        receipt << "Total Pembayaran Anda : " << total << "\n";
        receipt << "================================================\n";

        cout << "\n================================================\n";
        cout << "Total Pembayaran Anda : " << total << "\n";
        cout << "================================================\n";

        receipt.close();
    } else {
        cout << "Unable to open file strukSynema.txt" << endl;
    }
}

void checkSaldo() {
    system("cls");
    cout << "========== Cek Saldo =========\n";
    cout << "Saldo Synepoint Anda saat ini adalah: " << saldo << " poin\n";
}

void topUpSaldo() {
    system("cls");
    int topUpAmount;
    cout << "========== Top Up Saldo =========\n";
    cout << "Masukkan jumlah Synepoint yang ingin Anda top up: ";
    cin >> topUpAmount;
    saldo += topUpAmount;
    cout << "Top up berhasil! Saldo Synepoint Anda sekarang adalah: " << saldo << " poin\n";
}

void purchaseTicket() {
    system("cls");
    int dayChoice;
    cout << "Pilih hari pembelian tiket:\n";
    cout << "1. Weekday\n";
    cout << "2. Weekend\n";
    cout << "Pilihan Anda (1/2): ";
    cin >> dayChoice;

    string day;
    int price;

    switch (dayChoice) {
        case 1:
            day = "Weekday";
            break;
        case 2:
            day = "Weekend";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            return;
    }
    system("cls");
    cout << "Daftar film yang tersedia untuk " << day << ":\n";
    for (int i = 0; i < MAX_FILMS; ++i) {
        if (day == "Weekday") {
            cout << i + 1 << ". " << filmNames[i] << " (Harga: " << weekdayPrices[i] << " poin)\n";
        } else if (day == "Weekend") {
            cout << i + 1 << ". " << filmNames[i] << " (Harga: " << weekendPrices[i] << " poin)\n";
        }
    }

    int filmChoice;
    cout << "Pilih film yang ingin Anda beli tiketnya (masukkan nomor): ";
    cin >> filmChoice;

    if (filmChoice < 1 || filmChoice > MAX_FILMS) {
        cout << "Pilihan tidak valid.\n";
        return;
    }

    if (day == "Weekday") {
        price = weekdayPrices[filmChoice - 1];
    } else if (day == "Weekend") {
        price = weekendPrices[filmChoice - 1];
    }

    int quantity;
    cout << "Masukkan jumlah tiket yang ingin Anda beli: ";
    cin >> quantity;

    if (saldo < price * quantity) {
        cout << "Saldo Synepoint Anda tidak mencukupi untuk membeli tiket ini.\n";
        return;
    }

    purchasedFilmNames[ticketCount] = filmNames[filmChoice - 1];
    purchasedPrices[ticketCount] = price;
    purchasedQuantities[ticketCount] = quantity;
    purchasedDays[ticketCount] = day;
    ticketCount++;

    saldo -= price * quantity;

    cout << "Pembelian tiket berhasil!\n";
}

void showMenu() {
    system("cls");
    int choice;
    do {
        cout << "\n========== Menu Synepoint ==========\n";
        cout << "1. Cek Saldo Synepoint\n";
        cout << "2. Top Up Synepoint\n";
        cout << "3. Beli Tiket Film\n";
        cout << "4. Lihat Struk Pembelian\n";
        cout << "5. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                checkSaldo();
                break;
            case 2:
                topUpSaldo();
                break;
            case 3:
                purchaseTicket();
                break;
            case 4:
                printReceipt();
                break;
            case 5:
                cout << "Terima kasih telah menggunakan layanan Synepoint.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih menu yang tersedia.\n";
                break;
        }
    } while (choice != 5);
}

int main() {
    saveFilmsToFile(); // Menyimpan daftar film ke file films.txt
    loadFilmsFromFile(); // Memuat daftar film dari file films.txt
    showMenu(); // Menampilkan menu utama
    return 0;
}
