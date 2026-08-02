func groupAnagrams(strs []string) [][]string {
    groups := make(map[[26]int][]string)
    for _, s := range strs {
        // Character Distribution
        dist := [26]int{}
        for i := range s {
            dist[s[i]-'a']++
        }
        groups[dist] = append(groups[dist], s)
    }
    res := [][]string{}
    for _, group := range groups {
        res = append(res, group)
    }
    return res
}
