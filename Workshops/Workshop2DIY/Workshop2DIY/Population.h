#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {
	struct Population {
		char * postal;
		int pop;
	};
	void sort();
	bool load(Population& population);
	bool load(const char * datafilename);
	void display(Population& population);
	void display();
	void deallocateMemory();

}
#endif // SDDS_POPULATION_H_