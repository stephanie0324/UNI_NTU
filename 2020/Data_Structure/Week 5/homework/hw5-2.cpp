#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int Max_Val = 1000;


//============================================================================
// Item
// 若為 1，表示該道具是所有角色都可以使用的;若為 2，只有戰士可以 使用;若為 3，只有巫師可以使用。
//============================================================================

struct typeArray
{
  string name;
  int type;
};

template <typename Itemtype>
class BagInterface 
{
public:
  virtual int getCurrentSize() const = 0;
  virtual bool isEmpty() const = 0;
  virtual void add(const Itemtype& name) = 0;
};

//---------------NODE---------------------------//

template<class Itemtype>
class Node
{
private:
  Itemtype item;
  Node<Itemtype>* next; 
public:
  Node();
  Node(const Itemtype& anItem);
  Node(const Itemtype& anItem, Node<Itemtype>* nextNodePtr);
  void setItem(const Itemtype& anItem);
  void setNext(Node<Itemtype>* nextNodePtr);
  Itemtype getItem() const;
  Node<Itemtype>* getNext() const;
}; 

template<class Itemtype>
Node<Itemtype>::Node() : next(nullptr)
{
} 

template<class Itemtype>
Node<Itemtype>::Node(const Itemtype& anItem) : item(anItem), next(nullptr)
{
} 

template<class Itemtype>
Node<Itemtype>::Node(const Itemtype& anItem, Node<Itemtype>* nextNodePtr) :
                item(anItem), next(nextNodePtr)
{
} 

template<class Itemtype>
void Node<Itemtype>::setItem(const Itemtype& anItem)
{
  item = anItem;
} 

template<class Itemtype>
void Node<Itemtype>::setNext(Node<Itemtype>* nextNodePtr)
{
  next = nextNodePtr;
} 

template<class Itemtype>
Itemtype Node<Itemtype>::getItem() const
{
  return item;
} 

template<class Itemtype>
Node<Itemtype>* Node<Itemtype>::getNext() const
{
  return next;
}


//----------------LINKED----------------------//

template<typename Itemtype>
class LinkedBag: public BagInterface<Itemtype>
{
private:
    Node<Itemtype> *headPtr;
    int itemCnt;
public:
    virtual bool isEmpty() const = 0;
    virtual int getCurrentSize() const = 0;
    virtual void add(const Itemtype& newEntry);
    virtual void remove(const Itemtype& anEntry);
    virtual Node<Itemtype> *getPointerTo(const Itemtype& anEntry) const = 0;
    virtual bool contains(const Itemtype& anEntry) const = 0;
    virtual void clear();
    virtual void getItemList();
    LinkedBag(); //default constructor
    LinkedBag(const LinkedBag<Itemtype>& aBag); //copt constructor
    virtual ~LinkedBag();  //destructor



};


template<typename Itemtype>
bool LinkedBag<Itemtype>::isEmpty() const 
{
    return itemCnt == 0; 
}
template<typename Itemtype>
int LinkedBag<Itemtype>::getCurrentSize() const 
{
    return itemCnt;
}

template<typename Itemtype>
void LinkedBag<Itemtype>::add(const Itemtype& newEntry) 
{
    Node<Itemtype>* newNodePtr = new Node<Itemtype>();
    newNodePtr->setItem(newEntry); 
    newNodePtr->setNext(headPtr);
    headPtr = newNodePtr; 
    itemCnt++;
}

template<typename Itemtype>
void LinkedBag<Itemtype>::remove(const Itemtype& anEntry)
{
    Node<Itemtype>* entryNodePtr = getPointerTo(anEntry); // step 1 
    bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr); 
    if(canRemoveItem)
    {
        entryNodePtr->setItem(headPtr->getItem()); // step 2 
        Node<Itemtype>* nodeToDeletePtr = headPtr; // step 3 
        headPtr = headPtr->getNext();
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;
        itemCnt--; 
    }
}
template<typename Itemtype>
bool LinkedBag<Itemtype>::contains(const Itemtype& anEntry) const 
{
    return (getPointerTo(anEntry) != nullptr); 
}

template<typename Itemtype> 
Node<Itemtype>* LinkedBag<Itemtype>::getPointerTo(const Itemtype& anEntry) const 
{
    bool found = false;
    Node<Itemtype>* curPtr = headPtr; 
    while(!found && (curPtr != nullptr)) 
    {
        if(anEntry == curPtr->getItem()) 
            found = true;
        else
            curPtr = curPtr->getNext();
    }
    return curPtr; 
}

template<typename Itemtype>
void LinkedBag<Itemtype>::clear() 
{
    Node<Itemtype>* nodeToDeletePtr = headPtr; 
    while(headPtr != nullptr)
    {
        headPtr = headPtr->getNext();
        delete nodeToDeletePtr;
        nodeToDeletePtr = headPtr;
    }
    itemCnt = 0;
}


template<typename Itemtype>
void LinkedBag<Itemtype>::getItemList()
{
    string tmp[itemCnt];
    for(int i = 0 ; i < itemCnt ; i++){
        tmp[i] = headPtr->getItem();
        headPtr = headPtr->getNext();
    }
    for(int i =0; i<itemCnt ; i++){
        cout << tmp[i]<< " ";
    }
    cout << endl;
}



//-------------------------------Con & Destructors-----------------------------//
template<typename Itemtype>
LinkedBag<Itemtype>::LinkedBag():headPtr(nullptr),itemCnt(0)
{}

template<typename Itemtype>
LinkedBag<Itemtype>::~LinkedBag()
{
    clear();
}


//deep copy version
template<typename Itemtype>
LinkedBag<Itemtype>::LinkedBag(const LinkedBag<Itemtype>& aBag)
{
    itemCnt = aBag->itemCnt;
    Node<Itemtype>* origChainPtr = aBag->headPtr; 
    if(origChainPtr == nullptr)
        headPtr = nullptr; 
    else
    {
        headPtr = new Node<Itemtype>(); 
        headPtr->setItem(origChainPtr->getItem());
        Node<Itemtype>* newChainPtr = headPtr; 
        while(origChainPtr != nullptr)
        {
            origChainPtr = origChainPtr->getNext();
            Itemtype nextItem = origChainPtr->getItem();
            Node<Itemtype>* newNodePtr = new Node<Itemtype>(nextItem);
            newChainPtr->setNext(newNodePtr);
            newChainPtr = newChainPtr->getNext();
        }
        newChainPtr->setNext(nullptr); 
    }
}

//============================================================================
// End of Item
//============================================================================

// ===========================================================================
// Character, Warrior, Wizard, and Team 
// ===========================================================================

class Character
{
protected:
  static const int EXP_LV = 100;
  string name;
  int level;
  int bag_max;
  int career;
public:
  Character(string n, int lv, int bm , int career);
  LinkedBag <string> itemBag;
  string getName();
  int getBagMax();
  int getCareer();
  void useItem(const string& item_name , int ta_cnt , typeArray *ta);
};


Character::Character(string n, int lv, int bm , int career) 
  : name(n), level(lv), bag_max(bm), career(career)
{
}


string Character::getName()
{
  return this->name;
}


int Character::getBagMax()
{
  return this ->bag_max;  
}


int Character::getCareer()
{
  return this ->career;  
}


void Character::useItem(const string& item_name , int ta_cnt , typeArray *ta)
{
  if(this->itemBag.contains(item_name)==true){
    // cout <<"yyy"<<endl;
    for(int j = 0 ; j < ta_cnt ; j++){
      if((ta[j].name).compare(item_name)==0){
        if(ta[j].type == 1){
          this->itemBag.remove(item_name);
        }else if(ta[j].type == this->getCareer()){
          this->itemBag.remove(item_name);
        }else if(ta[j].type != this->getCareer())
          cout <<"cannot use it"<<endl;
      }
    }
  }else{
    cout << "does the character own it?"<<endl;
  }
}


class Warrior : public Character
{
private:
public:
  Warrior(string n, int lv , int bm ,int career) : Character(n, lv, bm ,career) {}
};


class Wizard : public Character
{
private:
public:
  Wizard(string n, int lv , int bm , int career) : Character(n, lv, bm ,career) {}
};


//=====================================================
// oop(p. 49)

class Team
{
private:
  int memberCount;
  Character *member[10];
public:
  Team();
  ~Team();
};


//======================================================
//opp(p. 50)


Team::Team()
{
  this->memberCount = 0;
  for(int i = 0; i < 10; i++)
    member[i] = nullptr;
}


Team::~Team()
{
  for(int i = 0; i < this->memberCount; i++)
    delete this->member[i];
}

// ===========================================================================
// End of Character, Warrior, Wizard, and Team 
// ===========================================================================




int main()
{
  Character *member[10];
  typeArray ta[Max_Val];
  string order;
  string sub;

  //各種cnt
  int characterCnt = 0;
  int ta_cnt = 0;
  int itembagCnt = 0;
  while(cin)
  {
    
    getline(cin , order ,' ');
    bool exists =false;
    // 增加一個戰士角色
    if(order.compare("R")==0)
    {
      string name;
      int lv = 0;
      int bm = 0;
      // cout << "addWAR" << endl;
      getline(cin , sub , ' ');
      name = sub;
      //---------檢查是否存在-------------
      for(int i = 0 ; i < characterCnt ; i++){
        if(member[i]->getName()==name){
          exists = true;
        }
      }
      if(exists ==true)
      {
        cout << "the character exists" <<endl;
        getline(cin , sub , '\n');
      }
      else{
        getline(cin , sub , ' ');
        lv = stoi(sub);
        getline(cin , sub , '\n');
        bm = stoi(sub);
        member[characterCnt] = new Warrior(name , lv , bm , 2);
        characterCnt++;
      }
    }
    //增加一個巫師
    else if(order.compare("D")==0)
    {
      string name;
      int lv = 0;
      int bm = 0;
      // cout << "addWIZ" << endl;
      getline(cin , sub , ' ');
      name = sub;
      //---------檢查是否存在-------------
      for(int i = 0 ; i < characterCnt ; i++){
        if(member[i]->getName()==name){
          exists = true;
        }
      }
      if(exists ==true)
      {
        cout << "the character exists"<<endl;
        getline(cin,sub,'\n');
      }
      else{
        getline(cin , sub , ' ');
        lv = stoi(sub);
        getline(cin , sub , '\n');
        bm = stoi(sub);
        member[characterCnt] = new Wizard(name , lv , bm , 3);
        characterCnt++;
      }
    //增加道具
    }else if(order.compare("A")== 0)
    {
      // cout << "Add" <<endl;
      string name;
      string item_name;
      int type;
      getline(cin , sub , ' ');
      name = sub;
      getline(cin , sub , ' ');
      item_name = sub;
      getline(cin , sub , '\n');
      type = stoi(sub);

      //先記錄屬性,不重複紀錄
      bool ta_exists = false;
      for(int i = 0 ; i < ta_cnt ; i++){
        if(ta[i].name==item_name){
          ta_exists = true;
        }
      }
      if(ta_exists==false){
        ta[ta_cnt].name = item_name;
        ta[ta_cnt].type = type;
        ta_cnt++;
      }
    

      //放入包包
      for(int i = 0 ; i < characterCnt ; i++){
        if(member[i]->getName()==name)
        {
          exists = true;
          // cout << member[i]->itemBag.getCurrentSize() <<endl;
          // cout << member[i]->getBagMax() <<endl;
          if(member[i]->itemBag->getCurrentSize()< member[i]->getBagMax())
          {
            member[i]->itemBag->add(item_name);
          }
          else
          {
            cout << "no more capacity"<<endl;
          }
        }
      }
      if(exists==false){
        cout <<"no such a character"<<endl;
      }
    // //該角色包包中有沒有道具
    // }else if(order.compare("H")== 0){
    //   string name;
    //   string item_name;
    //   getline(cin , sub ,' ');
    //   name = sub;
    //   getline(cin,sub,'\n');
    //   item_name = sub;
    //   for(int i = 0 ; i < characterCnt ; i++){
    //     if(member[i]->getName()== name){
    //       exists = true;
    //       if(member[i]->itemBag->contains(item_name)==true){
    //         cout << "yes"<<endl;
    //       }else{
    //         cout << "no"<<endl;
    //       }
    //     }
    //   }
    //   if(exists==false)
    //     cout << "no such a character"<<endl;
    // //該角色使用道具
    // }else if(order.compare("U")== 0){
    //   // cout << "uuu" <<endl;
    //   string name;
    //   string item_name;
    //   getline(cin,sub,' ');
    //   name = sub;
    //   getline(cin,sub,'\n');
    //   item_name = sub;
    //   for(int i = 0 ; i < characterCnt ; i++){
    //     if(member[i]->getName()==name){
    //       exists = true;
    //       member[i]->useItem(item_name , ta_cnt , ta);
    //     }
    //   }
    //   if(exists==false)
    //     cout << "no such a character"<<endl;
    // //印出東西
    // }else if(order.compare("L")== 0){
    //   // cout << "lll" <<endl;
    //   string name;
    //   getline(cin,sub,'\n');
    //   name = sub;
    //   for(int i = 0 ; i < characterCnt ; i++){
    //     if(member[i]->getName()==name){
    //       exists= true;
    //       if(member[i]->itemBag->getCurrentSize() > 0)
    //         member[i]->itemBag->getItemList();
    //       else 
    //         cout << "empty"<<endl;
    //     }
    //   }
    //   if(exists==false)
    //     cout << "no such a character"<<endl;
    //印出東西與數量
    // }else if(order.compare("S")== 0){
    //   // cout << "sss" <<endl;
    //   string name;
    //   getline(cin,sub,'\n');
    //   name = sub;
    //   for(int i = 0 ; i < characterCnt ; i++){
    //     if(member[i]->getName()==name){
    //       exists= true;
    //       if(member[i]->itemBag.getCurrentSize() > 0)
    //         member[i]->itemBag.getItemSummary();
    //       else 
    //         cout << "empty"<<endl;
    //     }
    //   }
    //   if(exists==false)
    //     cout << "no such a character"<<endl;
    // //丟掉東西
    // }else if(order.compare("V")== 0){
    //   // cout << "vvv" <<endl;
    //   string name;
    //   string item_name;
    //   getline(cin,sub,' ');
    //   name = sub;
    //   getline(cin,sub,'\n');
    //   item_name = sub;
    //   for(int i = 0 ; i < characterCnt ; i++){
    //     if(member[i]->getName()==name){
    //       exists= true;
    //       if(member[i]->itemBag.itemExists(item_name)==true){
    //         member[i]->itemBag.removeItem(item_name);
    //       }else{
    //         cout << "does the character own it?"<<endl;
    //       }
    //     }
    //   }
    //   if(exists==false)
    //     cout << "no such a character"<<endl;
    // }
    }
  }
  return 0;
}