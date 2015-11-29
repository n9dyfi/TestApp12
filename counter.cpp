#include "counter.h"

Counter::Counter(QObject *parent) :
    QObject(parent)
{
    myValue = -1;
}

void Counter::setValue(int v)
{
    if (v == myValue)
        return;
    myValue = v;
    emit valueChanged(myValue);
}

void Counter::increment()
{
    emit valueChanged(++myValue);
}

void Counter::decrement()
{
    emit valueChanged(--myValue);
}
