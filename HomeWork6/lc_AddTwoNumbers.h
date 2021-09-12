#pragma once
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class lc_AddTwoNumbers {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* _l1 = l1;
        ListNode* _l2 = l2;
        ListNode* _resultIterator = nullptr;
        ListNode* result = nullptr;
        int _movablePart = 0;
        while ((_l1 != nullptr) || (_l2 != nullptr)) {
            int _subResult = 0;

            if (_l1 != nullptr) {
                _subResult += _l1->val;
                _l1 = _l1->next;
            };
            if (_l2 != nullptr) {
                _subResult += _l2->val;
                _l2 = _l2->next;
            };

            _subResult += _movablePart;
            if (_subResult >= 10) {
                _movablePart = _subResult / 10;
                _subResult = _subResult % 10;
            }
            else {
                _movablePart = 0;
            }

            if (result == nullptr)
            {
                _resultIterator = new ListNode(_subResult);
                result = _resultIterator;
            }
            else
            {
                _resultIterator->next = new ListNode(_subResult);
                _resultIterator = _resultIterator->next;
            }
        };
        if (_movablePart != 0) {
            if (result == nullptr)
            {
                _resultIterator = new ListNode(_movablePart);
                result = _resultIterator;
            }
            else
            {
                _resultIterator->next = new ListNode(_movablePart);
                _resultIterator = _resultIterator->next;
            }
        };
        return result;
    }
};

