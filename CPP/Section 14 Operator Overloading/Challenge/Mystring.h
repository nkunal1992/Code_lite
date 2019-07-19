#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);
    //added by me for global method
    friend Mystring operator - (const Mystring &rhs);
    friend bool operator == (const Mystring &lhs,const Mystring &rhs);
    friend bool operator != (const Mystring &lhs,const Mystring &rhs);
    friend bool operator < (const Mystring &lhs,const Mystring &rhs);
    friend bool operator > (const Mystring &lhs,const Mystring &rhs);
    friend Mystring operator + (const Mystring &lhs,const Mystring &rhs);
    friend void operator += (Mystring &lhs,const Mystring &rhs);
    friend Mystring operator * (const Mystring &lhs,unsigned int n);
    friend void operator *= (Mystring &lhs,unsigned int n);
    friend Mystring &operator++(Mystring &obj);
    friend Mystring operator++(Mystring &obj,int);

private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                                         // No-args constructor
    Mystring(const char *s);                                     // Overloaded constructor
    Mystring(const Mystring &source);                    // Copy constructor
    Mystring( Mystring &&source);                         // Move constructor
    ~Mystring();                                                     // Destructor
    
    Mystring &operator=(const Mystring &rhs);     // Copy assignment
    Mystring &operator=(Mystring &&rhs);           // Move assignment
    
    //added by me for member method
    /*
    Mystring operator - ();
    bool operator == (const Mystring &rhs)const;
    bool operator != (const Mystring &rhs)const;
    bool operator < (const Mystring &rhs)const;
    bool operator > (const Mystring &rhs)const;
    Mystring operator + (const Mystring &rhs);
    void operator += (const Mystring &rhs);
    Mystring operator * (unsigned int n);
    void operator *= (unsigned int n);
    Mystring &operator++();
    Mystring operator++(int);
    //end added by me
    */
    void display() const;
    
    int get_length() const;                                      // getters
    const char *get_str() const;
};

#endif // _MYSTRING_H_