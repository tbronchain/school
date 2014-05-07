#ifndef _OBJECT_POOL_HPP_
# define _OBJECT_POOL_HPP_

# include <iostream>
# include <map>

template <typename T>
class ObjectPool
{
public:
  ObjectPool()
  {
  }
  
  ~ObjectPool()
  {
    while (this->freeObjs_.begin() != this->freeObjs_.end())
      {
		delete this->freeObjs_.begin()->first;
		this->freeObjs_.erase(this->freeObjs_.begin());
      }
    if (this->usedObjs_.begin() != this->usedObjs_.end())
	std::cerr << "Not all objects has been releases --> OBJECTPOOL" << std::endl;
  }
  
  T* getObj()
  {
    if (this->freeObjs_.begin() != this->freeObjs_.end())
      {
		T* obj = this->freeObjs_.begin()->first; 
		this->freeObjs_.erase(this->freeObjs_.begin());
		this->usedObjs_[obj] = obj;
		return (obj);
      }
    return 0;
  }
  

  void releaseObj(T* obj)
  {
    typename std::map<T *, T * >::iterator itFind = this->usedObjs_.find(obj);
    if (itFind != this->usedObjs_.end())
      {
		this->usedObjs_.erase(itFind);
		this->freeObjs_[obj] = obj;
      }
  }
  
  void putNewObjInFreeMap(T* obj)
  {
    this->freeObjs_[obj] = obj;
  }
  void putNewObjInUsedMap(T* obj)
  {
    this->usedObjs_[obj] = obj;
  }
 
private:
  std::map<T *, T*>	freeObjs_;
  std::map<T *, T*>	usedObjs_;
};

#endif // !_OBJECT_POOL_HPP_
