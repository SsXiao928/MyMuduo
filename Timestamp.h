#pragma once

#include <iostream>
#include <string>

class Timestamp
{
public:
    Timestamp();
    //单参数构造函数会发生隐式类型转换，所以需要explicit避免隐式类型转换
    explicit Timestamp(int64_t microSecondsSinceEpoch);
    static Timestamp now();
    std::string toString() const;
private:
    int64_t microSecondsSinceEpoch_;
};