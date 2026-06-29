int numOfStrings(char** patterns, int patternsSize, char* word) {

    int c=0;

    for(int i=0;i<patternsSize;i++)
    {
        if(strstr(word,patterns[i])!=NULL)
        {
            c++;
        }
        
    }

    return c;
    
}