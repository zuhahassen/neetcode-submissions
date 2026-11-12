class Solution {
    func hasDuplicate(_ nums: [Int]) -> Bool {
        var s = Set<Int>()
        for n in nums {

            if s.contains(n) {
                return true
            }

            s.insert(n)
        }

        return false
    }
}
