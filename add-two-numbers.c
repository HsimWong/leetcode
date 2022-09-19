#include <stdio.h>
#include <stdlib.h>


// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// struct ListNode *appendSuffix

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *ret = (struct ListNode *)malloc(sizeof(struct ListNode));
    ret->val = 0;
    struct ListNode *prev = (struct ListNode *)malloc(sizeof(struct ListNode));
    prev->next = ret;
    ret->next = NULL;
    int carrier = 0;

    int head = 1;

    struct ListNode *rear1 = l1;
    struct ListNode *rear2 = l2;
    struct ListNode *rearRet = ret;
    while (1) {
        // Check if null;


        // Make Computation;
        if (rear1->val == 0 && rear2->val == 0 && carrier == 0 && rear1->next == NULL && rear2->next == NULL){
            prev->next = NULL;
            // free(prev->next);
            return ret;
        }

        int value = carrier + rear1->val + rear2->val;
        int rearVal = value % 10;
        carrier = value / 10;


        rearRet->val = rearVal;
        rearRet->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        rearRet->next->next = NULL;
        // rearRet->val = 0;

        rearRet = rearRet->next;
        
        
        if (rear1->next == NULL) {
            rear1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            rear1->next->val = 0;
            rear1->next->next = NULL;
        }

        if (rear2->next == NULL) {
            rear2->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            rear2->next->val = 0;
            rear2->next->next = NULL;
        }
        rear1 = rear1->next;
        rear2 = rear2->next;
        prev = prev->next;
        // Prepare for the next loop
        // head = 0;

    }
}

int main(int argc, char **argv) {
    int length1 = 0;
    scanf("%d", &length1);
    struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *rear = l1;
    // printf("Length:%d", length1);
    for (int i = 0; i < length1; i++) {
        int value = 0;
        scanf("%d", &value);
        rear->val = value;
        rear->next = i < (length1 - 1) ? (struct ListNode *)malloc(sizeof(struct ListNode)) : NULL;
        rear = rear->next;
    }
    rear = NULL;
    // printf("L1: ");
    // for (rear = l1; rear != NULL; rear = rear->next) {
    //     printf("%d,", rear->val);
    // }










    
    rear = l2;


    int length2 = 0;
    scanf("%d", &length2);

    // printf("Length:%d", length2);
    for (int i = 0; i < length2; i++) {
        int value = 0;
        scanf("%d", &value);
        rear->val = value;
        rear->next = (i < length2 - 1) ?(struct ListNode *)malloc(sizeof(struct ListNode)) : NULL;
        rear = rear->next;
    }
    rear = NULL;
    // printf("L2: ");
    // for (rear = l2; rear != NULL; rear = rear->next) {
    //     printf("%d,", rear->val);
    // }

    struct ListNode *result = addTwoNumbers(l1, l2);
    for (rear = result; rear != NULL; rear = rear->next) {
        printf("%d,", rear->val);
    }


    
}