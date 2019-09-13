// calculates minimal spanning tree with prim's algorithm
template <GraafType TYPE,typename T>
void Prim<TYPE,T>::minimalSpanningTree()
{
 
	cout << "Running prim's legendary algorithm:" << endl;
	// sum of weights to calculate the total weight
	int weight = 0;
 
	// number of nodes
	unsigned int countnodes = graph.aantal_knopen();
 
	// initialize discovered
	discovered.reserve(countnodes);
	pad.reserve(countnodes);
	for(unsigned int i = 0; i < countnodes; i++)
		discovered[i] = false;
 
	// we start in 0 so this one is discovered
	int starting_point = 0;
	pad.push_back(starting_point);
	discovered[starting_point] = true;
 
	// loop for each node of the graph (so all nodes will contain the minimal spanning tree)
	// we need to add n-1 other nodes
	for(unsigned int i = 1; i < countnodes; i++)
	{
 
		// Get the connections
		// from our starting point
		map<int, int> connections = graph[starting_point];
		for(map<int, int>::iterator itr = connections.begin(); itr != connections.end(); ++itr){
			// check if a connection to a new node
			if(!discovered[itr->first])
			{
				// create a new object and push it to the priority queue
				KnoopRelation rknoop(starting_point,(*itr).first,graph.gewicht((*itr).second));
				priorqueue.push(rknoop);
			}
		}
 
		// we cancel all bad nodes (which are already in our MOB)
		while(pad.size()!=countnodes && discovered[priorqueue.top().knoop_to])
			priorqueue.pop();
 
		// we discovered our new node that we will add
		// to our MOB
		discovered[priorqueue.top().knoop_to] = true;
 
		// get the minimal pad from the priority queue
		pad.push_back(priorqueue.top().knoop_to);
 
		// add new weight to total weight
		weight += priorqueue.top().weight;
 
		// prints out the minimal destination , from --- (weight)--> to
		cout << priorqueue.top().knoop_from << "---- (weight:"<< 
			priorqueue.top().weight <<") ---->" << 
			priorqueue.top().knoop_to << endl;
 
		// Our new starting_point
		starting_point = priorqueue.top().knoop_to;
 
	}
 
	cout << "Total weight: " << weight << endl;
 
}