#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Product {
    int id;
    string name;
    double price;
};

vector<Product> products = {
    {1, "Laptop", 5000000},
    {2, "Smartphone", 3000000},
    {3, "Headphone", 500000},
    {4, "Mouse", 150000}
};

double saldo = 0;

void showProducts() {
    cout << "\nDaftar Produk:\n";
    for (const auto &product : products) {
        cout << product.id << ". " << product.name << " - Rp " << product.price << "\n";
    }
}

void setSaldo(double amount) {
    saldo = amount;
    cout << "Saldo telah diperbarui: Rp " << saldo << "\n";
}

void buyProduct(int id) {
    for (const auto &product : products) {
        if (product.id == id) {
            if (saldo >= product.price) {
                saldo -= product.price;
                cout << "Anda telah membeli " << product.name << " seharga Rp " << product.price << "\n";
                cout << "Sisa saldo: Rp " << saldo << "\n";
            } else {
                cout << "Saldo tidak cukup untuk membeli " << product.name << "!\n";
            }
            return;
        }
    }
    cout << "Produk tidak ditemukan!\n";
}

int main() {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Lihat Produk\n";
        cout << "2. Set Saldo\n";
        cout << "3. Beli Produk\n";
        cout << "4. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                showProducts();
                break;
            case 2:
                double amount;
                cout << "Masukkan saldo: ";
                cin >> amount;
                setSaldo(amount);
                break;
            case 3:
                int productId;
                cout << "Masukkan ID produk: ";
                cin >> productId;
                buyProduct(productId);
                break;
            case 4:
                cout << "Terima kasih telah berbelanja!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (choice != 4);
    
    return 0;
}
