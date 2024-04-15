
#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
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
 
class BagInterface 
{
public:
  virtual int getCurrentSize() const = 0;
  virtual bool isempty() const = 0;
  virtual void add(const string& name , int Capacity) = 0;
};
 
 
class ItemBag : public BagInterface 
{
private:
  static const int DEFAULT_CAPACITY = 10; 
  string items[DEFAULT_CAPACITY];
  int itemCount;
public:
  ItemBag();
  int getCurrentSize() const;
  bool isempty() const;
  void add(const string& item_name , int Capacity) throw(out_of_range);
  bool itemExists(const string& item_name);
  int getIndexOf(const string& item_name);
  void removeItem(const string& item_name);
  void sortArray();
  void getItemList();
  void getItemSummary();
};
 
ItemBag::ItemBag()
: itemCount(0){}
 
int ItemBag::getCurrentSize() const
{
  return itemCount; 
}
 
bool ItemBag::isempty() const
{
  return itemCount == 0; 
}
 
 
void ItemBag::add(const string& item_name , int Capacity) throw(out_of_range)
{
  int tmp =0;
  tmp = itemCount+1;
  if(tmp > Capacity){
    throw out_of_range("...");
  }
  items[itemCount] = item_name;
  itemCount++; 
}
 
bool ItemBag::itemExists(const string& item_name)
{
  for(int i = 0 ; i < itemCount;i++){
    if(items[i].compare(item_name)==0){
      return true;
    }
  }
  return false;
}
 
int ItemBag::getIndexOf(const string& item_name)
{
  bool found = false;
  int result = -1;
  int searchIndex =0;
  while(!found && (searchIndex<itemCount))
  {
    if(items[searchIndex]==item_name)
    {
      found = true;
      result = searchIndex;
    }
    else
    {
      searchIndex++;
    }
  }
  return result;
}
 
void ItemBag::removeItem(const string& item_name)
{
  int locatedIndex = getIndexOf(item_name);
  bool can_remove = (locatedIndex > -1);
  if(can_remove)
  {
    itemCount--;
    items[locatedIndex] = items[itemCount];
  }else if(locatedIndex == 0)
  {
    itemCount--;
    items[locatedIndex]= " ";
  }
 
}
 
void ItemBag::sortArray()
{
  string tmp;
  for(int i = 0 ; i <itemCount-1 ;i++){
    for(int j = i+1 ; j < itemCount ; j++){
      if(items[i].compare(items[j])> 0){
        tmp = items[i];
        items[i] = items[j];
        items[j] = tmp;
      }
    }
  }
}
 
void ItemBag::getItemList()
{
  this->sortArray();
  for(int i = 0 ; i < itemCount ; i++){
    if(i < itemCount-1)
      cout << items[i]<<",";
    else
    {
      cout << items[i];
    }
     
  }
  cout << endl;
}
 
void ItemBag::getItemSummary()
{
  this->sortArray();
  int tmpCnt = 1;
  if(this->itemCount==1)
  {
    cout << items[0] <<","<<tmpCnt;
  }else if(this->itemCount==2){
    if(this->items[0].compare(this->items[1])==0){
      cout << items[0] <<","<< 2;
    }else{
      cout << items[0] <<","<< 1 <<";"<<items[1]<<","<< 1;
    }
 
  }else{
    for(int i = 0 ; i < this->itemCount ; i++){
      if(i < itemCount -1 && i != itemCount-1)
      {
        if(this->items[i].compare(this->items[i+1])==0){
          tmpCnt++;
        }else
        {
          cout << this->items[i] << "," << tmpCnt << ";" ;
          tmpCnt = 1;
        }
      }else{
        if(this->items[i].compare(this->items[i-1])==0){
          cout << this->items[i] << "," << tmpCnt;
        }else
          cout << this->items[i] << "," << tmpCnt;
      }
    }
  }
  cout << endl;
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
  string name;
  int level;
  int bag_max;
  int career;
public:
  Character(string n, int lv, int bm , int career);
  ItemBag itemBag;
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
  if(this->itemBag.itemExists(item_name)==true){
    // cout <<"yyy"<<endl;
    for(int j = 0 ; j < ta_cnt ; j++){
      if((ta[j].name).compare(item_name)==0){
        if(ta[j].type == 1){
          this->itemBag.removeItem(item_name);
        }else if(ta[j].type == this->getCareer()){
          this->itemBag.removeItem(item_name);
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
  Character* member[10];
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
  string name;
  string item_name;
  int lv=0 , bm = 0 , type =0;
 
  //各種cnt
  int characterCnt = 0;
  int ta_cnt = 0;
  int itembagCnt = 0;
  while(cin>>order)
  {
    bool exists = false;
    // 增加一個戰士角色
    if(order.compare("R")==0)
    {
      // cout << "addWAR" << endl;
      cin>>name>>lv>>bm;
      //---------檢查是否存在-------------
      for(int i = 0 ; i < characterCnt ; i++){
        if(member[i]->getName()==name){
          exists = true;
        }
      }
      if(exists ==true)
      {
        cout << "the character exists" <<endl;
      }
      else{
        member[characterCnt] = new Warrior(name , lv , bm , 2);
        characterCnt++;
      }
    }
    //增加一個巫師
    else if(order.compare("D")==0)
    {
      // cout << "addWIZ" << endl;
      cin >> name >> lv >> bm;
      //---------檢查是否存在-------------
      for(int i = 0 ; i < characterCnt ; i++){
        if(member[i]->getName()==name){
          exists = true;
        }
      }
      if(exists ==true)
      {
        cout << "the character exists"<<endl;
      }
      else{
        member[characterCnt] = new Wizard(name , lv , bm , 3);
        characterCnt++;
      }
    //增加道具
    }else if(order.compare("A")== 0)
    {
      // cout << "Add" <<endl;
      cin >> name >> item_name >> type;
 
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
          try
          {
            member[i]->itemBag.add(item_name,member[i]->getBagMax());
          }
          catch(out_of_range e)
          {
            cout << "no more capacity"<<endl;
          }
        }
      }
      if(exists==false){
        cout <<"no such a character"<<endl;
      }
    //該角色包包中有沒有道具
    }else if(order.compare("H")== 0){
      // cout << "hhhh" <<endl;
      cin >> name >> item_name;
      for(int i = 0 ; i < characterCnt ; i++){
        if(member[i]->getName()== name){
          exists = true;
          if(member[i]->itemBag.itemExists(item_name)==true){
            cout << "yes"<<endl;
          }else{
            cout << "no"<<endl;
          }
        }
      }
      if(exists==false)
        cout << "no such a character"<<endl;
    //該角色使用道具
    }else if(order.compare("U")== 0){
      // cout << "uuu" <<endl;
      cin >> name >> item_name;
      for(int i = 0 ; i < characterCnt ; i++){
        if(member[i]->getName()==name){
          exists = true;
          member[i]->useItem(item_name , ta_cnt , ta);
        }
      }
      if(exists==false)
        cout << "no such a character"<<endl;
    //印出東西
    }else if(order.compare("L")== 0){
      // cout << "lll" <<endl;
      cin >> name;
      for(int i = 0 ; i < characterCnt ; i++){
        if(member[i]->getName()==name){
          exists= true;
          if(member[i]->itemBag.getCurrentSize() > 0)
            member[i]->itemBag.getItemList();
          else
            cout << "empty"<<endl;
        }
      }
      if(exists==false)
        cout << "no such a character"<<endl;
    //印出東西與數量
    }else if(order.compare("S")== 0){
      // cout << "sss" <<endl;
      cin >> name;
      for(int i = 0 ; i < characterCnt ; i++){
        if(member[i]->getName()==name){
          exists= true;
          if(member[i]->itemBag.getCurrentSize() > 0)
            member[i]->itemBag.getItemSummary();
          else
            cout << "empty"<<endl;
        }
      }
      if(exists==false)
        cout << "no such a character"<<endl;
    //丟掉東西
    }else if(order.compare("V")== 0){
      // cout << "vvv" <<endl;
      cin >> name >> item_name;
      for(int i = 0 ; i < characterCnt ; i++){
        if(member[i]->getName()==name){
          exists= true;
          if(member[i]->itemBag.itemExists(item_name)==true){
            member[i]->itemBag.removeItem(item_name);
          }else{
            cout << "does the character own it?"<<endl;
          }
        }
      }
      if(exists==false)
        cout << "no such a character"<<endl;
    }
  }
  return 0;
}
