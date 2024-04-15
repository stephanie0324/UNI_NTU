
## An AI version of Snake
### Concept
給予一張地圖，蛇在不碰壁與不碰撞自己身體的狀態下，吃到得分點。吃到得分點之後，長度會增加一並進入下一張地圖。
### Upload files
* TA ans 
    1. 只有前後左右是否可以往前走，同一排遇到障礙的話會選擇其他路徑
    2. 有判斷是否會撞到自己
* version_1
    1. 將過去走過的路也記錄下來，避免重複同樣道路
    2. 吃到得分點後，走過的道路會消除
* 0629
    1. 針對同一個地圖，只會做一次目標找尋，一直到吃到食物才會將 first_cnt = true;
* turnCountSnake
    1. 每一次都會計算蛇有幾個轉彎處，勁量將轉彎處控制在3個以下
    2. 如果超過三個轉彎處，就讓蛇先前行直到轉彎處低於3，若遇到障礙物不得轉彎，就在下一次繼續前嫌行直到轉彎處減少，一直重複執行直到吃到食物
* boolBeenThere
    1. 讓蛇不會重複前一個的路徑就好，這樣在繞的時候其他步數還是可以移動到該位置。
### Other files
* [writing_map.py](https://github.com/stephanie0324/Data-Structure-2020/blob/master/Final/writing_map.py) - 將助教的map 獨進之後輸出成c++ vector的格式
* [random_map.py](https://github.com/stephanie0324/Data-Structure-2020/blob/master/Final/random_map.py) - 自己製作地圖，製造不只一個分數點，與不只一個障礙，隨機分佈在地圖中
* [make_file_map.py](https://github.com/stephanie0324/Data-Structure-2020/blob/master/Final/make_file_map.py) - 從file中將map 做成可以讀得vector形式，統一存在同一個file
* [mySnakeCheck.cpp](https://github.com/stephanie0324/Data-Structure-2020/blob/master/Final/mySnakeCheck.cpp) - 可以將蛇每一次移動的樣子印出來，檢查是否走錯或是撞到自己
### Notes
* 如果是在 private 的參數，要直接呼叫才能對他作出改變，經過函數呼叫會做出一個copy constructor，這樣在進行計算的時候就不會動到原值
