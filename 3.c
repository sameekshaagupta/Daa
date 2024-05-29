#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insert(struct Node* head, int data, int flag) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (!flag) {
        if (head == NULL) {
            return newNode;
        } else {
            struct Node* curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = newNode;
            return head;
        }
    } else {
        if (head == NULL) {
            return newNode;
        } else {
            newNode->next = head;
            head = newNode;
            return head;
        }
    }
}

struct Node* addition(struct Node* head1, struct Node* head2) {
    struct Node* addList = NULL;
    int carry = 0;
    while (head1 != NULL && head2 != NULL) {
        int digOne = head1->data;
        int digTwo = head2->data;
        int sum = digOne + digTwo + carry;
        carry = sum / 10;
        sum = sum % 10;
        addList = insert(addList, sum, 1);
        head1 = head1->next;
        head2 = head2->next;
    }
    while (head1 != NULL) {
        int digit = head1->data + carry;
        carry = digit / 10;
        digit = digit % 10;
        addList = insert(addList, digit, 1);
        head1 = head1->next;
    }
    while (head2 != NULL) {
        int digit = head2->data + carry;
        carry = digit / 10;
        digit = digit % 10;
        addList = insert(addList, digit, 1);
        head2 = head2->next;
    }
    if (carry > 0) {
        addList = insert(addList, carry, 1);
    }
    return addList;
}

struct Node* subtraction(struct Node* head1, struct Node* head2, int isNo1Greater) {
    struct Node* subList = NULL;
    int borrow = 0;
    while (head1 != NULL && head2 != NULL) {
        int digOne = head1->data;
        int digTwo = head2->data;
        int sub = digOne - digTwo + borrow;
        if (sub < 0) {
            borrow = -1;
            sub += 10;
        } else {
            borrow = 0;
        }
        subList = insert(subList, sub, 1);
        head1 = head1->next;
        head2 = head2->next;
    }
    while (head1 != NULL) {
        int digit = head1->data + borrow;
        if (digit < 0) {
            borrow = -1;
            digit += 10;
        } else {
            borrow = 0;
        }
        subList = insert(subList, digit, 1);
        head1 = head1->next;
    }
    if (borrow < 0) {
        subList = insert(subList, borrow, 1);
    }
    if (!isNo1Greater) {
        subList->data = -(subList->data);
    }
    return subList;
}

struct Node* multiply(struct Node* num1, struct Node* num2) {
    struct Node* result = NULL;
    int multiplier = 0;
    struct Node* temp = num2;
    while (temp != NULL) {
        multiplier = multiplier * 10 + temp->data;
        temp = temp->next;
    }
    for (int i = 0; i < multiplier; i++) {
        result = addition(result, num1);
    }
    return result;
}

struct Node* power(struct Node* base, struct Node* exponent) {
    struct Node* result = NULL;

    // Initialize result with value 1
    result = insert(result, 1, 0);

    // Convert the exponent linked list to integer
    int exp = 0;
    struct Node* temp = exponent;
    while (temp != NULL) {
        exp = exp * 10 + temp->data;
        temp = temp->next;
    }

    // Multiply base by itself 'exp' times
    for (int i = 0; i < exp; i++) {
        result = multiply(result, base);
    }

    return result;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    printf("-Sameeksha Gupta 22BCP343--\n");

    int no1, no2;
    printf("Enter any two numbers : ");
    scanf("%d %d", &no1, &no2);
    int isNo1Greater = 1;
    if (no1 < no2) {
        isNo1Greater = 0;
    }
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    while (no1 > 0) {
        int rem = no1 % 10;
        head1 = insert(head1, rem, 0);
        no1 = no1 / 10;
    }
    while (no2 > 0) {
        int rem = no2 % 10;
        head2 = insert(head2, rem, 0);
        no2 = no2 / 10;
    }

    printf("Addition of Two Linked Lists : ");
    struct Node* add = addition(head1, head2);
    printList(add);
    struct Node* sub = NULL;

    if (isNo1Greater) {
        sub = subtraction(head1, head2, isNo1Greater);
    } else {
        sub = subtraction(head2, head1, isNo1Greater);
    }

    printf("Subtraction of Two Linked Lists : ");
    printList(sub);

    struct Node* mul = multiply(head1, head2);
    printf("Multiplication of Two Linked Lists : ");
    printList(mul);

    printf("Exponential result: ");
    struct Node* expResult = power(head1, head2);
    printList(expResult);

    return 0;
}
