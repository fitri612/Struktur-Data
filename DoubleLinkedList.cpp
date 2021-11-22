#include <iostream>
#include <malloc.h>
using namespace std;

struct node{
    int data;
    node *next;
    node *prev;
}*head, *tail;

typedef struct node *Node;

void CreateNewList(int value){
    Node TempNode, copy;

    TempNode=(Node)malloc(sizeof(struct node));
    TempNode->next = NULL;
    TempNode->prev = NULL;
    TempNode->data = value;
    if(head == NULL)
    {
        head = TempNode;
        tail = TempNode;
    }
    else{
        copy = head;
        while(copy->next != NULL)
            copy = copy->next;
        copy->next = TempNode;
        TempNode->prev = copy;
    }
}

void AddAtBegin(int value){
    Node TempNode;
    TempNode=(Node)malloc(sizeof(struct node));
    if(head == NULL)
        printf("Data not found in the list !\n");

    else{
        TempNode->data = value;
        TempNode->next = head;
        TempNode->prev = NULL;
        head->prev = TempNode;
        head = TempNode;
    }
}

void AddAtLast(int value){
    Node TempNode;
    TempNode=(Node)malloc(sizeof(struct node));
    if(tail == NULL)
        printf("Data not found in the list !\n");
    
    else{
        TempNode->data = value;
        TempNode->next = NULL;
        TempNode->prev = tail;
        tail->next = TempNode;
        tail = TempNode;
    }
}

void AddAtMidd(int value, int position){
    Node TempNode, copy;
    TempNode=(Node)malloc(sizeof(struct node));
    if(head == nullptr){
        TempNode->next = nullptr;
        TempNode->prev = nullptr;
        TempNode->data = value;
        head = tail = TempNode;
    }
    else{
        copy = head;
        while(copy->next != nullptr){
            if(copy->data == position){
                // TempNode->data = value;
                if(copy == tail){
                    TempNode->next = nullptr;
                    copy->next = TempNode;
                    TempNode->data = value;
                    tail = TempNode;
                }
                else{
                    TempNode->next = copy->next;
                    TempNode->data = value;
                    copy->prev = TempNode;
                    if(copy->next != nullptr){
                        copy->next->prev = TempNode;
                    }
                    copy->next = TempNode;
                } 
                break;
            }
            copy = copy->next;
        }
    }

}
void DellFirsetElement(int value){
    Node TempNode;
    TempNode=(Node)malloc(sizeof(struct node));
    if(head->data == value){
        TempNode = head;
        head = head->next;
        head->prev = NULL;
        free(TempNode);

    }
    else
        printf("\nSorry, not the first element list !");
}

void DellEndElement(int value){
    Node TempNode;
    if(tail->data == value){
        TempNode = tail;
        tail = tail->prev;
        tail->next = nullptr;
        free(TempNode);
    }
    else
        printf("\nSorry, not the last element list !");
}

void DellMiddElement(int position){
    Node TempNode, copy;
    if(head == nullptr)
        printf("\nSorry, failed to delete element list !");
    else{
        copy = head;
        while(copy->next->next != nullptr){
            if (copy->next->data == position){
                TempNode = copy->next;
                copy->next = TempNode->next;
                TempNode->next->prev = copy;
                free(TempNode);
            }

            // continue
            copy = copy->next;
        }
    }
}

void ChangeFirstElement(int value){
    if(head != nullptr){
        head->data = value;
        // head->prev = nullptr; // node prev otomatis null
    }
    else
        printf("\nSorry, can't change the element list");
}

void ChangeEndElemnt(int value){
    if(tail != nullptr)
        tail->data = value;
    else
        printf("\nSorry, can't change the element list");

}

void changeMiddElement(int value, int position){
    Node TempNode, copy;
    copy = head;
    if(copy != nullptr){
        while(copy->next != nullptr){
            if(copy->data == position){
                copy->data = value;
            }
            copy = copy->next;
        }
    }
    else
        printf("\nSorry, can't change the element list");
}

int CountElement(){
    Node copy;
    copy = head;
    int tamp = 0;
    while(copy != nullptr){
        copy = copy->next;
        ++tamp;
    }
    return tamp;
}

void rev(){
    Node copy, following, swap;
    swap = head;
    head = tail;
    tail = swap;
    copy = head;

    while(copy != nullptr){
        swap = copy->next;
        copy->next = copy->prev;
        copy->prev = swap;
        copy = copy->next;
    } 
}

void Search(int value){
    Node copy;
    copy = head;
    int numb = 1;
    while(copy != nullptr){
        if(copy->data == value){
            printf ("\n\nItem %d found at position %d", value, numb);
        }
    copy = copy->next;
    ++numb;
    }
    if (copy == nullptr)
        printf ("\n\nItem %d not found in list",value);
}

void ShowMyDisplay(){
    Node copy;
    // cout << "count : " << CountElement() << endl;
    if(head == nullptr){
        cout << "\nYour List Is Empty";
    }
    copy = head;
    cout << "\nYour List Is : ";
    cout << endl;
    cout << "NULL <- ";
    while(copy != nullptr){
        cout << copy->data << " " << "-> " << "<- ";
        copy = copy->next;
    }
    cout << "NULL" << endl;
}

int main(){
    CreateNewList(20);
    AddAtBegin(30);
    AddAtLast(10);
    AddAtLast(1);
    AddAtLast(3);
    AddAtLast(5);
    ShowMyDisplay();
    // cout << CountElement();
    // DellFirsetElement(10);
    // DellEndElement(20);
    // ChangeFirstElement(11);
    // ChangeEndElemnt(100);
    // AddAtMidd(14,10);
    // DellMiddElement(10);
    // changeMiddElement(14,10);
    // rev();
    // ShowMyDisplay();
    // Search(3);
}