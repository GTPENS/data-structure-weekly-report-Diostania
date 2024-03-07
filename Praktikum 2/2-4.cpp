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

void printList(Node* head) {
  Node* temp = head;
  while (temp != nullptr) {
    std::cout << temp->data << " ";
    temp = temp->next;
  }
  std::cout << std::endl;
}

int main() {
    int y;
  Node* head = nullptr;
  insertNode(&head, 17);
  insertNode(&head, 23);
  insertNode(&head, 15);
  std::cout << "Data: ";
  printList(head);
  std::cout << "Masukan Data yang ingin di input: ";
  std::cin >> y;
  insertNode(&head,y);
  printList(head);
  return 0;
}
