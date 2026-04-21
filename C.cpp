#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <sstream>

using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq, Node* left = nullptr, Node* right = nullptr) {
        this->ch = ch;
        this->freq = freq;
        this->left = left;
        this->right = right;
    }
};

struct comp {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

void generateCodes(Node* root, string str, unordered_map<char, string>& huffmanCode) {
    if (root == nullptr) return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str.empty() ? "0" : str;
    }

    generateCodes(root->left, str + "0", huffmanCode);
    generateCodes(root->right, str + "1", huffmanCode);
}

void decodeString(Node* root, string encodedStr, string& decodedStr) {
    Node* curr = root;
    for (char bit : encodedStr) {
        if (bit == '0') curr = curr->left;
        else curr = curr->right;

        if (!curr->left && !curr->right) {
            decodedStr += curr->ch;
            curr = root;
        }
    }
}

int main() {
    ifstream inFile("input.txt");
    if (!inFile) {
        cout << "Khong the mo file input.txt" << endl;
        return 1;
    }

    stringstream buffer;
    buffer << inFile.rdbuf();
    string text = buffer.str();
    inFile.close();

    if (text.empty()) {
        cout << "File rong!" << endl;
        return 0;
    }

    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    priority_queue<Node*, vector<Node*>, comp> pq;
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() != 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        int sum = left->freq + right->freq;
        pq.push(new Node('\0', sum, left, right));
    }

    Node* root = pq.top();

    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    string encodedStr = "";
    for (char ch : text) {
        encodedStr += huffmanCode[ch];
    }

    ofstream outFileEncode("encoded.txt");
    outFileEncode << encodedStr;
    outFileEncode.close();

    string decodedStr = "";
    decodeString(root, encodedStr, decodedStr);

    ofstream outFileDecode("decoded.txt");
    outFileDecode << decodedStr;
    outFileDecode.close();

    cout << "Ma hoa va giai ma thanh cong!" << endl;
    cout << "Kiem tra file: encoded.txt va decoded.txt" << endl;

    return 0;
}