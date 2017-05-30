#include <Arduino.h>
#include <xbutton.h>
//@Code By: Jesus Jose Navarrete Baca
xbutton::xbutton(int pin, char*mensaje, void(*call)())
:_pin(pin){
    this -> mensaje = mensaje;
    this -> call = call;
    this->setvalues();
}

xbutton::xbutton(int pin, char*mensaje)
:_pin(pin){
    this -> mensaje = mensaje;
    this -> call = NULL;
    this->setvalues();
}

xbutton::xbutton(int pin)
:_pin(pin)
{
    this -> mensaje = NULL;
    this -> call = NULL;
    this->setvalues();
}
void xbutton::setvalues(void)
{
    pinMode(_pin,INPUT_PULLUP);
    this->initialize(memorycapt());
    this->first=HIGH;
    this->now=HIGH;
}

void xbutton::initialize(xlist * listx)
{
    listx->first = NULL;
    listx->last = NULL;
    listx->countext = 0;
}

xlist* xbutton::memorycapt()
{
    if(!(this->mylist != NULL))
    {
        this->mylist = new xlist();
    }

    return this->mylist;
}

void xbutton::setText(char * text)
{
    this->mensaje = text;
}

void xbutton::check(void)
{
    this->now = digitalRead(_pin);

    if((!now)&&(first))
    {
        Serial.println(mensaje);
        if(!(NULL == call))
            call();
            this->internalcheck();
    }
    this->first = this->now;
}
void xbutton::add(char msg[], void(*callx)(void))
{
    element * newelement = new element();
    newelement->datamsg = msg;
    newelement->callx=callx;
    newelement->next = this->mylist->first;
    this->mylist->first = newelement;
    this->mylist->countext++;
    newelement->myid = this->mylist->countext;
}

void xbutton::internalcheck(void)
{
    element * temp = this->mylist->first;
    while(!(NULL == temp))
    {
        Serial.println(temp->datamsg);
        temp->callx();
        temp = temp->next;
    }
}

void xbutton::freememory(void)
{
    element * temp = this->mylist->first;
    while(!(NULL==temp))
    {
        this->mylist->first = this->mylist->first->next;
        free(temp);
        temp = this->mylist->first;
    }
}

xbutton::~xbutton(void)
{
    this->freememory();
}
