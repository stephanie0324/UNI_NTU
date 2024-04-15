#include <iostream>
#include <algorithm>
using namespace  std;







int main()
{
    string **dynamicMatrix;
    int *result;
    int *Arr;
    int num = 0 , Bagmax =0;
    cin >> num >> Bagmax;
    result = new int[num];
    Arr = new int[num];
    dynamicMatrix = new string *[num];
    for(int i = 0 ; i < num ; i++){
        dynamicMatrix[i] = new string[Bagmax+1];
    }
    int tmpCnt =0;
    for(int i = 0 ; i < num ; i++){
        cin >> Arr[i];
    }




    for(int i = 0 ; i < num ; i++){
        for(int j = 0 ; j < Bagmax+1; j++){
            dynamicMatrix[i][j] = "Q";
        }
    }

    //--------------------檢查sortArray(沒問題)------------------//
    // for(int i = 0 ; i <  num; i++){
    //     cout << Arr[i].number << " " << Arr[i].spot<< endl;
    // }



    //------------------------drawMatrix-----------------------------------------
    for(int i = 0 ; i < num ; i ++){
        for(int j = 0 ; j<Bagmax+1; j++){
            if(i==0){      //第一行
                if(j==0){
                     dynamicMatrix[i][j] = "N";
                }else if(Arr[i]==j){
                    dynamicMatrix[i][j] = "S";
                }else{
                    dynamicMatrix[i][j] = "I";
                }
            }else{
                if(j==0){
                    dynamicMatrix[i][j] = "N";
                    if(j+Arr[i] <= Bagmax){
                        dynamicMatrix[i][j+Arr[i]] = "S";
                    }
                }else if(dynamicMatrix[i-1][j].compare("S")==0 || dynamicMatrix[i-1][j].compare("N")==0){
                    if(dynamicMatrix[i][j].compare("S")==0){

                    }else{
                         dynamicMatrix[i][j] = "N";
                    }

                    if(j+Arr[i] <= Bagmax){
                        dynamicMatrix[i][j+Arr[i]] = "S";
                    }
                }else if(dynamicMatrix[i-1][j].compare("I")==0 && dynamicMatrix[i][j].compare("Q")==0){
                    dynamicMatrix[i][j] = "I";
                }
            }
            
        }
    }


    //-------檢查是否正確
    // for(int i = 0 ; i < num ; i++){
    //     for(int j = 0 ; j < Bagmax+1 ;j++){
    //         cout << dynamicMatrix[i][j] <<" ";
    //     }
    //     cout <<endl;
    // }
    // cout << endl;


    //----------SearchResults--------------------------
    int tmp_num = 0;
    tmp_num = num;
    if(dynamicMatrix[num-1][Bagmax].compare("I")==0){
        tmpCnt=0;
    }else{
        while(Bagmax!=0){
            if(dynamicMatrix[num-1][Bagmax].compare("S")==0){
                result[tmpCnt] = num;
                tmpCnt++;
                Bagmax = Bagmax - Arr[num-1];
                num--;
            }else if(dynamicMatrix[num-1][Bagmax].compare("N")==0){ //N
                num--;
            }
        }
    }
    if(tmpCnt>1)
        sort(result , result+tmpCnt);





    //-----------OutputResults------------------------

    if(tmpCnt==0){
        cout << "0" <<endl;
    }else{
        if(tmpCnt==1){
            cout <<result[0]<<endl;
        }else{
            for(int i = 0 ; i < tmpCnt; i++){
                if(i<tmpCnt-1){
                    cout << result[i] << ","; 
                }else{
                    cout << result[i]<<endl;
                }
            }
        }
    }

    delete []result;
    delete []Arr;

    for(int i = 0 ; i < num ; i++){
        delete []dynamicMatrix[i];
    }
    delete []dynamicMatrix;



    return 0;
}
