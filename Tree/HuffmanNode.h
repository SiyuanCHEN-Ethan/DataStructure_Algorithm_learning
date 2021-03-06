#pragma once
template <class T>
class HuffmanNode {
public:
    T key;              // 权值
    HuffmanNode* left;  // 左孩子
    HuffmanNode* right; // 右孩子
    HuffmanNode* parent;// 父结点


    HuffmanNode() {}
    HuffmanNode(T value, HuffmanNode* l, HuffmanNode* r, HuffmanNode* p) :
        key(value), left(l), right(r), parent(p) {}
};
