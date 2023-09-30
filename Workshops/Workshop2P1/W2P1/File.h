#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
	
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	bool read(char name[]);
	bool read(int& empNum);
	bool read(double& sal);


}
#endif // !SDDS_FILE_H_