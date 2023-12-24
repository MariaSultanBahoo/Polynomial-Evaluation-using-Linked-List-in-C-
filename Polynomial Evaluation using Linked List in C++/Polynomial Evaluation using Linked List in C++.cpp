// Polynomial Evaluation using Linked List in C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class PolyNode {
public:
    int coeff;
    int exponent;
    PolyNode* next;
};

int power(int x, int n) {
    if (n == 0)
        return 1;
    else
        return x * power(x, n - 1);
}

int Evaluate(PolyNode* head, int val) {
    if (head == nullptr) {
        return 0;
    }
    else {
        return head->coeff * power(val, head->exponent) + Evaluate(head->next, val);
    }
}

int main() {
    int value = 2;
    PolyNode* node1 = new PolyNode();
    PolyNode* node2 = new PolyNode();
    PolyNode* node3 = new PolyNode();
    PolyNode* node4 = new PolyNode();

    node1->coeff = 4;
    node1->exponent = 3;
    node1->next = node2;
    node2->coeff = 6;
    node2->exponent = 2;
    node2->next = node3;
    node3->coeff = 10;
    node3->exponent = 1;
    node3->next = node4;
    node4->coeff = 6;
    node4->exponent = 0;
    node4->next = nullptr;

    int temp = Evaluate(node1, value);
    cout << "Result of the polynomial (4x^3 + 6x^2 + 10x + 6) at value " << value << " is: " << temp << endl;

    // Clean up memory (deallocate nodes)
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}
