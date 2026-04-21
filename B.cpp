#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } 
    else {
        root->right = insert(root->right, val);
    }

    return root;
}

void storeInOrder(Node* root, int arr[], int& index) {
    if (root != nullptr) {
        storeInOrder(root->left, arr, index);
        
        arr[index++] = root->data;
        
        storeInOrder(root->right, arr, index);
    }
}

void deleteTree(Node* root) {
    if (root != nullptr) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

void treeSort(int arr[], int n) {
    Node* root = nullptr;
    
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    
    int index = 0;
    storeInOrder(root, arr, index);

    deleteTree(root);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {54, 26, 93, 17, 77, 31, 44, 55, 20, 26};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Mang ban dau: ";
    printArray(arr, n);

    treeSort(arr, n);

    cout << "Mang sau khi sap xep (Tree Sort): ";
    printArray(arr, n);

    return 0;
}