/*!\file UNDIRECTED_GRAPH.hpp
 * \author Lisa Tatro && Thomas Dolan
 * \defines undirected graph's functions
 */
 
template <class T, unsigned int N>
void UNDIRECTED_GRAPH<T, N>::addEdge(const unsigned int i, const unsigned int j, const int w)
{
  if( i >= COLLECTION<T>::m_size || j >= COLLECTION<T>::m_size)
    throw std::out_of_range("requested entry is out of range");
		
  DIRECTED_GRAPH<T, N>::addEdge(i, j, w);
  DIRECTED_GRAPH<T, N>::addEdge(j, i, w);
}

template <class T, unsigned int N>
void UNDIRECTED_GRAPH<T, N>::removeEdge(const unsigned int i, const unsigned int j)
{
  if( i >= COLLECTION<T>::m_size || j >= COLLECTION<T>::m_size)
	    throw std::out_of_range("requested entry is out of range");
		
  DIRECTED_GRAPH<T, N>::addEdge(i, j, 0);
  DIRECTED_GRAPH<T, N>::addEdge(j, i, 0);
}

template <class T, unsigned int N>
int UNDIRECTED_GRAPH<T, N>::vertexDegree(const unsigned int i) const
{
  if( i >= COLLECTION<T>::m_size /*|| j >= COLLECTION<T>::m_size*/)
	  throw std::out_of_range("requested entry is out of range");
	  
	int DegreeSum = 0;
	for (int index = 0; index < COLLECTION<T>::m_size; index++)
	{
	  if(DIRECTED_GRAPH<T,N>::getEdgeWeight(i, index) != 0)
	  {
	    if( i == index)
		  DegreeSum = DegreeSum + 2;
		else
		  DegreeSum ++;
	  }
	}
	return DegreeSum;
}

template <class T, unsigned int N>
int UNDIRECTED_GRAPH<T, N>::graphDegree() const
{
  int totalDegree = 0;
  for(int i =0; i < COLLECTION<T>::m_size; i++)
  {
	totalDegree = totalDegree + vertexDegree(i);
  }
  return totalDegree;
}

template <class T, unsigned int N>
bool UNDIRECTED_GRAPH<T, N>::isSimple() const
{
 //checking for loops first
  for(int i = 0; i < COLLECTION<T>::m_size; i++)
  {
	if(DIRECTED_GRAPH<T,N>::getEdgeWeight(i, i) != 0)
	  return false;
  }
  return true;
}

template <class T, unsigned int N>
bool UNDIRECTED_GRAPH<T, N>::isComplete() const
{
    if( isSimple() )
	{
	  for(int i = 0; i< COLLECTION<T>::m_size; i++)
	 {
	   for(int j = i+1; j <COLLECTION<T>::m_size; j++)
	   {
	     if(DIRECTED_GRAPH<T,N>::getEdgeWeight(i, j) == 0 && DIRECTED_GRAPH<T,N>::getEdgeWeight(j, i) == 0)
		   return false;
	   }
	 }
	 return true;
	}
	return false;
}

//Need a way to fix m_Edges_Array
//How to reset m_Edges_Array in protected inheritance?
//Same idea with vertices_data_array
/* Couldn't get it to work
template <class T, unsigned int N>
void UNDIRECTED_GRAPH<T, N>::complement(const UNDIRECTED_GRAPH<T,N>& compMe)
{
	T* vertices_data_array;

  //in case this isnt the same size as compMe
    if( COLLECTION<T>::m_size != compMe.COLLECTION<T>::m_size)
	{
      DIRECTED_GRAPH<T, N>::clear();
	//get m_size from the graph to be copied
	  COLLECTION<T>::m_size = compMe.COLLECTION<T>::m_size;
	// make an NxN array
	  int * m_Edges_Array;
      try
	  {
	    m_Edges_Array = new int*[COLLECTION<T>::m_size];  //FIXME
	  }catch( std::bad_alloc& e)
	  {
	    throw e;
	  }
      for(int i = 0; i < COLLECTION<T>:: m_size; i++)
	  {
	    try
	    {
	      m_Edges_Array[i] = new int[COLLECTION<T>::m_size]; //FIXME
	    }catch( std::bad_alloc& e)
	    {
	      throw e;
	    }
	  }
	   //making array for vertices data
	  try
	    {
	      vertices_data_array = new T[COLLECTION<T>::m_size]; //FIXME
	    }catch( std::bad_alloc& e)
	    {
	      throw e;
	    }
	}
	//copying the data for the vertices
	for(int i = 0; i < COLLECTION<T>::m_size; i++)
	{
	  vertices_data_array[i] = compMe.vertices_data_array[i]; //FIXME
	}
	
	for(int i = 0; i < COLLECTION<T>::m_size; i++)
	{
	  for(int j = i; j < COLLECTION<T>::m_size; j++)
	  {
	    if( compMe.m_Edges_Array[i][j] != 0)
		{
		  DIRECTED_GRAPH<T,N>::setEdgeWeight(i, j, 0);
		  DIRECTED_GRAPH<T,N>::setEdgeWeight(j, i, 0);
		}
		else
		{
		  DIRECTED_GRAPH<T,N>::getEdgeWeight(i, j, 1);
		  DIRECTED_GRAPH<T,N>::getEdgeWeight(j, i, 1);
		}
	  }
	}
}*/

template <class T, unsigned int N>
bool UNDIRECTED_GRAPH<T, N>::operator==(const UNDIRECTED_GRAPH<T,N>& rhs) const
{
//checking vertices
    for(int i =0; i < COLLECTION<T>::m_size;i++)
	{
	  if(DIRECTED_GRAPH<T, N>::getVertexData(i) != rhs.DIRECTED_GRAPH<T, N>::getVertexData(i))
	    return false;
	}
	//checkings edges
    for(int i = 0; i < COLLECTION<T>::m_size; i++)
	{
	  for( int j =0; j < COLLECTION<T>::m_size;  j++)
	  {
	    if(DIRECTED_GRAPH<T, N>::getEdgeWeight(i, j) != rhs.DIRECTED_GRAPH<T, N>::getEdgeWeight(i, j))
		  return false;
	  }
	}
	return true;
}

//Same idea as above
template <class T, unsigned int N>
UNDIRECTED_GRAPH<T,N>& UNDIRECTED_GRAPH<T, N>::operator=(DIRECTED_GRAPH<T,N>& rhs)
{
clear();
int * m_Edges_Array;

	//get m_size from the graph to be copied
	COLLECTION<T>::m_size = rhs.COLLECTION<T>::m_size;
	// make an NxN array
    try
	{
	  m_Edges_Array = new int*[COLLECTION<T>::m_size];  //FIXME
	}catch( std::bad_alloc& e)
	{
	  throw e;
	}
    for(int i = 0; i < COLLECTION<T>:: m_size; i++)
	{
	  try
	  {
	    m_Edges_Array[i] = new int[COLLECTION<T>::m_size]; //FIXME
	  }catch( std::bad_alloc& e)
	  {
	    throw e;
	  }
	}
	//filling the new array with the edges of the array to be copied
	for(int i = 0; i < COLLECTION<T>::m_size; i++)
	{
	  for(int j = 0; j < COLLECTION<T>::m_size; j++)
	  {
	    DIRECTED_GRAPH<T,N>::setEdgeWeight(i, j, rhs.DIRECTED_GRAPH<T,N>::getEdgeWeight(i, j));
	  }
	}
	//making an array for data
	T* vertices_data_array = new T[COLLECTION<T>::m_size]; //FIXME
	//copying the rhs vertices data to the lhs
	for(int i =0; i < COLLECTION<T>::m_size; i++)
	{
	  DIRECTED_GRAPH<T,N>::setVertexData(i, rhs.DIRECTED_GRAPH<T,N>::getVertexData(i));
	}
}
