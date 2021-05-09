package main

import (
	"fmt"
)

func countingSort(raw_list []int, max_val int) []int {

	result := make([]int, max_val+1)

	for _, val := range raw_list {
		result[val]++
	}
	return result
}

func main() {
	//reader := bufio.NewReader(os.Stdin)
	num := 0
	fmt.Scan(&num)
	in_list := make([]int, 0)
	max_val := 0
	for i := 0; i < num; i++ {
		temp := 0
		fmt.Scan(&temp)
		if max_val < temp {
			max_val = temp
		}
		in_list = append(in_list, temp)
	}

	result := countingSort(in_list, max_val)
	for idx, val := range result {
		if val != 0 {
			for i := 0; i < val; i++ {
				fmt.Println(idx)
			}
		}
	}
}
