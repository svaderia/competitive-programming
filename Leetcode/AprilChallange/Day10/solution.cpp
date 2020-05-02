class MinStack {
public:
    struct node{
        int data;
        int currMin;
        struct node* next;
    }typedef node;
    node* head;
    /** initialize your data structure here. */
    MinStack() {
        head = NULL;
    }
    
    void push(int x) {
        node* n = new node();
        n->data = n->currMin = x;
        if(head != NULL){
            n -> currMin = min(head -> currMin, x);
        }
        n->next = head;
        head = n;
    }
    
    void pop() {
        if(head != NULL)
            head = head -> next;
    }
    
    int top() {
        return head -> data;
    }
    
    int getMin() {
        return head -> currMin;
    }
};
