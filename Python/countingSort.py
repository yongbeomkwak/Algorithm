import sys
sys.setrecursionlimit(2500)

def mergeSort(raw_list:list,length:int):
    temp_list=list()
    mSort(raw_list,temp_list,0,length-1)

def mSort(raw_list:list,temp_list:list,start:int,end:int):
    mid=(start+end)//2
    if(start<end):
        mSort(raw_list,temp_list,start,mid)
        mSort(raw_list,temp_list,mid+1,end)
        merge(raw_list,temp_list,start,mid,end)

def merge(raw_list:list,temp_list:list,start:int,mid:int,end:int):
    temp_list=raw_list[0:end+1] #복사
    part1=start
    part2=mid+1
    index=start
    print(temp_list)
    while part1<=mid and part2<=end:
        if temp_list[part1] <=temp_list[part2]:
            raw_list[index] =temp_list[part1]
            part1+=1
        else :
            raw_list[index]=temp_list[part2]
            part2+=1
        index+=1

    for i in range(0,mid-part1+1): #[0....mid-part1]
        raw_list[index+i]=temp_list[part1+i]

if __name__ == "__main__":
    num=int(input())
    in_list=list()
    for i in range(num):
        in_list.append(int(input()))
    mergeSort(in_list,len(in_list))

    for val in in_list:
        print(val)