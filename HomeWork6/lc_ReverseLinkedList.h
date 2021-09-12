#pragma once
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class lc_ReverseLinkedList {
public:
    ListNode* reverseList(ListNode* head) {
        if ((head == nullptr) || (head->next == nullptr))
            return head;

        ListNode* _previous = nullptr;
        ListNode* _current = head;
        ListNode* _next = head->next;
        while (_next != nullptr)
        {
            ListNode* temp = _next->next;
            _current->next = _previous;
            _previous = _next;
            _next->next = _current;
            _current = temp;
            if (temp == nullptr) {
                return _previous;
            }
            else
                _next = temp->next;
        }
        _current->next = _previous;
        return _current;
    }
};

