#include<iostream>
#include<limits>
class Node{
    public:
        int key;
        int data;
        Node*  next;
        Node*  prev;
        Node(){
            key = 0;
            data = 0;
            next = nullptr;
            prev = nullptr;
        }
        Node(int k, int d){
            key = k;
            data = d;
            next = nullptr;
            prev = nullptr;
        }
};
class doublyLinkedList{
    public:
        Node* head;
        Node* tail;
        int count;
        doublyLinkedList(){
            head = nullptr;
            tail = nullptr;
            count = 0;
        }
        doublyLinkedList(Node* n){
            head = n;
            tail = n;
            count = 1;
            n->next = nullptr;
        }
        ~doublyLinkedList(){
            Node*  temp;
            while(head!=nullptr){
                temp = head;
                head = head->next;
                delete temp;
            }
        }
        Node*  keyExist(int k){
            Node*  temp = head;
            Node*  found = nullptr;
            while(temp!=nullptr){
                if(temp->key == k){
                    found = temp;
                    break;
                }
                temp = temp->next;
            }
            return found;
        }
        bool isEmpty(){
            return head==nullptr;
        }
        void append(Node* n){
            if(keyExist(n->key)!=nullptr){
                std::cout<< "The key node already exist in the list "<<std::endl;
                return;
            }
            if(isEmpty()){
                head = n;
                tail = n;
                n->next = nullptr;
            }
            else{
                Node* temp = head;
                while(temp->next!=nullptr){
                    temp = temp->next;
                }
                temp->next = n;
                n->prev = temp;
                tail = n;
            }
            count++;
        }
        void prepend(Node* n){
            if(keyExist(n->key)!=nullptr){
                std::cout<< "The key node already exist in the list"<<std::endl;
                return;
            }
            if(isEmpty()){
                head = n;
                tail = n;
            }
            else{
                n->next = head;
                head->prev = n;
                head = n;
            }
            count++;
        }
        void insertAfterKey(int k, Node* n){
            if(keyExist(n->key)!=nullptr){
                std::cout<< "The key node already exist in the list"<<std::endl;
                return;
            }
            if(keyExist(k)==nullptr){
                std::cout<< "The key node you are looking for doesnt exist in the list"<<std::endl;
            }
            else{
                Node* current = keyExist(k);
                Node* after = current->next;
                if(current == tail){
                    current->next = n;
                    n->prev = current;
                    tail = n;
                }
                else{
                    n->next = after;
                    after->prev = n;
                    current->next = n;
                    n->prev = current;
                }
            }
            count++;
        }
        void deleteKey(int k){
            Node*  current = keyExist(k);
            if(current==nullptr){
                std::cout<< "The key node you are looking for doesnt exist in the list"<<std::endl;
                return;
            }
            Node*  previous = current->prev;
            Node*  after = current->next;
            if(current == head){
                head = head->next;
                if(head!=nullptr){
                    head->prev = nullptr;
                }
            }
            else if(current == tail){
                previous->next = nullptr;
                tail = previous;
            }
            else{
                previous->next = current->next;
                current->next->prev = previous;
            }
            count--;
        }
        void update(int k, int d2){
            if(keyExist(k)==nullptr){
                std::cout<< "The key node you are looking for doesnt exist in the list"<<std::endl;
                return;
            }
            Node* current = keyExist(k);
            current->data = d2;
        }
        int Count(){
            return count;
        }
        void displayForward(){
            Node* temp = head;
            std::cout<< "Head-->";
            while(temp!=nullptr){
                std::cout<<" ("<<temp->key<< " , "<<temp->data<<" )-->"; 
                temp = temp->next;
            }
            std::cout<< " NULL"<<std::endl;
        }
        void displayBackward(){
            Node* temp = tail;
            std::cout<< "NULL-->";
            while(temp!=nullptr){
                std::cout<<" ("<<temp->key<< " , "<<temp->data<<" )-->"; 
                temp = temp->prev;
            }
            std::cout<< " Head"<<std::endl;
        }
        void reverse(){
            int size = count;
            Node*  temp = head;
            Node* rev = head;
            int tem;
            if(isEmpty()){
                std::cout<< "The list is empty"<<std::endl;
                return;
            }
            else{
                while(size!= count/2){
                    for(int i=1;i<size;i++){
                        rev = rev->next;
                    }
                    tem = temp->data;
                    temp->data = rev->data;
                    rev->data = tem;
                    tem = temp->key;
                    temp->key = rev->key;
                    rev->key = tem;
                    rev = head;
                    temp = temp->next;
                    size--;
                }
            }
        }
        void sort(){
            if(isEmpty()){
                std::cout<< "The list is empty"<<std::endl;
                return;
            }
            else{
                Node* min = head;
                Node* temp = head;
                int tem;
                while(temp!=nullptr){
                    while(min!=nullptr){
                        if(temp->data>min->data){
                            tem = temp->data;
                            temp->data = min->data;
                            min->data = tem;
                            tem = temp->key;
                            temp->key = min->key;
                            min->key = tem;
                        }
                        min = min->next;
                    }
                    temp = temp->next;
                }
            }
        }
        Node* findMiddle(){
            int size = count/2;
            Node*  temp = head;
            for(int i=1;i<=size;i++){
                temp = temp->next;
            }
            return temp;
        }
};
void Merge(doublyLinkedList s1,doublyLinkedList s2,doublyLinkedList* merge){
    Node* temp = s1.head;
    while(temp!=nullptr){
        Node* newNode = new Node();
        newNode->key = temp->key;
        newNode->data = temp->data;
        merge->append(newNode);
        temp = temp->next;
    }
    temp = s2.head;
    while(temp!=nullptr){
        Node* newNode = new Node();
        newNode->key = temp->key;
        newNode->data = temp->data;
        merge->append(newNode);
        temp = temp->next;
    }
}
int valid(int num){
    while(true){
        std::cin>>num;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<< "Invalid input! Please try again"<<std::endl;
        }
        else{
            return num;
        }
    }
}
int main(){
    doublyLinkedList d;
    int op,k,key1,data1;
    bool leave = false;
    while(leave == false){
        std::cout<< "#####################operations##################"<<std::endl;
        std::cout<< "1.Does the node exist in the list?\n2.Is the list empty?\n3.Append a node\n4.Prepend a node\n5.Insert a node after a key\n6.Delete a key\n7.Update a node\n8.How many nodes are in the list?\n9.Display the list\n10.Reverse the list\n11.Sort the list\n12.Find the middle node\n13.Exit"<<std::endl;
        std::cout<< "Enter the numebr of the operation"<<std::endl;
        op = valid(op);
        while(op>13  || op<1){
            std::cout<<"Invalid number of opeartions! Please t4ry again"<<std::endl;
            op = valid(op);
        }
        Node* n = new Node();
        switch(op){
            case 1:
                std::cout<< "Enter the key you are looking for: ";
                key1 = valid(key1);
                n = d.keyExist(key1);
                if(n ==nullptr){
                    std::cout<< "The key doesnt exist in the list "<<std::endl;
                }
                else{
                    std::cout<< "( "<<n->key<< " , "<<n->data<<" )"<<std::endl;
                }
                break;
            case 2:
                std::cout<< "Is the list empty? "<<d.isEmpty()<<std::endl;
                 break;
            case 3:
                std::cout<< "Enter the key: ";
                k = valid(k);
                std::cout<< "Enter the data: ";
                data1 = valid(data1);
                n->key = k;
                n->data = data1;
                d.append(n);
                break;
            case 4:
                std::cout<< "Enter the key:";
                k = valid(k);
                std::cout<< "Enter the data: ";
                data1 = valid(data1);
                n->key = k;
                n->data = data1;
                d.prepend(n);
                break;
            case 5: 
                std::cout<< "Enter the key: ";
                k = valid(k);
                std::cout<< "Enter the data: ";
                data1 = valid(data1);
                n->key = k;
                n->data = data1;
                std::cout<< "Enetr the key you want to insert after:";
                key1 = valid(key1);
                d.insertAfterKey(key1,n);
                break;
            case 6:
                std::cout<< "Enter the key value of the node you want to delete:";
                key1= valid(key1);
                d.deleteKey(key1);
                break;
            case 7:
                std::cout<< "Enetr the key value of the node you want to update:";
                key1 = valid(key1);
                std::cout<< "Enter the new value of data:";
                data1 = valid(data1);
                d.update(key1 , data1);
                break;
            case 8:
                std::cout<<"There are "<<d.Count()<<" nodes in the list"<<std::endl;
                break;
            case 9:
                std::cout<< "Displayed Forward: ";
                d.displayForward();
                /*std::cout<< "Displayed Backward: ";
                d.displayBackward();*/
                break;
            case 10:
                d.reverse();
                break;
            case 11:
                d.sort();
                break;
            case 12:
                n = d.findMiddle();
                if(n == nullptr){
                    std::cout<< "The list is empty"<<std::endl;
                }
                else{
                    std::cout<< "middle node: ("<<n->key << " , "<<n->data<<" )"<<std::endl;
                }
                break;
            case 13:
                leave = true;
                std::cout<< "Bye!"<<std::endl;
                break;
        }
    }
    return 0;
}