# include <iostream>
#include  <cctype>
#include <cstring>
#include <cmath>
using namespace std;
 
struct Node
{
    int Gen;
    int words;
};

int countWords( string sub )
{
    int wcnt =0;
    //處理字串個數
           long sublength = sub.length();
           int senCnt = 0 , wordCnt = 0;
           char sub_array[sublength + 1];
           char sub_2[sublength+1];
           strcpy(sub_array, sub.c_str());
           strcpy(sub_2, sub_array);
           
           //數句子
           char delim[] = ".,!?;";
           char *start  =strtok(sub_array, delim);
           while(start != nullptr){
               senCnt++;
               start = strtok(nullptr, delim);
           }
           //數字數
           char bar_delim[] = " ";
           char *bar = strtok(sub_2, bar_delim);
           while (bar!=nullptr) {
               wordCnt++;
               bar = strtok(nullptr, bar_delim);
           }
           wcnt += wordCnt/senCnt;
    return wcnt;
}
 
int findBestVal( Node nodes[] , int minT , int maxT , int n)
{
    int avg_wcnt = 0;
    int min_wrong =10000;
    int tmp_gen;
    for(int i = minT ; i < maxT+1 ; i++){
        int tmp_val = i;
        int sum_wrong =0;
        for(int j = 0 ; j < n ; j++){
            if(nodes[j].words <tmp_val ){
                tmp_gen = 1;
                if(tmp_gen != nodes[j].Gen)
                    sum_wrong++;
            }else{
                tmp_gen =2;
                if(tmp_gen != nodes[j].Gen)
                    sum_wrong++;
            }
        }
        if(sum_wrong < min_wrong){
            min_wrong = sum_wrong;
            avg_wcnt = tmp_val;
        }
    }
    
    return avg_wcnt;
}





int main()
{
    int n = 0 , m = 0;
    cin >> n >> m;
   
     
    //-------------- Training Sets---------------------
    int num =0;
    int wcnt = 0;
    int avg_wcnt = 0;
    int minT =1000;
    int maxT =0;
    string gender ="";
    string sub = " ";
    Node nodes[n];

 
    for(int i  = 0 ; i < n ; i++){
        getline(cin, gender , ';');
        getline(cin , sub);
        num = stoi(gender);
        nodes[i].Gen= num;
        wcnt = countWords(sub);
        nodes[i].words = countWords(sub);
        if(wcnt < minT)
            minT = wcnt;
        if(wcnt > maxT)
            maxT = wcnt;
    }

    //----------在測試值之中找出最好的測值------------------

    avg_wcnt = findBestVal(nodes, minT, maxT, n) ;
    
    
    
    
     
//-------------- Validation Set --------------
    int *correctAns;
    correctAns = new int [m];
    int *guessAns =0;
    guessAns = new int [m];
    
    for(int i =0; i<m ; i++){
        getline(cin, gender , ';');
        getline(cin,sub);
        num = stoi(gender);
        correctAns[i] = num;  //存放正確的性別比
        wcnt = countWords(sub);
        // 臨界值
        if(wcnt < avg_wcnt)
            guessAns[i] = 1;
        else
            guessAns[i] = 2;
    }
     
/*
 檢查correct answer 是否有被存
 */
//    for(int i = 0 ; i<m ; i++)
//        cout << correctAns[i] << " ";
//    cout<< endl;
//    for(int i = 0 ;i < m ; i++)
//        cout << guessAns[i] << " ";
//    cout << endl;
//    for(int i = 0 ;i < m ; i++)
//         cout << guessAns_2[i] << " ";
//     cout << endl;
//    for(int i = 0 ;i < m ; i++)
//         cout << guessAns_3[i] << " ";
//     cout << endl;
   
//-------------------比對--------------------
    int wrongCnt = 0;
    for(int i = 0 ; i < m ; i++)
        if(correctAns[i] != guessAns[i])
            wrongCnt++;

    cout << avg_wcnt << "," << wrongCnt <<endl;
    
    
    delete [] correctAns;
    delete [] guessAns;

}