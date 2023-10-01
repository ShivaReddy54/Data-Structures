#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* next;

    Node(int data){
        val = data;
        next = NULL;
    }
};

void insertHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
} // O(1) Time

void insertEnd(Node* &head, int data){
    Node* temp = new Node(data);
    Node* trav = head;

    while (trav->next != NULL)
        trav = trav->next;

    trav->next = temp;
}  // O(n)  Time

void insertPosition(Node* &head, int data, int k){
    if(k == 0){
        insertHead(head, data);
        return;
    }

    else{
        Node* new_node = new Node(data);
        Node* temp = head;

        for(int i=0; i<k-1; i++)
            temp = temp->next;

        new_node->next = temp->next;
        temp->next = new_node;
    }
}  // O(k)  Time

void update(Node* &head, int data, int k){
    Node* temp = head;

    for(int i=0; i<k; i++)
        temp = temp->next;

    temp->val = data;
} // O(k) Time

void display(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->val << " " ;
        temp = temp->next;
    }
    cout << endl;
}

void deleteHead(Node* &head){
    if (head == NULL){
        cout << "List is empty" << endl;
        return;
    }

    else{
        Node* temp = head;
        head = head->next;

        cout << "Deleted: " << temp->val << endl;
        free(temp);
    }
}  // O(1) Time

void deleteTail(Node* &head){
    Node* sec_last = head;

    while(sec_last->next->next != NULL)
        sec_last = sec_last->next;

    Node* temp = sec_last->next;
    sec_last->next = NULL;

    cout << "Deleted : " << temp->val << endl;
    free(temp);
}  // O(n) Time

void deletePosition(Node* &head, int k){
    if (k == 0){
        deleteHead(head);
        return;
    }

    Node* trav = head;
    for(int i=0; i<k-1; i++)
        trav = trav->next;

    Node* temp = trav->next;
    trav->next = trav->next->next;

    cout << "Deleted : " << temp->val << endl;
    free(temp);
}  // O(n) Time

int main(){
    Node* head = NULL;
    insertHead(head, 1);
    insertHead(head, 2);
    insertEnd(head, 3);
    insertPosition(head, 5, 2);
    update(head, 2, 2);

    display(head);


    deleteHead(head);
    deleteTail(head);
    deletePosition(head, 1);
    
    display(head);
}