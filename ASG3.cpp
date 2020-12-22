#include <stdio.h>
#include <stdlib.h>

struct angka {
    int num;
    angka *next;
}*head = NULL, *tail = NULL;

angka *insert(int a) {
    angka *temp = (angka*)malloc(sizeof(angka));
    temp->num = a;
    temp->next= NULL;
    return temp;
}

void pushHead(int a) {
    if(!head) head = tail = insert(a);
    else {
        angka *temp = insert(a);
        temp->next = head;
        head = temp;
    }
}

void pushTail (int a) {
    if (!head) head = tail = insert(a);
    else {
        angka *temp = insert(a);
        tail->next = temp;
        tail = temp;
    }
}

void pushMid (int a) {
    if(!head) pushHead(a);
    else if(a <= head->num) pushHead(a);
    else if (a > tail->num) pushTail(a);

    else {
        angka *temp = insert(a);
        angka *now, *prev;
        now = head;

        while(a > now->num) {
            prev = now;
            now = now->next;
        }

        prev->next = temp;
        temp->next = now;
    }
}

int main() {
    int n; scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        int temp; scanf("%d", &temp);
        pushMid(temp);
    }
	
    angka *temp = head;
    int idx = 1;
    while (idx <= (n/2)) {
    	temp = temp->next;
    	idx++;
	}
    printf("Middle element : %d\n", temp->num);

    return 0;
}