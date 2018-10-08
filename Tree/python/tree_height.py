'''
Consider the Tree : 
              1
           /     \
          2       3
        /   \    /  
       4     5  6
'''
class Node:   
    # Constructor to create a new node 
    def __init__(self, data): 
        self.data = data 
        self.left = None
        self.right = None
  
# Compute the "maxDepth" of a tree 
# Find the depth of each subtree & return the maximum among the two
def maxHeight(node): 
    if node is None: 
        return 0 ;  
  
    else :  
        # Compute the depth of each subtree 
        l = maxHeight(node.left) 
        r = maxHeight(node.right) 
  
        # Use the larger one 
        if (l > r): 
            return l+1
        else: 
            return r+1

# Driver program to test above function 
root = Node(1) 
root.left = Node(2) 
root.right = Node(3) 
root.left.left = Node(4) 
root.left.right = Node(5)
root.right.left = Node(6)

print(maxHeight(root))
