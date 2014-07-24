class Solution:
    # @param head, a list node
    # @return a tree node
    def sortedListToBST(self, head):
        if head == None: return None
        fast = head
        low = head
        pre = low
        while fast!=None and fast.next!=None :
            fast = fast.next.next
            pre = low
            low = low.next
        pre.next = None
        node = TreeNode(low.val)
        if head != low:
            node.left = self.sortedListToBST(head)
        pre = low.next
        low.next =None
        node.right = self.sortedListToBST(pre)
        return node
        