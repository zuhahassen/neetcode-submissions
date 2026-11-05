struct NumFreq: Comparable {
    let num: Int
    let freq: Int

    static func < (lhs: NumFreq, rhs: NumFreq) -> Bool {
        return lhs.freq < rhs.freq
    }
}

class Solution {
    func topKFrequent(_ nums: [Int], _ k: Int) -> [Int] {
        var count = [Int: Int]()

        for num in nums {
            count[num, default: 0] += 1
        }
        
        var heap: Heap<NumFreq> = [] 
        for (num, freq) in count {
            heap.insert(NumFreq(num: num, freq: freq))
            if heap.count > k {
                heap.removeMin()
            }
        }

        var res = [Int]()

        while !heap.isEmpty {
            res.append(heap.removeMin().num)
        }

        return res
    }
}
