class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        cnt1, cnt2 = 0, 0
        for s in word:
            if s.isupper():
                cnt1+=1
            else:
                cnt2+=1
        if cnt1==len(word):
            return True
        else:
            if (word[0].isupper() and cnt2+1==len(word)) or cnt2==len(word):
                return True
        return False