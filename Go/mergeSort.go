package main

import (
	"fmt"
)

func merge(raw_list []int, temp_list []int, start int, mid int, end int) {

	temp_list = append(temp_list, raw_list...)
	// temp_list=raw_list[0:end+1] 사용하면 raw_list가 바뀔 때마다 변경됨
	part1 := start
	part2 := mid + 1
	index := start

	for part1 <= mid && part2 <= end {
		if temp_list[part1] <= temp_list[part2] {
			raw_list[index] = temp_list[part1]
			part1++

		} else {
			raw_list[index] = temp_list[part2]
			part2++
		}

		index++

	}
	for i := 0; i <= mid-part1; i++ {
		raw_list[index+i] = temp_list[part1+i]
	}

}

func mSort(raw_list []int, temp_list []int, start int, end int) {
	mid := (start + end) / 2

	if start < end {
		mSort(raw_list, temp_list, start, mid)
		mSort(raw_list, temp_list, mid+1, end)
		merge(raw_list, temp_list, start, mid, end)
	}
}

func mergeSort(raw_list []int, length int) {
	temp := make([]int, 0)
	mSort(raw_list, temp, 0, length-1)

}

func main() {
	//reader := bufio.NewReader(os.Stdin)
	num := 0
	fmt.Scan(&num)
	in_list := make([]int, 0)
	for i := 0; i < num; i++ {
		temp := 0
		fmt.Scan(&temp)
		in_list = append(in_list, temp)
	}
	mergeSort(in_list, len(in_list))

	for _, val := range in_list {
		fmt.Println(val)
	}
}
