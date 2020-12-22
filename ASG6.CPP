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

int main() {
    int t; scanf("%d", &t);

    for(int i = 1; i <= t; i++ ) {
        int temp; scanf("%d", &temp);
        pushHead(temp);
    }
    
    angka *temp = head;
    while(temp){
        printf("%d", temp->num);
        if(temp->next) printf(" -> ");
        temp = temp->next;
    }
    

    return 0;
}