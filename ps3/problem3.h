const int ORIGINAL_CAPACITY = 16;
const int GROW_FACTOR = 2;

template<typename T>
class DynArr {
    T* data;
    int size;
    int capacity;
public:
    DynArr() : size(0), capacity( ORIGINAL_CAPACITY ) { // preallocate memory
    data = new T[capacity];}
    void insert( const T & t ) {
        if ( size >= capacity ) { // grow the array
            int newCapacity = capacity * GROW_FACTOR;
            T* newData = new T[ newCapacity ];
            for ( int i = 0; i < size; i++ ) {
                newData[ i ] = data[ i ]; // copy old data
            }
            delete[] data; // discard old memory
            data = newData; // point to the new data
            capacity = newCapacity; // set capacity
        }

        data[ size ] = t; // place new element
        size = size + 1; // increment size
    }
};
