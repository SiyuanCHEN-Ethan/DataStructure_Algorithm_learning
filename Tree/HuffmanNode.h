#pragma once
template <class T>
class HuffmanNode {
public:
    T key;              // Ȩֵ
    HuffmanNode* left;  // ����
    HuffmanNode* right; // �Һ���
    HuffmanNode* parent;// �����


    HuffmanNode() {}
    HuffmanNode(T value, HuffmanNode* l, HuffmanNode* r, HuffmanNode* p) :
        key(value), left(l), right(r), parent(p) {}
};
