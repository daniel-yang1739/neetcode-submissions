type HeapNode struct {
	Len		int
	R		int
}

type MinHeap []HeapNode

func (h MinHeap) Len() int {
	return len(h)
}

func (h MinHeap) Less(i, j int) bool {
	if h[i].Len != h[j].Len {
		return h[i].Len < h[j].Len
	}
	return h[i].R < h[j].R
}

func (h MinHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *MinHeap) Push(x any) {
	*h = append(*h, x.(HeapNode))
}

func (h *MinHeap) Pop() any {
	lastIdx := len(*h) - 1
	top := (*h)[lastIdx]
	(*h) = (*h)[0:lastIdx]
	return top
}

type Query struct {
	Val		int
	Idx 	int
}

func minInterval(intervals [][]int, queries []int) []int {
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})

	qList := make([]Query, len(queries))
	for i, q := range queries {
		qList[i] = Query{Val: q, Idx: i}
	}
	sort.Slice(qList, func(i, j int) bool {
		return qList[i].Val < qList[j].Val
	})

	res := make([]int, len(queries))
	minHeap := &MinHeap{}
	heap.Init(minHeap)

	I := 0
	for _, q := range qList {
		for I < len(intervals) && q.Val >= intervals[I][0] {
			start, end := intervals[I][0], intervals[I][1] 
			heap.Push(minHeap, HeapNode{
				Len:	end - start + 1,
				R:		end,
			})
			I++
		}
		for minHeap.Len() > 0 && (*minHeap)[0].R < q.Val {
			heap.Pop(minHeap)
		}
		if minHeap.Len() <= 0 {
			res[q.Idx] = -1
		} else {
			res[q.Idx] = (*minHeap)[0].Len
		}
	}
	return res
}