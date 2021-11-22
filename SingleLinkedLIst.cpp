#include <iostream>
using namespace std;

struct node{
    int data;
    node *ptrNext;
}*head, *tail, *TempNode;

void CreateMyList(int value){
    node *copy;
    TempNode = (node*)new(node);
    TempNode->data = value;
    TempNode->ptrNext = nullptr;

    if(head == nullptr){
        // cout << "Kondisi Pertama " << endl;
        head = TempNode;
        tail = head;
    }
    else{
        // cout << "Kondisi Kedua" << endl;
        copy = head;
        while(copy->ptrNext != nullptr)
            copy = copy->ptrNext;
        copy->ptrNext = TempNode;
    }
}

void AddBeginning(int value){
    TempNode = (node*)new(node);
    TempNode->data = value;
    TempNode->ptrNext = head;
    head = TempNode;
}

void AddLast(int value){
    TempNode = (node*)new(node);
    TempNode->data = value;
    TempNode->ptrNext = nullptr;
    tail->ptrNext = TempNode;
    tail = TempNode;
}

void AddMidd(int value, int position){
   node *copy;
   TempNode = (node*)new(node);
   if(head == nullptr){
       TempNode->ptrNext = nullptr;
       TempNode->data = value;
       head = TempNode;
       tail = head;
   }
   else{
       copy = head;
       while (copy->ptrNext != nullptr) {

           if (copy->data == position) {

               // initialized new node 

               if (copy == tail)
               {
                   TempNode->ptrNext = nullptr;
                   copy->ptrNext = TempNode;
                   TempNode->data = value;
                   tail = TempNode;
                   break;
               }
               else{
                    TempNode->ptrNext = copy->ptrNext; // if safe == tail, nullptr
                    TempNode->data = value;
                    copy->ptrNext = TempNode;

               }
               break;
           }
           // continue
           copy = copy->ptrNext;
       }
   }
}

void DellFirst(int value){
   TempNode = (node*)new(node);
   if(head->data == value){
       TempNode = head;
       //dell first element 
       head = head->ptrNext;
       free(TempNode);
   }
}

// void delfirst() {

//    node* safe; 
//    safe = head;
//    head = head->ptrNext;
//    free(safe);
// }

void DellLast(){
    node *del, *copy;
    del = tail;
    copy = head;
    while(copy->ptrNext != tail){
        copy = copy->ptrNext;
    }
    tail = copy;
    tail->ptrNext = nullptr;
    delete del;
    // free(copy);
}

void DellMidd(int position){
    node *copy;
    TempNode = (node*)new(node);
    copy = head;
    while(copy->ptrNext->ptrNext != nullptr){
        if(copy->ptrNext->data == position){
            TempNode = copy->ptrNext;
            copy->ptrNext = TempNode->ptrNext;
            free(TempNode);
        }
        // continue
        copy = copy->ptrNext;
    }    
}

void ChangeFirst(int value){
    node *copy;
    copy = head;
    if(copy != nullptr)
        copy->data = value;
}

void ChangeLast(int value){
    node *copy;
    copy = tail;
    if(copy != nullptr)
        copy->data = value;
}

void ChangeMidd(int value, int position){
    node *copy;
    TempNode = (node*)new(node);
    copy = head;
    while(copy->ptrNext != nullptr){
        if(copy->data == position){
            copy->data = value;
        }
        copy = copy->ptrNext;
    }
}

// count your length data
int Count(){
    node *copy;
    copy = head;
    int tamp = 0;
    while(copy != nullptr){
        copy = copy->ptrNext;
        ++tamp;
    }
    return tamp;
}

int rev(){
    node *previous, *copy, *following, *swap;
    previous = nullptr;
    copy = head;
    following = head;

    while(copy != nullptr){
        following = following->ptrNext;
        copy->ptrNext = previous;
        previous = copy;
        copy = following;
    }
    swap = head;
    head = tail;
    tail = swap;
    return previous->data;
}

void Search(int value){
    node *copy;
    copy = head;
    int numb = 1;
    while(copy != nullptr){
        if(copy->data == value){
            printf ("\n\nItem %d found at position %d", value, numb);
        }
    copy = copy->ptrNext;
    ++numb;
    }
    if (copy == nullptr)
        printf ("\n\nItem %d not found in list",value);
}

void ShowMenu(){
    cout << "======== Menu LinkedList By Fitri ========" << endl << endl;
    cout << "1.  Create a New List" << endl;
    cout << "2.  Add first element list" << endl;
    cout << "3.  Add last element list" << endl;
    cout << "4.  Add Middle element list" << endl;
    cout << "5.  Delete First element list" << endl;
    cout << "6.  Delete Last element list" << endl;
    cout << "7.  Delete Middle element list" << endl;
    cout << "8.  Find/Change First element list" << endl;
    cout << "9.  Find/ Change Last element list" << endl;
    cout << "10. Find/Change Middle element list" << endl;
    cout << "11. Search a element list" << endl;
    cout << "12. Reverse data" << endl;
    cout << "13. Count of your data" << endl;
    cout << "14. Show your data " << endl;
    cout << "15. exit"  << endl;
}

void ShowMyDisplay(){
    node *copy;
    copy = head;
    if(copy == nullptr){
        cout << "\nYour List Is Empty";
    }
    cout << "\nYour List Is : ";
    cout << endl;
    while(copy != nullptr){
        cout << copy->data << " " << "-> ";
        copy = copy->ptrNext;
    }
    cout << "NULL" << endl;
}

int main(){
    int option, position, data;
    head = nullptr;
    do{
        ShowMenu();
        cout << "Choose your option : "; cin  >> option;
        switch(option){
            case 1:
                cout << "create your new list : "; cin >> data;
                CreateMyList(data);
                break;
            case 2:
                cout << "Add your first list : "; cin >> data;
                AddBeginning(data);
                break;
            case 3:
                cout << "Add your last list : "; cin >> data;
                AddLast(data);
                break;
            case 4:
                cout << "Add your Middle list : "; cin >> data;
                cout << endl;
                cout << "Data added after : "; cin >> position;
                AddMidd(data, position);
                break;
            case 5:
                cout << "Delete your first list : "; cin >> data;
                DellFirst(data);
                break;
            case 6:
                DellLast();
                break;
            case 7:
                cout << "Data added after : "; cin >> position;
                DellMidd(position);
                break;
            case 8:
                cout << "Find or Change your first list : "; cin >> data;
                ChangeFirst(data);
                break;
            case 9:
                cout << "Find or Change your Last list : "; cin >> data;
                ChangeLast(data);
                break;
            case 10:
                cout << "Find or Change your Last list : "; cin >> data;
                cout << endl;
                cout << "Data added after : "; cin >> position;
                ChangeMidd(data, position);
                break;
            case 11:
                cout << "Search your data : "; cin >> data;
                Search(data);
                break;
            case 12:
                rev();
                break;
            case 13:
                cout << "Count your data is " << Count() << endl;
                break;
            case 14:
                ShowMyDisplay();
                break;
        }

    }
    while(option != 15);

    // CreateMyList(12);
    // AddBeginning(124);
    // AddLast(14);
    // AddLast(24);
    // AddLast(3);
    // AddMidd(3,14);
    // AddLast(32); 
    // AddLast(2);
    // ChangeFirst(1);
    // ChangeLast(5);
    // ChangeMidd(8,3);
    // DellLast();   
    // DellMidd(14);
    // DellMidd(24);
    // DellMidd(124);
    // DellMidd(12);
    // DellMidd(32);
    // DellMidd(32);
    // cout << "Sebelum perubahah rev " << endl;
    // ShowMyDisplay();
    // cout << endl;
    // Search(32);

    // rev();
    // cout << "Sesudah perubahan rev " << endl;
    // ShowMyDisplay();

    return 0;
}
