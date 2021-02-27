class UnionFind:
    def __init__(self, size):
        self.data = [-1] * size
    def root(self, x):
        if self.data[x] < 0:
            return x
        ans = self.root(self.data[x])
        self.data[x] = ans
        return ans
    def unite(self, x, y):
        x = self.root(x)
        y = self.root(y)
        if x == y:
            return False
        if self.data[x] > self.data[y]:
            x, y = y, x
        self.data[x] += self.data[y]
        self.data[y] = x
        return True
    def same(self, x, y):
        return self.root(x) == self.root(y)
