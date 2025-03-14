#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Product {
    int id;
    string name;
    float price;
    float discountInPercent;
};

vector<Product> products = {
    {1, "Wireless Mouse", 250000, 0},
    {2, "Keyboard", 300000, 0},
    {3, "Headphone", 500000, 0},
    {4, "Mouse", 150000, 0}
};

double saldo = 0;

void showProducts() {
    cout << "\nDaftar Produk:\n";
    for (auto &product : products) {
        if(product.discountInPercent > 0){
            cout << product.id << ". " << product.name << " - Rp " << product.price << " (Diskon " << product.discountInPercent << "%!!)\n";      
        } else {
            cout << product.id << ". " << product.name << " - Rp " << product.price << "\n";
        }
    }
}

void setSaldo(double amount) {
    saldo = amount;
    cout << "Saldo telah diperbarui: Rp " << saldo << "\n";
}

void buyProduct(int id, int count) {
    for (const auto &product : products) {
        if (product.id == id) {
            float totalPrice = product.price * count;
            if(product.discountInPercent > 0){
                cout << product.discountInPercent;
                float totalDiscount = (product.discountInPercent / 100) * totalPrice;
                totalPrice = totalPrice - totalDiscount;
                cout << "Selamat anda mendapat diskon sebanyak " << product.discountInPercent << "%!!\n";
            }
            if (saldo >= totalPrice) {
                saldo -= totalPrice;
                cout << "Anda telah membeli " << count << " buah " << product.name << " seharga Rp." << product.price << " dengan total " << "Rp." << totalPrice << "\n";             
                cout << "Sisa saldo: Rp " << saldo << "\n";
            } else {
                cout << "Saldo tidak cukup untuk membeli " << product.name << "!\n";
            }
            return;
        }
    }
    cout << "Produk tidak ditemukan!\n";
    return;
}

void setDiscount(int id, float discountInPercent){
    for(auto &product : products){
        if(product.discountInPercent >= 100){
            cout << "Discount tidak bisa lebih dari sama dengan 100!\n";
            break;
        }
        if(product.id == id){
            product.discountInPercent = discountInPercent;
            cout << "Berhasil set Discount!\n";
            return;
        }
    }
    cout << "Product tidak ditemukan!\n";
}

int main() {
    cout << "PTS INFORMATIKA 2025\n";
    cout << "Nama : M. Raihan Al Farizy\n";
    cout << "Kelas : X-RPL\n";
    cout << "Tanggal : Jumat, 14/03/2025\n"
    int choice;
    cout << "=============\n";
    cout << "--Jual-Beli--\n";
    cout << "=============\n";
    do {
        cout << "\nMenu:\n";
        cout << "1. Lihat Produk\n";
        cout << "2. Set Saldo\n";
        cout << "3. Beli Produk\n";
        cout << "4. Set Diskon\n";
        cout << "5. Keluar\n\n";
        cout << "Saldo : " << saldo << "\n";
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
                int productCount;
                cout << "Masukkan ID produk: ";
                cin >> productId;
                cout << "Masukan Jumlah Produk : ";
                cin >> productCount;
                buyProduct(productId, productCount);
                break;
            case 4:
                int discountInPercent;
                cout << "Masukan ID produk : ";
                cin >> productId;
                cout << "Masukan Diskon Dalam Persen : ";
                cin >> discountInPercent;
                setDiscount(productId, discountInPercent);
                break;
            case 5:
                cout << "Terima kasih telah berbelanja!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
    } while (choice != 5);
    
    return 0;
}
