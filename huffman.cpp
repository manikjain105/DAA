#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int buildHuffmanTree(vector<pair<int, char>>& nodes) {
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq(nodes.begin(), nodes.end());
       while (pq.size() > 1)
       {
        pair<int, char> left = pq.top();
        pq.pop();
        pair<int, char> right = pq.top();
        pq.pop();
        pq.push(make_pair(left.first + right.first , '*'));
        }
    return pq.top().first;
}

int main() {
    vector<pair<int, char>> nodes = {{6, 'a'}, {2, 'e'}, {5, 'i'}, {4, 'o'}, {1, 'u'}};
    int root = buildHuffmanTree(nodes);
    cout << "Root of Huffman Tree: " << root << endl;
    return 0;
}
