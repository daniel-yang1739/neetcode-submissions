func myPow(x float64, n int) float64 {
    isNeg := n < 0
    if isNeg {
        n = -n
    }
    res := float64(1)
    for n > 0 {
        if n % 2 == 1 {
            res *= x
        }
        x = x * x
        n /= 2
    }
    if isNeg {
        res = 1 / res
    }
    return res
}