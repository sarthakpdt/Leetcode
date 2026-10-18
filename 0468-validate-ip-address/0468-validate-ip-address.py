class Solution(object):
    def validIPAddress(self, queryIP):
        if "." in queryIP:
            p = queryIP.split(".")
            if len(p) != 4:
                return "Neither"
            for x in p:
                if (
                    not x
                    or not x.isdigit()
                    or (len(x) > 1 and x[0] == "0")
                    or int(x) > 255
                ):
                    return "Neither"
            return "IPv4"
        elif ":" in queryIP:
            p = queryIP.split(":")
            if len(p) != 8:
                return "Neither"
            h = "0123456789abcdefABCDEF"
            for x in p:
                if not x or len(x) > 4 or any(c not in h for c in x):
                    return "Neither"
            return "IPv6"
        return "Neither"