class Solution {
    func isPalindrome(_ s: String) -> Bool {
        let char = Array(s)

        var l = 0
        var r = char.count - 1

        while l < r {
            if !char[l].isLetter  && !char[l].isNumber {
                l += 1
                continue
            }

            if !char[r].isLetter  && !char[r].isNumber {
                r -= 1
                continue
            }

            if char[l].lowercased() != char[r].lowercased() {
                return false
            }

            r -= 1
            l += 1 
        }

        return true; 

    }
}
