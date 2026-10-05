from collections import defaultdict
class UndergroundSystem(object):
    def __init__(self):
        self.checkins={}
        self.routes=defaultdict(lambda: [0, 0])
    def checkIn(self, id, stationName, t):
        self.checkins[id]=(stationName, t)
    def checkOut(self, id, stationName, t):
        start_station, start_time=self.checkins.pop(id)
        route=(start_station, stationName)
        self.routes[route][0]+=t-start_time
        self.routes[route][1]+=1
    def getAverageTime(self, startStation, endStation):
        total_time, total_trips=self.routes[(startStation, endStation)]
        return float(total_time)/total_trips