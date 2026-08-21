/**
 * *********************************************************************
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * // Initializes an empty nested list and return a reference to the nested integer.
 * struct NestedInteger *NestedIntegerInit();
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * bool NestedIntegerIsInteger(struct NestedInteger *);
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * int NestedIntegerGetInteger(struct NestedInteger *);
 *
 * // Set this NestedInteger to hold a single integer.
 * void NestedIntegerSetInteger(struct NestedInteger *ni, int value);
 *
 * // Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
 * void NestedIntegerAdd(struct NestedInteger *ni, struct NestedInteger *elem);
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * struct NestedInteger **NestedIntegerGetList(struct NestedInteger *);
 *
 * // Return the nested list's size that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * int NestedIntegerGetListSize(struct NestedInteger *);
 * };
 */
struct NestedInteger* deserialize(char* s) {
    if(s[0]!='['){
        struct NestedInteger* res=NestedIntegerInit();
        NestedIntegerSetInteger(res,atoi(s));
        return res;
    }
    struct NestedInteger* stack[50000];
    int top=-1;
    int i=0;
    while(s[i]!='\0'){
        if(s[i]=='['){
            struct NestedInteger* ni=NestedIntegerInit();
            stack[++top]=ni;
            i++;
        }else if(s[i]==']'||s[i]==','){
            if(s[i]==']'&&top>0){
                struct NestedInteger* completedList=stack[top--];
                NestedIntegerAdd(stack[top],completedList);
            }
            i++;
        }else{
            int sign=1;
            if(s[i]=='-'){
                sign=-1;
                i++;
            }
            long num=0;
            while(isdigit(s[i])){
                num=num*10+(s[i]-'0');
                i++;
            }
            num*=sign;
            struct NestedInteger* numNI=NestedIntegerInit();
            NestedIntegerSetInteger(numNI,(int)num);
            NestedIntegerAdd(stack[top],numNI);
        }
    }
    return stack[0];
}