## problem 1
```
bool isMyPunct(char c, string punct);

int main()
{
  string s = "";
  getline(cin, s);
  
  int numMyPunct = 0;
  for(int i = 0; i < s.length(); i++)
    if(isMyPunct(s[i], ",.:;!?"))
      numMyPunct++;
  
  cout << numMyPunct << endl;
  
  return 0;
}

bool isMyPunct(char c, string punct)
{
  for(int i = 0; i < punct.length(); i++)
    if(c == punct[i])
      return true;
  return false;
}
```
## problem 2
```
void makeLowercase(string& str);

int main()
{
  int wordCnt = 0;
  cin >> wordCnt;
  string target = "";
  cin >> target;
  makeLowercase(target);
  
  string* dict = new string[wordCnt];
  for(int i = 0; i < wordCnt; i++)
    cin >> dict[i];
  
  // just a linear search
  bool targetExist = false;
  for(int i = 0; i < wordCnt; i++)
  {
    if(target.compare(dict[i]) == 0)
    {
      cout << 1; 
      targetExist = true;
      break;
    }
  }
  if(targetExist == false)
    cout << 0;

  delete [] dict;

  return 0;
}

void makeLowercase(string& str)
{
  for(int i = 0; i < str.length(); i++)
    str[i] = tolower(str[i]);
}
```
## problem 3
```
const int MAX_DIGIT = 100;

string toDollarNumber(int value)
{
  // one way of converting an integer to a C++ string
  // char c[MAX_DIGIT] = {0};
  // itoa(value, c, 10);
  // string s = c;

  // another way
  string s = to_string(value);
  
  string dn = "$";
  int n = s.length();

  int startPos = n % 3;
  if(startPos == 1)
    dn = dn + s[0] + ",";
  else if(startPos == 2)
    dn = dn + s.substr(0, 2) + ",";

  for(int i = startPos; i < n; i += 3)
    dn = dn + s.substr(i, 3) + ",";
  dn.erase(dn.length() - 1);
  
  return dn;
}

int main()
{
  int dollar = 0;
  cin >> dollar; 
  
  cout << toDollarNumber(dollar) << endl;
  
  return 0;
}
```
## problem 4
```
void makeLowercase(string& str);
bool isInDict(string target, string dict[], int wordCnt);


int main()
{
  int wordCnt = 0;
  cin >> wordCnt;

  string target = "";
  cin >> target;
  makeLowercase(target);
  
  string filePath = "";
  cin >> filePath;
  
  ifstream fin(filePath);
  if(fin)
  {
    string* dict = new string[wordCnt];
    for(int i = 0; i < wordCnt; i++)
      fin >> dict[i];
    
    cout << isInDict(target, dict, wordCnt) << endl;
  
    delete [] dict;
  }
  fin.close();

  return 0;
}

void makeLowercase(string& str)
{
  for(int i = 0; i < str.length(); i++)
    str[i] = tolower(str[i]);
}

bool isInDict(string target, string dict[], int wordCnt)
{
  for(int i = 0; i < wordCnt; i++)
  {
    if(target.compare(dict[i]) == 0)
      return true;
  }
  return false;
}
```
## problem 5
```
void makeLowercase(string& str);
bool isInDict(string target, ifstream& fin);


int main()
{
  string target = "";
  cin >> target;
  makeLowercase(target);
  
  string filePath = "";
  cin >> filePath;
  
  ifstream fin(filePath);
  if(fin)
    cout << isInDict(target, fin) << endl;
  fin.close(); 

  return 0;
}
```
## problem 6
```

void makeLowercase(string& str);
bool isInDict(string target, ifstream& fin);


int main()
{
  string target = "";
  cin >> target; // be careful!!
  cin.ignore(); 
  makeLowercase(target);
  
  string filePath = "";
  getline(cin, filePath); // be careful!!
  
  ifstream fin(filePath);
  if(fin)
    cout << isInDict(target, fin) << endl;
  fin.close(); 

  return 0;
}

void makeLowercase(string& str)
{
  for(int i = 0; i < str.length(); i++)
    str[i] = tolower(str[i]);
}

bool isInDict(string target, ifstream& fin)
{
  while(!fin.eof())
  {
    string current = ""; 
    getline(fin, current);

    if(target.compare(current) == 0)
      return true;
  }
  return false;
}
```
## problem 7
```
void makeLowercase(string& str);
bool isInDict(string target, string dict[], int wordCnt);


int main()
{
  string target = "";
  cin >> target;
  
  string filePath = "";
  cin >> filePath;
  
  int wordCnt = 0;
  ifstream fin(filePath);
  if(fin)
  {
    while(!fin.eof())
    {
      string temp = ""; 
      getline(fin, temp);
      wordCnt++;
    }
    fin.seekg(0, fin.beg);

    string* dict = new string[wordCnt];
    for(int i = 0; i < wordCnt; i++)
      fin >> dict[i];
    
    cout << isInDict(target, dict, wordCnt) << endl;
  
    delete [] dict;
  }
  fin.close(); 

  return 0;
}

void makeLowercase(string& str)
{
  for(int i = 0; i < str.length(); i++)
    str[i] = tolower(str[i]);
}

bool isInDict(string target, string dict[], int wordCnt)
{
  ofstream fout("out.txt");
  string orignalTarget = target; 
  makeLowercase(target);
  for(int i = 0; i < wordCnt; i++)
  {
    fout << "Comparing " << orignalTarget << " with " << dict[i];
    if(target.compare(dict[i]) == 0)
    {
      fout << "... Got it!" << endl;
      return true;
    }
    fout << endl;
  }
  fout.close();
  return false;
}
```
## problem 8
```
// class definition of MyVector
class MyVector
{
friend bool operator==(double d, const MyVector& v);
friend ostream& operator<<(ostream& out, const MyVector& v);
friend istream& operator>>(istream& in, MyVector& v);

private:
  static double equalityGap;
  int n; 
  double* m; 
public:
  MyVector();
  MyVector(int n, double m[]);  
  MyVector(const MyVector& v);
  const MyVector& operator=(const MyVector& v);
  ~MyVector();
  void print() const; 
  
  bool operator==(const MyVector& v) const;
  bool operator==(double d) const;
// end of class definition of MyVector
};

bool operator==(double d, const MyVector& v);






double MyVector::equalityGap = 0.00001;




// MyVector's instance functions
MyVector::MyVector(): n(0), m(NULL) 
{
}
MyVector::MyVector(int n, double m[])
{
  this->n = n;
  this->m = new double[n];
  for(int i = 0; i < n; i++)
    this->m[i] = m[i];
}
MyVector::MyVector(const MyVector& v)
{
  this->n = v.n;
  this->m = new double[n];
  for(int i = 0; i < n; i++)
    this->m[i] = v.m[i];	
}
const MyVector& MyVector::operator=(const MyVector& v)
{
  if(this != &v)
  {
    if(this->n != v.n)
    {
      delete [] this->m;
      this->n = v.n;
      this->m = new double[this->n];
    }
    for(int i = 0; i < n; i++)
      this->m[i] = v.m[i];
  }  
  return *this;
}
MyVector::~MyVector() 
{ 
  delete [] m; 
}
void MyVector::print() const 
{
  cout << "(";
  for(int i = 0; i < n - 1; i++)
    cout << m[i] << ", ";
  cout << m[n-1] << ")\n";
}
// end of MyVector's instance functions

// MyVector's overloaded operators
bool MyVector::operator==(const MyVector& v) const
{
  if(this->n != v.n)
    return false;
  else
  {
    for(int i = 0; i < n; i++)
    {
      if(this->m[i] != v.m[i])
      return false;
    }
  }	
  return true;
}
bool MyVector::operator==(double d) const
{
  for(int i = 0; i < n; i++)
  {
    if(abs(this->m[i] - d) > MyVector::equalityGap)
      return false;
  }
  return true;
}






int main()
{
  double d = 1.23;
  MyVector v;
  
  ifstream fin("text\\MyVector.txt");
  ofstream fout("text\\out.txt");
  fin >> v;
  fout << v << endl;
  
  if(d == v)
    fout << "Equal!";
  else
    fout << "Unequal!";

  fin.close();
  fout.close();

  return 0;
}






bool operator==(double d, const MyVector& v) 
{
  return (v == d);
}

ostream& operator<<(ostream& out, const MyVector& v)
{
  out << "(";
  for(int i = 0; i < v.n - 1; i++)
    out << v.m[i] << ", ";
  out << v.m[v.n - 1] << ")";
  return out;
}
istream& operator>>(istream& in, MyVector& v)
{
  int tempN = 0;
  in >> tempN;
  if(tempN != v.n)
  {
    v.n = tempN;
    delete [] v.m;
    v.m = new double[tempN];
  }
  for(int i = 0; i < v.n; i++)
    in >> v.m[i];
  return in;
}
```
