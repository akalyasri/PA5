#include "queue.hpp"



void run24Simulation(void) {
	Queue* expressLane;
	Queue* normalLane;
	expressLane = new Queue;
	normalLane = new Queue;

	srand(time(0));
	int elapsedMins = 0;

	int eLaneArrTime = rand() % 5 + 1;
	int nLaneArrTime = rand() % 8 + 3;


	int eCusNum = 0;
	int nCusNum = 0;

	int eSerTime = 0;
	int nSerTime = 0;

	int eTotalT = 0;
	int nTotalT = 0;

	int eTimer = 5;
	int nTimer = 5;


	QueueNode* epCur = expressLane->getpHead();
	QueueNode* npCur = normalLane->getpHead();

	while (elapsedMins < (24 * 60)) {

		/*if (eTimer <0 && !expressLane->isEmpty()) {

			eTimer = expressLane->getpHead()->getData()->getServiceTime();
		}

		else if (eTimer == 0 && !expressLane->isEmpty()) {
			int cNum = expressLane->getpHead()->getData()->getCustomerNumber();
			int sNum = expressLane->getpHead()->getData()->getServiceTime();
			int tTime = expressLane->getpHead()->getData()->getTotalTime();
			int& ref1 = cNum;
			int& ref2 = sNum;
			int& ref3 = tTime;

			expressLane->dequeue(ref1,ref2,ref3);
		}

		if (nTimer < 0 && !normalLane->isEmpty()) {

			nTimer = normalLane->getpHead()->getData()->getServiceTime();
		}

		else if (nTimer == 0 && !normalLane->isEmpty()) {
			int cNum = normalLane->getpHead()->getData()->getCustomerNumber();
			int sNum = normalLane->getpHead()->getData()->getServiceTime();
			int tTime = normalLane->getpHead()->getData()->getTotalTime();
			int& ref1 = cNum;
			int& ref2 = sNum;
			int& ref3 = tTime;

			normalLane->dequeue(ref1, ref2, ref3);

		}*/

		if (elapsedMins == eLaneArrTime) {

			// first calculate total time - ServiceTime + sum of 
			// serviceTimes of customers in line before this customer
			eTotalT = expressLane->calcTotalServiceTime(expressLane->getpHead());

			expressLane->enqueue(++eCusNum, eSerTime = rand() % 5 + 1, eTotalT);

			//int eCurMins = elapsedMins;

			eLaneArrTime = elapsedMins + (rand() % 5 + 1);

			//then sort express lane queue based on service time
		}

		if (elapsedMins == nLaneArrTime) {

			// first calculate total time - ServiceTime + sum of 
			// serviceTimes of customers in line before this customer
			nTotalT = normalLane->calcTotalServiceTime(normalLane->getpHead());


			normalLane->enqueue(++nCusNum, nSerTime = rand() % 8 + 3, nTotalT);

			//int nCurMins = elapsedMins;

			nLaneArrTime = elapsedMins + (rand() % 8 + 3);

			//then sort normal lane queue based on service time
		}

		if (elapsedMins % 120 == 0) {

			cout << "EXPRESS LANE" << endl << endl;
			expressLane->printQueue(epCur);

			cout << "NORMAL LANE" << endl << endl;
			normalLane->printQueue(npCur);

			epCur = expressLane->getpTail();
			npCur = normalLane->getpTail();

		}

		eTimer--;
		nTimer--;
		elapsedMins++; // one min has passed

		Sleep(0); // simulating one min
	}
}