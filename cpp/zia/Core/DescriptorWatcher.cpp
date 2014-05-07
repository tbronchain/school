//

#include <iostream>
#include "DescriptorWatcher.h"

DescriptorWatcher::DescriptorWatcher(unsigned int descMax) :
        descMax_(descMax),
        pollTable_(new ABSPOLLTABLE[descMax])
{
}

DescriptorWatcher::~DescriptorWatcher()
{
    delete [] this->pollTable_;
}

void DescriptorWatcher::build()
{
    this->currDescNb_ = 0;
    while (!this->askDescriptors_.empty())
    {
        int events = 0;
        if (this->askDescriptors_.front().getRead())
            events = events | POLLIN;
        if (this->askDescriptors_.front().getWrite())
            events = events | POLLOUT;
        this->pollTable_[currDescNb_].fd = this->askDescriptors_.front().getDescriptor();
        this->pollTable_[currDescNb_].events = events;
        this->currDescNb_++;
        this->askDescriptors_.pop_front();
    }
}

void DescriptorWatcher::resetDescriptorConfDeque(std::deque<DescriptorConf>& que)
{
    while (!que.empty())
        que.pop_front();
}
void DescriptorWatcher::watch(int timeout)
{
    this->build();
    if (ABSPOLL(this->pollTable_, this->currDescNb_, timeout) < 0)
        std::cerr << "poll err" << std::endl;
    this->unBuild();
}

void DescriptorWatcher::unBuild()
{
    this->resetDescriptorConfDeque(this->readyDescriptors_);
    for (int i = 0; i< this->currDescNb_ ; i++)
    {
        DescriptorConf cf;
        cf.setDescriptor(this->pollTable_[i].fd);
        if (this->pollTable_[i].revents & (POLLERR | POLLNVAL | POLLHUP))
            cf.setReadyError();
        if (this->pollTable_[i].revents & (POLLOUT))
            cf.setReadyWrite();
        if (this->pollTable_[i].revents & (POLLIN))
            cf.setReadyRead();
        this->readyDescriptors_.push_back(cf);
    }
}

std::deque<DescriptorConf>& DescriptorWatcher::getAskDeque()
{
    return this->askDescriptors_;
}

std::deque<DescriptorConf>& DescriptorWatcher::getReadyDeque()
{
    return this->readyDescriptors_;
}
