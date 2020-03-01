//Class of Node in linked structure

template <class T>class Link {                          
public:
	T element;                //element of a node
	Link*next;                //pointer to next
	
	Link(const T& elemval, Link* nextval = NULL)
	{
		element = elemval; 
		next = nextval;
	}                       
    
	// set up the tail node
	Link(Link* nextval = NULL) {
		next = nextval;
	}                      
};
