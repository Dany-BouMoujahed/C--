// this is file llnode . h
#pragma once
class LLNode { 
    private :
    T _d ; // data
    LLNode * _next ; // pointer to next
    LLNode * _prev ;// pointer to prev
    protected:
    LLNode (const T & d, LLNode * next = NULL, LLNode * prev = NULL) : _d ( d ) , _next ( next ), _prev ( prev ){}
    T & data () {return _d ;}
    LLNode *& next () { return _next ;}
    LLNode *& prev () { return _prev ;}
    void
    printRec(ostream & os) {
        if ( this == NULL ) {return ;}
        os << _d << " " ;
        _next -> printRec (os);}
    ~LLNode () {
    if (_next){
        delete _next;} 
    }
    friend class LList ;
};