package main

//spoj 1437 PT07Z - Longest path in a tree

import (
	"fmt"
	"sort"
)

// firstly read as a graph, and then tansfer into a tree
type Graph struct {
	Vertexes []map[int]int
}

func NewGraph(edgeCount int) *Graph {
	var g Graph
	g.Vertexes = make([]map[int]int, edgeCount)
	for i := 0; i < len(g.Vertexes); i++ {
		g.Vertexes[i] = map[int]int{}
	}
	return &g
}

func (g *Graph) AddEdge(a, b int) {
	g.Vertexes[a-1][b] = b
	g.Vertexes[b-1][a] = a
}

type Tree struct {
	Value int
	Childs []*Tree
}

func NewTree(vertex int) *Tree {
	var t Tree = Tree{vertex, []*Tree{}}
	return &t
}

func (t *Tree) AppendChild(child *Tree) {
	t.Childs = append(t.Childs, child)
}

func GetArbitoryFirstOfMap(m map[int]int) int {
	for k, _ := range m {
		return k
	}
	panic("empty")
}

func AddChildEdge(root *Tree, g *Graph, vertex int) {
	child := NewTree(vertex)
	root.AppendChild(child)
	delete(g.Vertexes[root.Value-1], vertex)
	delete(g.Vertexes[vertex-1], root.Value)
	for len(g.Vertexes[vertex-1]) > 0 {
		v := GetArbitoryFirstOfMap(g.Vertexes[vertex-1])
		AddChildEdge(child, g, v)
	}
}

func TraverseTree(root *Tree) {
	fmt.Println(root.Value)
	for _, v := range root.Childs {
		TraverseTree(v)
	}
}

func FindMaxPath(root *Tree, maxPath *int) int {
	if len(root.Childs) == 0 {
		return 0
	}
	paths := make([]int, len(root.Childs))
	for k, v := range root.Childs {
		paths[k]  = 1 + FindMaxPath(v, maxPath)
	}
	sort.Ints(paths)
	first := paths[len(paths)-1]
	second := 0
	if len(paths) > 1 {
		second = paths[len(paths)-2]
	}
	max := first + second
	if max > *maxPath {
		*maxPath = max
	}
	return first
}

func main() {
	var lines int
	fmt.Scan(&lines)
	g := NewGraph(lines)
	for i := 1; i < lines; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		g.AddEdge(a, b)
	}
/*	
	for k, v := range g.Vertexes {
		fmt.Print("vertex ", k+1, ": ")
		for _, vv := range v {
			fmt.Print(vv, ", ")
		}
		fmt.Println("")
	}
*/	
	root := NewTree(1)
	for len(g.Vertexes[0]) > 0 {
		v := GetArbitoryFirstOfMap(g.Vertexes[0])
		AddChildEdge(root, g, v)
	}
	
//	TraverseTree(root)
	
	maxPath := 0
	FindMaxPath(root, &maxPath)
	fmt.Println(maxPath)
}