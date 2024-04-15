#include <iostream>
#include <stdexcept>
#include <cstring>
#include <math.h>
using namespace std;

struct Event
{
    int a;
    int t;
};


template<class ItemType>
class QueueInterface

{
public:
   /** Sees whether this queue is empty.
    @return True if the queue is empty, or false if not. */
   virtual bool isEmpty() const = 0;
   
   /** Adds a new entry to the back of this queue.
    @post If the operation was successful, newEntry is at the back of the queue.
    @param newEntry  The object to be added as a new entry.
    @return True if the addition is successful or false if not. */
   virtual bool enqueue(const ItemType& newEntry) = 0;
   
   /** Removes the front of this queue.
    @post If the operation was successful, the front of the queue has been removed.
    @return True if the removal is successful or false if not. */
   virtual bool dequeue() = 0;
   
   /** Returns the front of this queue.
    @pre The queue is not empty.
    @post The front of the queue has been returned, and the zqueue is unchanged.
    @return The front of the queue. */
   virtual ItemType peekFront() const =0;
}; // end QueueInterface
 
template <class ItemType>
class Node
{
private:
    ItemType item;
    Node<ItemType> *next;
 
public:
    Node();
    Node(const ItemType &anItem);
    Node(const ItemType &anItem, Node<ItemType> *nextNodePtr);
    void setItem(const ItemType &anItem);
    void setNext(Node<ItemType> *nextNodePtr);
    ItemType getItem() const;
    Node<ItemType> *getNext() const;
};
 
template <class ItemType>
Node<ItemType>::Node() : next(nullptr)
{
}
 
template <class ItemType>
Node<ItemType>::Node(const ItemType &anItem) : item(anItem), next(nullptr)
{
}
 
template <class ItemType>
Node<ItemType>::Node(const ItemType &anItem, Node<ItemType> *nextNodePtr) : item(anItem), next(nextNodePtr)
{
}
 
template <class ItemType>
void Node<ItemType>::setItem(const ItemType &anItem)
{
    item = anItem;
}
 
template <class ItemType>
void Node<ItemType>::setNext(Node<ItemType> *nextNodePtr)
{
    next = nextNodePtr;
}
 
template <class ItemType>
ItemType Node<ItemType>::getItem() const
{
    return item;
}
 
template <class ItemType>
Node<ItemType> *Node<ItemType>::getNext() const
{
    return next;
}

//Linked Queue
template<class ItemType>
class LinkedQueue : public QueueInterface<ItemType>
{
private:
   // The queue is implemented as a chain of linked nodes that has 
   // two external pointers, a head pointer for front of the queue and
   // a tail pointer for the back of the queue.
   Node<ItemType>* backPtr;
   Node<ItemType>* frontPtr;

public:
   LinkedQueue();
   LinkedQueue  (const LinkedQueue& aQueue);
   ~LinkedQueue();

	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
   
   /** @throw PrecondViolatedExcep if the queue is empty */
	ItemType peekFront() const ;
}; // end LinkedQueue

template <typename ItemType>
LinkedQueue<ItemType>::LinkedQueue() : frontPtr(nullptr)
{
}
 
template <typename ItemType>
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue<ItemType> &aQueue)
{
    // Point to nodes in original chain
    Node<ItemType> *origChainPtr = aQueue.frontPtr; // typo in the textbook
    if (origChainPtr == nullptr)
        this->frontPtr = nullptr; // Original bag is empty
    else
    {
        // Copy first node
        frontPtr = new Node<ItemType>();
        frontPtr->setItem(origChainPtr->getItem());
        Node<ItemType> *newChainPtr = frontPtr;
        // Copy remaining nodes
        while (origChainPtr->getNext() != nullptr) // typo in the textbook
        {
            origChainPtr = origChainPtr->getNext();
            ItemType nextItem = origChainPtr->getItem();
            Node<ItemType> *newNodePtr = new Node<ItemType>(nextItem);
            newChainPtr->setNext(newNodePtr);
            newChainPtr = newChainPtr->getNext();
        }
        newChainPtr->setNext(nullptr); // Mark the bottom of stack
    }
}
 
template <typename ItemType>
LinkedQueue<ItemType>::~LinkedQueue()
{
    // Pop until stack is empty
    while (!isEmpty())
        dequeue();
}
 


template<class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const
{
    return frontPtr == nullptr;
}


template<class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& newEntry)
{
   Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);	

   // Insert the new node
   if (isEmpty())
      frontPtr = newNodePtr;        // Insertion into empty queue
   else
      backPtr->setNext(newNodePtr); // Insertion into nonempty queue
   
   backPtr = newNodePtr;            // New node is at back
   
	return true;
}  // end enqueue

template<class ItemType>
bool LinkedQueue<ItemType>::dequeue()
{
	bool result = false;
	if (!isEmpty())
	{
      // Queue is not empty; delete front
		Node<ItemType>* nodeToDeletePtr = frontPtr;
      if (frontPtr == backPtr)
      {  // Special case: one node in queue
         frontPtr = nullptr;
         backPtr = nullptr;
      }
      else
		   frontPtr = frontPtr->getNext();
		
		// Return deleted node to system
      nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
      nodeToDeletePtr = nullptr;
      
      result = true;
	}  // end if
   
	return result;	
}  // end dequeue

template<class ItemType>
ItemType LinkedQueue<ItemType>::peekFront() const
{
    if (!this->isEmpty()) // check precondition
        return frontPtr->getItem();
    else
        throw logic_error("...");
}// end peekfront







//Linked Sorted Queue
template<class ItemType>
class LinkedSortedQueue : public QueueInterface<ItemType>
{
private:
   // The queue is implemented as a chain of linked nodes that has 
   // two external pointers, a head pointer for front of the queue and
   // a tail pointer for the back of the queue.
   Node<ItemType>* backPtr;
   Node<ItemType>* frontPtr;
   Node<ItemType>* prev;
   Node<ItemType>* headPtr;
 
public:
   LinkedSortedQueue();
   LinkedSortedQueue  (const LinkedSortedQueue& aQueue);
   ~LinkedSortedQueue();

	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
   
	ItemType peekFront() const ;

}; // end LinkedQueue

template <typename ItemType>
LinkedSortedQueue<ItemType>::LinkedSortedQueue() : headPtr(nullptr)
{
}
 
template <typename ItemType>
LinkedSortedQueue<ItemType>::LinkedSortedQueue(const LinkedSortedQueue<ItemType> &aQueue)
{
    // Point to nodes in original chain
    Node<ItemType> *origChainPtr = aQueue.headPtr; // typo in the textbook
    if (origChainPtr == nullptr)
        this->headPtr = nullptr; // Original bag is empty
    else
    {
        // Copy first node
        headPtr = new Node<ItemType>();
        headPtr->setItem(origChainPtr->getItem());
        Node<ItemType> *newChainPtr = headPtr;
        // Copy remaining nodes
        while (origChainPtr->getNext() != nullptr) // typo in the textbook
        {
            origChainPtr = origChainPtr->getNext();
            ItemType nextItem = origChainPtr->getItem();
            Node<ItemType> *newNodePtr = new Node<ItemType>(nextItem);
            newChainPtr->setNext(newNodePtr);
            newChainPtr = newChainPtr->getNext();
        }
        newChainPtr->setNext(nullptr); // Mark the bottom of stack
    }
}
 
template <typename ItemType>
LinkedSortedQueue<ItemType>::~LinkedSortedQueue()
{
    // Pop until stack is empty
    while (!isEmpty())
        dequeue();
}
 


template<class ItemType>
bool LinkedSortedQueue<ItemType>::isEmpty() const
{
    return headPtr == nullptr;
}

template<class ItemType>
bool LinkedSortedQueue<ItemType>::enqueue(const ItemType& newEntry)
{
   Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);	
   
   // Insert the new node
   if (isEmpty()){      
       headPtr = newNodePtr; // Insertion into empty queue
   }
   else{
       prev = headPtr;
       frontPtr = headPtr->getNext();
       while(frontPtr != nullptr && newNodePtr->getItem() > frontPtr->getItem())
       {
           prev = frontPtr;
           frontPtr = frontPtr->getNext();

       }
       prev->setNext(newNodePtr);
       prev = newNodePtr;
       prev->setNext(frontPtr);
   }
   return true;
}  // end enqueue

template<class ItemType>
bool LinkedSortedQueue<ItemType>::dequeue()
{
	bool result = false;
    if(headPtr !=nullptr)
    {
        frontPtr = headPtr;
        headPtr = headPtr->getNext();
        delete frontPtr;
        return true;
    }// end if
	return result;	
}  // end dequeue

template<class ItemType>
ItemType LinkedSortedQueue<ItemType>::peekFront() const
{
    if (!this->isEmpty()) // check precondition
        return headPtr->getItem();
    else
        throw logic_error("...");
}

int main()
{
    LinkedSortedQueue <Event> aQueue;
    Event event;

    int a = 0 , b = 0;

    while(!cin.eof())
    { 
        cin >> a >> b;
        if(a ==999)
            break;
        event.type = 'A';
        event.a = a;
        event.t = b;
        aQueue.enqueue(event);

    }
    
    while(!aQueue.isEmpty())
    {
        event = aQueue.peekFront();
        cout << event.a  <<endl;
        aQueue.dequeue();
    }

    // int start =0 , duration =0;
    // cout << "Simulation Begins"<<endl;
    // cout << "Processing an arrival event at time: " << "1" <<endl;
    // cout << "Processing a departure event at time: " << "6" <<endl;
    // cout << "Simulation Ends" <<endl;
    // cout << endl;
    // cout << "Final Statistics:" <<endl;
    // cout << endl;
    // cout << "        Total number of people processed: " << "1" <<endl;
    // cout << "        Average amount of time spent waiting: " <<"0.0" <<endl;
    
}