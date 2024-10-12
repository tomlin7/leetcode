from typing import List

class UnionFind:
    def __init__(self, n):
        self.n = n
        self.parent = [i for i in range(n)]
        self.rank = [0 for i in range(n)]
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def is_connected(self, x, y):
        return self.parent[x] == self.parent[y]

    def union(self, x, y):
        x_root = self.find(x)
        y_root = self.find(y)
        if x_root != y_root:
            if self.rank[x_root] < self.rank[y_root]:
                self.parent[x_root] = y_root
            elif self.rank[x_root] > self.rank[y_root]:
                self.parent[y_root] = x_root
            else:
                self.parent[y_root] = x_root
                self.rank[x_root] += 1
            return True
        return False


        if x_root == y_root:
            return False

        if self.rank[x_root] < self.rank[y_root]:
            self.parent[x_root] = y_root
        elif self.rank[x_root] > self.rank[y_root]:
            self.parent[y_root] = x_root
        else:
            self.parent[y_root] = x_root
            self.rank[x_root] += 1

        return True


class Solution:
    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
        uf = UnionFind(n)
        uf.union(0, firstPerson)
        for meeting in meetings:
            uf.union(meeting[0], meeting[1])
        return [i for i in range(n) if uf.is_connected(0, i)]
s = Solution()
# print(s.findAllPeople(6, [[1,2,5],[2,3,8],[1,5,10]], 1))
# print(s.findAllPeople(4, [[3,1,3],[1,2,2],[0,3,3]], 3))
# print(s.findAllPeople(5, [[3,4,2],[1,2,1],[2,3,1]], 1))
print(s.findAllPeople(5, [[1,4,3],[0,4,3]], 3))