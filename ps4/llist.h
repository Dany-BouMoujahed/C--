template <class T>
class LList { 
    public:
    #include "llnode.h"
    typedef LLNode * LLNodeP;
    LLNodeP head;
    LLNodeP tail;
    unsigned int size;
    LList () : head (0) , tail (0) , size(0) {}
    ~LList () {}
    LLNodeP insert (const T & d){ 
        if (head==null && tail== null){
            LLnodeP n = new LLNode(d);
            head = n;
            tail = n;
            size++;
            return n;
        }
        else{
            LLnodeP n = new LLNode(d, head);
            head = n;
            size++;
            return n;
        }
    }
    LList & operator <<( const T & d) {
        insert (d) ;
        return * this ;
    }
    void print ( ostream & os ){
        LLNodeP n = head ;
        while ( n != NULL ) {os << n-> data () << " ";
        n=n->next () ;
        }
    }
    void printRec (stream & os) {
        head -> printRec (os) ;
        }
    ~LList () {
        if ( head ) {
            delete head;}
            head=tail = NULL;
            size=0;
    }
    LLNodeP insert (const T & d , LLNodeP after){
        if (head == NULL || after == NULL){
            return insert(d);
        }
        else{
            LLNodeP n = new LLNode(d, after->next);
            after->next = n;
            if (tail == after){
                tail = n;
            }
            size++;
            return n;
        }
    }
    void append(LList & ol){
        if (head == NULL){
            head = ol.head;
            tail = ol.tail;
        }
        if (ol.head == NULL){
            return;
        }
        else{
            tail->next = ol.head;
            tail = ol.tail;
        }
        size += ol.size;
        ol.head = NULL;
        ol.tail = NULL;
        ol.size = 0;

    }
    LLNodeP insertInPlace(const T & d){
        if (head == NULL){return insert(d);}
        else if (head->data > d){return insert(d);}
        LLNodeP temp = head;
        while (temp->next != NULL && temp->next->data < d){
            temp = temp->next;
        }
        return insert(d,temp)
    }
void merge(LList& ol) {
    LLNodeP *prev = &head;
    LLNodeP point1 = head;
    LLNodeP point2 = ol.head;
    size += ol.size;
    while (point1 && point2) {
        if (point1->data < point2->data) {
            *prev = point1;
            point1 = point1->next;
        } else {
            *prev = point2;
            point2 = point2->next;
        }
        prev = &((*prev)->next);
    }
    if (point1 != NULL){*prev = point1;} else{*prev = point2;}
    if (point2 != NULL){tail = ol.tail;}
    ol.head = ol.tail = nullptr;
    ol.size = 0;
}
};

/*This is the problem tackled by the well known Floyd's cycle detection algorithm, the way it works it rather simple

you start with two pointer to head we call on "slow" and the other "fast", we use these two pointers to traverse the llist
however the slow moves 1 node at a time while fast moves 2, if there is a cycle then eventually the two pointers will point to the same node
otherwise fast would reach a null pointer and that means there is no cycle

code:

slow := head 
fast := head
while (fast != NULL and fast.next != null){
slow = slow.next
fast = fast.next.next
if (slow == fast) return true
}
return false */