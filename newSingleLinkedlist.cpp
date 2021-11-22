#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

class List {

    // private:

    public:

        Node* head;
        Node* tail;
        int count;

        List() {
            head = nullptr;
            tail = nullptr;
            count = 0;
        }
        ~List() {}

        void push(int value) {

            Node *safe;
            safe = new Node();
            safe->data = value;
            if (head == nullptr) {
                head = safe;
                tail = safe;
            } else {
                tail->next = safe;
                tail = safe;
            }
            count++;
        }

        int get (const int index) {
            if (index < count) {
                Node *safe;
                safe = head;
                int i = index;
                while (!(i == 0)) {
                    safe = safe->next;
                    i--;
                }
                return safe->data;
            }
            return 0;
        }

        void shift() {
        	if (count > 0) {    		
	            Node *safe;
	            safe = head;
	            head = safe->next;
	            free(safe);
	            count--;
        	} 
        }

        void pop() {
        	if (count > 0) {    		
	            Node *safe;
	            safe = head;
	            while (safe->next != tail) {
	                safe = safe->next;
	            }
	            tail = safe;
	            tail->next = nullptr;
	            free(safe->next);
	            count--;
        	}
        }

        void remove(const int index) {
            if (index < count) {
                Node *safe;
                Node *previous;
                safe = head;
               	previous = head;
                int i = index;
                if (i == 0) shift();
                else if (i == (count -1)) pop();
				else {
					while (!(i == 0)) {
						if (!((i - 1) == 0)) {
							previous = previous->next;
						}
						safe = safe->next;
						i--;
					}
					previous->next = safe->next;
					free(safe);
					count--;
				}
            }
        }

        void removeMiddle() { // middle delete
        	if (count > 0) {    		
			    int middle = size(); // N
			    if ((middle & 1) == 1) middle = (middle + 1) / 2; // ODD
			    else middle = middle / 2; // EVEN
			    remove(middle - 1);
        	}
        }

        int size() {
            return count;
        }


};

int main(const int argc, const char** argv) {

    (void)argc;
    (void)argv;

    List* list;
    list = new List();

    list->push(23);
    list->push(24);
    list->push(25); // delete
    list->push(26);
    list->push(27);
    // list->push(28); // 6 data

    // list->shift();
    // list->pop();
    // list->pop();
    // delete middle
    list->removeMiddle();

    cout << list->size() << endl;

    for (int i = 0; i < list->size(); i++) {

        cout << list->get(i) << endl;
    }
}
