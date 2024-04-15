#include <iostream>
#include <stdexcept>
#include <cstring>
#include <math.h>
#include <iomanip>
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
    ItemType peekBack() const ;
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

template<class ItemType>
ItemType LinkedQueue<ItemType>::peekBack() const
{
    if (!this->isEmpty()) // check precondition
        return backPtr->getItem();
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



//===================== Functions ===========================//
void ProcessArrival(Event newEvent , LinkedQueue<Event>eventListQueue ,LinkedQueue<int> bankQueue )
{
    int customer =0, depart =0;

    if(bankQueue.isEmpty())
        customer = newEvent.a;
    else
    {
        customer = bankQueue.peekBack();
    }
    

    if(bankQueue.isEmpty())
    {
        depart = customer+ newEvent.t;
    }else
    {
        depart = customer + newEvent.t;
    }
    bankQueue.enqueue(depart);
}

//=================== End Of Functions =====================//

int main()
{
    LinkedQueue <int> AbankQueue;
    LinkedQueue <int> BbankQueue;
    LinkedQueue <int> CbankQueue;
    LinkedQueue <Event> eventListQueue;
    LinkedSortedQueue <int> arrivalQueue;
    LinkedSortedQueue <int> departQueue;
    Event newArrivalevent , newEvent;
    bool Ateller , Bteller , Cteller = true;
 
    int start =0 , duration =0 , currentTime = 0,AcurrentTime = 0, BcurrentTime = 0,CcurrentTime = 0, totalTime=0 , departTime =0 ,customer =0, depart =0;
    double customerCnt =0 ,waitingTime =0 ;


    while(!cin.eof())
    {
        cin >> start >>duration;
        if(start == 999)
            break;
        newArrivalevent.a = start;
        newArrivalevent.t = duration;
        eventListQueue.enqueue(newArrivalevent);
        customerCnt++;
    }

    //dequeue 沒問題
    // while(!eventListQueue.isEmpty())
    // {
    //     newEvent = eventListQueue.peekFront();
    //     cout << newEvent.a << " " << newEvent.t << endl;
    //     eventListQueue.dequeue();

    // }


    cout << "Simulation Begins"<<endl;

    while(!eventListQueue.isEmpty())
    {
        newEvent = eventListQueue.peekFront();
        currentTime = newEvent.a;
        
        //只有一位客人
        if(customerCnt ==1)
        {
            cout << "Processing an arrival event at time: " << currentTime <<endl;
            // ProcessArrival(newEvent , eventListQueue, bankQueue);
            if(AbankQueue.isEmpty())
                customer = newEvent.a;
            else
            {
                customer = AbankQueue.peekBack();
            }
            
            if(AbankQueue.isEmpty())
            {
                depart = customer+ newEvent.t;
            }else
            {
                depart = customer + newEvent.t;
            }
            AbankQueue.enqueue(depart);

            eventListQueue.dequeue();
            departTime = AbankQueue.peekFront();
            AbankQueue.dequeue();
            cout << "Processing a departure event at time: " << departTime <<endl;

        }else //多位客人
        {
            if(AbankQueue.isEmpty())
            {
                arrivalQueue.enqueue(currentTime);
                // ProcessArrival(newEvent , eventListQueue, bankQueue);
                customer = newEvent.a;
                depart = customer+ newEvent.t;
                AbankQueue.enqueue(depart);
                waitingTime +=0;
                eventListQueue.dequeue();

            }else if(BbankQueue.isEmpty())
            {
                arrivalQueue.enqueue(currentTime);
                // ProcessArrival(newEvent , eventListQueue, bankQueue);
                customer = newEvent.a;
                depart = customer+ newEvent.t;
                BbankQueue.enqueue(depart);
                waitingTime +=0;
                eventListQueue.dequeue();

            }else if(CbankQueue.isEmpty())
            {
                arrivalQueue.enqueue(currentTime);
                // ProcessArrival(newEvent , eventListQueue, bankQueue);
                customer = newEvent.a;
                depart = customer+ newEvent.t;
                CbankQueue.enqueue(depart);
                waitingTime +=0;
                eventListQueue.dequeue();
            }else{ //三排都滿了
                
                //先把三個排隊時間找出來
                AcurrentTime = AbankQueue.peekBack();
                BcurrentTime = BbankQueue.peekBack();
                CcurrentTime = CbankQueue.peekBack();

                if(BcurrentTime >= AcurrentTime  && CcurrentTime >= AcurrentTime) //選擇A排
                {
                    if(AcurrentTime - currentTime >0)
                        waitingTime += AcurrentTime - currentTime;
                    departTime = AbankQueue.peekFront();
                    if(currentTime <= departTime)
                    {
                        arrivalQueue.enqueue(currentTime);
                        // ProcessArrival(newEvent , eventListQueue, bankQueue);
                        int customer =0, depart =0;
                        customer = AbankQueue.peekBack();
                        depart = customer + newEvent.t;
                        AbankQueue.enqueue(depart);
                        eventListQueue.dequeue();
                    }else
                    {
                        while(currentTime > departTime && !AbankQueue.isEmpty())
                        {
                            departQueue.enqueue(departTime);
                            AbankQueue.dequeue();
                            if(!AbankQueue.isEmpty())
                                departTime= AbankQueue.peekFront();
                        }
                        arrivalQueue.enqueue(currentTime);
                        if(AbankQueue.isEmpty())
                            customer = newEvent.a;
                        else
                        {
                            customer = AbankQueue.peekBack();
                        }
            
                        if(AbankQueue.isEmpty())
                        {
                            depart = customer+ newEvent.t;
                        }else
                        {
                            depart = customer + newEvent.t;
                        }
                        AbankQueue.enqueue(depart);

                        eventListQueue.dequeue();
                    }
                //end of a shortest
                }else if(AcurrentTime > BcurrentTime && CcurrentTime >= BcurrentTime)  //選擇b排
                {
                    if(BcurrentTime - currentTime >0)
                        waitingTime += BcurrentTime - currentTime;
                    departTime = BbankQueue.peekFront();
                    if(currentTime <= departTime)
                    {
                        arrivalQueue.enqueue(currentTime);
                        // ProcessArrival(newEvent , eventListQueue, bankQueue);
                        int customer =0, depart =0;
                        customer = BbankQueue.peekBack();
                        depart = customer + newEvent.t;
                        BbankQueue.enqueue(depart);
                        eventListQueue.dequeue();
                    }else
                    {
                        while(currentTime > departTime && !BbankQueue.isEmpty())
                        {
                            departQueue.enqueue(departTime);
                            BbankQueue.dequeue();
                            if(!BbankQueue.isEmpty())
                                departTime= BbankQueue.peekFront();
                        }
                        arrivalQueue.enqueue(currentTime);
                        if(BbankQueue.isEmpty())
                            customer = newEvent.a;
                        else
                        {
                            customer = BbankQueue.peekBack();
                        }
            
                        if(BbankQueue.isEmpty())
                        {
                            depart = customer+ newEvent.t;
                        }else
                        {
                            depart = customer + newEvent.t;
                        }
                        BbankQueue.enqueue(depart);

                        eventListQueue.dequeue();
                    }
                // end of smallest b
                }else if(AcurrentTime > CcurrentTime && BcurrentTime > CcurrentTime)
                {
                    if(CcurrentTime - currentTime >0)
                        waitingTime += CcurrentTime - currentTime;
                    departTime = CbankQueue.peekFront();
                    if(currentTime <= departTime)
                    {
                        arrivalQueue.enqueue(currentTime);
                        // ProcessArrival(newEvent , eventListQueue, bankQueue);
                        int customer =0, depart =0;
                        customer = CbankQueue.peekBack();
                        depart = customer + newEvent.t;
                        CbankQueue.enqueue(depart);
                        eventListQueue.dequeue();
                    }else
                    {
                        while(currentTime > departTime && !CbankQueue.isEmpty())
                        {
                            departQueue.enqueue(departTime);
                            CbankQueue.dequeue();
                            if(!CbankQueue.isEmpty())
                                departTime= CbankQueue.peekFront();
                        }
                        arrivalQueue.enqueue(currentTime);
                        if(CbankQueue.isEmpty())
                            customer = newEvent.a;
                        else
                        {
                            customer = CbankQueue.peekBack();
                        }
            
                        if(CbankQueue.isEmpty())
                        {
                            depart = customer+ newEvent.t;
                        }else
                        {
                            depart = customer + newEvent.t;
                        }
                        CbankQueue.enqueue(depart);

                        eventListQueue.dequeue();
                    }
                }
            }
        }
          
    } // end while

    if(!AbankQueue.isEmpty())
        departTime = AbankQueue.peekFront();
    while(!AbankQueue.isEmpty())
    {
        departQueue.enqueue(departTime);
        AbankQueue.dequeue();
        if(!AbankQueue.isEmpty())
            departTime = AbankQueue.peekFront();
    }

    if(!BbankQueue.isEmpty())
        departTime = BbankQueue.peekFront();
    while(!BbankQueue.isEmpty())
    {
        departQueue.enqueue(departTime);
        BbankQueue.dequeue();
        if(!BbankQueue.isEmpty())
            departTime = BbankQueue.peekFront();
    }

    if(!CbankQueue.isEmpty())
        departTime = CbankQueue.peekFront();
    while(!CbankQueue.isEmpty())
    {
        departQueue.enqueue(departTime);
        CbankQueue.dequeue();
        if(!CbankQueue.isEmpty())
            departTime = CbankQueue.peekFront();
    }

    // int a , d ;
    // while(!arrivalQueue.isEmpty())
    // {
    //     a = arrivalQueue.peekFront();
    //     cout << "arrival : "<<a <<endl;
    //     arrivalQueue.dequeue();

    // }
    // while(!departQueue.isEmpty())
    // {
    //     d = departQueue.peekFront();
    //     cout << "dep : "<<d <<endl;
    //     departQueue.dequeue();

    // }

    if(customerCnt>1)
    {
        int arr = 0 , dep = 0 ,cnt =0 , i =0;
        arr = arrivalQueue.peekFront();
        arrivalQueue.dequeue();
        dep = departQueue.peekFront();
        departQueue.dequeue();
        cnt = 2*customerCnt;

        while (cnt>0)
        {
            if(arr <= dep)
            {
                cout << "Processing an arrival event at time: " << arr <<endl;
                if(!arrivalQueue.isEmpty())
                    arr = arrivalQueue.peekFront();
                else
                {
                    arr=100000;
                }
            
                arrivalQueue.dequeue();
            }
            else if(dep < arr)
            {
                cout << "Processing a departure event at time: " << dep <<endl;
                if(!departQueue.isEmpty())
                    dep = departQueue.peekFront();
                departQueue.dequeue();
            }
            cnt--;
        }
    }
    
    

    cout << "Simulation Ends" <<endl;

    cout << endl;
    cout << "Final Statistics:" <<endl;
    cout << endl;
    cout << '\t'<<"Total number of people processed: " << customerCnt <<endl;
    cout << '\t'<<"Average amount of time spent waiting: " << fixed << setprecision(1)<< waitingTime/customerCnt <<endl;
    
}