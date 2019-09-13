/* derped by Thomas Dolan
// file: HEAP.hpp
// 11/11/11 
*/
template <class T>
void HEAP<T>::heapifyUp(BNODE<T>* newestNode)
{
  while( newestNode != NULL && 
    higherPriority( newestNode ->m_data, newestNode -> m_parent -> m_data))
  {
    swapData( newestNode, newestNode -> m_parent);
	newestNode = newestNode -> m_parent;
  }
}
template<class T>
void HEAP<T>::insert(const T& x)
{
  if(BINARY_TREE<T>::m_root == NULL)  
    BINARY_TREE<T>::m_root = new BNODE<T>;
	BINARY_TREE<T>::m_root -> m_left = NULL;
	BINARY_TREE<T>::m_root -> m_right = NULL;
	BINARY_TREE<T>::m_root -> m_parent = NULL;
	BINARY_TREE<T>::m_root -> m_data = x;
	BINARY_TREE<T>::m_root -> m_count = 1;
	COLLECTION<T>::m_size++;
  }
  else
  {
    if(isFull(BINARY_TREE<T>:: m_root, height(BINARY_TREE<T>:: m_root)) ) 
	
	{
	  BNODE<T> *temp = BINARY_TREE<T>::m_root;
	  while(temp -> m_left != NULL)
	  {
	    temp = temp -> m_left;
	  }
	  temp -> m_left = new BNODE<T>;
	  COLLECTION<T>::m_size++;
	  temp -> m_left -> m_data = x;
	  temp -> m_left -> m_left = NULL;
	  temp -> m_left -> m_right = NULL;
	  temp -> m_left -> m_parent = temp;
	
	  temp -> m_left -> m_count = 1;
	  while(temp != NULL)
	  {
	    temp -> m_count ++;
		temp = temp -> m_parent;
	  }
	  heapifyUp(temp -> m_left); 
	}
	else
	{
	  BNODE<T> *temp = BINARY_TREE<T>::m_root;
	  while( temp -> m_left != NULL && temp-> m_right != NULL)
	  {
	    if(!isFull( temp-> m_left, height(temp-> m_left)))
		  temp = temp -> m_left;
		else 
		  temp = temp -> m_right;
	  }
	  
	  temp = temp -> m_parent;
	  if(temp -> m_left == NULL)
	  {
	    temp -> m_left = new BNODE<T>;
		temp -> m_left -> m_data = x;
	    temp -> m_left -> m_left = NULL;
	    temp -> m_left -> m_right = NULL;
	    temp -> m_left -> m_parent = temp;
		temp -> m_left -> m_count = 1;
		COLLECTION<T>::m_size++;
		heapifyUp(temp -> m_left);
	  }
	  else
	  {
	    temp -> m_right = new BNODE<T>;
		temp -> m_right -> m_data = x;
	    temp -> m_right -> m_left = NULL;
	    temp -> m_right -> m_right = NULL;
	    temp -> m_right -> m_parent = temp;
		temp -> m_right -> m_count++;
		COLLECTION<T>::m_size++;
		heapifyUp(temp-> m_right);
	  }
	  while(temp != NULL)
	  {
	    temp -> m_count ++;
		temp = temp -> m_parent;
	  }
	}
  }
}
template <class T>
void HEAP<T>::heapifyDown(BNODE<T> *rootPtr)
{
  BNODE<T> *temp = BINARY_TREE<T>::getRoot();
  while( temp != NULL)
  {
    if( higherPriority(temp -> m_left -> m_data, temp -> m_right -> m_data)
	  && higherPriority(temp -> m_left -> m_data, temp -> m_data))
	{
	  swapData(temp -> m_left, temp);
	  temp = temp -> m_left;
	}
	if( higherPriority(temp -> m_right -> m_data, temp -> m_left -> m_data)
	  && higherPriority(temp -> m_right -> m_data, temp -> m_data))
	{
	  swapData(temp -> m_right, temp);
	  temp = temp -> m_right;
	}
	else
	{
	  temp = NULL;
	}
  }
  
}
template<class T>
bool HEAP<T>::removeRoot()
{
  if(BINARY_TREE<T>::getRoot()-> isLeaf())
  {
	delete BINARY_TREE<T>::m_root;
	COLLECTION<T>::m_size--;
	BINARY_TREE<T>::m_root = NULL;
  }
  else
  {
	BNODE<T>* temp = BINARY_TREE<T>::getRoot();
	if( HEAP<T>::isFull(BINARY_TREE<T>::getRoot(), height(BINARY_TREE<T>::getRoot())))  
	{
	  while(temp -> m_right -> m_right != NULL)
	  {
	    temp = temp -> m_right;
	  }
	  swapData( (BINARY_TREE<T>::getRoot()), (temp-> m_right) );
	  
	  while (temp-> m_parent != NULL)
	  {
	    temp -> m_count--;
		temp = temp -> m_parent;
	  }
	  delete temp -> m_right;
	  COLLECTION<T>::m_size--;
	  heapifyDown(BINARY_TREE<T>::getRoot());
	}
	else 
	{
	 
	  while ( !(temp -> isLeaf()) )
	  {
	    if( isFull(temp -> m_left, height(temp -> m_left)) 
		    && !isFull(temp -> m_right, height(temp -> m_right))
			&& temp -> m_right -> m_left == NULL)
		{
		  temp = temp -> m_left;
		}
		else if( isFull(temp -> m_left, height(temp -> m_left)) 
		    && !isFull(temp -> m_right, height(temp -> m_right))
			&& temp -> m_right -> m_left != NULL)
		{
		  temp = temp -> m_right;
		}
		else if( isFull(temp, height(temp)))
		{
		  temp = temp -> m_right;
		}
		else
		{
		  temp = temp -> m_left;
		}
	  }
	  swapData( BINARY_TREE<T>::m_root, temp-> m_right);
	  
	  while (temp-> m_parent != NULL)
	  {
	    temp -> m_count--;
		temp = temp -> m_parent;
	  }
	  delete temp;
	  COLLECTION<T>::m_size--;
	  heapifyDown(BINARY_TREE<T>::getRoot());
	}
  }
}
