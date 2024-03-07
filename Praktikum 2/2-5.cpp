#include <iostream>

struct Node {
    int data;
    Node* next;
};
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}
void insertNodeAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void insertNodeAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
Node* searchNode(Node* head, int key) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}
int main() {
    Node* head = nullptr;
    int choice;
    int data;

    do {
        std::cout << "Menu Pilihan\n";
        std::cout << "1. Tambahkan data di akhir\n";
        std::cout << "2. Tambahkan data di awal\n";
        std::cout << "3. Tampilkan data\n";
        std::cout << "4. Cari data\n";
        std::cout << "5. Keluar\n";
        std::cout << "Pilih: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Masukkan data: ";
                std::cin >> data;
                insertNodeAtEnd(&head, data);
                break;
            case 2:
                std::cout << "Masukkan data: ";
                std::cin >> data;
                insertNodeAtBeginning(&head, data);
                break;
            case 3:
                std::cout << "Data: ";
                printList(head);
                break;
            case 4:
                std::cout << "Masukkan data yang ingin dicari: ";
                std::cin >> data;
                if (searchNode(head, data) != nullptr) {
                    std::cout << "Data ditemukan.\n";
                } else {
                    std::cout << "Data tidak ditemukan.\n";
                }
                break;
            case 5:
                std::cout << "Program selesai.\n";
                break;
            default:
                std::cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (choice != 5);
    return 0;
}
