'''
Find the Deepest left most Leaf NODE

Consider the Tree : 
			  1
		      /       \
		     2         3
	  	   /    \     /   
	 	  4      5   6
		/          /
   	       8          7
			 /
			9

The two left-most leaf nodes in our case are 8 and 9.
But the deepest here in the node 9 at height 5

The idea is to create a dictionary which stores all the left-most leaf node values & their depths
We then print the node which is at the maximum depth

'''

class Node:   
	# Constructor to create a new node 
	def __init__(self, data): 
		self.data = data 
		self.left = None
		self.right = None

#Parameters - current node , parent node , dictionary , tree depth  
def deepest(self,parent,dct,depth):
	if self is None:
		return
	#Checks if the node is a leaf node  & also if it is a left child of its parent
	if self.left == None and self.right == None and parent.left == self :
		dct[self.data] = depth
		return self.data
	deepest(self.left,self,dct,depth+1)
	deepest(self.right,self,dct,depth+1)
  
# Driver to test above function 
root = Node(1) 
root.left = Node(2) 
root.right = Node(3) 
root.right.left = Node(6)
root.right.left.left = Node(7)  
root.right.left.left.left = Node(9)  
root.left.left = Node(4) 
root.left.left.left = Node(8) 
root.left.right = Node(5)

dct = dict()
deepest(root,root,dct,0)

#Find the maximum height
max = 0
for value in dct.values():
	if value > max:
		max = value 

#Print all those nodes which are max height
for key,value in dct.items():
	if value == max:
		print("NODE : ",key," HEIGHT : ",value)
