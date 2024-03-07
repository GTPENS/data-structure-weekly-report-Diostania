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
void insertNode(Node** head, int data) {
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
Node* searchNode(Node* head, int key) {
    Node* temp = head;
    if (temp != nullptr && temp->data == key) {
        return temp;
    }
    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }
    return temp;
}
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}
int main() {
    Node* head = nullptr;
    insertNode(&head, 17);
    insertNode(&head, 23);
    insertNode(&head, 15);
    insertNode(&head, 3);
     printList(head);
    int searchData = 2;
    Node* foundNode = searchNode(head, searchData);
    if (foundNode != nullptr) {
        std::cout << "Node dengan data " << searchData << " ditemukan." << std::endl;
    } else {
        std::cout << "Node dengan data " << searchData << " tidak ditemukan." << std::endl;
    }
   printList(head);
    int frontData = head->data;
    Node* frontNode = searchNode(head, frontData);
    if (frontNode != nullptr) {
        std::cout << "Node dengan data paling depan " << frontData << " ditemukan." << std::endl;
    } else {
        std::cout << "Node dengan data paling depan tidak ditemukan." << std::endl;
    }
    return 0;
}
