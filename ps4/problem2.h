#include <iostream>
using namespace std;
class LList_Interface;
template <class T>
class LList {
  friend class LList_interface;
  public:
    class LLNode {
        friend class LList_Interface;
        private :
        T _d ; // data
        LLNode * _next; // pointer to next
        protected:
        LLNode (const T & d, LLNode * next = NULL) : _d ( d ) , _next ( next ){}
        T & data () {return _d;}
        public:
        void printRec(ostream & os) {
            if (this == NULL) {return;}
            os << _d << " " ;
            if (_next)
            _next -> printRec (os);}
        ~LLNode () {
        if (_next){
            delete _next;} 
        }
        LLNode* & next () {return _next;}
        friend class LList<T>;
};
  public:
    typedef LLNode *LLNodeP;
    LLNodeP head;
    LLNodeP tail;
    unsigned int size;
    LList () : head (0) , tail (0) , size(0) {}
    LLNodeP insert (const T& d) {
    LLNodeP n=new LLNode (d,head);
    if ( head == NULL ) { tail =n ;}
    head = n; 
    size = size +1;
    return n;
    }
    LList & operator << (const T & d){
        insert (d);
        return *this;
    }
    void print (ostream & os){
        LLNodeP n = head;
        while ( n != NULL ){
        os << n-> data () << " ";
        n=n->next ();
        }
    }
    ~LList (){
        if (head){delete head;}
        head=tail = NULL;
        size=0;
    }
    LLNodeP insert (const T & d , LLNodeP after){
        if (head == NULL || after == NULL){return insert(d);}
        else{
            LLNodeP n = new LLNode(d, after->next());
            after->next() = n;
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
            tail->next() = ol.head;
            tail = ol.tail;
        }
        size += ol.size;
        ol.head = NULL;
        ol.tail = NULL;
        ol.size = 0;
    }
    LLNodeP insertInPlace(const T & d){
        if (head == NULL){return insert(d);}
        else if (head->data() > d){return insert(d);}
        LLNodeP temp = head;
        while (temp->next() != NULL && temp->next()->data() < d){
            temp = temp->next();
        }
        return insert(d,temp);
    }
    void merge(LList& ol) {
    LLNodeP *prev = &head;
    LLNodeP point1 = head;
    LLNodeP point2 = ol.head;
    size += ol.size;
    while (point1 && point2) {
        if (point1->data() < point2->data()) {
            *prev = point1;
            point1 = point1->next();
        } else {
            *prev = point2;
            point2 = point2->next();
        }
        prev = &((*prev)->next());
    }
    if (point1 != NULL){*prev = point1;} else{*prev = point2;}
    if (point2 != NULL){tail = ol.tail;}
    ol.head = ol.tail = nullptr;
    ol.size = 0;
    }
    LLNodeP removeAfter(LLNodeP after){
    if (size <= 0){
        return NULL;
    }
    if (after == NULL){
        size--;
        LLNodeP n = head;
        head = head->next();
        n->next() = NULL;
        return n;
    }
    LLNodeP n = after->next();
    if (after == tail){
        return NULL;
    }
    if (n == NULL){
        return NULL;
    }
    if (n == tail){
        tail = after;
    }
    after->next() = n->next();
    n->next() = NULL;
    size--;
    return n;
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
