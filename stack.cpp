#include <iostream>
using namespace std;

struct stackByme
{
    int arr[100];
};

int top, maxArr = 100;
stackByme Stack;

void SetFirst(){
    top = 0;
}
bool IsFullStack(){
    if(top == maxArr){
        return true;
    }
    else{
        return false;
    }
}

bool IsEmptyStack(){
    if(top == 0){
        return true;
    }
    else{
        return false;
    }
}

void PushArrayByStack( int valuedata){
    if(!IsFullStack()){
        Stack.arr[top+1] = valuedata;
        cout << "Data yang berhasil dipush : "<< valuedata << endl;
        top++;
    }
}

void PopArrayStack(){
    if(!IsEmptyStack()){
        cout << "Berhasil Pop Data : " << Stack.arr[top] << endl;
        top--;
    }
}

void DisplayPrint(){
    int i;
    cout << "Data : " << endl;
    for ( int i = 1; i <= top; i++){
        cout << Stack.arr[i] << " ";
        cout << endl;
    }
}


int main(){
    int choose, input;
    SetFirst();
    do {
      cout << "1. push data"<< endl; 
      cout << "2. pop data"<< endl; 
      cout << "3. print data"<< endl; 
      cout << "4. clear data"<< endl; 
      cout << "5. exit"<< endl; 
      cout << "Pilih : ";
      cin >> choose;
      switch (choose) {
      case 1:
        if(IsFullStack() == 1) {
        	cout << "Tumpukan Penuh" << endl;
        } 
        else {
            cout << "Data yang di push: ";
            cin >> input;
            PushArrayByStack(input);
        } 
        break;
      case 2:
        if (IsEmptyStack() == 1) {
        	cout << "Tumpukan Kosong"<<endl;
        } 
        else {
        	PopArrayStack();
        } 
        break;  
      case 3:
        if(IsEmptyStack()==1) {
        	cout << "Tumpukan kosong"<<endl;
        } 
        else {
        	DisplayPrint();
        } 
        break; 
      case 4:
        SetFirst();
        break;
      }
    } while (choose >= 1 && choose <= 4);
    
    return 0;
}