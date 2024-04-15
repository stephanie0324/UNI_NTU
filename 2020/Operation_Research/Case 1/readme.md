# 作業研究 Case 1

## Goal
排出總不足 (lack) 最少的班表

## Rules

### Case 0. 原有項目
1.	每個人每天至少安排一個 shift
2.	每個人這個月**必須**休八天假
3.	每連續七天最多只能上一次晚班
4.	每連續七天最多只能上兩個下午班
5.	每個連續七個工作天**必須**修一天假

### Case 1. 新增項目 (Excel)

6. 新增排班要求
7. 新增請假要求
8. **特定時段** 資歷達到 **最低年限限制以上** 的 CSR 應達到 **特定比例** 的要求
9. **特定時段** Manager 應達到 **特定人數** 的要求

## 員工階層

員工階層從低到高分別為：

| Associate | Specialist | Senior Specialist | Assistant Manager | Manager |
| --- | --- | --- | --- | --- |

## Code
我們有寫出檢查我們生出的班表是否符合所有規定，以及透過自動產出班表與檢查差距是否最小化的程式並將最終班表產出。
因為不知道最小值是什麼，所以只能使用暴力方法跑很多次組合之後最小的那一個班表。

## 補充圖檔

### shift
![shift](https://github.com/stephanie0324/Operation-Research-2020/blob/master/Case%201/截圖%202020-03-08%20下午7.03.30.png)

### demand
![demand](https://github.com/stephanie0324/Operation-Research-2020/blob/master/Case%201/截圖%202020-03-08%20下午7.03.44.png)

### CSRs
![CSRs](https://github.com/stephanie0324/Operation-Research-2020/blob/master/Case%201/截圖%202020-03-08%20下午7.03.59.png)

### senior limit
![senior limit](https://github.com/stephanie0324/Operation-Research-2020/blob/master/Case%201/截圖%202020-03-08%20下午7.04.06.png)

### manager limit
![manager limit](https://github.com/stephanie0324/Operation-Research-2020/blob/master/Case%201/截圖%202020-03-08%20下午7.04.12.png)

### leave request
![leave request](https://github.com/stephanie0324/Operation-Research-2020/blob/master/Case%201/截圖%202020-03-08%20下午7.04.19.png)

### shift request
![shift request](https://github.com/stephanie0324/Operation-Research-2020/blob/master/Case%201/截圖%202020-03-08%20下午7.04.26.png)
