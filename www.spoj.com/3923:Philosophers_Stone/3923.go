package main

// spoj 3923, BYTESM2 - Philosophers Stone
// 3923 不支持用go提交，反正已经验证过了

import (
	"fmt"
)

type Matrix struct {
	w, h int
	data [][]int
}

func NewMatrix(w, h int) *Matrix {
	m := new(Matrix)
	m.w, m.h = w, h
	m.data = make([][]int, w)
	for i := 0; i < len(m.data); i++ {
		m.data[i] = make([]int, h)
	}
	return m
}

func (m *Matrix) Scan(row int) {
	for j := 0; j < m.h; j++ {
		fmt.Scan(&m.data[row][j])
	}
}

func Solve(m *Matrix) {
	tmp := make([][]int, m.w)
	for i := 0; i < m.w; i++ {
		tmp[i] = make([]int, m.h)
	}
	
	for row := m.w - 1; row >= 0; row-- {
		for col := 0; col < m.h; col++ {
			tmp[row][col] = m.data[row][col] + MaxOfNext(tmp, m.w, m.h, row, col)
		}
//		fmt.Println(row, "==>", tmp[row])
	}
	
	fmt.Println(MaxOf(tmp[0]))
}

func PreNextIndexOf(col, maxCol int) (int, int) {
	pre := col - 1
	if pre < 0 {
		pre = 0
	}
	next := col + 1
	if next > maxCol - 1 {
		next = maxCol - 1
	}
	return pre, next
}

func MaxOf(piece []int) int {
	max := -1
	for _, v := range piece {
		if v > max {
			max = v
		}
	}
	return max
}

func MaxOfNext(m [][]int, w, h, row, col int) int {
	if row >= w - 1 {
		return 0
	}
	pre, next := PreNextIndexOf(col, h)
	//fmt.Println(row, col, pre, next)
	return MaxOf(m[row+1][pre:next+1])
}

func main() {
	caseCount := 0
	fmt.Scan(&caseCount)
	for i := 0; i < caseCount; i++ {
		var w, h int
		fmt.Scan(&w, &h)
		m := NewMatrix(w, h)
		for j := 0; j < w; j++ {
			m.Scan(j)
		}
		//fmt.Println(*m)
		Solve(m)
	}
}