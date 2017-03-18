/* This function is a no bloat approach
 * to handling ASCII string comparisons */


/* Function Prototype */
int strCmp(char *this, char *that);


int strCmp(char *this, char *that)
{
        while(*this != '\0'){
                if(*this++ != *that++) return 0;
        }

        return (*that == '\0');
}

