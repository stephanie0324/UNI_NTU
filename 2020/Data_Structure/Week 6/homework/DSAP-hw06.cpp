#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_VAL =100;

struct items
{
    double weight;
    double value;
    double ratio;

};


//===================================Functions===================================//
double searchCp(items *itembag , int *bag , int num , int bagMax , int tmpCnt , int tmp_weight)
{
    double max =0;
    int tmp_i =0;
    double tmpW =0;
    int i =0;

    while(i < num)
    {
        if(itembag[i].ratio > max && itembag[i].weight + tmp_weight<=bagMax)
        {
            max = itembag[i].ratio;
            tmp_i = i;
            tmpW = itembag[i].weight;
        }
        i++;
    }
    itembag[tmp_i].weight = 0;
    itembag[tmp_i].value = 0;
    itembag[tmp_i].ratio = 0;
    bag[tmpCnt] = tmp_i+1;
    tmp_weight = tmp_weight + tmpW;

    return tmp_weight;


}

bool overMax(items *itembag , double tmp_weight , int num , int bagMax)
{
    int i =0;
    while(i < num)
    {
        if(itembag[i].value!=0 && itembag[i].weight+tmp_weight <= bagMax){
            return true;
            break;
        }
        i++;
    }
    return false;
}







//=========================Function End=======================================//

int main()
{
    items itembag[MAX_VAL];
    int bag[MAX_VAL];
    int num = 0 ,  bagMax =0;
    cin >> num >> bagMax;
    double tmp_weight;
    int tmpCnt = 0;
    bool canFill = true;

    //輸入資料 放入itembag裡面
    for(int i = 0 ; i < 2 ; i++)
    {
        int tmp = 0;
        for(int j = 0 ; j < num ; j++)
        {
            int a;
            cin >>a;
            if(i==0)
            {
                itembag[tmp].value = a;
                tmp++;
            }
            if(i==1)
            {
                itembag[tmp].weight =a;
                itembag[tmp].ratio = itembag[tmp].value / itembag[tmp].weight;
                tmp++;
            }
        }
    }

    // cout << "finishItembag" <<endl;


    while(canFill ==true)
    {
        tmp_weight = searchCp(itembag , bag , num , bagMax , tmpCnt , tmp_weight);
        canFill = overMax(itembag , tmp_weight, num , bagMax);
        tmpCnt++;
    }

    sort(bag , bag+tmpCnt);


    for(int i = 0 ; i < tmpCnt ; i++){
       if(i<tmpCnt-1){
           cout << bag[i]<<",";
       }else{
           cout << bag[i] << ";" << tmp_weight<<endl;
       }
        
    }
    return 0;
}