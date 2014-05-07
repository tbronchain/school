# ifndef CIRCULAR_BUFFER_CONTAINER
# define CIRCULAR_BUFFER_CONTAINER

namespace CBContainerSearch
{
  enum AnsDescription
    {
      NOT_MATCHED,
      MATCHED_PARTIALY_ON_END,
      FULLY_MATCHED
    };
  struct Ans
  {
    unsigned int	blocksReadBuffer;
    unsigned int	blocksSearchBuffer;
    AnsDescription	description;
  };
}

template <typename T>
class CircularBufferContainer
{
public:
  CircularBufferContainer(unsigned int buffLength) :
    circularBufferBegin_(new T[buffLength + 1]),
    circularBufferEnd_(circularBufferBegin_ + buffLength),
    readPtr(circularBufferBegin_),
    writePtr(circularBufferBegin_),
    empty(true){}
  
  unsigned int write(const T *buffSource, unsigned int nbWrite)
  {
    unsigned int iNbWrite = 0;
    
    if ((!empty) && (this->readPtr == this->writePtr))
      return 0;
        else if (nbWrite > 0)
	  {
            while (true)
	      {
                if (this->writePtr == this->circularBufferEnd_)
		  this->writePtr = this->circularBufferBegin_;
                if (((this->readPtr != this->writePtr) || ((empty) && (iNbWrite  == 0)))
                    && (iNbWrite < nbWrite))
		  *this->writePtr++ = buffSource[iNbWrite++];
                else
		  {
                    if (iNbWrite > 0)
		      this->empty = false;
                    break;
                }
	      }
	  }
    return iNbWrite;
  }
  
  unsigned int read(T *buffTo, unsigned int nbRead)
  {
    unsigned int iNbRead = 0;
        if ((empty) && (this->readPtr == this->writePtr))
            return 0;
        else if (nbRead > 0)
        {
            while (true)
            {
                if (this->readPtr == this->circularBufferEnd_)
                    this->readPtr = this->circularBufferBegin_;
                if (((this->readPtr != this->writePtr) || ((!empty) && (iNbRead  == 0)))
                    && (iNbRead < nbRead))
                    buffTo[iNbRead++] = *this->readPtr++;
                else
                {
                    if ((this->readPtr == this->writePtr) && iNbRead > 0)
                        this->empty = true;
                    break;
                }
            }
        }
        return iNbRead;
    }

    unsigned int getSize() const
    {
        unsigned int iNbRead = 0;
        T *fakeReadPtr = this->readPtr;
        if ((empty) && (fakeReadPtr == this->writePtr))
            return 0;
        while (true)
        {
            if (fakeReadPtr == this->circularBufferEnd_)
                fakeReadPtr = this->circularBufferBegin_;
            if ((fakeReadPtr != this->writePtr) || ((!empty) && (iNbRead  == 0)))
            {
                ++iNbRead;
                ++fakeReadPtr;
            }
            else
                break;
        }
        return iNbRead;
    }
  
  
  CBContainerSearch::Ans  findFromArray(const T *buffSearch, unsigned int length)
  {
    unsigned int iNbRead = 0;
    T *fakeReadPtr = this->readPtr;
    if ((empty) && (fakeReadPtr == this->writePtr))
      {
	CBContainerSearch::Ans awnser;
	awnser.description =  CBContainerSearch::NOT_MATCHED;
	awnser.blocksReadBuffer  = iNbRead;
	awnser.blocksSearchBuffer = 0;
	return awnser;
      }

    while (true)
      {
	if (fakeReadPtr == this->circularBufferEnd_)
	  fakeReadPtr = this->circularBufferBegin_;
	if ((fakeReadPtr != this->writePtr) || ((!empty) && (iNbRead  == 0)))
	  {
	    CBContainerSearch::Ans awnser = this->recursiveFindOnChar(fakeReadPtr , buffSearch, 0, length);
	    
	    if (awnser.description != CBContainerSearch::NOT_MATCHED)
	      {
		awnser.blocksReadBuffer  = iNbRead;
		return awnser;
	      }
	    ++iNbRead;
	    ++fakeReadPtr;
	  }
	else
	  break;
      }
    CBContainerSearch::Ans awnser;
    awnser.description =  CBContainerSearch::NOT_MATCHED;
    awnser.blocksReadBuffer  = iNbRead;
    awnser.blocksSearchBuffer  = 0;
    return awnser;
  }

  CBContainerSearch::Ans  recursiveFindOnChar(T *fakeReadPtr, const T *buffSearch, unsigned int lengthRun, unsigned int lengthTotal)
  {
    if (fakeReadPtr == this->circularBufferEnd_) 
      fakeReadPtr = this->circularBufferBegin_;
    if ((fakeReadPtr == this->writePtr) && (lengthRun > 0))
      {
	CBContainerSearch::Ans ans;
	ans.description = CBContainerSearch:: MATCHED_PARTIALY_ON_END;
	ans.blocksSearchBuffer  = lengthRun;
	return ans;
      }
    if (lengthRun <= lengthTotal)
      {
	if (*fakeReadPtr == buffSearch[lengthRun])
	  {
            if (lengthRun == lengthTotal - 1)
	      {
		CBContainerSearch::Ans ans;
		ans.description  =  CBContainerSearch::FULLY_MATCHED;
		ans.blocksSearchBuffer  = lengthRun;
		return ans;
	      }
	    else
	      {
		return (recursiveFindOnChar(fakeReadPtr + 1, buffSearch, lengthRun  + 1, lengthTotal));
	      }
	  }
      }
    CBContainerSearch::Ans ans;
    ans.description =  CBContainerSearch::NOT_MATCHED;
    ans.blocksSearchBuffer = lengthRun;
    return ans;
  }

  void reset()
  {
    this->readPtr = this->writePtr;
    this->empty = true;
  }
  
  bool isEmpty()
  {
    return this->empty;
  }
    ~CircularBufferContainer()
  {
    delete [] this->circularBufferBegin_;
  }
  
private:
  T		*circularBufferBegin_;
  T		*circularBufferEnd_;
  T		*readPtr;
  T		*writePtr;
  bool		empty;
};
# endif //CIRCULAR_BUFFER_CONTAINER
