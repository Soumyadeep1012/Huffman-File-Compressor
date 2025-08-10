#include <iostream>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <bitset>

using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

void buildCodes(Node* root, string str, unordered_map<char, string> &codes) {
    if (!root) return;

    if (!root->left && !root->right) {
        codes[root->ch] = str;
    }

    buildCodes(root->left, str + "0", codes);
    buildCodes(root->right, str + "1", codes);
}

void compress(const string& inputFile, const string& outputFile) {
    ifstream in(inputFile);
    unordered_map<char, int> freq;

    char ch;
    while (in.get(ch)) freq[ch]++;
    in.clear(); in.seekg(0);

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto p : freq) pq.push(new Node(p.first, p.second));

    while (pq.size() > 1) {
        Node *l = pq.top(); pq.pop();
        Node *r = pq.top(); pq.pop();
        Node *merged = new Node('\0', l->freq + r->freq);
        merged->left = l;
        merged->right = r;
        pq.push(merged);
    }

    Node* root = pq.top();
    unordered_map<char, string> codes;
    buildCodes(root, "", codes);

    ofstream out(outputFile, ios::binary);
    string encoded = "";
    while (in.get(ch)) {
        encoded += codes[ch];
    }

    // Padding
    int padding = 8 - (encoded.size() % 8);
    encoded.append(padding, '0');
    out.put(padding);

    for (size_t i = 0; i < encoded.size(); i += 8) {
        bitset<8> bits(encoded.substr(i, 8));
        out.put(static_cast<unsigned char>(bits.to_ulong()));
    }

    cout << "Compression complete. Output: " << outputFile << endl;
}

int main() {
    string input = "sample.txt";
    string output = "compressed.bin";
    compress(input, output);
    return 0;
}