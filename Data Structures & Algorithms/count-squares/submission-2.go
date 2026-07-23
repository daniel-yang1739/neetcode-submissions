// This struct must be comparable
type Point struct {
	x, y int
}

type CountSquares struct {
	pointCount	map[Point]int
	points		[]Point
}

func Constructor() CountSquares {
	return CountSquares{
		pointCount: make(map[Point]int),
		points:		[]Point{},
	}
}

func (this *CountSquares) Add(point []int)  {
   	p := Point{x: point[0], y: point[1]} 
   	this.pointCount[p]++
   	this.points = append(this.points, p)
}

func (this *CountSquares) Count(point []int) int {
	res := 0
	x1, y1 := point[0], point[1]
   	for _, p := range this.points {	
		if abs(x1 - p.x) != abs(y1 - p.y) || p.x == x1 || p.y == y1{
			continue
		}
		p1 := Point{x: x1, y: p.y}
		p2 := Point{x: p.x, y: y1}
		res += this.pointCount[p1] * this.pointCount[p2]
   	} 
	return res
}

func abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}