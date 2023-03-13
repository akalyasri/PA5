#include <iostream>
#include <Windows.h>



class Data {

public: // Member functions

	Data(int cNum, int sTime, int tTime) {

		customerNumber = cNum;

		serviceTime = sTime;

		totalTime = tTime;

	}


	// Getters

	int getCustomerNumber(void) {
		return customerNumber;
	}

	int getServiceTime(void) {
		return serviceTime;
	}

	int getTotalTime(void) {
		return totalTime;
	}


	// Setters

	void setCustomerNumber(int cusNum) {
		customerNumber = cusNum;
	}

	void setServiceTime(int serTime) {
		serviceTime = serTime;
	}

	void setTotalTime(int totalT) {
		totalTime = totalT;
	}



private:
	int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
	
	int serviceTime;   // Random time; varies between express and normal lanes; units in minutes
	
	int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes

}; // This memory needs to be allocated on the heap!


