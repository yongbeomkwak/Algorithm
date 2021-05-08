import sys
sys.setrecursionlimit(2500)

def swap(raw_list:list,left:int,right:list):
    temp=raw_list[left]
    raw_list[left]=raw_list[right]
    raw_list[right]=temp

def quickSort(raw_list:list,start:int,end:int):
    part2=partition(raw_list,start,end)
    if(start<part2-1):
        quickSort(raw_list,start,part2-1)
    if(part2<end):
        quickSort(raw_list,part2,end)

def partition(raw_list:list,start:int,end:int) -> int:
    pivot=raw_list[(start+end)//2]
    while start<=end:
        while raw_list[start]<pivot: 
            start+=1
        while pivot<raw_list[end]:
            end-=1
        if start<=end:
            swap(raw_list,start,end)
            start+=1
            end-=1
    
    return start
            

if __name__ == "__main__":
    num=int(input())
    in_list=list()
    for i in range(num):
        in_list.append(int(input()))
    quickSort(in_list,0,len(in_list)-1)

    for val in in_list:
        print(val)