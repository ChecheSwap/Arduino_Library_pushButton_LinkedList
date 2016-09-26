#ifndef xbutton_H
#define xbutton_H
#include <Arduino.h>

typedef struct globalelement
{
    int myid;
    void (*callx)(void);
    char * datamsg;
    struct globalelement * next;
}element;

typedef struct myembeddedlist
{
    element * first;
    element * last;
    int countext;

}xlist;
class xbutton
{
public:
    xbutton(int);
    xbutton(int,char[]);
    xbutton(int,char[],void(*)());
    ~xbutton(void);
    void check(void);
    void add(char[],void(*)());
    void setText(char *);
private:
    int first, now;
    xlist* (memorycapt)();
    void initialize(xlist *);
    void (*call)();
    int _pin;
    xlist * mylist;
    char *mensaje;
    void internalcheck(void);
    void freememory();
    void setvalues(void);
};
#endif
