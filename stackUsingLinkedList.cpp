#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int value;
        Node *nextNode;
        Node(int value){
            this->value = value;
            this->nextNode = NULL;
        }
};

void push(Node *node, int value){
    Node *newNode = new Node(value);
    while(node->nextNode != NULL){
        node = node->nextNode;  
    }
    node->nextNode = newNode;
}

int pop(Node *node){
    while(node->nextNode->nextNode != NULL){
        node = node->nextNode;
    }
    Node *lastNode = node->nextNode->nextNode;
    int poppedElement = lastNode->value;
    node->nextNode = NULL;
    delete(lastNode);
    return poppedElement;
}

void printStack(Node *node){
    while(node->nextNode){
        cout<<node->value<<">>";
        node = node->nextNode;
    }
    cout<<node->value<<endl;
}


int main(){
    Node *head = new Node(12);
    while (true){
        int choice;
        cout<<"What do you want to do?"<<endl<<"1.Push"<<endl<<"2.Pop"<<endl<<"3.Print"<<endl<<"Quit"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            int element;
            cout<<"Enter the element You want to push :- ";
            cin>>element;
            push(head, element);
            break;
        case 2:
            cout<<"Enter the element You want to push :- "<<pop(head);
            break;
        case 3:
            cout<<"The stack is as Following :- "<<endl;
            printStack(head);
        case 4:
            cout<<"Quitting.........."<<endl;
            exit;
        default:
            cout<<"please Choose a correct Choice"<<endl;
            break;
        }
    }

}