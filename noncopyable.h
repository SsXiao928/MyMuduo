#pragma once

//被继承后派生类对象可以正常的析构和构造， 但派生类对象
//无法进行拷贝构造和赋值操作
class noncopyable{
public:

    noncopyable(const noncopyable&) = delete;
    noncopyable& operator=(const noncopyable&) = delete;
protected:
    noncopyable() = default;
    ~noncopyable() = default;
};