/* Final Project Milestone 5
Module: LibApp
Filename: LibApp.cpp
Version 1.0
Author	Kevin Gunawan
Revision History
-----------------------------------------------------------
Date      Reason
2023/August/1  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include "LibApp.h"
#include "PublicationSelector.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

namespace sdds {

	LibApp::LibApp(const char* filename) :m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?"), m_publicationType("Choose the type of publication:")
	{
		if (filename) {
			strcpy(m_filename, filename);
		}
		m_changed = false;
		m_NOLP = 0;

		m_mainMenu << "Add New Publication"
			<< "Remove Publication"
			<< "Checkout publication from library"
			<< "Return publication to library";

		m_exitMenu << "Save changes and exit"
			<< "Cancel and go back to the main menu";

		m_publicationType << "Book" << "Publication";

		load();
	}
	bool LibApp::confirm(const char* message) {
		Menu confirmationMenu(message);
		confirmationMenu << "Yes";

		if (confirmationMenu.run() == 1) {
			return true;
		}
		return false;
	}

	void LibApp::load() {
		cout << "Loading Data" << endl;
		ifstream file(m_filename);
		char type{};
		int i;
		for (i = 0; file && i < SDDS_LIBRARY_CAPACITY; i++) {
			file >> type;
			file.ignore();
			if (file) {
				if (type == 'P') {
					m_PPA[i] = new Publication;
				}
				else if (type == 'B') {
					m_PPA[i] = new Book;
				}
				if (m_PPA[i]) {
					file >> *m_PPA[i];
					m_NOLP++;
					m_LLRN = m_PPA[i]->getRef();
				}
			}
		}
	}

	void LibApp::save() {
		cout << "Saving Data" << endl;
		ofstream file(m_filename);
		int i;
		for (i = 0; i < m_NOLP; i++) {
			if (m_PPA[i]->getRef() != 0) {
				file << *m_PPA[i] << endl;
			}
		}
	}

	int LibApp::search(int search) {
		char title[300]{};
		int select = 0;
		int i = 0;
		int ref = 0;
		char type;
		PublicationSelector pubSel("Select one of the following found matches:", 15);

		select = m_publicationType.run();

		if (select == 1) {
			type = 'B';
		}
		else if (select == 2) {
			type = 'P';
		}

		cin.ignore(1000, '\n');
		cout << "Publication Title: ";
		cin.getline(title, 300);

		if (search == 1) {
			for (i = 0; i < m_NOLP; i++) {
				if (m_PPA[i]->operator==(title) && type == m_PPA[i]->type() && m_PPA[i]->getRef() != 0) {
					pubSel << m_PPA[i];
				}
			}
		}
		else if (search == 2) {
			for (i = 0; i < m_NOLP; i++) {
				if (m_PPA[i]->operator==(title) && m_PPA[i]->onLoan() && type == m_PPA[i]->type() && m_PPA[i]->getRef() != 0) {
					pubSel << m_PPA[i];
				}
			}			
		}
		else if (search == 3) {
			for (i = 0; i < m_NOLP; i++) {
				if (m_PPA[i]->operator==(title) && m_PPA[i]->onLoan() && type == m_PPA[i]->type() && m_PPA[i]->getRef() != 0) {
					pubSel << m_PPA[i];
				}
			}
		}
		if (pubSel) {
			pubSel.sort();
			ref = pubSel.run();
			if (ref > 0)
			{
				cout << *getPub(ref) << endl;
			}
			else {
				cout << "Aborted!" << endl;
			}
		}
		else {
			cout << "No matches found!" << endl;
		}
		return ref;
	}

	void LibApp::returnPub() {
		bool abort = false;
		cout << "Returning publication to the library" << endl;
		int ref = search(2);

		if (!(ref > 0)) {
			abort = true;
		}

		if (!abort) {
			bool confirmed = confirm("Return Publication?");

			if (confirm) {
				int numDaysLoaned = Date() - getPub(ref)->checkoutDate();

				if (numDaysLoaned > SDDS_MAX_LOAN_DAYS) {
					double penaltyCost = (numDaysLoaned - SDDS_MAX_LOAN_DAYS) * 0.5;
					cout << fixed << setprecision(2) << "Please pay $" << penaltyCost << " penalty for being " << (numDaysLoaned - SDDS_MAX_LOAN_DAYS) << " days late!" << endl;
				}
				getPub(ref)->set(0);
				m_changed = true;
			}
			cout << "Publication returned" << endl;
		}
		cout << endl;
	}

	

	LibApp::~LibApp() {
		for (int i = 0; i < m_NOLP; i++) {
			delete m_PPA[i];
		}
	}

	void LibApp::newPublication() {
		bool abort = false;

		if (m_NOLP == SDDS_LIBRARY_CAPACITY) {
			cout << "Library is at its maximum capacity!" << endl;
			abort = true;
		}
		if (!abort) {
			cout << "Adding new publication to library" << endl;
			int type = m_publicationType.run();
			cin.ignore(1000, '\n');

			Publication* p = nullptr;

			if (type == 0) {
				cout << "Aborted!" << endl;
				abort = true;
			}
			else if (type == 1) {
				p = new Book;
				cin >> *p;
			}
			else if (type == 2) {
				p = new Publication;
				cin >> *p;
			}
			if (cin.fail()) {
				cin.ignore(1000, '\n');
				cin.clear();
				cout << "Aborted!" << endl;
				exit(0);
			}
			else {
				if (!abort && confirm("Add this publication to library?")) {
					if (!*p) {
						cout << "Failed to add publication!" << endl;
						delete p;
					}
					else {
						m_LLRN++;
						p->setRef(m_LLRN);
						m_PPA[m_NOLP] = p;

						m_NOLP++;
						m_changed = true;

						cout << "Publication added" << endl;
					}
				}
			}
		}
		cout << endl;
	}

	void LibApp::removePublication() {
		cout << "Removing publication from the library" << std::endl;
		int ref = search(1); 
		if (ref) {
			if (confirm("Remove this publication from the library?")) {
				getPub(ref)->setRef(0);
				m_changed = true;
				cout << "Publication removed" << endl;
			}
		}
		cout << endl;
	}
	void LibApp::checkOutPub() {
		cout << "Checkout publication from the library" << endl;
		int ref = search(3); 

		if (ref > 0) {
			bool confirmed = confirm("Check out publication?");
			if (confirmed) {
				cout << "Enter Membership number: ";
				int membership;
				cin >> membership;
				while (membership < 10000 || membership > 99999 || cin.fail()) {
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Invalid membership number, try again: ";
					cin >> membership;
				}
				getPub(ref)->set(membership);
				m_changed = true;
				cout << "Publication checked out" << endl;
			}
		}
		cout << endl;
	}

	Publication* LibApp::getPub(int libref) {
		Publication* result = nullptr;
		for (int i = 0; i < m_NOLP; i++)
		{
			if (m_PPA[i]->getRef() == libref) {
				result = m_PPA[i];
			}
		}

		return result;
	}

	void LibApp::run() {
		int menu, exit;

		do {
			menu = m_mainMenu.run();
			switch (menu) {
			case 0:
				if (m_changed == true) {
					exit = m_exitMenu.run();

					switch (exit) {
					case 0:
						if (confirm("This will discard all the changes are you sure?")) {
							m_changed = false;
						}
						break;
					case 1:
						save();
						break;
					case 2:
						menu = 1;
						break;
					}
				}
				std::cout << std::endl;
				break;
			case 1:
				newPublication();
				break;
			case 2:
				removePublication();
				break;
			case 3:
				checkOutPub();
				break;
			case 4:
				returnPub();
				break;
			}
		} while (menu != 0); 

		cout << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;
	}
}

