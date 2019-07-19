#include <iostream>

struct Node{
    int data;
    struct Node *link;
};

Node* getNode(){
    Node *temp {nullptr};
    temp = new Node;
    temp->link = nullptr;
    return temp;
}

Node* insert_front(Node *head, int item){
    Node *temp = getNode();
    temp->data = item;
    temp->link = head;
    
    return temp;
}

Node* insert_last(Node *head, int item){
    Node *temp = getNode(),*prev,*cur;
    temp->data = item;
    
    if(head == nullptr)
        return temp;
    
    cur = head;
    while(cur!=nullptr){
        prev = cur;
        cur = cur->link;
    }
    prev->link = temp;
    
    return head;
}

void display_list(Node *head){
    while(head!=nullptr){
        std::cout << head->data <<"\t";
        head = head->link;
    }
    std::cout << std::endl;
}

int main()
{
    Node *head {nullptr};
    display_list(head);
    head = insert_front(head,10);
    head = insert_front(head,20);
    display_list(head);
    head = insert_front(head,30);
    head = insert_front(head,40);
    display_list(head);
    head = insert_last(head,60);
    head = insert_last(head,70);
    display_list(head);
    head = insert_front(head,10);
    head = insert_front(head,20);
    display_list(head);
	std::cout << std::endl;
	return 0;
}
