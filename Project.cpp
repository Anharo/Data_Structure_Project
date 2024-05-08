#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
struct Nodebt {
    int data;
    struct Nodebt *left;
    struct Nodebt *right;
    Nodebt(int value) : data(value), left(nullptr), right(nullptr) {}
};

class Array {
public:
    void display(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void insertdata(int arr[], int n, int data, int p) {
        if (p < 0 || p > n) {
            cout << "Invalid position for insertion!" << endl;
            return;
        }

        for (int i = n; i > p; i--) {
            arr[i] = arr[i - 1];
        }
        arr[p] = data;
        n++;
    }

    void deletedata(int arr[], int& n, int p) {
        if (p < 0 || p >= n) {
            cout << "Invalid position for deletion!" << endl;
            return;
        }

        for (int i = p; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
    }

    void copyArray(int source[], int destination[], int n) {
        for (int i = 0; i < n; i++) {
            destination[i] = source[i];
        }
    }

    void reverseArray(int arr[], int n) {
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    void mergeArrays(int arr1[], int n1, int arr2[], int n2, int merged[], int& mergedn) {
        int i = 0, j = 0, k = 0;
        while (i < n1 && j < n2) {
            if (arr1[i] < arr2[j]) {
                merged[k++] = arr1[i++];
            } else {
                merged[k++] = arr2[j++];
            }
        }
        while (i < n1) {
            merged[k++] = arr1[i++];
        }
        while (j < n2) {
            merged[k++] = arr2[j++];
        }
        mergedn = k;
    }
};


class LinkedList {
public:
    void displayList(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insertNode(Node*& head, int data, int position) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (position == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 0; i < position - 1 && temp != nullptr; i++) {
                temp = temp->next;
            }
            if (temp == nullptr) {
                cout << "Invalid position for insertion!" << endl;
                delete newNode;
                return;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteNode(Node*& head, int position) {
        if (head == nullptr) {
            cout << "List is empty! Cannot delete." << endl;
            return;
        }

        Node* temp = head;
        if (position == 0) {
            head = head->next;
            delete temp;
        } else {
            Node* prev = nullptr;
            for (int i = 0; temp != nullptr && i < position; i++) {
                prev = temp;
                temp = temp->next;
            }
            if (temp == nullptr) {
                cout << "Invalid position for deletion!" << endl;
                return;
            }
            prev->next = temp->next;
            delete temp;
        }
    }

    int countNodes(Node* head) {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};
class StackArray {
private:
    int* stackArray;
    int top;
    int capacity;

public:
    StackArray(int cap) {
        capacity = cap;
        stackArray = new int[capacity];
        top = -1;
    }

    ~StackArray() {
        delete[] stackArray;
    }

    void push(int data) {
        if (isFull()) {
            cout << "Stack overflow! Cannot push element." << endl;
            return;
        }
        stackArray[++top] = data;
        cout << "Pushed element: " << data << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot pop element." << endl;
            return;
        }
        int poppedElement = stackArray[top--];
        cout << "Popped element: " << poppedElement << endl;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == capacity - 1);
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot peek." << endl;
            return -1;
        }
        return stackArray[top];
    }
};

class StackLinkedList {
private:
    Node* top;

public:
    StackLinkedList() {
        top = nullptr;
    }

    ~StackLinkedList() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = top;
        top = newNode;
        cout << "Pushed element: " << data << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot pop element." << endl;
            return;
        }
        Node* temp = top;
        int poppedElement = top->data;
        top = top->next;
        delete temp;
        cout << "Popped element: " << poppedElement << endl;
    }

    bool isEmpty() {
        return (top == NULL);
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot peek." << endl;
            return -1;
        }
        return top->data;
    }
};
class QueueArray {
private:
    int* queueArray;
    int front, rear, capacity;

public:
    QueueArray(int cap) {
        capacity = cap;
        queueArray = new int[capacity];
        front = rear = -1;
    }

    ~QueueArray() {
        delete[] queueArray;
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue overflow! Cannot enqueue element." << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        queueArray[rear] = data;
        cout << "Enqueued element: " << data << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue element." << endl;
            return;
        }
        int dequeuedElement = queueArray[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        cout << "Dequeued element: " << dequeuedElement << endl;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return ((rear + 1) % capacity == front);
    }

    int rearElement() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot get rear element." << endl;
            return -1;
        }
        return queueArray[rear];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot peek." << endl;
            return -1;
        }
        return queueArray[front];
    }
};

class QueueLinkedList {
private:
    Node* front;
    Node* rear;

public:
    QueueLinkedList() {
        front = rear = NULL;
    }

    ~QueueLinkedList() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued element: " << data << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue element." << endl;
            return;
        }
        Node* temp = front;
        int dequeuedElement = front->data;
        if (front == rear) {
            front = rear = NULL;
        } else {
            front = front->next;
        }
        delete temp;
        cout << "Dequeued element: " << dequeuedElement << endl;
    }

    bool isEmpty() {
        return (front == NULL && rear == NULL);
    }

    int rearElement() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot get rear element." << endl;
            return -1;
        }
        return rear->data;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot peek." << endl;
            return -1;
        }
        return front->data;
    }
};


class BinaryTree {
private:
    Nodebt* root;

public:
    BinaryTree() : root(nullptr) {}

    Nodebt* createNode(int data) {
        return new Nodebt(data);
    }

    void insert(int data) {
        root = insertRecursive(root, data);
    }

    Nodebt* insertRecursive(Nodebt* current, int data) {
        if (current == nullptr) {
            return createNode(data);
        }

        if (data < current->data) {
            current->left = insertRecursive(current->left, data);
        } else if (data > current->data) {
            current->right = insertRecursive(current->right, data);
        }

        return current;
    }

    void preOrder() {
        preOrderRecursive(root);
        cout << endl;
    }

    void preOrderRecursive(Nodebt* current) {
        if (current != nullptr) {
            cout << current->data << " ";
            preOrderRecursive(current->left);
            preOrderRecursive(current->right);
        }
    }

    void inOrder() {
        inOrderRecursive(root);
        cout << endl;
    }

    void inOrderRecursive(Nodebt* current) {
        if (current != nullptr) {
            inOrderRecursive(current->left);
            cout << current->data << " ";
            inOrderRecursive(current->right);
        }
    }

    void postOrder() {
        postOrderRecursive(root);
        cout << endl;
    }

    void postOrderRecursive(Nodebt* current) {
        if (current != nullptr) {
            postOrderRecursive(current->left);
            postOrderRecursive(current->right);
            cout << current->data << " ";
        }
    }
};

class search
{
public:
    int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
};
class Sorting {
public:
    void selectionSort(int arr[], int n)
    {
        for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
    }
    void bubbleSort(int arr[], int n)
    {
        for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
      }
    }
    void printArray(int arr[], int n)
    {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    }
    void insertionSort(int arr[], int n)
    {
        for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    }
    void mergeSort(int arr[], int left, int right){
        if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
    }
    void merge(int arr[], int left, int mid, int right){
        int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void quickSort(int arr[], int low, int high){
     if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void radixSort(int arr[], int n){
    int max = getMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}
};


int main() {
    cout << "This is the final project of Data Structure and Algorithm..." << endl;
    int ch;
    do {
        cout << "Enter a choice of Data Structure you wanna work on." << endl;
        cout << "1. Array" << endl;
        cout << "2. Linked List" << endl;
        cout << "3. Stack" << endl;
        cout << "4. Queue" << endl;
        cout << "5. Tree" << endl;
        cout << "6. Search" << endl;
        cout << "7. Sort" << endl;
        cout << "8. Exit the code" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: {
                Array ary;
                int n1, n2;

                cout << "Enter the n of the first array: ";
                cin >> n1;
                int arr1[n1];
                cout << "Enter datas for the first array:" << endl;
                for (int i = 0; i < n1; i++) {
                    cin >> arr1[i];
                }

                cout << "Enter the n of the second array: ";
                cin >> n2;
                int arr2[n2];
                cout << "Enter datas for the second array:" << endl;
                for (int i = 0; i < n2; i++) {
                    cin >> arr2[i];
                }

                int choice;
                do {
                    cout << "\nMenu:" << endl;
                    cout << "1. Insert data into array" << endl;
                    cout << "2. Delete data from array" << endl;
                    cout << "3. Copy array datas" << endl;
                    cout << "4. Reverse array datas" << endl;
                    cout << "5. Merge two arrays" << endl;
                    cout << "6. Display arrays" << endl;
                    cout << "7. Exit" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                        case 1: {
                            int data, p;
                            cout << "Enter the data to insert: ";
                            cin >> data;
                            cout << "Enter the position to insert: ";
                            cin >> p;
                            ary.insertdata(arr1, n1, data, p);
                        }
                        break;
                        case 2: {
                            int p;
                            cout << "Enter the position to delete: ";
                            cin >> p;
                            ary.deletedata(arr1, n1, p);
                        }
                        break;
                        case 3: {
                            int copy[n1];
                            ary.copyArray(arr1, copy, n1);
                            cout << "Array copied successfully!" << endl;
                            cout << "Copied array: ";
                            ary.display(copy, n1);
                        }
                        break;
                        case 4: {
                            ary.reverseArray(arr1, n1);
                            cout << "Array reversed successfully!" << endl;
                            cout << "Reversed array: ";
                            ary.display(arr1, n1);
                        }
                        break;
                        case 5: {
                            int merged[n1 + n2];
                            int mergedn = 0;
                            ary.mergeArrays(arr1, n1, arr2, n2, merged, mergedn);
                            cout << "Arrays merged successfully!" << endl;
                            cout << "Merged array: ";
                            ary.display(merged, mergedn);
                        }
                        break;
                        case 6:
                            cout << "Array 1: ";
                            ary.display(arr1, n1);
                            cout << "Array 2: ";
                            ary.display(arr2, n2);
                            break;
                        case 7:
                            cout << "Exiting program..." << endl;
                            break;
                        default:
                            cout << "Invalid choice! Please try again." << endl;
                            break;
                    }
                } while (choice != 7);
            }
            break;
            case 2: {
                LinkedList ll;
                Node* head = NULL;
                int choice, data, position;
                do {
                    cout << "\nMenu:" << endl;
                    cout << "1. Insert node into list" << endl;
                    cout << "2. Delete node from list" << endl;
                    cout << "3. Count number of nodes" << endl;
                    cout << "4. Display list" << endl;
                    cout << "5. Exit" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                        case 1:
                            cout << "Enter data for new node: ";
                            cin >> data;
                            cout << "Enter position to insert (0 for beginning): ";
                            cin >> position;
                            ll.insertNode(head, data, position);
                            break;
                        case 2:
                            cout << "Enter position to delete: ";
                            cin >> position;
                            ll.deleteNode(head, position);
                            break;
                        case 3:
                            cout << "Number of nodes in the list: " << ll.countNodes(head) << endl;
                            break;
                        case 4:
                            cout << "Current list: ";
                            ll.displayList(head);
                            break;
                        case 5:
                            cout << "Exiting program..." << endl;
                            break;
                        default:
                            cout << "Invalid choice! Please try again." << endl;
                            break;
                    }
                } while (choice != 5);

                Node* temp;
                while (head != NULL) {
                    temp = head;
                    head = head->next;
                    delete temp;
                }
            }
            break;
            case 3: {
                int choice, element, capacity;
                cout << "Enter the capacity of the stack: ";
                cin >> capacity;

                StackArray stackArr(capacity);
                StackLinkedList stackLL;

                do {
                    cout << "\nMenu:" << endl;
                    cout << "1. Push element (using array)" << endl;
                    cout << "2. Pop element (using array)" << endl;
                    cout << "3. Peek element (using array)" << endl;
                    cout << "4. Check if array stack is empty" << endl;
                    cout << "5. Check if array stack is full" << endl;
                    cout << "6. Push element (using linked list)" << endl;
                    cout << "7. Pop element (using linked list)" << endl;
                    cout << "8. Peek element (using linked list)" << endl;
                    cout << "9. Check if linked list stack is empty" << endl;
                    cout << "10. Exit" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                        case 1:
                            cout << "Enter element to push (array): ";
                            cin >> element;
                            stackArr.push(element);
                            break;
                        case 2:
                            stackArr.pop();
                            break;
                        case 3:
                            cout << "Top element (array): " << stackArr.peek() << endl;
                            break;
                        case 4:
                            if (stackArr.isEmpty()) {
                                cout << "Array stack is empty." << endl;
                            } else {
                                cout << "Array stack is not empty." << endl;
                            }
                            break;
                        case 5:
                            if (stackArr.isFull()) {
                                cout << "Array stack is full." << endl;
                            } else {
                                cout << "Array stack is not full." << endl;
                            }
                            break;
                        case 6:
                            cout << "Enter element to push (linked list): ";
                            cin >> element;
                            stackLL.push(element);
                            break;
                        case 7:
                            stackLL.pop();
                            break;
                        case 8:
                            cout << "Top element (linked list): " << stackLL.peek() << endl;
                            break;
                        case 9:
                            if (stackLL.isEmpty()) {
                                cout << "Linked list stack is empty." << endl;
                            } else {
                                cout << "Linked list stack is not empty." << endl;
                            }
                            break;
                        case 10:
                            cout << "Exiting program..." << endl;
                            break;
                        default:
                            cout << "Invalid choice! Please try again." << endl;
                            break;
                    }
                } while (choice != 10);
            }
            break;
            case 4: {
                int choice, element, capacity;
                cout << "Enter the capacity of the queue: ";
                cin >> capacity;

                QueueArray queueArr(capacity);
                QueueLinkedList queueLL;

                do {
                    cout << "\nMenu:" << endl;
                    cout << "1. Enqueue element (using array)" << endl;
                    cout << "2. Dequeue element (using array)" << endl;
                    cout << "3. Peek element (using array)" << endl;
                    cout << "4. Get rear element (using array)" << endl;
                    cout << "5. Check if array queue is empty" << endl;
                    cout << "6. Enqueue element (using linked list)" << endl;
                    cout << "7. Dequeue element (using linked list)" << endl;
                    cout << "8. Peek element (using linked list)" << endl;
                    cout << "9. Get rear element (using linked list)" << endl;
                    cout << "10. Check if linked list queue is empty" << endl;
                    cout << "11. Exit" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                        case 1:
                            cout << "Enter element to enqueue (array): ";
                            cin >> element;
                            queueArr.enqueue(element);
                            break;
                        case 2:
                            queueArr.dequeue();
                            break;
                        case 3:
                            cout << "Front element (array): " << queueArr.peek() << endl;
                            break;
                        case 4:
                            cout << "Rear element (array): " << queueArr.rearElement() << endl;
                            break;
                        case 5:
                            if (queueArr.isEmpty()) {
                                cout << "Array queue is empty." << endl;
                            } else {
                                cout << "Array queue is not empty." << endl;
                            }
                            break;
                        case 6:
                            cout << "Enter element to enqueue (linked list): ";
                            cin >> element;
                            queueLL.enqueue(element);
                            break;
                        case 7:
                            queueLL.dequeue();
                            break;
                        case 8:
                            cout << "Front element (linked list): " << queueLL.peek() << endl;
                            break;
                        case 9:
                            cout << "Rear element (linked list): " << queueLL.rearElement() << endl;
                            break;
                        case 10:
                            if (queueLL.isEmpty()) {
                                cout << "Linked list queue is empty." << endl;
                            } else {
                                cout << "Linked list queue is not empty." << endl;
                            }
                            break;
                        case 11:
                            cout << "Exiting program..." << endl;
                            break;
                        default:
                            cout << "Invalid choice! Please try again." << endl;
                            break;
                    }
                } while (choice != 11);
            }
            break;
            case 5:{
               BinaryTree binaryTree;

                binaryTree.insert(5);
                binaryTree.insert(3);
                binaryTree.insert(8);
                binaryTree.insert(2);
                binaryTree.insert(4);
                binaryTree.insert(7);
                binaryTree.insert(9);

                int choice;
                do {
                    cout << "\nBinary Tree Traversal Menu:" << endl;
                    cout << "1. Preorder Traversal" << endl;
                    cout << "2. Inorder Traversal" << endl;
                    cout << "3. Postorder Traversal" << endl;
                    cout << "4. Exit" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                        case 1:
                            cout << "Preorder traversal: ";
                            binaryTree.preOrder();
                            break;
                        case 2:
                            cout << "Inorder traversal: ";
                            binaryTree.inOrder();
                            break;
                        case 3:
                            cout << "Postorder traversal: ";
                            binaryTree.postOrder();
                            break;
                        case 4:
                            cout << "Exiting program..." << endl;
                            break;
                        default:
                            cout << "Invalid choice! Please try again." << endl;
                            break;
                    }
                } while (choice != 4);


            }
            break;
            case 6:{
                 int n, key, choice;

             cout << "Enter the number of elements in the list: ";
             cin >> n;
         
             int arr[n];
             cout << "Enter " << n << " numbers in the list:" << endl;
             for (int i = 0; i < n; i++) {
                 cin >> arr[i];
             }
         
             do {
                 cout << "\nSearch Menu:" << endl;
                 cout << "1. Linear Search" << endl;
                 cout << "2. Binary Search" << endl;
                 cout << "3. Exit" << endl;
                 cout << "Enter your choice: ";
                 cin >> choice;
                 search sc;
         
                 switch (choice) {
                     case 1:
                         cout << "Enter the key to search for: ";
                         cin >> key;
                         if (sc.linearSearch(arr, n, key) != -1) {
                             cout << "Linear search: Element found" << endl;
                         } else {
                             cout << "Linear search: Element not found" << endl;
                         }
                         break;
                     case 2:
                         cout << "Enter the key to search for: ";
                         cin >> key;
                         if (sc.binarySearch(arr, 0, n - 1, key) != -1) {
                             cout << "Binary search: Element found" << endl;
                         } else {
                             cout << "Binary search: Element not found" << endl;
                         }
                         break;
                     case 3:
                         cout << "Exiting program..." << endl;
                         break;
                             default:
                             cout << "Invalid choice! Please try again." << endl;
                             break;
                             }
                         } while (choice != 3);
         
            }
            break;
            case 7:{
                Sorting s;
                 int n;
                 cout << "Enter the number of elements in the list: ";
                 cin >> n;

                 int arr[n];
                 cout << "Enter " << n << " numbers in the list:" << endl;
                 for (int i = 0; i < n; i++) {
                     cin >> arr[i];
                 }

                 cout << "Original array: ";
                 s.printArray(arr, n);
                 int ch;
                 do{
                 cout<<"Following are list of sorting methods to chose from: "<<endl;
                 cout << "1. Selection Sort" << endl;
                 cout << "2. Bubble Sort" << endl;
                 cout << "3. Insertion Sort" << endl;
                 cout << "4. Merge Sort" << endl;
                 cout << "5. Quick Sort" << endl;
                 cout << "6. Radix Sort" << endl;
                 cout << "7. Exit " << endl;
                 cout << "Enter your choice: ";
                 cin>>ch;
                 switch(ch)
                 {
                     case 1:{
                      s.selectionSort(arr, n);
                     cout << "After Selection Sort: ";
                      s.printArray(arr, n);
                     }
                     break;
                     case 2:{
                      s.bubbleSort(arr, n);
                      cout << "After Bubble Sort: ";
                      s.printArray(arr, n);
                     }
                     break;
                     case 3:{
                         s.insertionSort(arr, n);
                         cout << "After Insertion Sort: ";
                         s.printArray(arr, n);
                     }
                     case 4:{
                         s.mergeSort(arr, 0, n - 1);
                         cout << "After Merge Sort: ";
                         s.printArray(arr, n);
                     }
                     case 5:{
                         s.quickSort(arr, 0, n - 1);
                         cout << "After Quick Sort: ";
                         s.printArray(arr, n);
                     }
                     break;
                     case 6:{
                         s.radixSort(arr, n);
                         cout << "After Radix Sort: ";
                         s.printArray(arr, n);
                     }
                    break;
                     case 7:{
                         cout<<"Exiting"<<"\n";
                    } 
                    break;
                        default:
                        cout<<"Wrong choice"<<endl;
                        break;
                    }
                    }while(ch!=7);
                    
            }
            break;
            case 8:
                cout << "Exiting the code" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    } while (ch != 8);

    return 0;
}
