class Solution {
    func isAnagram(_ s: String, _ t: String) -> Bool {
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
