template <class dataType>
NODE<dataType>::NODE() {
  data = dataType();
  next = NULL;
}

template <class dataType>
NODE<dataType>::NODE(const dataType& initData, 
		     NODE* initNext) {
  data = initData;
  next = initNext;
}

template <class dataType>
NODE<dataType>::NODE(const NODE& otherNode) {
  data = otherNode.data;
  next = otherNode.next;
}

template <class dataType>
const dataType& NODE<dataType>::getData() const { return(data); }

template <class dataType>
NODE<dataType>* NODE<dataType>::getNext() { return(next); }       

template <class dataType>
void NODE<dataType>::setData(const dataType& x) { data = x; }

template <class dataType>
void NODE<dataType>::setNext(NODE* newNext) { next = newNext; }

template <class dataType>
NODE<dataType>& NODE<dataType>::operator = (const NODE& rhs) {
  if (&rhs != this) {
    this->setData(rhs.data);
    this->setNext(rhs.next);
  }
  return(*this);
}

