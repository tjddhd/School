/*!\file COLLECTION.h
 * \author Jennifer Leopold
 * \brief a virtual collection class
 */
#ifndef COLLECTION_H
#define COLLECTION_H

template <class T>
class COLLECTION {
protected:
  unsigned int m_size;
  
public:
  COLLECTION() : m_size(0) {}
  
  virtual void clear() = 0;
  virtual bool find(const T& x) const = 0;
  
  bool isEmpty() const { return m_size==0;}
  unsigned int size() const { return m_size; }
};

#endif // COLLECTION.h


