/**
 * Definition of Interval:
 * type Interval struct {
 *    start int
 *    end   int
 * }
 */

func minMeetingRooms(intervals []Interval) int {
	n := len(intervals)
	startTimes := make([]int, n)
	endTimes := make([]int, n)
	for i, interval := range intervals {
		startTimes[i] = interval.start
		endTimes[i] = interval.end
	}
	sort.Ints(startTimes)
	sort.Ints(endTimes)
	roomCount := 0
	S, E := 0, 0
	for S < n && E < n {
		if startTimes[S] < endTimes[E] {
			roomCount++
			S++
		} else {
			S++
			E++
		}
	}
	return roomCount
}