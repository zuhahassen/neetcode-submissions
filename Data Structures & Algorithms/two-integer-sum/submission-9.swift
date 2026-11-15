class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        
        var prevMap = [Int: Int]()

        for (i, n) in nums.enumerated() {
            let diff = target - n

            if let ind = prevMap[diff] {
                return [ind, i]
            }
            
            prevMap[n] = i
        }

        return []
    }
}
