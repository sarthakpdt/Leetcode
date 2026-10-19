class AuthenticationManager(object):
    def __init__(self, timeToLive):
        self.ttl=timeToLive
        self.tokens={}
    def generate(self, tokenId, currentTime):
        self.tokens[tokenId]=currentTime+self.ttl
    def renew(self, tokenId, currentTime):
        if tokenId in self.tokens and self.tokens[tokenId]>currentTime:
            self.tokens[tokenId]=currentTime+self.ttl
    def countUnexpiredTokens(self, currentTime):
        return sum(1 for exp in self.tokens.values() if exp>currentTime)