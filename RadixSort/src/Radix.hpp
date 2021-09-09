class Number {
    private:
        int value;
        Number* next;
        Number* prev;
    public:
        // Number(); // undefined reference to `Number::Number()`
        Number() {};
        Number(int v): value(v) {};
        ~Number() {};
        Number(const Number& other): value(other.value), next(other.next), prev(other.prev) {};
        Number& operator=(const Number& other) {
            value = other.value;
            next = other.next;
            prev = other.prev;

            return *this;
        }
        int iAt(int); // return value at given position;
        int getValue() { return value; };
        Number* getNext() { 
            if(next) 
                return next; 
            return nullptr; 
        }
        Number* getPrev() { 
            if(prev) 
                return prev; 
            return nullptr; 
        }
        void setNext(Number* n) { next = n; }
        void setPrev(Number* p) { prev = p; }
};

