namespace sdds
{

    void strCpy(char* des, char* src)
    {
       
        while (*src) {
            *des = *src;
            des++;
            src++;
        }
        *des = '\0';

    }

    void strnCpy(char* des, char* src, int len)
    {

        for (int i = 0; i < len; i++)
        {
            des[i] = src[i];
        }
    }

    int strCmp(const char* s1, const char* s2)
    {
        while (*s1 && *s2 && *s1 == *s2) {
            s1++;
            s2++;
        }

        if (*s1 > *s2)
            return 1;
        else if (*s1 < *s2)
            return -1;
        else
            return 0;

    }

    int strnCmp(const char* s1, const char* s2, int len)
    {
        for (int i = 0; i < len; i++) {
            if (*s1 && *s2 && *s1 != *s2) {
                if (*s1 > *s2)
                    return 1;
                else
                    return -1;
            }

            s1++;
            s2++;
        }

        return 0;
    }

    int strLen(const char* s)
    {
        int length = 0;
        while (s[length] != '\0') {
            length++;
        }
        return length;
    }

    const char* strStr(const char* str1, const char* str2)
    {
        while (*str1) {
            const char* temp1 = str1;
            const char* temp2 = str2;

            while (*temp1 && *temp2 && *temp1 == *temp2) {
                temp1++;
                temp2++;
            }

            if (!*temp2)
            {
                return str1;
            }
            str1++;
        }

        return nullptr;
    }
    void strCat(char* des, const char* src)
    {
        int len1 = strLen(des);
        int len2 = strLen(src);

        int i = len1;
        int j = 0;
        while (j < len2) {
            des[i] = src[j];
            i++;
            j++;
        }

        des[i] = '\0';

    }

}