/*!\file HASHTABLE.hpp
 * \author Lisa Tatro
 * \brief class definition for a hash table
 */

 
 template <class KeyType, class DataType>
 HASHTABLE<KeyType, DataType>::HASHTABLE(unsigned int n)
 {
    m_capacity = n;
    table_ptr = new HASH_NODE<KeyType, DataType>[ n ];
	
	if( !table_ptr )
      throw std::bad_alloc();
	  
	/*for( int i = 0; i < n; i++)
    {
	  table_ptr[i] = NEVER_USED;
    }*/
	iterator = table_ptr;
 }
 
  template <class KeyType, class DataType>
  void HASHTABLE<KeyType, DataType>::clear()
  {
      delete [] table_ptr;
	  table_ptr = NULL;
	  iterator = NULL;
	  m_capacity = 0;
	  COLLECTION<DataType>::m_size = 0;
  }
  
  template <class KeyType, class DataType>
  bool HASHTABLE<KeyType, DataType>::find(const DataType& x) const
  {
    HASH_NODE<KeyType,DataType>* temp = table_ptr;
    for(int i = 0; i < m_capacity; i++)
	{
	  if( x == temp -> m_data)
	    return true;
	  else
	    temp++;
	}
	return false;
  }
  
  template <class KeyType, class DataType>
  bool HASHTABLE<KeyType, DataType>::find(const KeyType& key, int& position)
  {
    iteratorReset();
	if( position  >= 0)
	{
	  iterator = table_ptr + position;
	  if( iterator -> m_key == key)
	    return true;
	  else 
	    return false;
	}
	throw std::out_of_range("Please give me a positive position.");
	
  }
  
  template <class KeyType, class DataType>
  const DataType HASHTABLE<KeyType, DataType>::operator[] (const KeyType& key)
  {
    DataType datum;
    int index = 0;
	bool found = false;
    iteratorReset();
	while( !found  && index < m_capacity)
	{
	  if( iterator -> m_key == key)
	  {
	    datum = iteratorGetNext();
		found = true;
	  }
	  index++;
	}
	return datum;
  }
  
  template <class KeyType, class DataType>
  void HASHTABLE<KeyType, DataType>::insert(const KeyType& key, const DataType& data)
  {
	if(COLLECTION<DataType>::m_size != m_capacity)
	{
	  int position = hash(key);
	  iterator = table_ptr + position;
	  if(iterator -> m_key == NEVER_USED || iterator -> m_key == PREV_USED 
	        || iterator -> m_key == key)
	  {
	    iterator -> m_key = key;
		iterator -> m_data = data;
	    COLLECTION<DataType>::m_size++;
	  }
	  else
	  {
	    bool inserted = false;
	    while( !inserted)
		{
		  iterator++;
		  if(iterator -> m_key == NEVER_USED || iterator -> m_key == PREV_USED 
	          || iterator -> m_key == key)
		  {
		    iterator -> m_key = key;
			iterator -> m_data = data;
			COLLECTION<DataType>::m_size++;
			inserted = true;
		  }
		}
	  }
	}
	else
	  throw length_error("The hash table is full.");
  }
  
  template <class KeyType, class DataType>
  void HASHTABLE<KeyType, DataType>::remove(const KeyType& key)
  {
    bool found = false;
	int index = 0;
    iteratorReset();
	while(!found && index < m_capacity)
	{
	  if(iterator -> m_key == key)
	  {
	    iterator -> m_key = PREV_USED;
		iterator -> m_data = PREV_USED;
		COLLECTION<DataType>::m_size--;
	  }
	  index++;
	}
	
  }
  
  template <class KeyType, class DataType>
  void HASHTABLE<KeyType, DataType>::iteratorReset()
  {
    if( !table_ptr)
	  throw std::out_of_range("");
	  
	iterator = table_ptr;
  }
  
  template <class KeyType, class DataType>
  const DataType& HASHTABLE<KeyType, DataType>::iteratorGetNext()
  {
    HASH_NODE<KeyType, DataType>* temp = NULL;
    if( iterator != NULL)
	{
	  temp = iterator;
      if( iterator == (m_capacity - 1) + table_ptr)
      {
	    iterator = table_ptr;
      }
      else	  
	    iterator++;
	}
	else
	  throw std::out_of_range("");
  
  return temp -> m_data;
  }
  