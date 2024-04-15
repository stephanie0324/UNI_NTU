//
//  main.cpp
//  prac
//
//  Created by Stephanie on 2020/3/2.
//  Copyright © 2020 Stephanie. All rights reserved.
//



//--------------測值----------------
/*
 7,7
 1,2,1
 1,3,1
 2,4,1
 3,5,1
 4,6,1
 5,6,1
 6,7,1
 1,9
 */

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace  std;
 
 
bool inStack(int tmp_j ,int n,  int *stack)
{
    for(int i = 1 ; i < n ; i++)
        if(stack[i]==tmp_j)
            return true;
    return false;
};
 
void findPoints(int startPt , int dist , int m, int n  , int **graph , int *chosen_pt, int chosenCnt , int *stack )
{
    int tmp_j=0;
    int tmp_dist =0;
    
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < 2; j ++ ){
            if(graph[i][j] == startPt){
                if(j == 0){       //另一個點
                    if(graph[i][1] != chosen_pt[1]){  // 確認該點不是起始點
                        tmp_j = graph[i][1];
                        if(graph[i][2]<= dist){
                            tmp_dist = graph[i][2];
                            if(inStack(tmp_j, n , stack)==false){
                                for(int k = 0 ; k < m ; k++){   // 把距離加上去其他的node
                                    for(int l = 0 ; l < 2 ;l++){
                                        if(graph[k][l] == tmp_j)
                                            graph[k][2]+=tmp_dist;
                                    }
                                }
                                stack[chosenCnt-1] = tmp_j;
                                chosen_pt[chosenCnt] = tmp_j;
                                chosenCnt++;
                            }
                        }
                    }
                    graph[i][0] = 0;
                    graph[i][1] = 0;
                    graph[i][2] =0;
                }else{
                    if(graph[i][0] != chosen_pt[1]){  // 確認該點不是起始點
                        tmp_j =graph[i][0];
                        if(graph[i][2] <= dist){
                            tmp_dist = graph[i][2];
                            if(inStack(tmp_j, n ,stack)==false){
                                for(int k = 0 ; k < m ; k++){
                                    for(int l = 0 ; l < 2 ;l++){
                                        if(graph[k][l] == tmp_j)
                                            graph[k][2]+=tmp_dist;
                                    }
                                }
                                stack[chosenCnt-1] = tmp_j;
                                chosen_pt[chosenCnt] = tmp_j;
                                chosenCnt++;
                            }
                        }
                    }
                }
                graph[i][0] = 0;
                graph[i][1] = 0;
                graph[i][2] =0;
            }
        }
    }
     
    //數stack 有幾個
    int stackCnt =0 ;
    for(int i = 1; i < n; i++){
        if(stack[i] !=0 ){
            stackCnt++;
        }
    }
    stack[0] = stackCnt;
    chosen_pt[0] = chosenCnt;
}
 
int main(){
    char info[3][3] = {0};
    int cnt= 0,  n = 0 , m = 0 ;
     
//-----------------------處理第一行---------------------------------
    char *a = 0; // 處理第一行
    a = new char [10];
    char *b = 0;  //處理圖
    b = new char[10000];
    char *c = 0;  // 處理最後一行
    c = new char[10000];
    
    char delim[] = "," ;
    cin  >> a;
    char *start  =strtok(a, delim);
    while(start != nullptr){
        strcpy(info[cnt], start);
        cnt++;
        start = strtok(nullptr, delim);
    }
    n= atoi(info[0]);
    m = atoi(info[1]);    //將邊跟點分隔出來
    
    //delete info ,  a
    delete [] a;

//---------------------------處理圖形---------------------------------
// --------------------------將它存成整數二維陣列----------------------
    int graphCnt = 0;
    int **graph=0;
    graph = new int *[m];
    for(int i = 0 ;i < m; i++)
        graph[i] = new int [3];
    
    char tmp_graph[3][3] = {0};
    for(int i =0 ; i < m ; i++){
        cnt = 0 ;
        cin >> b;
        char *start_2  =strtok(b, delim);
        while(start_2 != nullptr){
            strcpy(tmp_graph[cnt], start_2);
            cnt++;
            start_2 = strtok(nullptr, delim);
        }
        for(int i = 0 ; i < 3 ; i++){
            graph[graphCnt][i] = atoi(tmp_graph[i]);
        }
        graphCnt++;
    }
    
    //delete b
    delete [] b;
//-------------------------處理最後一行-----------------------------------
    int startPt = 0 , dist = 0 , pt_cnt = 0;
    char tmp_pt[3][3] = {0};
    cin  >> c;
    char *start_3  =strtok(c, delim);
    while(start_3 != nullptr){
        strcpy(tmp_pt[pt_cnt], start_3);
        pt_cnt++;
        start_3 = strtok(nullptr, delim);
    }
    startPt= atoi(tmp_pt[0]);
    dist = atoi(tmp_pt[1]);
    
    //delete c
    delete [] c;
     
//    cout << startPt << " " <<dist <<endl;  //確認最後指令有被接收
     
//------------------處理符合距離個數---------------------
    int *chosen_pt = 0;
    int chosenCnt = 0 ;
    chosen_pt = new int [n];
     
    int *stack = 0;  //記錄走過的點  stackㄉ 第一格儲存stackCnt
    int stackCnt = 0;
    stack = new int [n];
    for(int i = 0 ; i < n ; i++){
        stack[i] =  0 ;
    }
    stackCnt = stack[0];
    chosen_pt[0] = 2;     // chosen_pt的第一個儲存起始點
    chosen_pt[1] = startPt;   // chosen_pt 的第二個儲存起始點
    findPoints( startPt , dist , m, n, graph , chosen_pt ,chosen_pt[0], stack);
    
    /*
     看看graph 有沒有問題

    for(int i = 0 ; i < m;i++){
        for(int j = 0 ; j  <3 ; j++){
            cout << graph[i][j] << " ";
        }
        cout <<endl;
    }
    cout <<endl;
     */
    
    
    
    chosenCnt = chosen_pt[0];
    if(chosenCnt-2 != 0){    // 第一次找startpt 連出去的點
        int tmp_stack = 1;
        do {
            chosenCnt = chosen_pt[0];
//---------------檢查第一次find有沒有錯誤----------------------
//            for(int i = 0 ; i < chosenCnt ; i++){
//                cout << stack[i] << " ";
//            }
//            cout << endl;
            findPoints(stack[tmp_stack] , dist, m, n , graph, chosen_pt, chosenCnt, stack);
            stack[tmp_stack]=0;
            stack[0] --;
            tmp_stack++;
             
//-------------檢查-----------------
//            chosenCnt = distList[0][0];
//            for(int i = 0 ; i < chosenCnt ; i++){
//                cout << stack[i] << " choosen : " << chosen_pt[i] << " ";
//            }
//            cout << endl;
//            cout << "gjhiak;f" <<endl;
//            for(int i = 0 ; i < chosenCnt;i++){
//                for(int j = 0 ; j < 2; j++){
//                    cout << distList[i][j] << " ";
//                }
//                cout << endl;
//            }
//            cout << " allalla" <<endl;
        } while (stack[0]!=0);
    }
    for(int i = 0 ; i < m ;i++){
        delete [] graph[i];
    }
    delete graph;
     
    //--------------------------整理chosen_pt 成 new_chosen-----------------------
    chosenCnt = chosen_pt[0];
    int *new_chosen = 0;
    int tmp = 0;
    new_chosen = new int [chosenCnt];
    if((chosenCnt-2) !=0){      // 確認陣列有東西
        for(int i = 2 ; i < chosenCnt ; i++){
            new_chosen[tmp] = chosen_pt[i];
            tmp++;
        }
        sort(new_chosen,new_chosen+tmp);
    }
 
    //---------------------------印出結果---------------------------
     
    if(tmp == 0){
        cout << "None" << endl;
    }else{
        for(int i = 0 ; i < tmp ; i++){
               if(i < tmp-1){
                   cout << new_chosen[i] << "," ;
               }else{
                    cout << new_chosen[i] << endl;
               }
           }
    }
}
