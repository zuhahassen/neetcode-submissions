class Solution {
    func isAnagram(_ s: String, _ t: String) -> Bool {
        if s.count != t.count {
            return false
        }
        
        var sHash = [Character: Int](); 
        var tHash = [Character: Int](); 

        for cs in s {
            sHash[cs, default: 0] += 1
        }

        for ct in t {
            tHash[ct, default: 0] += 1
        }

        return sHash == tHash

    }
}
