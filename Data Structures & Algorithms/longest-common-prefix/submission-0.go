func longestCommonPrefix(strs []string) string {
    res := []byte(strs[0])
    for _, str := range strs {
        for i := 0; i < len(res); i++ {
            if i >= len(str) || res[i] != str[i] {
                res = res[0:i]
                break
            }
        }
    }
    return string(res)
}
