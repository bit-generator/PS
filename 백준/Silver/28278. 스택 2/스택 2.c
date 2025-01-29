#include <stdio.h>

typedef struct Stack {
    int top;
    int arr[1000000];
} stack;

int N, A, B;
stack st = {0, {0}};

void push(int x) {
    st.arr[st.top++] = x;
}

int pop() {
    if(!st.top) return -1;
    return st.arr[--st.top];
}

int size() {
    return st.top;
}

int isEmpty() {
    return !st.top;
}

int top() {
    if(!st.top) return -1;
    return st.arr[st.top - 1];
}

int main() {
    scanf("%d", &N);

    while(N--) {
        scanf("%d", &A);
        if(A == 1) {
            scanf("%d", &B);
            push(B);
        }
        else if(A == 2) {
            printf("%d\n", pop());
        }
        else if(A == 3) {
            printf("%d\n", size());
        }
        else if(A == 4) {
            printf("%d\n", isEmpty());
        }
        else {
            printf("%d\n", top());
        }
    }
    
    return 0;
}