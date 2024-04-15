# Answer
## problem 1
```
class Time
{
private:
    int hour;
    int minute;
    int second;
public:
    Time(int h, int m, int s);
    bool isEarlierThan(Time t);
    void print();
};

Time::Time(int h, int m, int s)
{
    hour = h; minute = m; second = s;
}

void Time::print()
{
    cout << hour << ":" << minute << ":"<< second;
}

bool Time::isEarlierThan(Time t)
{
    if(hour < t.hour)
       return true;
     else if(hour == t.hour)
     {
       if(minute < t.minute)
         return true;
       else if(minute == t.minute)
       {
         if(second < t.second)
           return true;
       }
     }
     return false;   
}

int main()
{
    int te[9] = {0};
    for(int i = 0; i < 9; i++)
      cin >> te[i];
    Time t1(te[0], te[1], te[2]);
    Time t2(te[3], te[4], te[5]);
    Time t3(te[6], te[7], te[8]);
    
    if(t1.isEarlierThan(t2))
    {
      if(t2.isEarlierThan(t3))
        cout << 3 <<endl;
      else
        cout << 2<< endl;
    }
    else
    {
      if(t1.isEarlierThan(t3))
        cout << 3 <<endl;
      else
        cout << 1 <<endl;
    }
    return 0;
}
```
## problem 2
```
class Time
{
private:
    int hour;
    int minute;
    int second;
    void printTwoDigits(int n); // new added
public:
    Time(int h, int m, int s);
    bool isEarlierThan(Time t); 
    void printNicely();   // new added
};

void Time::printTwoDigits(int n)
{
  cout << (n < 10 ? "0" : "");
  cout << n;
}

void Time::printNicely()
{
    printTwoDigits(hour);
     cout << ":";
     printTwoDigits(minute);
     cout << ":";
     printTwoDigits(second);
    cout  << endl;
}

int main()
{
    if(t1.isEarlierThan(t2))
    {
      if(t2.isEarlierThan(t3))
          t3.printNicely();
      else
          t2.printNicely();
    }
    else
    {
      if(t1.isEarlierThan(t3))
          t3.printNicely();
      else
          t1.printNicely();
    }
    
    return 0;
}
```
## problem 3
```
class Time
{
private:
    int hour;
    int minute;
    int second;
    void printTwoDigits(int n);
public:
    Time(int h, int m, int s);
    bool isEarlierThan(Time t);
    void printNicely();
    void displayFormat(); // new added
};

void Time::displayFormat()
{
    if(hour > 12){
        printTwoDigits(hour-12);
        cout << ":";
        printTwoDigits(minute);
        cout << ":";
        printTwoDigits(second);
        cout  << " "<<"PM"<< endl;
    }else if (hour == 12){
        printTwoDigits(hour);
        cout << ":";
        printTwoDigits(minute);
        cout << ":";
        printTwoDigits(second);
        cout  << " "<<"PM" <<endl;
    }else{
        printTwoDigits(hour);
        cout << ":";
        printTwoDigits(minute);
        cout << ":";
        printTwoDigits(second);
        cout  <<  endl;
    }
}

int main()
{
    if(t1.isEarlierThan(t2))
    {
      if(t2.isEarlierThan(t3))
          t3.displayFormat();
      else
          t2.displayFormat();
    }
    else
    {
      if(t1.isEarlierThan(t3))
          t3.displayFormat();
      else
          t1.displayFormat();
    }
    return 0;
}
```
## problem 
```
#include <iostream>
#include <cstring>
using namespace std;

class Time
{
private:
  static bool hourIn12;
  int hour;
  int minute;
  int second;
  void printTwoDigits(int n);
public:
  Time();
  Time(int h, int m, int s);
  static void print12Hour(bool in12);
  bool isEarlierThan(Time t);
  void print();
  void printNicely();
};

bool Time::hourIn12 = false;

void Time::print12Hour(bool in12)
{
  Time::hourIn12 = in12;
}

void Time::printTwoDigits(int n)
{
  cout << (n < 10 ? "0" : "");
  cout << n; 
}


Time::Time()
{
  hour = minute = second = 0;
}


Time::Time(int h, int m, int s)
{
  hour = h;
  minute = m;
  second = s;
}

bool Time::isEarlierThan(Time t)
{
  int numSecSelf = 3600 * hour + 60 * minute + second;
  int numSecT = 3600 * t.hour + 60 * t.minute + t.second;
  if(numSecSelf < numSecT)
    return true;
  else
    return false;
}

void Time::print()
{
  if(hourIn12 == false)
    cout << hour << ":" << minute << ":" << second;
  else
  {
    if(hour < 12)
      cout << hour << ":" << minute << ":" << second << " AM";
    else
      cout << (hour - 12) << ":" << minute << ":" << second << " PM";      
  }
}

void Time::printNicely()
{
  if(hourIn12 == false || hour < 12)
    printTwoDigits(hour);
  else
    printTwoDigits(hour - 12);
  cout << ":"; 
  
  printTwoDigits(minute); 
  cout << ":"; 
  
  printTwoDigits(second);
  
  if(hourIn12 == true)
    cout << (hour < 12 ? " AM" : " PM");
}

class Event
{
private:
  char* name;
  Time start;
  Time end;
public:
  Event(char* n, Time s, Time t);
  ~Event();
  void printNicely();
};

Event::Event(char* n, Time s, Time t)
{
  int nameLen = strlen(n);
  name = new char[nameLen + 1];
  strcpy(name, n);
  start = s;
  end = t;
}

Event::~Event()
{
  delete [] name;
}

void Event::printNicely()
{
  cout << "\"" << name << "\"\n";
  cout << "Start: ";
  start.printNicely();
  cout << "\n";
  cout << "End:   ";
  end.printNicely();
  cout << "\n";
}

int main()
{
  char n1[] = "PD";
  Event e1(n1, Time(14, 20, 0), Time(17, 20, 0));
  e1.printNicely(); // "PD"
                    // Start: 14:20:00
                    // End:   17:20:00
    
  return 0;
}
```
## problem 6
```
class Event
{
private:
  char* name;
  Time start;
  Time end;
public:
  Event(char* n, Time s, Time t);
  ~Event();
  void printNicely();
  void setName(char *n);
};

void Event::setName(char* n)
{
  delete [] name;
  
  int nameLen = strlen(n);
  name = new char[nameLen + 1];
  strcpy(name, n);  
}
```
## problem 7
```
int main()
{
  Event* schedule[10];
  char n1[] = "PD";
  schedule[0] = new Event(n1, Time(14, 20, 0), Time(17, 20, 0));
  schedule[0]->printNicely();
    
  return 0;
}

```
