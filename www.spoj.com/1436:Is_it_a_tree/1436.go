package main

import (
	"fmt"
)

type Graph struct {
	nodes []*Node
}

type Node struct {
	id int
	next map[int]int
}

func NewNode(index int) *Node {
	var node Node
	node.id = index
	node.next = make(map[int]int)
	return &node
}

func NewGraph(size int) *Graph {
	var g Graph
	g.nodes = make([]*Node, size)
	for i := 0; i < size; i++ {
		g.nodes[i] = NewNode(i+1)
	}
	return &g
}

func (g *Graph)AddNode(a, b int) {
	g.nodes[a-1].next[b] = b
	g.nodes[b-1].next[a] = a
}

func (g *Graph)DeleteLeaf() bool {
	for i := 0; i < len(g.nodes); i++ {
		if len(g.nodes[i].next) == 1 {
			for k, v := range g.nodes[i].next {
				delete(g.nodes[i].next, k)
				delete(g.nodes[v-1].next, i+1)
				return true
			}
		}
	}
	return false
}

func main() {
	var leafCount, edgeCount int
	fmt.Scan(&leafCount, &edgeCount)
	g := NewGraph(leafCount)
	for i := 0; i < edgeCount; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		g.AddNode(a, b)
	}
	result := true
	for i := 0; i < edgeCount; i++ {
		if ! g.DeleteLeaf() {
			result = false
			break
		}
	}
	if result {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}