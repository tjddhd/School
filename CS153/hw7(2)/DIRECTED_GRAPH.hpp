/*!\file DIRECTED_GRAPH.hpp
 * \author Lisa Tatro
 * \definitions for directed graph functions
 */
 #include<stdlib.h>
 
 using namespace std;

template <class T, unsigned int N>
DIRECTED_GRAPH<T,N>::DIRECTED_GRAPH()
{	
	COLLECTION<T>::m_size = N;
	
	if (N>0)
	{
		//allocating memory
		try
		{
			m_Edges_Array = new int*[COLLECTION<T>::m_size];
		}catch( std::bad_alloc& e)
		{
			throw e;
		}
		for(int i = 0; i < COLLECTION<T>:: m_size; i++)
		{
			try
			{
				m_Edges_Array[i] = new int[COLLECTION<T>::m_size];
			}catch( std::bad_alloc& e)
			{
				throw e;
			}
		}
		//making no edges
		for( int i = 0; i < COLLECTION<T>:: m_size; i++)
		{
			for( int j =0; j < COLLECTION<T>::m_size; j++)
			{
				m_Edges_Array[i][j] = 0;
			}
		}
		//making an array for data value of type T storage for N vertices
		vertices_data_array = new T[COLLECTION<T>::m_size];
	}
}

template <class T, unsigned int N>
void DIRECTED_GRAPH<T,N>::clear()
{
	if (N>0)
	{
		for( int i = 0; i < COLLECTION<T>::m_size; i++)
		{
			delete[ ] m_Edges_Array[i];
			m_Edges_Array[i] = NULL;
		}
	
	
		delete [ ] m_Edges_Array;
		m_Edges_Array = NULL;
		
		delete [] vertices_data_array;
		vertices_data_array = NULL;
		COLLECTION<T>::m_size = 0;
	}
}

template <class T, unsigned int N>
bool DIRECTED_GRAPH<T,N>::find(const T& x) const
{
	for(int i = 0; i < COLLECTION<T>::m_size; i++)
	{
		if(vertices_data_array[i] == x)
			return true;
	}
	return false;
}

template <class T, unsigned int N>
void DIRECTED_GRAPH<T,N>::addEdge(const unsigned int i,
		const unsigned int j, const int w )
		{
	if( i >= COLLECTION<T>::m_size || j >= COLLECTION<T>::m_size)
	{
		throw std::out_of_range("requested entry is out of range");
	}
	else
	{
	  m_Edges_Array[i][j] = w;
	}
		}

template <class T, unsigned int N>	
void DIRECTED_GRAPH<T,N>::removeEdge(const unsigned int i, const unsigned int j)
{
	if( i >= COLLECTION<T>::m_size || j >= COLLECTION<T>::m_size)
		throw std::out_of_range("requested entry is out of range");

	m_Edges_Array[i][j] = 0;
}

template <class T, unsigned int N>
bool DIRECTED_GRAPH<T,N>::isEdge(const unsigned int i, const unsigned int j) const
{
	if( i >= COLLECTION<T>::m_size || j >= COLLECTION<T>::m_size)
		throw std::out_of_range("requested entry is out of range");
	if (m_Edges_Array[i][j] != 0)
		return true;
	else
		return false;
}

template <class T, unsigned int N>
int DIRECTED_GRAPH<T,N>::getEdgeWeight(const unsigned int i, const unsigned int j) const
{
	if( i >= COLLECTION<T>::m_size || j >= COLLECTION<T>::m_size)
		throw std::out_of_range("requested entry is out of range");

	return m_Edges_Array[i][j];
}

template <class T, unsigned int N>
void DIRECTED_GRAPH<T,N>::setEdgeWeight(const unsigned int i,
		const unsigned int j, const int w)
		{
	if( i >= COLLECTION<T>::m_size || j >= COLLECTION<T>::m_size)
		throw std::out_of_range("requested entry is out of range");

	m_Edges_Array[i][j] = w;
		}

template <class T, unsigned int N>
T DIRECTED_GRAPH<T,N>::getVertexData(const unsigned int i) const
{
	if( i >= COLLECTION<T>::m_size)
		throw std::out_of_range("requested entry is out of range");

	return vertices_data_array[i];
}

template <class T, unsigned int N>
void DIRECTED_GRAPH<T,N>::setVertexData(const unsigned int i, const T& data)
{
	if( i >= COLLECTION<T>::m_size)
		throw std::out_of_range("requested entry is out of range");
	else
		vertices_data_array[i] = data;
}

template <class T, unsigned int N>
int DIRECTED_GRAPH<T,N>::vertexInDegree(const unsigned int i) const
{
	if( i >= COLLECTION<T>::m_size /*|| j >= COLLECTION<T>::m_size*/)
		throw std::out_of_range("requested entry is out of range");

	int inDegreeSum = 0;
	for (int index = 0; index < COLLECTION<T>::m_size; index++)
	{
		if( m_Edges_Array[index][i] != 0)
			inDegreeSum++;
	}
	return inDegreeSum;
}

template <class T, unsigned int N>
int DIRECTED_GRAPH<T,N>::vertexOutDegree(const unsigned int i) const
{
	if( i >= COLLECTION<T>::m_size /*|| j >= COLLECTION<T>::m_size*/)
		throw std::out_of_range("requested entry is out of range");

	int DegreeSum = 0;
	for (int index = 0; index < COLLECTION<T>::m_size; index++)
	{
		if( m_Edges_Array[i][index] != 0)
			DegreeSum++;
	}
	return DegreeSum;
}

template <class T, unsigned int N>
int DIRECTED_GRAPH<T,N>::graphDegree() const
{
	int totalDegree = 0;
	for(int i =0; i < COLLECTION<T>::m_size; i++)
	{
		totalDegree = totalDegree + vertexInDegree(i);
		totalDegree = totalDegree + vertexOutDegree(i);
	}
	return totalDegree;
}
template <class T, unsigned int N>
bool DIRECTED_GRAPH<T,N>::isSimple() const
{
	//checking for loops first
	for(int i = 0; i < COLLECTION<T>::m_size; i++)
	{
		if(m_Edges_Array[i][i] != 0)
			return false;
	}
	//checking for parallel edges
	//tonly checks upper triangle of indices since checking symmetry
	for(int i = 0; i< COLLECTION<T>::m_size; i++)
	{
		for(int j = i+1; j <COLLECTION<T>::m_size; j++)
		{
			if( m_Edges_Array[i][j] != 0 && m_Edges_Array[j][i] != 0)
				return false;
		}
	}
	return true;
}

template <class T, unsigned int N>
bool DIRECTED_GRAPH<T,N>::isComplete() const
{
	//only checks upper triangle worth of indices since checking symmetry
	if( isSimple() )
	{
		for(int i = 0; i< COLLECTION<T>::m_size; i++)
		{
			for(int j = i+1; j <COLLECTION<T>::m_size; j++)
			{
				if( m_Edges_Array[i][j] == 0 && m_Edges_Array[j][i] == 0)
					return false;
			}
		}
		return true;
	}
	return false;
}

template <class T, unsigned int N>
bool DIRECTED_GRAPH<T,N>::isAcyclic() const
{
	if(COLLECTION<T>::m_size == 0)
		return true;
	if(!isSimple())
		return false;
	if(COLLECTION<T>::m_size == 1)
		return true;

	int visited1[COLLECTION<T>::m_size];
	int visited2[COLLECTION<T>::m_size];
	//looking for
	for( int i = 0; i < COLLECTION<T>::m_size; i++)
	{
		for(int j = 0; j < COLLECTION<T>::m_size; j++)
		{
			if(i != j)
			{
				for(int k =0; k < COLLECTION<T>::m_size; k++)
				{
					visited1[k] = NOT_YET_VISITED;
					visited2[k] = NOT_YET_VISITED;
				}
				dfs(i, visited1);
				dfs(j, visited2);
				if(visited1[j] != NOT_YET_VISITED && visited2[i] != NOT_YET_VISITED)
					return false;
			}
		}
	}
	return true;
}  
template <class T, unsigned int N>
bool DIRECTED_GRAPH<T,N>::isBipartite(int vertexGrouping[]) const
{
	bool isBP = true;
	int visited1[COLLECTION<T>::m_size];
	int visited2[COLLECTION<T>::m_size];
	for(int i = 0; i < COLLECTION<T>::m_size; i++)
	{
		for(int j = 0; j < COLLECTION<T>::m_size; j++)
		{
			if(i != j)
			{
				for(int h = 0; h <COLLECTION<T>::m_size; h++)
				{
					visited1[h] = NOT_YET_VISITED;
					visited2[h] = NOT_YET_VISITED;
				}
				isBP = true;
				bfs(i, visited1);
				bfs(j, visited2);
				for(int h = 0; h <COLLECTION<T>::m_size; h++)
				{
					visited1[h] = visited1[h] % 2;
					visited2[h] = visited2[h] % 2;
				}
				for(int x = 0; x <COLLECTION<T>::m_size; x++)
				{
					isBP = !(visited1[x] == visited2[x]);  //FIXME --- Need to refine how to determine Bipartite-ness
					if(!isBP)
						return false;
				}
				
			}
		}
	}
	
	for(int w = 0; w <COLLECTION<T>::m_size; w++)
	{
		if(visited1[w] == 0)
			vertexGrouping[w] = 1;
		else
			vertexGrouping[w] = 2;
	}

	return isBP;
}

template <class T, unsigned int N>
bool DIRECTED_GRAPH<T,N>::isStronglyConnected() const
{
	int visited1[COLLECTION<T>::m_size];
	// only checks upper triangle of indices since checking symmetry
	for(int i = 0; i< COLLECTION<T>::m_size; i++)
	{
		for(int j = 0; j <COLLECTION<T>::m_size; j++)
		{
			if( i != j)
			{
				dfs(i, visited1);
				if( visited1[j] == NOT_YET_VISITED)
					return false;
			}
		}
	}
	return true;
}

template <class T, unsigned int N>
void DIRECTED_GRAPH<T,N>::complement(const DIRECTED_GRAPH<T, N>& compMe)
{
	//in case this isnt the same size as compMe
	if( COLLECTION<T>::m_size != compMe.COLLECTION<T>::m_size)
	{
		clear();
		//get m_size from the graph to be copied
		COLLECTION<T>::m_size = compMe.COLLECTION<T>::m_size;
		// make an NxN array
		try
		{
			m_Edges_Array = new int*[COLLECTION<T>::m_size];
		}catch( std::bad_alloc& e)
		{
			throw e;
		}
		for(int i = 0; i < COLLECTION<T>:: m_size; i++)
		{
			try
			{
				m_Edges_Array[i] = new int[COLLECTION<T>::m_size];
			}catch( std::bad_alloc& e)
			{
				throw e;
			}
		}

		//making array for vertices data
		try
		{
			vertices_data_array = new T[COLLECTION<T>::m_size];
		}catch( std::bad_alloc& e)
		{
			throw e;
		}
	}
	//copying the data for the vertices
	for(int i = 0; i < COLLECTION<T>::m_size; i++)
	{
		vertices_data_array[i] = compMe.vertices_data_array[i];
	}

	for(int i = 0; i < COLLECTION<T>::m_size; i++)
	{
		for(int j = 0; j < COLLECTION<T>::m_size; j++)
		{
			if( compMe.m_Edges_Array[i][j] != 0)
				m_Edges_Array[i][j] = 0;
			else
				m_Edges_Array[i][j] = 1;
		}
	}
}



#include <queue>
template <class T, unsigned int N>
void DIRECTED_GRAPH<T,N>::bfs(const unsigned int start, int visited[]) const
{
	if(start >= COLLECTION<T>::m_size)
		throw std::out_of_range("requested entry is out of range");
	//intializing each entry in visited[N] to NOT_YET_VISITED
	for(int i = 0; i <COLLECTION<T>::m_size; i++)
	{
		visited[i] = NOT_YET_VISITED;
	}
	T neighbor;
	queue<T> q; 
	visited[start] = 0;
	q.push(start);
	while( !q.empty())
	{
		neighbor = q.front();
		q.pop();
		for(int i = 0; i < COLLECTION<T>::m_size; i++)
		{
			if( m_Edges_Array[neighbor][i] != 0)
			{
				//hi neighbor
				if( visited[i] == NOT_YET_VISITED)
				{
					visited[i] = visited[neighbor] + 1;
					q.push(i);
				}
			}
		}
	}
}

template <class T, unsigned int N>
void DIRECTED_GRAPH<T,N>::dfs(const unsigned int start, int visited[], int count = 0) const
{
	if(start >= COLLECTION<T>::m_size)
		throw std::out_of_range("requested entry is out of range");
	if(count == 0)
	{
		for(int i = 0; i <COLLECTION<T>::m_size; i++)
		{
			visited[i] = NOT_YET_VISITED;
		}	
	}		
	visited[start] = count;
	for(int i = 0; i < COLLECTION<T>::m_size; i++)
	{
		if( m_Edges_Array[start][i] != 0)
		{
			//hi neighbor
			if( visited[i] == NOT_YET_VISITED)
				dfs(i, visited, count+1);
		}
	}
}

template <class T, unsigned int N>
bool DIRECTED_GRAPH<T,N>::operator==(const DIRECTED_GRAPH<T, N>& rhs) const
{
	//checking vertices
	for(int i =0; i < COLLECTION<T>::m_size;i++)
	{
		if(vertices_data_array[i] != rhs.vertices_data_array[i])
			return false;
	}
	//checkings edges
	for(int i = 0; i < COLLECTION<T>::m_size; i++)
	{
		for( int j =0; j < COLLECTION<T>::m_size;  j++)
		{
			if( m_Edges_Array[i][j] != rhs.m_Edges_Array[i][j])
				return false;
		}
	}
	return true;
}

template <class T, unsigned int N>
DIRECTED_GRAPH<T, N>& DIRECTED_GRAPH<T,N>::operator=(DIRECTED_GRAPH<T, N>& rhs)
{
    if(*this == rhs)
	  return *this;
	clear();
	//get m_size from the graph to be copied
	COLLECTION<T>::m_size = rhs.COLLECTION<T>::m_size;
	// make an NxN array
	try
	{
		m_Edges_Array = new int*[COLLECTION<T>::m_size];
	}catch( std::bad_alloc& e)
	{
		throw e;
	}
	for(int i = 0; i < COLLECTION<T>:: m_size; i++)
	{
		try
		{
			m_Edges_Array[i] = new int[COLLECTION<T>::m_size];
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
			m_Edges_Array[i][j] = rhs.m_Edges_Array[i][j];
		}
	}
	//making an array for data
	vertices_data_array = new T[COLLECTION<T>::m_size];
	//copying the rhs vertices data to the lhs
	for(int i =0; i < COLLECTION<T>::m_size; i++)
	{
		vertices_data_array[i] = rhs.vertices_data_array[i];
	}
}

