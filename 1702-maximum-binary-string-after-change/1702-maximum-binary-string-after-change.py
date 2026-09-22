class Solution(object):
    def maximumBinaryString(self, binary):
        if "0" not in binary:
            return binary
        first_zero=binary.find("0")
        zero_count=binary.count("0")
        zero_pos=first_zero+zero_count-1
        res=["1"]*len(binary)
        res[zero_pos]="0"
        return "".join(res)