#include <iostream>
#include <vector>
using namespace std;

// 트리의 노드 정의
struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int v) {
        value = v;
        left = nullptr;
        right = nullptr;
    }
};

// 전위 순회를 기반으로 이진 검색 트리에 노드 삽입
void insertNode(Node*& root, int new_value) {
    if (root == nullptr) {
        root = new Node(new_value);
        return;
    }

    if (new_value < root->value) {
        insertNode(root->left, new_value);
    } 
    else {
        insertNode(root->right, new_value);
    }
}

// 후위 순회로 출력하는 함수 (왼 -> 오 -> 루트)
void postorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->value << '\n';
}

// 전위 순회 결과로 트리 구성 후 후위 순회 결과 출력
void BSTFromPreorder(const vector<int>& preorder_values) {
    Node* root = nullptr;

    for (int i = 0; i < (int)preorder_values.size(); i++) {
        insertNode(root, preorder_values[i]);
    }

    postorder(root);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> preorder_values;
    int value;

    while (cin >> value) {
        preorder_values.push_back(value);
    }

    BSTFromPreorder(preorder_values);

    return 0;
}