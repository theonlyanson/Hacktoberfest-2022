class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        
        def solve(k):
            if len(k)==0:
                return
            
            ans , newk= [], []
            for node in k:
                ans.append( node.val )
                
                if node.left:
                    newk.append(node.left)
                if node.right:
                    newk.append(node.right)
            
            res.append(ans)
            solve( newk )
            return
        
        res = []
        if root:
            solve( [root] )
        return res
