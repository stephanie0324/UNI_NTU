#include "snake.h"

Snake::Snake(queue<tuple<int, int>> start_position)
{
	position = start_position;
}

queue<tuple<int,int>> Snake::nextPosition(vector<vector<int>> map)
{
	target = getTarget(map);
	int head_x = std::get<0>(position.back());
	int head_y = std::get<1>(position.back());
	
	//Check if going x-1 is toward target and viable
	if(std::get<0>(target) < head_x)
	{
		if(!collide(position,tuple<int, int>(head_x-1,head_y),map))
		{
			position.push(tuple<int, int>(head_x-1,head_y));
			if(map[head_x-1][head_y] == 0)
			{
				position.pop();
			}
			return position;
		}
	}
	
	//Check if going x+1 is toward target and viable
	if(std::get<0>(target) > head_x)
	{
		if(!collide(position,tuple<int, int>(head_x+1,head_y),map))
		{
			position.push(tuple<int, int>(head_x+1,head_y));
			if(map[head_x+1][head_y] == 0)
			{
				position.pop();
			}
			return position;
		}
	}
	
	//Check if going y-1 is toward target and viable
	if(std::get<1>(target) < head_y)
	{
		if(!collide(position,tuple<int, int>(head_x,head_y-1),map))
		{
			position.push(tuple<int, int>(head_x,head_y-1));
			if(map[head_x][head_y-1] == 0)
			{
				position.pop();
			}
			return position;
		}
	}
	
	//Check if going y+1 is toward target and viable
	if(std::get<1>(target) > head_y)
	{
		if(!collide(position,tuple<int, int>(head_x,head_y+1),map))
		{
			position.push(tuple<int, int>(head_x,head_y+1));
			if(map[head_x][head_y+1] == 0)
			{
				position.pop();
			}
			return position;
		}
	}
	
	//If none of those is viable, then repeat it without having to go toward the target
	
	if(!collide(position,tuple<int, int>(head_x-1,head_y),map))
	{
		position.push(tuple<int, int>(head_x-1,head_y));
		if(map[head_x-1][head_y] == 0)
		{
			position.pop();
		}
		return position;
	}
	if(!collide(position,tuple<int, int>(head_x+1,head_y),map))
	{
		position.push(tuple<int, int>(head_x+1,head_y));
		if(map[head_x+1][head_y] == 0)
		{
			position.pop();
		}
		return position;
	}
	if(!collide(position,tuple<int, int>(head_x,head_y-1),map))
	{
		position.push(tuple<int, int>(head_x,head_y-1));
		if(map[head_x][head_y-1] == 0)
		{
			position.pop();
		}
		return position;
	}
	if(!collide(position,tuple<int, int>(head_x,head_y+1),map))
	{
		position.push(tuple<int, int>(head_x,head_y+1));
		if(map[head_x][head_y+1] == 0)
		{
			position.pop();
		}
		return position;
	}

	//If all of those if unreachable, then GG!
	
	return position;
}

bool Snake::collide(queue<tuple<int, int>> pos_body, tuple<int, int> pos_head, vector<vector<int>> map)
{
	//Check if the head is crashing into the obstacle
	if(map[std::get<0>(pos_head)][std::get<1>(pos_head)] == -1)
	{
		return true;
	}
	
	//Check if the head is crashing into itself, a.k.a. tails
	while(pos_body.size() != 0)
	{
		if(std::get<0>(pos_body.front()) == std::get<0>(pos_head) and std::get<1>(pos_body.front()) == std::get<1>(pos_head))
		{
			return true;
		}
		pos_body.pop();
	}
	return false;
}

tuple<int, int> Snake::getTarget(vector<vector<int>> map)
{
	for(int i = 0 ; i < map.size() ; i++)
	{
		for(int j = 0 ; j < map[0].size() ; j++)
		{
			// This sample code will only try 1-point target
			if(map[i][j] == 1)
			{
				return tuple<int,int> (i,j);
			}
		}
	}
	cout << "No 1-Point Target!! Call the TA!!";
	exit(0); 
}

/*

// This is not impotrant, just for TA displaying
Display(queue<tuple<int, int>> pos, vector<vector<int>> map)
{
	bool find_body = false;
	queue<tuple<int, int>> temp_pos;
	//cout << pos.size();
	cout << "---------------------------------------------------\n";
	for(int i = 0 ; i < map.size() ; i++)
	{
		for(int j = 0 ; j < map[0].size() ; j++)
		{					
			find_body = false;
			temp_pos = pos;
			while(temp_pos.size() != 0)
			{
				if(std::get<0>(temp_pos.front()) == i and std::get<1>(temp_pos.front()) == j)
				{
					cout << setw(5) << " X ";
					find_body = true;
					break;
				}
				temp_pos.pop();
			}
			
			if(!find_body)
			{
				cout << setw(4) << map[i][j] << " ";
			}			
				
		}
		cout << "\n";
	}
	cout << "---------------------------------------------------\n";
}

int main()
{
	queue<tuple<int, int>> start_q;
	queue<tuple<int, int>> middle_q;
	start_q.push(tuple<int,int> (1,1));
	
	Snake s1(start_q);
	
	
	vector<vector<int>> v1 = {{-1,-1,-1,-1,-1,-1,-1},{-1,0,0,0,0,1,-1},{-1,0,0,0,0,0,-1},{-1,0,1,0,0,0,-1},{-1,0,0,0,0,0,-1},{-1,0,0,0,1,0,-1},{-1,-1,-1,-1,-1,-1,-1}};	
	middle_q = s1.nextPosition(v1);
	Display(middle_q,v1);
	middle_q = s1.nextPosition(v1);
	Display(middle_q,v1);
	middle_q = s1.nextPosition(v1);
	Display(middle_q,v1);
	middle_q = s1.nextPosition(v1);
	Display(middle_q,v1);
	
	v1 = {{-1,-1,-1,-1,-1,-1,-1},{-1,0,0,0,0,0,-1},{-1,0,0,0,0,0,-1},{-1,0,1,0,0,0,-1},{-1,0,0,0,0,0,-1},{-1,0,0,0,1,0,-1},{-1,-1,-1,-1,-1,-1,-1}};	
	middle_q = s1.nextPosition(v1);
	Display(middle_q,v1);
	middle_q = s1.nextPosition(v1);
	Display(middle_q,v1);
	middle_q = s1.nextPosition(v1);
	Display(middle_q,v1);
	middle_q = s1.nextPosition(v1);
	Display(middle_q,v1);
	middle_q = s1.nextPosition(v1);
	Display(middle_q,v1);
	
	v1 = {{-1,-1,-1,-1,-1,-1,-1},{-1,0,0,0,0,0,-1},{-1,0,0,0,0,0,-1},{-1,0,0,0,0,0,-1},{-1,0,0,0,0,0,-1},{-1,0,0,0,1,0,-1},{-1,-1,-1,-1,-1,-1,-1}};	
	middle_q = s1.nextPosition(v1);
	Display(middle_q,v1);
	middle_q = s1.nextPosition(v1);
	Display(middle_q,v1);
	middle_q = s1.nextPosition(v1);
	Display(middle_q,v1);
	
	return 0;
}

*/

