#include<iostream>
#include<string>
#include <sstream>
using namespace std;

int get_id(string data[],string name)
{
	for(int i = 0;i < 500;i++)
	{
		if(data[i].compare(name) == 0)
		{
			return i;
		}
	}
	cout << "Error! No find!";
	return 0;
}
 
int main()
{
    //for all
    int max_data = 500;
    int id = 0;
    int temp_space = 0;
    int* space = new int[5];
    string input_str;
    string split_input[max_data];
    
    //for C
    int num_c = 0;
    string c_buyer_name[max_data];
    float c_num_score[max_data];
    float c_total_score[max_data];
    
    //for M
    int num_m = 0;
    string m_market_name[max_data];
    float m_num_score[max_data];
    float m_total_score[max_data];
    
    //for A
    int num_a = 0;
    string a_market_name[max_data];
    string a_item_name[max_data];
     
    //for T
    int num_t = 0;
    string t_buyer_name[max_data];
    string t_market_name[max_data];
    string t_item_name[max_data];
    float score_market[max_data];
    float score_buyer[max_data];
     
    //for S
    int num_s = 0;
    float best_point = 0,s_min_num_score,s_scan_all;
    string s_buyer,s_item,s_temp;
    string s_market[max_data];
     
    while(cin >> input_str)
    {        
        if(input_str.compare("C") == 0)
        {
    		cin >> input_str;   		
			c_buyer_name[num_c] = input_str;
			c_num_score[num_c] = 0;
			c_total_score[num_c] = 0;
			num_c++;
        }       
        else if(input_str.compare("M") == 0)
        {
    		cin >> input_str;  		
    		m_market_name[num_m] = input_str;
			m_num_score[num_m] = 0;
			m_total_score[num_m] = 0;
			num_m++;
        }
        else if(input_str.compare("P") == 0)
        {
            // Literally do nothing
            getline(cin,input_str,'\n');
        }
		else if(input_str.compare("A") == 0)
        {
    		cin >> input_str;		
    		a_market_name[num_a] = input_str;
			cin >> input_str;  
            a_item_name[num_a] = input_str;
			num_a++;     		 		
        }     
        else if(input_str.compare("T") == 0)
        {
			cin >> input_str;			
            t_buyer_name[num_t] = input_str;	
            cin >> input_str;
            t_market_name[num_t] = input_str;
			cin >> input_str;      
            t_item_name[num_t] = input_str;
            cin >> input_str;
            score_market[num_t] = stoi(input_str);
            cin >> input_str;
            score_buyer[num_t] = stoi(input_str);           
            
            //Store in buyer data
            id = get_id(c_buyer_name,t_buyer_name[num_t]);
            c_total_score[id] += score_buyer[num_t];
			c_num_score[id]++;
			
			//Store in market data
			id = get_id(m_market_name,t_market_name[num_t]);
			m_total_score[id] += score_market[num_t];
			m_num_score[id]++;
			
			num_t++;
        }       
        else if(input_str.compare("S") == 0)
        {
    		getline(cin,input_str,'\n');
    		  		
    		temp_space = 0;
    		int* space = new int[5];
            for(int i = 0; i < input_str.length(); i++)
            {
                if(input_str[i] == ' ')
                {
                    space[temp_space] = i;
                    temp_space++;
                }
            }  		
			
			if(temp_space < 3)
			{
	            s_buyer = input_str.substr(space[0] + 1, space[1] - space[0] - 1);
	            s_item = input_str.substr(space[1] + 1, space[2] - space[1] - 1);
	            
	            num_s = 0;	            
	            best_point = 0;
	             
	            for(int i = 0;i < num_t;i++)
	            {
	                if(t_buyer_name[i].compare(s_buyer) == 0 and t_item_name[i].compare(s_item) == 0)
	                {
	                    if(score_market[i] > best_point)
	                    {
	                        best_point = score_market[i];
	            			num_s = 0;
	                        s_market[num_s] = t_market_name[i];
	                        num_s++;
	                    }
	                    else if(score_market[i] == best_point)
	                    {
							for(int j = 0;j < num_s;j++)
	                        {
	                            if(s_market[j].compare(t_market_name[i]) > 0)
	                            {
	                                for(int p = j;p < num_s;p++)
	                                {
	                                	s_market[p+1] = s_market[p];
									}
									s_market[j] = t_market_name[i];
									num_s++;
	                                break;
	                            }                               
	                            else if(j == num_s-1)
	                            {
	                                s_market[num_s] = t_market_name[i];
	                                num_s++;
	                                break;
	                            }
	                        }                       
	                    }
	                }
	            }      
				
				//Output   
	            //cout << "\n" << "Cout-----------------------------------------" << "\n";          
	            if(num_s == 0)
	            {
	                cout << "\n";
	            }
	            else
	            {
	                for(int i = 0;i < num_s;i++)
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
	            //cout << "Cout-----------------------------------------" << "\n" << "\n";
			}			
			else
			{  			
    			s_buyer = input_str.substr(space[0] + 1, space[1] - space[0] - 1);
	            s_item = input_str.substr(space[1] + 1, space[2] - space[1] - 1);
	            s_min_num_score = stoi(input_str.substr(space[2] + 1,space[3] - space[2] - 1));
				s_scan_all = stoi(input_str.substr(space[3] + 1));
				
	            num_s = 0;	 
	            best_point = 0;
    			
    			//cout << "\n" << "Cout-----------------------------------------" << "\n";        				  			
	            id = get_id(c_buyer_name,s_buyer);
				if(c_num_score[id] <= 2 or c_total_score[id]/c_num_score[id] <= 3)
    			{
    				cout << "reject" << "\n";
				}
				else
				{
					if(s_scan_all == 0)
					{
						for(int i = 0;i < num_t;i++)
			            {
			                if(t_buyer_name[i].compare(s_buyer) == 0 and t_item_name[i].compare(s_item) == 0)
			                {
			                    id = get_id(m_market_name,t_market_name[i]);
			                    if(m_num_score[id] >= s_min_num_score)
			                    {
			                    	if(score_market[i] > best_point)
				                    {
				                        best_point = score_market[i];
	            						num_s = 0;	 
				                        s_market[num_s] = t_market_name[i];
	                       				num_s++;
				                    }
				                    else if(score_market[i] == best_point)
				                    {
				                        for(int j = 0;j < num_s;j++)
				                        {
				                            if(s_market[j].compare(t_market_name[i]) > 0)
				                            {
				                                for(int p = j;p < num_s;p++)
				                                {
				                                	s_market[p+1] = s_market[p];
												}
												s_market[j] = t_market_name[i];
												num_s++;
				                                break;
				                            }                               
				                            else if(j == num_s-1)
				                            {
				                                s_market[num_s] = t_market_name[i];
				                                num_s++;
				                                break;
				                            }
				                        }                              
				                    }
								}			                 								
			                }
			            } 
					}
					else
					{
						for(int i = 0;i < num_a;i++)
			            {
		                    if(a_item_name[i].compare(s_item) == 0)
			                {
								id = get_id(m_market_name,a_market_name[i]);
								if(m_num_score[id] >= s_min_num_score) 
								{
									if(m_total_score[id] / m_num_score[id] > best_point)
				                    {
				                        best_point = m_total_score[id] / m_num_score[id];
	            						num_s = 0;	 
				                        s_market[num_s] = a_market_name[i];
	                       				num_s++;
				                    }
				                    else if(m_total_score[id] / m_num_score[id] == best_point)
				                    {
				                        for(int j = 0;j < num_s;j++)
				                        {
				                            if(s_market[j].compare(a_market_name[i]) > 0)
				                            {
				                                for(int p = num_s-1;p >= j;p--)
				                                {
				                                	s_market[p+1] = s_market[p];
												}
												s_market[j] = a_market_name[i];
												num_s++;																																				
				                                break;
				                            }                               
				                            else if(j == num_s-1)
				                            {
				                                s_market[num_s] = a_market_name[i];
				                                num_s++;				                                				                               												
				                                break;
				                            }
				                        }                           
				                    }	
								}			                			                    	                    										
			            	}								                 								
			            } 
					}
					
					//Output
					if(num_s == 0)
		            {
		                cout << "\n";
		            }
		            else
		            {
		                for(int i = 0;i < num_s;i++)
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
				}
				//cout << "Cout-----------------------------------------" << "\n" << "\n";		
			}			
        }       
    }
     
    return 0;
}
