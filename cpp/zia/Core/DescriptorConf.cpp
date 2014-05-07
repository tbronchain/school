//

#include "DescriptorConf.h"

DescriptorConf::DescriptorConf()
{
    this->flagIn_ = 0;
    this->flagOut_ = 0;
}

DescriptorConf::~DescriptorConf()
{
}

void DescriptorConf::setDescriptor(const int descriptor)
{
    this->descriptor_ = descriptor;
}

int DescriptorConf::getDescriptor()
{
    return this->descriptor_;
}

void DescriptorConf::setRead()
{
    this->flagIn_ = this->flagIn_ | SET_READ;
}

void DescriptorConf::setWrite()
{
    this->flagIn_ = this->flagIn_ | SET_WRITE;
}

void DescriptorConf::setError()
{
    this->flagIn_ = this->flagIn_ | SET_ERROR;
}

void DescriptorConf::setReadyRead()
{
    this->flagOut_ = this->flagOut_ | READY_READ;
}

void DescriptorConf::setReadyWrite()
{
    this->flagOut_ = this->flagOut_ | READY_WRITE;
}

void DescriptorConf::setReadyError()
{
    this->flagOut_ = this->flagOut_ | READY_ERROR;
}

bool DescriptorConf::getRead()
{
    return ((this->flagIn_ & SET_READ) ? true : false);
}

bool DescriptorConf::getWrite()
{
    return ((this->flagIn_ & SET_WRITE) ? true : false);
}

bool DescriptorConf::getError()
{
    return ((this->flagIn_ & SET_ERROR) ? true : false);
}

bool DescriptorConf::readyRead()
{
    return ((this->flagOut_ & READY_READ) ? true : false);
}

bool DescriptorConf::readyWrite()
{
    return ((this->flagOut_ & READY_WRITE) ? true : false);
}

bool DescriptorConf::readyError()
{
    return ((this->flagOut_ & READY_ERROR) ? true : false);
}
