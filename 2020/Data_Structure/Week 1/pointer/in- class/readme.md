# Answer
## Problem 1
```
int main()
{
  int anInteger = 0;
  cout << &anInteger << "\n";
  for(int i = 0; i < 10; i++)
  {
    int anotherInteger = 0;
    cout << &anotherInteger << "\n";
  }
  return 0;
}
```
## Problem 2
```
int main() 
{
    int a = 0;
    int *p = NULL;
    cin >> a;
    p = &a;
    cin >> *p ;
    cout << a << "\n";
    return 0;
}
```
## Problem 3
```
int* maxPtr(int* a, int* b)
{
    return *a > *b ? a : b;
}
int main() {
int a = 0, b = 0;
cin >> a >> b;
cout << *maxPtr(&a, &b) << "\n"; return 0;
}
```
## Problem 4
```
// No error
```
## Problem 5
```
int* max(int a, int b)
{
    int* cPtr = new int(a);  // c is a pointer
    if(b > a)
        *cPtr = b;
    return cPtr;
}
int main()
{
    int a = 0, b = 0;
    cin >> a >> b;
    int* maxAddr = max(a, b);
    cout << *maxAddr << "\n"; 
    delete maxAddr; // to avoid memory leak 
    return 0;
}
```
## Problem 6
```
const int NODE_CNT_MAX = 100;
int inputGraphInfo(int* neighbors[], int degrees[]);
void printGraph(int* neighbors[], const int degrees[], int nodeCnt); 
void releaseMemory(int* neighbors[], int nodeCnt);

int inputGraphInfo(int* neighbors[], int degrees[])
{
    int nodeCnt = 0;
    cin >> nodeCnt;
    for(int i = 0; i < nodeCnt; i++) {
        cin >> degrees[i];
        neighbors[i] = new int[degrees[i]];
        for(int j = 0; j < degrees[i]; j++)
            cin >> neighbors[i][j];
    }
    return nodeCnt;
}

void printGraph(int* neighbors[], const int degrees[],int nodeCnt)
{
    int matrix[nodeCnt][nodeCnt];
    for(int i = 0 ; i < nodeCnt ; i ++)
        for(int j = 0 ; j < nodeCnt ;j++)
            matrix[i][j] = 0;
    for(int i = 0; i < nodeCnt; i++)
        for(int j = 0; j < degrees[i]; j++)
            matrix[i][neighbors[i][j]] = 1;
    for(int i = 0 ; i < nodeCnt ; i++)
        for(int j = 0 ; j < nodeCnt ; j++)
            if(j != nodeCnt-1)
                cout << matrix[i][j] << " ";
            else
                cout<<matrix[i][j] <<endl;
}

void releaseMemory(int* neighbors[],int nodeCnt)
{
    for(int i = 0; i < nodeCnt; i++)
        delete [] neighbors[i];
}

int main() {
    int* neighbors[NODE_CNT_MAX] = {0};
    int degrees[NODE_CNT_MAX] = {0};
    int nodeCnt = inputGraphInfo(neighbors, degrees);
    printGraph(neighbors, degrees, nodeCnt);
    releaseMemory(neighbors, nodeCnt);
    return 0;
    
}
```
## Problem 7
```
int inputGraphInfo(int**&neighbors, int *&degrees);
void printGraph(int** neighbors, const int *degrees, int nodeCnt);
void releaseMemory(int** neighbors, int nodeCnt);

int inputGraphInfo(int**& neighbors, int *&degrees)
{
    int nodeCnt = 0;
    cin >> nodeCnt;
    neighbors = new int*[nodeCnt];
    degrees = new int [nodeCnt];
    for(int i = 0; i < nodeCnt; i++) {
        cin >> degrees[i];
        neighbors[i] = new int[degrees[i]];
        for(int j = 0; j < degrees[i]; j++)
            cin >> neighbors[i][j];
    }
    return nodeCnt;
}

void printGraph(int* neighbors[], const int degrees[],int nodeCnt)
{
    int matrix[nodeCnt][nodeCnt];
    for(int i = 0 ; i < nodeCnt ; i ++)
        for(int j = 0 ; j < nodeCnt ;j++)
            matrix[i][j] = 0;
    for(int i = 0; i < nodeCnt; i++)
        for(int j = 0; j < degrees[i]; j++)
            matrix[i][neighbors[i][j]] = 1;
    for(int i = 0 ; i < nodeCnt ; i++)
        for(int j = 0 ; j < nodeCnt ; j++)
            if(j != nodeCnt-1)
                cout << matrix[i][j] << " ";
            else
                cout<<matrix[i][j] <<endl;
}

void releaseMemory(int* neighbors[],int nodeCnt)
{
    for(int i = 0; i < nodeCnt; i++)
        delete [] neighbors[i];
}

int main() {
    int** neighbors = 0;
    int *degrees = 0 ;
    int nodeCnt = inputGraphInfo(neighbors, degrees);
    printGraph(neighbors, degrees, nodeCnt);
    releaseMemory(neighbors, nodeCnt);
    return 0;
    
}
```

