#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
//Run: F5 + Shift

// --------------------------------------- Bubble Sort------------------------------------------------------------------------------------------------------------------------------

void bubble_swap_vector(vector<int> &v, const int &i, const int &j) //swap 함수
{

    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
void bubble_sort(vector<int> &v, const int &start, int end)
{
    //end는 마지막인덱스의 바로 다음을 가르키며 실질적으로 쓸 때는 -1을 해준, end-1을 사용한다
    if (start != end - 1) //만약 시작과 끝이 같지 않다는 뜻은 아직 정렬이 끝나지 않았다는 뜻
    {
        for (int i = start; i < end - 1; i++) //시작 부터 주어진 끝가지 반복문을 돌면서
        {
            if (v[i] > v[i + 1]) //오른쪽(i+1)이 더 작으면 , 바꾸준다
            {
                bubble_swap_vector(v, i, i + 1); //변경할 때는 변경 해얄할 1쌍의 인덱스를 전달
            }
        }
        bubble_sort(v, start, end - 1); //다음 실행,다음 end를 1 줄여준다, 위 정렬이 끝났다는 거는 가장 큰 수가 가장 마지막 인덱스에 갔다는 뜻
    }
}
// --------------------------------------- Quick Sort------------------------------------------------------------------------------------------------------------------------------

void quick_swap(vector<int> &v, const int &left, const int &right)
{
    int temp = v[left];
    v[left] = v[right];
    v[right] = temp;
}
int partition_(vector<int> &v, int start, int end)
{
    int piviot = v[(start + end) / 2]; //중간값을 피벗으로 잡음
    while (start <= end)               //start가 end보다 작거나 같다는 것은  둘이 교체하지 않았다는 뜻 , 교체하면 비교 끝
    {
        while (v[start] < piviot)
            start++; // 만약 피벗보다 현재 왼쪽에서 가르키는 값이 작을 경우 정상, 다음 값으로 이동(오른쪽으로) ++
        while (v[end] > piviot)
            end--;        //만약 피벗보다 현재 오른쪽에서 가르키는 값이 클 경우 정상,다음 값으로 이동한다(왼쪽) --
        if (start <= end) //아직 start가 end보다 왼쪽에 있을 시 교환
        {
            quick_swap(v, start, end); //두개 다 값을 찾은 후, 그 값을 swap 해줌
                                       //다음 진행
            start++;
            end--;
        }
    }
    //모두 정렬한 후, start는 end를 넘어 있다      0 0 0 end start  1 1 1 이런 식,그러므로 start는 왼쪽의 끝값,오른쪽에 시작값임
    //시작값(다음 quick sort)의  왼쪽 파트에서는 끝값(가장 오른쪽) 값이 된다.,오른쪽 파트에서는 시작 값이 된다
    return start;
}
void qucik_sort(vector<int> &v, int start, int end)
{
    int part = partition_(v, start, end); // 경계 위치를 받아옴(왼쪽 파트에서는 끝값,오른쪽 파트에서는 시작값)

    if (start < part - 1) //왼쪽 파트에 끝 값인 part-1 보다 작다는 뜻은 아직 정렬해야할 요소가 2개 이상 남았다는 뜻
    {
        qucik_sort(v, start, part - 1); //끝값 전달 part-1
    }
    if (part < end) //오른쪽 파트의 시작값 part가  끝값 end보다 작다는 것 정렬해야할 요소가 2개 이상이라는 것
    {
        qucik_sort(v, part, end); //시작값은 part, 끝값은 end 전달
    }
}
// --------------------------------------- Merge Sort------------------------------------------------------------------------------------------------------------------------------

void mergeTask(vector<int> &v, int  *temp, int start, int mid, int end) //해당 값들을 temp에 넣어줌
{
    //해당 구역 병합 작업
    
    for (int i = start; i<=end; i++) //밑에서 비교하기 위에 임시 저장소에 일단 모두 넣음
    {
        temp[i]=v[i];
    }

    int part1 = start;                   //왼쪽 파트 시작값 , 끝값은 mid
    int part2 = mid + 1;                 //오른쪽 파트 시작값 ,끝값은 end
    int index = start;                   //행당
    while (part1 <= mid && part2 <= end) //각 파트를 가르키는 변수 part1 과 part2 가  각 파트의 끝 mid+1과 end를 초과하지 않을 시 반복
    {
        if (temp[part1] <= temp[part2])
        {
            v[index] = temp[part1]; //만약 왼쪽 파트의 변수가 오른쪽 파트보다 작다면 ,v에 해당 index 위치에 part1값을 넣어준다
            part1++;                // 다음 것을 가르킴
        }
        else //part2가 작다는 뜻
        {
            v[index] = temp[part2]; // part2값 을 넣어줌
            part2++;                //증가
        }
        // if 든 else든 일단 넣었으니 index를 증가시킨다
        index++;
    }
    //이후 뒷쪽(오른쪽은 끝났지만), 앞쪽(왼쪽)에 데이터가 남아있을 경우, 남은 만큼 돌면서 뒷쪽에 채워준다
    // mid는 앞쪽의 끝을 의미하는데 거기서 part1(현재 왼쪽 구역에서 가르키고 있는 위치),mid-part1 만큼 돈다는 것은, part1과 mid 사이 만큼 돈다는 뜻
    // index는 다음 넣을 자리를 의미 index+i는 앞에서 부터
    // index +0 , index +1 ,infex +2 ...  즉 temp의 part1부터 mid 까지 어준다는 뜻

    for (int i = 0; i <= mid - part1; i++)
    {
        v[index + i] = temp[part1 + i]; //걀국 part1+1은 mid 까지 간다
    }
    //반대로 뒷쪽 배열은 남아있고 앞쪽이 비어있으면 걱정안해도됨, 최종 배열뒷쪽에 미리 자리함
}

void mergeSort2(vector<int> &v, int *temp, int start, int end)
{
    int mid = (start + end) / 2; // 중간 값(물리적 중간 값) 찾기 (중간 값은 왼쪽의 끝값) ,오른쪽의  start값으로 사용(mid+1)
    if (start < end)             //만약 start와 end가 차이가 없다면 분할 필요 없음
    {
        //분할 작업
        mergeSort2(v, temp, start, mid);
        mergeSort2(v, temp, mid + 1, end);
        //병합 작업
        mergeTask(v, temp, start, mid, end);
    }
}
int main(int, char **)
{
    vector<int> v;
    v.push_back(7);
    v.push_back(6);
    v.push_back(5);
    v.push_back(4);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    int * temp =new int[v.size()];
    //bubble_sort(v, 0, v.size()); // 해당 벡터,시작인덱스,초기 벡터 길이 전달
    //qucik_sort(v, 0, v.size() - 1); // 시작 인덱스는 0, 끝인덱스는 사이즈 -1
    mergeSort2(v, temp, 0, v.size() - 1);
    vector<int>::iterator start = v.begin();
    for (auto i = start; i != v.end(); i++)
    {
        printf("%d ", *i);
    }
}
