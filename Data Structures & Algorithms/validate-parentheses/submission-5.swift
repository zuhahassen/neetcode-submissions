class Solution {
    func isValid(_ s: String) -> Bool {
        var stack = [Character]()

        let bracket : [Character: Character] = ["}" : "{", ")" : "(", "]" : "["]

        for c in s {
            if let open = bracket[c] {
                if !stack.isEmpty && open == stack.last! {
                    stack.popLast()
                } else {
                    return false
                }
            } else {
                stack.append(c)
            }
        }

        return stack.isEmpty
    }
}
