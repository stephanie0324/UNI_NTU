#include "Snake.h"
#include <stdexcept>
#include <cmath>

Snake::Snake(queue<tuple<int, int>> start_position)
{
	position = start_position;
}

queue<tuple<int,int>> Snake::nextPosition(vector<vector<int>> map)
{
    
    int turn_cnt =0;
	int head_x = std::get<0>(position.back());
	int head_y = std::get<1>(position.back());
    if(first_cnt==true){
        target = getTarget(map , head_x, head_y);
        first_cnt=false;
    }
    //    cout << path.size() << endl;
    //    cout <<  "Snake : "<<head_x  << " " << head_y <<endl;
    //    cout << get<0>(target) << " " << get<1>(target) <<endl;
    turn_cnt = countTurns(position);
    if(turn_cnt<3){
        if(std::get<0>(target) < head_x )
        {
            if(!collide(position,tuple<int, int>(head_x-1,head_y),map) && !beenThere(path,tuple<int, int>(head_x-1,head_y)))
            {
                move_x_minus = true;
                move_x_plus = false;
                move_y_minus = false;
                move_y_plus = false;
                position.push(tuple<int, int>(head_x-1,head_y));
                if(map[head_x-1][head_y] == 0)
                {
                    position.pop();
                    path.push(tuple<int, int>(head_x-1,head_y));
                }
                else{
                    while (path.size()!=0) {
                        path.pop();
                    }
                    eaten = true;
                    first_cnt = true;
                }
                return position;
            }
        }
        
        //Check if going x+1 is toward target and viable
        if(std::get<0>(target) > head_x)
        {
            //cout << "at right" <<endl;
            if(!collide(position,tuple<int, int>(head_x+1,head_y),map) && !beenThere(path,tuple<int, int>(head_x+1,head_y)))
            {
                move_x_minus = false;
                move_x_plus = true;
                move_y_minus = false;
                move_y_plus = false;
                position.push(tuple<int, int>(head_x+1,head_y));
                if(map[head_x+1][head_y] == 0)
                {
                    position.pop();
                    path.push(tuple<int, int>(head_x+1,head_y));
                }
                else{
                    while (path.size()!=0) {
                        path.pop();
                    }
                    eaten = true;
                    first_cnt = true;
                }
                return position;
            }
            //cout << " boom " <<endl;
        }
        
        //Check if going y-1 is toward target and viable
        if(std::get<1>(target) < head_y )
        {
            //cout << "at top" <<endl;
            if(!collide(position,tuple<int, int>(head_x,head_y-1),map) && !beenThere(path,tuple<int, int>(head_x,head_y-1)))
            {
                move_x_minus = false;
                move_x_plus = false;
                move_y_minus = true;
                move_y_plus = false;
                position.push(tuple<int, int>(head_x,head_y-1));
                if(map[head_x][head_y-1] == 0)
                {
                    position.pop();
                    path.push(tuple<int, int>(head_x,head_y-1));
                }else{
                    while (path.size()!=0) {
                        path.pop();
                    }
                    eaten = true;
                    first_cnt = true;
                }
                return position;
            }
            //cout << " boom " <<endl;
        }
        
        //Check if going y+1 is toward target and viable
        if(std::get<1>(target) > head_y )
        {
            //cout << "at down" <<endl;
            if(!collide(position,tuple<int, int>(head_x,head_y+1),map) && !beenThere(path,tuple<int, int>(head_x,head_y+1)))
            {
                move_x_minus = false;
                move_x_plus = false;
                move_y_minus = false;
                move_y_plus = true;
                position.push(tuple<int, int>(head_x,head_y+1));
                if(map[head_x][head_y+1] == 0)
                {
                    position.pop();
                    path.push(tuple<int, int>(head_x,head_y+1));
                }else{
                    while (path.size()!=0) {
                        path.pop();
                    }
                    eaten = true;
                    first_cnt = true;
                }
                return position;
            }
            //cout << " boom " <<endl;
        }
        
        //If none of those is viable, then repeat it without having to go toward the target
        
        if(!collide(position,tuple<int, int>(head_x-1,head_y),map) && !beenThere(path,tuple<int, int>(head_x-1,head_y)))
        {
            move_x_minus = true;
            move_x_plus = false;
            move_y_minus = false;
            move_y_plus = false;
            position.push(tuple<int, int>(head_x-1,head_y));
            if(map[head_x-1][head_y] == 0)
            {
                position.pop();
                path.push(tuple<int, int>(head_x-1,head_y));
            }else{
                while (path.size()!=0) {
                    path.pop();
                }
                eaten = true;
                first_cnt = true;
            }
            return position;
        }
        if(!collide(position,tuple<int, int>(head_x+1,head_y),map) && !beenThere(path,tuple<int, int>(head_x+1,head_y)))
        {
            move_x_minus = false;
            move_x_plus = true;
            move_y_minus = false;
            move_y_plus = false;
            position.push(tuple<int, int>(head_x+1,head_y));
            if(map[head_x+1][head_y] == 0)
            {
                position.pop();
                path.push(tuple<int, int>(head_x+1,head_y));
            }else{
                while (path.size()!=0) {
                    path.pop();
                }
                eaten = true;
                first_cnt = true;
            }
            return position;
        }
        if(!collide(position,tuple<int, int>(head_x,head_y-1),map) && !beenThere(path,tuple<int, int>(head_x,head_y-1)))
        {
            move_x_minus = false;
            move_x_plus = false;
            move_y_minus = true;
            move_y_plus = false;
            position.push(tuple<int, int>(head_x,head_y-1));
            if(map[head_x][head_y-1] == 0)
            {
                position.pop();
                path.push(tuple<int, int>(head_x,head_y-1));
            }else{
                while (path.size()!=0) {
                    path.pop();
                }
                eaten = true;
                first_cnt = true;
            }
            return position;
        }
        if(!collide(position,tuple<int, int>(head_x,head_y+1),map) && !beenThere(path,tuple<int, int>(head_x,head_y+1)))
        {
            move_x_minus = false;
            move_x_plus = false;
            move_y_minus = false;
            move_y_plus = true;
            position.push(tuple<int, int>(head_x,head_y+1));
            if(map[head_x][head_y+1] == 0)
            {
                position.pop();
                path.push(tuple<int, int>(head_x,head_y+1));
            }else{
                while (path.size()!=0) {
                    path.pop();
                }
                eaten = true;
                first_cnt = true;
            }
            return position;
        }
    }else{
        if(move_x_minus==true){
            if(!collide(position,tuple<int, int>(head_x-1,head_y),map) && !beenThere(path,tuple<int, int>(head_x-1,head_y)))
            {
                move_x_minus = true;
                move_x_plus = false;
                move_y_minus = false;
                move_y_plus = false;
                position.push(tuple<int, int>(head_x-1,head_y));
                if(map[head_x-1][head_y] == 0)
                {
                    position.pop();
                    path.push(tuple<int, int>(head_x-1,head_y));
                }
                else{
                    while (path.size()!=0) {
                        path.pop();
                    }
                    eaten = true;
                    first_cnt = true;
                }
                return position;
            }
        }
        if(move_x_plus == true){
            if(!collide(position,tuple<int, int>(head_x+1,head_y),map) && !beenThere(path,tuple<int, int>(head_x+1,head_y)))
            {
                move_x_minus = false;
                move_x_plus = true;
                move_y_minus = false;
                move_y_plus = false;
                position.push(tuple<int, int>(head_x+1,head_y));
                if(map[head_x+1][head_y] == 0)
                {
                    position.pop();
                    path.push(tuple<int, int>(head_x+1,head_y));
                }
                else{
                    while (path.size()!=0) {
                        path.pop();
                    }
                    eaten = true;
                    first_cnt = true;
                }
                return position;
            }
        }
        if(move_y_minus==true){
            if(!collide(position,tuple<int, int>(head_x,head_y-1),map) && !beenThere(path,tuple<int, int>(head_x,head_y-1)))
            {
                move_x_minus = false;
                move_x_plus = false;
                move_y_minus = true;
                move_y_plus = false;
                position.push(tuple<int, int>(head_x,head_y-1));
                if(map[head_x][head_y-1] == 0)
                {
                    position.pop();
                    path.push(tuple<int, int>(head_x,head_y-1));
                }else{
                    while (path.size()!=0) {
                        path.pop();
                    }
                    eaten = true;
                    first_cnt = true;
                }
                return position;
            }
        }
        if(move_y_plus==true){
            if(!collide(position,tuple<int, int>(head_x,head_y+1),map) && !beenThere(path,tuple<int, int>(head_x,head_y+1)))
            {
                move_x_minus = false;
                move_x_plus = false;
                move_y_minus = false;
                move_y_plus = true;
                position.push(tuple<int, int>(head_x,head_y+1));
                if(map[head_x][head_y+1] == 0)
                {
                    position.pop();
                    path.push(tuple<int, int>(head_x,head_y+1));
                }else{
                    while (path.size()!=0) {
                        path.pop();
                    }
                    eaten = true;
                    first_cnt = true;
                }
                return position;
            }
        }
        else{
            if(!collide(position,tuple<int, int>(head_x-1,head_y),map) && !beenThere(path,tuple<int, int>(head_x-1,head_y)))
            {
                move_x_minus = true;
                move_x_plus = false;
                move_y_minus = false;
                move_y_plus = false;
                position.push(tuple<int, int>(head_x-1,head_y));
                if(map[head_x-1][head_y] == 0)
                {
                    position.pop();
                    path.push(tuple<int, int>(head_x-1,head_y));
                }else{
                    while (path.size()!=0) {
                        path.pop();
                    }
                    eaten = true;
                    first_cnt = true;
                }
                return position;
            }
            if(!collide(position,tuple<int, int>(head_x+1,head_y),map) && !beenThere(path,tuple<int, int>(head_x+1,head_y)))
            {
                move_x_minus = false;
                move_x_plus = true;
                move_y_minus = false;
                move_y_plus = false;
                position.push(tuple<int, int>(head_x+1,head_y));
                if(map[head_x+1][head_y] == 0)
                {
                    position.pop();
                    path.push(tuple<int, int>(head_x+1,head_y));
                }else{
                    while (path.size()!=0) {
                        path.pop();
                    }
                    eaten = true;
                    first_cnt = true;
                }
                return position;
            }
            if(!collide(position,tuple<int, int>(head_x,head_y-1),map) && !beenThere(path,tuple<int, int>(head_x,head_y-1)))
            {
                move_x_minus = false;
                move_x_plus = false;
                move_y_minus = true;
                move_y_plus = false;
                position.push(tuple<int, int>(head_x,head_y-1));
                if(map[head_x][head_y-1] == 0)
                {
                    position.pop();
                    path.push(tuple<int, int>(head_x,head_y-1));
                }else{
                    while (path.size()!=0) {
                        path.pop();
                    }
                    eaten = true;
                    first_cnt = true;
                }
                return position;
            }
            if(!collide(position,tuple<int, int>(head_x,head_y+1),map) && !beenThere(path,tuple<int, int>(head_x,head_y+1)))
            {
                move_x_minus = false;
                move_x_plus = false;
                move_y_minus = false;
                move_y_plus = true;
                position.push(tuple<int, int>(head_x,head_y+1));
                if(map[head_x][head_y+1] == 0)
                {
                    position.pop();
                    path.push(tuple<int, int>(head_x,head_y+1));
                }else{
                    while (path.size()!=0) {
                        path.pop();
                    }
                    eaten = true;
                    first_cnt = true;
                }
                return position;
                
            }
        }
    }
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

tuple<int, int> Snake::getTarget(vector<vector<int>> map , int head_x , int head_y)
{
    int dist = 0 , tmp_i = 0 , tmp_j = 0 , tmp_score =0 , min_dist = 10000;
        for(int i = 0 ; i < map.size() ; i++)
        {
            for(int j = 0 ; j < map[0].size() ; j++)
            {
                // This sample code will only try 1-point target
                if(map[i][j] != 0 && map[i][j] != -1)
                {
                    dist = abs(i-head_x)+abs(j-head_y);
                    if(dist < min_dist){
                            tmp_i = i;
                            tmp_j = j;
                            min_dist = dist;
                    }else if(dist == min_dist){
                        if(map[i][j] > tmp_score){
                            tmp_i = i;
                            tmp_j = j;
                            min_dist = dist;
                            tmp_score = map[i][j];
                        }
                    }
                }
            }
        }
    return tuple<int,int> (tmp_i,tmp_j);
	cout << "No 1-Point Target!! Call the TA!!";
	exit(0); 
}

bool Snake::beenThere(queue<tuple<int, int>> pos_body, tuple<int, int> pos_head){
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

int Snake::countTurns(queue<tuple<int, int>> pos_body){
    int count =0;
    int tmp_x , tmp_y;
    tmp_x = get<0>(pos_body.front());
    tmp_y = get<1>(pos_body.front());
    pos_body.pop();
    while (pos_body.size()!=0) {
        if(tmp_x != get<0>(pos_body.front()) && tmp_y != get<1>(pos_body.front())){
            count++;
            tmp_x = get<0>(pos_body.front());
            tmp_y = get<1>(pos_body.front());
        }
        pos_body.pop();
    }
    return count;
}