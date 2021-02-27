class SegmentTree:
  def __init__(self, v, e, op):
    self.sz = len(v)
    self.e = e
    self.op = op
    self.n = 1
    while self.n < self.sz:
      self.n <<= 1
    self.node = [e]*(self.n*2)

    for i in range(self.sz):
      self.node[i+self.n] = v[i]
    
    for i in range(self.n-1, -1, -1):
      self.node[i] = self.op(self.node[i*2], self.node[i*2+1])
  
  def at(self, k):
    return self.node[k+self.n]
  
  def change(self, k, x):
    k += self.n
    self.node[k] = x
    while k > 1:
      k >>= 1
      self.node[k] = self.op(self.node[k*2], self.node[k*2+1])


  def query(self, a, b):
    l = self.e
    r = self.e
    a += self.n
    b += self.n
    while a < b:
      if a&1 == 1:
        l = self.op(l, self.node[a])
        a += 1
      if b&1 == 1:
        b -= 1
        r = self.op(self.node[b], r)
      a >>= 1
      b >>= 1
    return self.op(l, r)
