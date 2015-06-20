#include "singleton.h"
#include <iostream>

using namespace std;

Singleton *Singleton::GetInstance() {
    if (instance_ != NULL)
        return instance_;
    instance_ = new Singleton;
    instance_->value_ = 0;
    return instance_;
}
bool Singleton::DeleteInstance() {
    if (instance_ == NULL)
        return false;
    delete instance_;
    return true;
}
void Singleton::SetValue(int value) {
    instance_->value_ = value;
}
int Singleton::GetValue() {
    return instance_->value_;
}
