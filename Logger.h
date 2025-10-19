#pragma once
#include <string>

#include "noncopyable.h"

// '\'是换行符
//"##__VA_ARGS__"获取变参列表
// LOG_INFO ("%s %d", arg1, arg2)
#define LOG_INFO(logmsgFormat, ...) \
    do \
    {\
        Logger &logger = logger::instance();\
        logger.setLogLevel(INFO);\
        char buf[1024] = {0};\
        snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__);\
        logger.log(buf); \
    }while(0)

#define LOG_ERROR(logmsgFormat, ...) \
    do \
    {\
        Logger &logger = logger::instance();\
        logger.setLogLevel(ERROR);\
        char buf[1024] = {0};\
        snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__);\
        logger.log(buf); \
    }while(0)

#define LOG_FATAL(logmsgFormat, ...) \
    do \
    {\
        Logger &logger = logger::instance();\
        logger.setLogLevel(FATAL);\
        char buf[1024] = {0};\
        snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__);\
        logger.log(buf); \
    }while(0)


#ifdef MUDUBUG
#define LOG_DEBUG(logmsgFormat, ...) \
    do \
    {\
        Logger &logger = logger::instance();\
        logger.setLogLevel(DEBUG);\
        char buf[1024] = {0};\
        snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__);\
        logger.log(buf); \
    }while(0)
#else
    #define LOG_DEBUG(logmsgFormat, ...)
#endif

//定义日志级别 INFO ERROR FATAL DEBUG
enum LogLevel
{
    INFO, //普通信息
    ERROR,  //错误信息
    FATAL,  //core信息
    DEBUG, //调试信息
};

//日志类
class Logger : noncopyable
{
public:
    // 获取日志唯一实例对象
    static Logger& instance();
    // 设置日志级别
    void setLogLevel(int Level);
    // 写日志
    void log(std::string msg);
private:
    int logLevel_;
    Logger(){}
};