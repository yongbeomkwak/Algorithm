package main

import (
	"fmt"
)

func swap(raw_list []int, left int, right int) {
	temp := raw_list[left]
	raw_list[left] = raw_list[right]
	raw_list[right] = temp
}

func partition(raw_list []int, start int, end int) int {
	piviot := raw_list[(start+end)/2]
	for start <= end {
		for raw_list[start] < piviot {
			start++
		}
		for piviot < raw_list[end] {
			end--
		}
		if start <= end {
			swap(raw_list, start, end)
			start++
			end--
		}
	}
	return start
}

func qucikSort(raw_list []int, start int, end int) {
	part2 := partition(raw_list, start, end)
	if start < end-1 {
		qucikSort(raw_list, start, part2-1)
	}
	if part2 < end {
		qucikSort(raw_list, part2, end)
	}

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
	qucikSort(in_list, 0, len(in_list)-1)

	for _, val := range in_list {
		fmt.Println(val)
	}
}
