//
// Created by 冯鸿杰 on 2018/7/2.
//

#include "LuaOperationQueue.h"



using namespace cn::vimfung::luascriptcore;

LuaOperationQueue::LuaOperationQueue()
{
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&_lock, &attr);
    pthread_mutexattr_destroy(&attr);
}

LuaOperationQueue::~LuaOperationQueue()
{
    pthread_mutex_destroy(&_lock);
}

void LuaOperationQueue::performAction(std::function<void(void)> const& action)
{
    pthread_mutex_lock(&_lock);
    action();
    pthread_mutex_unlock(&_lock);
}
