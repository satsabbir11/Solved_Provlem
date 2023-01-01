class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
     p,q = [], []

     map1, map2 = {}, {}

     words = s.split()

     for i, word in enumerate(words):
       if word not in map1:
         map1[word] = i+1
       p.append(map1[word])

     for i, word in enumerate(pattern):
       if word not in map2:
         map2[word] = i+1
       q.append(map2[word])

     return p == q
