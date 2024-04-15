#include<iostream>
#include<string>
#include<vector>
using namespace std;
 
int main()
{
    //for all 
    string input_str;
     
    //for T
    vector <string> buyer_name;
    vector <string> market_name;
    vector <string> item_name;    
    vector <int> score_market;
    vector <int> score_buyer;
    buyer_name.clear();
    market_name.clear();
    item_name.clear();
    score_market.clear();
    score_buyer.clear();
     
    //for S
    int best_point = 0;
    string s_buyer,s_item,s_temp;
    vector <string> s_market;
    s_market.clear();
     
    while(cin)
    {
        getline(cin,input_str,' ');
         
        if(input_str.compare("C") == 0)
        {
            // Literally do nothing
            getline(cin,input_str,'\n');    
        }       
        else if(input_str.compare("M") == 0)
        {
            // Literally do nothing
            getline(cin,input_str,'\n');
        }   
        else if(input_str.compare("T") == 0)
        {
            getline(cin,input_str,' ');
            buyer_name.push_back(input_str);
            getline(cin,input_str,' ');
            market_name.push_back(input_str);
            getline(cin,input_str,' ');         
            item_name.push_back(input_str);
            getline(cin,input_str,' ');
            score_market.push_back(stoi(input_str));
            getline(cin,input_str,'\n'); 
            score_buyer.push_back(stoi(input_str));
        }       
        else if(input_str.compare("S") == 0)
        {
            getline(cin,input_str,' ');
            s_buyer = input_str;
            getline(cin,input_str,'\n');
            s_item = input_str;
            s_market.clear();
            best_point = 0;
             
            for(int i = 0;i < buyer_name.size();i++)
            {
                if(buyer_name[i].compare(s_buyer) == 0 and item_name[i].compare(s_item) == 0)
                {
                    if(score_market[i] > best_point)
                    {
                        best_point = score_market[i];
                        s_market.clear();
                        s_market.push_back(market_name[i]);
                    }
                    else if(score_market[i] == best_point)
                    {
                        for(int j = 0;j < s_market.size();j++)
                        {
                            if(s_market[j].compare(market_name[i]) > 0)
                            {
                                s_market.insert(s_market.begin()+j,market_name[i]);
                                break;
                            }                               
                            else if(j == s_market.size()-1)
                            {
                                s_market.push_back(market_name[i]);
                                break;
                            }
                        }                       
                    }
                }
            }           
            //cout << "Cout-----------------------------------------" << "\n";          
            if(s_market.empty())
            {
                cout << "\n";
            }
            else
            {
                for(int i = 0;i < s_market.size();i++)
                {
                    if(i == 0)
                    {
                        cout << s_market[i];
                    }
                    else
                    {
                        cout << " " << s_market[i];
                    }
                }
                cout << "\n";
            }           
            //cout << "Cout-----------------------------------------" << "\n";
        }       
    }
     
    return 0;
}
