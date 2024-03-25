#include <iostream>
using namespace std;

//struct Node mendefinisikan struktur data untuk simpul dalam double linked list.
//data: Variabel integer untuk menyimpan data pada simpul.
//next: Pointer yang menunjuk ke simpul berikutnya dalam linked list.
//prev: Pointer yang menunjuk ke simpul sebelumnya dalam linked list.
struct Node {
    int data;
    Node* next;
    Node* prev;
};

//head: pointer global yang menunjuk ke simpul pertama (kepala) dalam linked list.
//NULL: menandakan bahwa linked list awalnya kosong.
Node* head = nullptr;

//insertAtBeginning(int data): Fungsi ini berfungsi untuk menerima data sebagai input (nilai yang akan disimpan pada simpul baru).
//Fungsi ini berfungsi untuk menyisipkan simpul baru dengan data tersebut di awal linked list.
// Fungsi untuk memasukkan simpul di awal linked list
void insertAtBeginning(int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head;
    newNode->prev = nullptr;
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}

// findNode(int data): berfungsi untuk menerima nilai data sebagai input dan mencari simpul dengan data dalam linked list. 
// while (temp != NULL && temp->data != data) melakukan loop selama pointer temporary (tempt) tidak sama dengan NULL (menandakan akhir linked list).
// dan data pada simpul temp tidak sama dengan data yang dicari. 
// Mencari simpul dengan data tertentu
Node* findNode(int data) {
    Node* temp = head;
    while (temp != nullptr && temp->data != data) {
        temp = temp->next;
    }
    return temp;
}

// Fungsi ini menghapus simpul dengan nilai data tertentu dari Linked List. 
// Fungsi ini memiliki penanganan khusus untuk menghapus simpul terdepan (head) atau simpul terakhir (tail).
void deleteNode(int data) {
    Node* nodeToDelete = findNode(data);
    if (nodeToDelete == nullptr) {
        cout << "Simpul dengan data " << data << " tidak ditemukan." << endl;
        return;
    }

    if (nodeToDelete == head) {
        head = nodeToDelete->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
    } else if (nodeToDelete->next == nullptr) { // Jika simpul yang akan dihapus adalah yang terakhir
        nodeToDelete->prev->next = nullptr;
    } else { // Simpul berada di tengah linked list
        nodeToDelete->prev->next = nodeToDelete->next;
        nodeToDelete->next->prev = nodeToDelete->prev;
    }

    delete nodeToDelete;
    cout << "Simpul dengan data " << data << " telah dihapus." << endl;
}
// displayList(): Fungsi ini menampilkan semua data yang tersimpan dalam Linked List
// dimulai dari simpul head dan terus iterasi hingga mencapai simpul 
void displayList() {
    Node* current = head;
    if (current == nullptr) {
        cout << "Linked list kosong." << endl;
        return;
    }
    cout << "Isi linked list: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

//main() : Fungsi utama digunakan untuk demonstrasi.
//insertAtBeginning(data) digunakan untuk menyisipkan simpul baru di awal linked list dengan nilai data yang diberikan.
int main() {
insertAtBeginning(3);
insertAtBeginning(5);
insertAtBeginning(7);
insertAtBeginning(11);

int choice;
int data;

// fungsi ini untuk memberikan interaksi kode kepada pengguna agar pengguna dapat memilih kode yang ingin digunakan
do {
    cout << "\nMenu:\n";
    cout << "1. Tambahkan simpul di awal linked list\n";
    cout << "2. Hapus simpul\n";
    cout << "3. Tampilkan linked list\n";
    cout << "4. Keluar\n";
    cout << "Pilihan Anda: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Masukkan data untuk simpul baru: ";
            cin >> data;
            insertAtBeginning(data);
            cout << "Simpul berhasil ditambahkan.\n";
            break;
        case 2:
            if (head == nullptr) {
                cout << "Linked list kosong.\n";
            } else {
                cout << "Masukkan data yang ingin dihapus: ";
                cin >> data;
                deleteNode(data);
            }
            break;
        case 3:
            displayList();
            break;
        case 4:
            cout << "Terima kasih!\n";
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
            break;
    }
} while (choice != 4);
  
    return 0;
}
