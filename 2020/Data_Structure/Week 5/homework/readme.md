## 第一題- array-based

    第一次在寫的時候使用 while(cin) getline(cin , sub , ' ') 仍有讀檔的問題，應該是因為換行符號。
    後來直接使用while(cin >> order) 這時候他會讀到空白格， 例如 A esjh 1 3 , order他會呈現 "A"
    接著用cin >> name >> int >> int 切割。即可切出空白格，若是只放一個參數，則是讀到換行鍵
  
## 第二題- linked-based

    使用Node與linkedBag來取代原先的ArrayBag，使用起來更能節省空間。也有在function裡面使用throw-catch來抓錯。

## 123.txt
        
     自己做了一份冊資來測試所有方法，單都找不到錯誤地方。 推論不是演算法的問題。
