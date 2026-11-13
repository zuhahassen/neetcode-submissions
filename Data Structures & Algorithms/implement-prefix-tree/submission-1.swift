class TrieNode {
    var children : [Character: TrieNode]
    var endOfWord : Bool 

    init() {
        self.children = [:]
        self.endOfWord = false
    }
}

class PrefixTree {
    private let root: TrieNode

    init() {
        self.root = TrieNode()
    }

    func insert(_ word: String) {
        var cur = root

        for c in word {
            if cur.children[c] == nil {
                cur.children[c] = TrieNode()
            }

            cur = cur.children[c]!
        }

        cur.endOfWord = true
    }

    func search(_ word: String) -> Bool {
        var cur = root

        for c in word {
            if cur.children[c] == nil {
                return false
            }

            cur = cur.children[c]!
        }

        return cur.endOfWord
    }

    func startsWith(_ prefix: String) -> Bool {
        var cur = root

        for c in prefix {
            if cur.children[c] == nil {
                return false
            }

            cur = cur.children[c]!
        }

        return true
    }
}
