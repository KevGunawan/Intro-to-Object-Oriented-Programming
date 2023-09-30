#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "cstring.h"
#include "TextFile.h"
using namespace std;
namespace sdds {
    Line::operator const char* () const {
        return (const char*)m_value;
    }
    Line& Line::operator=(const char* lineValue) {
        delete[] m_value;
        m_value = new char[strlen(lineValue) + 1];
        strcpy(m_value, lineValue);
        return *this;
    }
    Line::~Line() {
        delete[] m_value;
    }

    void TextFile::setFilename(const char* fname, bool isCopy) {

        if (isCopy) {
            const char* prefix = "C_";
            m_filename = new char[strlen(prefix) + strlen(fname) + 1];
            strcpy(m_filename, prefix);
            strcat(m_filename, fname);
        }
        else {
         
            m_filename = new char[strlen(fname) + 1];
            strcpy(m_filename, fname);
        }
    }
    void TextFile::setEmpty() {
        delete[] m_filename;
        delete[] m_textLines;
        m_filename = nullptr;
        m_textLines = nullptr;
        m_noOfLines = 0;
        m_pageSize = 0;
    }

    void TextFile::saveAs(const char* fileName) const {
        std::ofstream file(fileName);

        if (file.is_open()) {
            for (unsigned i = 0; i < m_noOfLines; i++) {
                file << m_textLines[i] << std::endl;
            }
            file.close();
        }
        
    }

    void TextFile::setNoOfLines() {
        std::ifstream file(m_filename);
        
        m_noOfLines = 0;
        if (file.is_open()) {
            char character = '\0';
            while (file.get(character)) {
                if (character == '\n') {
                    m_noOfLines++;
                }
            }
            m_noOfLines++;
        }

        if (m_noOfLines == 0) {
            setEmpty();
        }

        file.close();
    }

    void TextFile::loadText() {
        if (m_filename) {
            std::ifstream file(m_filename);
            std::string line;
            size_t i = 0;
            delete[] m_textLines;
            m_textLines = new Line[m_noOfLines];

            for (i = 0; i < m_noOfLines; i++) {
                std::getline(file, line);
                m_textLines[i] = line.c_str();
            }

           file.close();

        }
        
    }

    TextFile::TextFile(unsigned pageSize) {
        m_textLines = nullptr;
        m_filename = nullptr;
        m_noOfLines = 0;
        m_pageSize = pageSize;
        
    }

    TextFile::TextFile(const char* filename, unsigned pageSize) {
        m_textLines = nullptr;
        m_filename = nullptr;
        m_noOfLines = 0;
        m_pageSize = pageSize;

        setFilename(filename);
        if (m_filename) {
            setNoOfLines();
            loadText();
        }
        else {
            setEmpty();
        }
    }

    TextFile::TextFile(const TextFile& other) {
        m_textLines = new Line[other.m_noOfLines];
        m_filename = new char[strlen(other.m_filename) +1];
        setEmpty();

        m_pageSize = other.m_pageSize;

        if (other) {
            setFilename(other.m_filename, true);
            other.saveAs(m_filename);
            m_noOfLines = other.m_noOfLines;
            loadText();
        }
        else {
            setEmpty();
        }
    }


    TextFile& TextFile::operator=(const TextFile& other) {
        if (this != &other) {
            delete[] m_textLines;
            m_textLines = nullptr;

            m_pageSize = other.m_pageSize;
            if (other) {
                other.saveAs(m_filename);
                m_noOfLines = other.m_noOfLines;
                loadText();
            }
            else {
                setEmpty();
            }
        }
        return *this;
    }

    TextFile::~TextFile() {
        delete[] m_filename;
        m_filename = nullptr;
        delete[] m_textLines;
        m_textLines = nullptr;
        m_noOfLines = 0;
    }

    std::ostream& TextFile::view(std::ostream& ostr) const {

        if (m_filename) {
            ostr << m_filename << std::endl;

            for (unsigned int i = 0; i < strlen(m_filename); ++i) {
                ostr << '=';
            }
            ostr << std::endl;

            for (size_t i = 0; i < m_noOfLines; ++i) {
                ostr << m_textLines[i] << std::endl;


                if ((i+1) % m_pageSize == 0) {
                    ostr << "Hit ENTER to continue...";
                    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cin.ignore(1000, '\n');
                }
            }
        }
        return ostr;
    }

    std::istream& TextFile::getFile(std::istream& istr) {
        std::string filename;
        istr >> filename;
        cin.ignore(1000, '\n');
        setFilename(filename.c_str());
        if (m_filename) {
            setNoOfLines();
            loadText();
        }
        else {
            setEmpty();
        }
        return istr;
    }

    TextFile::operator bool() const {
        return (m_filename != nullptr);
    }

    const char* TextFile::name() const {
        return m_filename;
    }

    unsigned TextFile::lines()const {
        return m_noOfLines;
    }

    const char* TextFile::operator[](unsigned index) const {
        if (m_filename == nullptr) {
            return nullptr;
        }

        if (index >= m_noOfLines) {
            index = index % m_noOfLines;
        }

        return m_textLines[index];
    }

    std::ostream& operator<<(std::ostream& ostr, const TextFile& text) {
        return (text.view(ostr));
       
    }

    std::istream& operator>>(std::istream& istr, TextFile& text) {
       return (text.getFile(istr)); 
    }

}