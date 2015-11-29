#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>

class Counter : public QObject
{
    Q_OBJECT
public:
    explicit Counter(QObject *parent = 0);

signals:
    void valueChanged(int value);

public slots:
    void setValue(int v);
    void increment();
    void decrement();

private:
    int myValue;

};

#endif // COUNTER_H
