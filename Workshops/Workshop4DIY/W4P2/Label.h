#ifndef SDDS_LABEL_H 
#define SDDS_LABEL_H

namespace sdds
{
    class Label {
        char m_labelFrame[9];
        char * m_labelContent;

    public:
        Label();
        Label(const char* frameArg);
        Label(const char* frameArg, const char* content);
        ~Label();
        void readLabel();
        std::ostream& printLabel()const;
    };
}

#endif
