#include <iostream>

struct Node {
    int data;
    Node* next;
};
Node* createNode(int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;  
    return newNode;
}
void insertNode(Node** head, int data){
    Node* newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;      
    }      
    else{
        Node* temp = *head;
        while(temp->next != NULL){
            temp = temp->next;          
        }
        temp->next = newNode;      
    }
}
void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}
int main() {
    Node* head = NULL;
    insertNode(&head, 17);
    insertNode(&head, 23);
    insertNode(&head, 15);
    insertNode(&head, 3);
    printList(head);
}