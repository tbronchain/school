
# ifndef CIRCULAR_BUFFER_HPP
# define CIRCULAR_BUFFER_HPP

# include <list>
# include "CircularBufferContainer.hpp"

static const unsigned int reset_nb_max_container = 10;

template <typename T>
        class CircularBuffer
{
public:
  CircularBuffer(unsigned int containerSize) :
    containerSize_(containerSize)
  {
    /*Do not remove the only allocation*/
    this->circularBufferContainerList_.push_back(new CircularBufferContainer<T>(this->containerSize_));
    this->writeIt_ = this->circularBufferContainerList_.begin();
    this->readIt_ = this->circularBufferContainerList_.begin();
  }
  
  void	       writeReplaceIterator()
  {
    typename std::list<CircularBufferContainer<T> * >::iterator itEnd = this->circularBufferContainerList_.end();
    if ((this->readIt_ == this->writeIt_) && (!(*this->readIt_)->isEmpty()))
      {
	this->circularBufferContainerList_.insert(this->readIt_, new CircularBufferContainer<T>(this->containerSize_));
	this->writeIt_--;
      }
    else if (this->writeIt_ == itEnd)
      {
	    if ((*this->circularBufferContainerList_.begin())->isEmpty())
	      this->writeIt_ = this->circularBufferContainerList_.begin();
            else
	      {
                this->circularBufferContainerList_.insert(this->circularBufferContainerList_.begin() , new CircularBufferContainer<T>(this->containerSize_));
                this->writeIt_ = this->circularBufferContainerList_.begin();
	      }
      }
  }
  
  unsigned int write(const T *buffSource, unsigned int nbWrite)
  {
    unsigned int iNbWrite = 0;
    
    while (true)
      {
	this->writeReplaceIterator();
	if (iNbWrite < nbWrite)
	  iNbWrite += (*this->writeIt_)->write(buffSource + iNbWrite, nbWrite - iNbWrite);
	else
	  break;
	this->writeIt_++;
      }
    return iNbWrite;
  }
  
  void	       readReplaceIterator()
  {
    if (this->readIt_ == this->circularBufferContainerList_.end())
      this->readIt_ = this->circularBufferContainerList_.begin();
  }
  
  unsigned int read(T *buffTo, unsigned int nbRead)
  {
    unsigned int iNbRead = 0;
    while (true)
      {	
	this->readReplaceIterator();
	if ((iNbRead < nbRead) && (!(*this->readIt_)->isEmpty()))
	  {
	    iNbRead += (*this->readIt_)->read(buffTo + iNbRead, nbRead - iNbRead);
	  }
	else
	  break;
	if (((*this->readIt_)->isEmpty()))
	  this->readIt_++;
      }
    return iNbRead;
  }

  int	findFromArray(const T *buffSearch, unsigned int length)
  {
    int nbFind = 0;
    typename std::list<CircularBufferContainer<T> * >::iterator it = this->readIt_;
    while (true)
      {
	//replace it
	if (it == this->circularBufferContainerList_.end())
	  it = this->circularBufferContainerList_.begin();
	//end replace it
	
	CBContainerSearch::Ans awnser = (*it)->findFromArray(buffSearch, length);
	nbFind += awnser.blocksReadBuffer;
	if (awnser.description == CBContainerSearch::FULLY_MATCHED)
	  return nbFind;
	else if (awnser.description == CBContainerSearch::MATCHED_PARTIALY_ON_END)
	  {
	    if(this->findFromArrayRec(buffSearch + awnser.blocksSearchBuffer, length - awnser.blocksSearchBuffer , it))
	      return nbFind;
	    nbFind += awnser.blocksSearchBuffer;
	  }
	if (it == this->writeIt_)
	  break;
	it++;
      }
    return -1;
  }  

  bool	findFromArrayRec(const T *buffSearch, unsigned int length, typename std::list<CircularBufferContainer<T> * >::iterator it)
  {
    if (it != this->circularBufferContainerList_.end())
      it++;
    
    //replace it
    if (it == this->circularBufferContainerList_.end())
      it = this->circularBufferContainerList_.begin();
    
    CBContainerSearch::Ans awnser = (*it)->findFromArray(buffSearch, length);
    if (awnser.description == CBContainerSearch::FULLY_MATCHED)
      return true;
    else if (awnser.description == CBContainerSearch::MATCHED_PARTIALY_ON_END && it != this->writeIt_)
      return this->findFromArrayRec(buffSearch + awnser.blocksSearchBuffer , length - awnser.blocksSearchBuffer , it);
    return false;
  }
  
  void reset()
  {
      while (this->circularBufferContainerList_.begin() != this->circularBufferContainerList_.end())
      {
          delete (*this->circularBufferContainerList_.begin());
          this->circularBufferContainerList_.erase(this->circularBufferContainerList_.begin());
      }
      this->circularBufferContainerList_.push_back(new CircularBufferContainer<T>(this->containerSize_));
      this->writeIt_ = this->circularBufferContainerList_.begin();
      this->readIt_ = this->circularBufferContainerList_.begin();
  }
  
  unsigned int getSize()
    {
      unsigned int size = 0;
      typename std::list<CircularBufferContainer<T> * >::iterator it = this->circularBufferContainerList_.begin();
      while (it != this->circularBufferContainerList_.end())
	{
	  if (!(*it)->isEmpty())
	    size += (*it)->getSize();
	  it++;
	}
      return size;
    }

    ~CircularBuffer()
    {
        while (this->circularBufferContainerList_.begin() != this->circularBufferContainerList_.end())
        {
            delete (*this->circularBufferContainerList_.begin());
            this->circularBufferContainerList_.erase(this->circularBufferContainerList_.begin());
        }
    }

private:
    std::list<CircularBufferContainer<T> * >			circularBufferContainerList_;
    typename std::list<CircularBufferContainer<T> * >::iterator	readIt_;
    typename std::list<CircularBufferContainer<T> * >::iterator	writeIt_;
    unsigned int						containerSize_;
};
# endif
