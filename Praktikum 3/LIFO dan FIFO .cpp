#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;

// Fungsi untuk memasukkan simpul di awal linked list (LIFO)
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

// Fungsi untuk menghapus simpul dari awal linked list
void deleteFromBeginning() {
    if (head == nullptr) {
        cout << "Linked list kosong." << endl;
        return;
    }

    Node* nodeToDelete = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }

    delete nodeToDelete;
    cout << "Simpul dari awal linked list telah dihapus." << endl;
}

// Fungsi untuk memasukkan simpul di akhir linked list (FIFO)
void insertAtEnd(int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
        return;
    }

    Node* lastNode = head;
    while (lastNode->next != nullptr) {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;
    newNode->prev = lastNode;
}

// Fungsi untuk menghapus simpul dari akhir linked list (FIFO)
void deleteFromEnd() {
    if (head == nullptr) {
        cout << "Linked list kosong." << endl;
        return;
    }

    Node* lastNode = head;
    while (lastNode->next != nullptr) {
        lastNode = lastNode->next;
    }

    if (lastNode->prev != nullptr) {
        lastNode->prev->next = nullptr;
    } else {
        head = nullptr;
    }

    delete lastNode;
    cout << "Simpul dari akhir linked list telah dihapus." << endl;
}

// Fungsi untuk mencari simpul dengan data tertentu
Node* findNode(int data) {
    Node* temp = head;
    while (temp != nullptr && temp->data != data) {
        temp = temp->next;
    }
    return temp;
}

// Fungsi untuk menampilkan isi linked list
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

int main() {
    int choice;
    int data;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambahkan simpul (FIFO)\n";
        cout << "2. Hapus simpul (FIFO)\n";
        cout << "3. Tambahkan simpul (LIFO)\n";
        cout << "4. Hapus simpul (LIFO)\n";
        cout << "5. Tampilkan linked list\n";
        cout << "6. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan data untuk simpul baru: ";
                cin >> data;
                insertAtEnd(data);
                cout << "Simpul berhasil ditambahkan (FIFO).\n";
                break;
            case 2:
                deleteFromEnd();
                break;
            case 3:
                cout << "Masukkan data untuk simpul baru: ";
                cin >> data;
                insertAtBeginning(data);
                cout << "Simpul berhasil ditambahkan (LIFO).\n";
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                displayList();
                break;
            case 6:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
