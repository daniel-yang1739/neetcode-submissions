type ListNode struct {
	val 	int
	next 	*ListNode
}

type MyHashSet struct {
	size 	int
	buckets []*ListNode
}

func Constructor() MyHashSet {
	const bucketSize = 100
	buckets := make([]*ListNode, bucketSize)
	for i := 0; i < bucketSize; i++ {
		buckets[i] = &ListNode{}
	}
	return MyHashSet{
		size:		bucketSize,
		buckets:	buckets,
	}
}

func (this *MyHashSet) Add(key int) {
	if this.Contains(key) {
		return
	}
	bucketID := key % this.size
	newNode := &ListNode{ val: key, next: this.buckets[bucketID].next }
	this.buckets[bucketID].next = newNode
}

func (this *MyHashSet) Remove(key int) {
	if !this.Contains(key) {
		return
	}
    bucketID := key % this.size
	node := this.buckets[bucketID]
	for node.next != nil && node.next.val != key {
		node = node.next
	}
	node.next = node.next.next
}

func (this *MyHashSet) Contains(key int) bool {
    bucketID := key % this.size
	node := this.buckets[bucketID].next
	for node != nil {
		if node.val == key {
			return true
		}
		node = node.next
	}
	return false
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(key);
 * obj.Remove(key);
 * param_3 := obj.Contains(key);
 */
 