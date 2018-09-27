def pick(visited,dist):
	min = 998
	for i in range(0,len(dist)):
		if i not in visited and dist[i] < min:
			min = dist[i]
			index = i
	return index

def djikstra(adjacency_list,dist,visited):
	visited.append(0)
	while len(visited) != len(adjacency_list):
		vertex = pick(visited,dist)
		print("Picked Vertex : ",vertex)
		visited.append(vertex)
		for neighbour in range(0,len(adjacency_list)):
			if dist[vertex] + adjacency_list[vertex][neighbour] < dist[neighbour]:
				dist[neighbour] = dist[vertex] + adjacency_list[vertex][neighbour]
	print(dist)


adjacency_list = [
					[0,3,4,2,999],
					[3,0,2,999,4],
					[4,2,0,1,5],
					[2,999,1,0,6],
					[999,4,5,6,0]
				]

dist = []
source = int(input("Enter your source : "))
for i in range(0,len(adjacency_list)):
	dist.append(adjacency_list[i][source])
visited = []
djikstra(adjacency_list,dist,visited)