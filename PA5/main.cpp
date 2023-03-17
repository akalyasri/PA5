#include "queue.hpp"
#include <Windows.h>


Queue *expressLane;
Queue* normalLane;

int main(void) {

	
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

	int eTimer = rand() % 5 + 1;
	int nTimer = rand() % 8 + 3;


	QueueNode* epCur = expressLane->getpHead();
	QueueNode* npCur = normalLane->getpHead();

	while (elapsedMins <= (24 * 60)) {

		
		// express lane enqueue
		if (elapsedMins == eLaneArrTime) {

			// first calculate total time - ServiceTime + sum of 
			// serviceTimes of customers in line before this customer
			eTotalT = expressLane->calcTotalServiceTime(expressLane->getpHead());

			
			expressLane->enqueue(++eCusNum, eSerTime = rand() % 5 + 1, eTotalT);
			cout << "customer entered the express lane at " << eLaneArrTime << " mins" << endl;

			//int eCurMins = elapsedMins;

			eLaneArrTime = elapsedMins + (rand() % 5 + 1);


			// express lane dequeue
			/*if (elapsedMins != eTimer && !expressLane->isEmpty()) {

				eTimer = elapsedMins + (expressLane->getpHead()->getData()->getServiceTime());
			}*/
			if (elapsedMins == eTimer && !expressLane->isEmpty()) {
				int cNum = 0;// expressLane->getpHead()->getData()->getCustomerNumber();
				int sNum = 0;// expressLane->getpHead()->getData()->getServiceTime();
				int tTime = 0;// expressLane->getpHead()->getData()->getTotalTime();
				int& ref1 = cNum;
				int& ref2 = sNum;
				int& ref3 = tTime;

			
				expressLane->dequeue(ref1, ref2, ref3);
				cout << "customer exited the express lane at " << eTimer << " mins" << endl;

				eTimer = elapsedMins + (expressLane->getpHead()->getData()->getServiceTime());
			}


		}


		// normal lane enqueue
		if (elapsedMins == nLaneArrTime) {

			// first calculate total time - ServiceTime + sum of 
			// serviceTimes of customers in line before this customer
			nTotalT = normalLane->calcTotalServiceTime(normalLane->getpHead());

			
			normalLane->enqueue(++nCusNum, nSerTime = rand() % 8 + 3, nTotalT);
			cout << "customer entered the normal lane at " << nLaneArrTime << " mins" << endl;

			//int nCurMins = elapsedMins;

			nLaneArrTime = elapsedMins + (rand() % 8 + 3);


			// normal lane dequeue
			/*if (elapsedMins != nTimer && !normalLane->isEmpty()) {
				
				nTimer = elapsedMins + (normalLane->getpHead()->getData()->getServiceTime());
				
			}*/
			if (elapsedMins == nTimer && !normalLane->isEmpty()) {
				int cNum = 0;// normalLane->getpHead()->getData()->getCustomerNumber();
				int sNum = 0;// normalLane->getpHead()->getData()->getServiceTime();
				int tTime = 0;// normalLane->getpHead()->getData()->getTotalTime();
				int& ref1 = cNum;
				int& ref2 = sNum;
				int& ref3 = tTime;

				
				normalLane->dequeue(ref1, ref2, ref3);
				cout << "customer exited the normal lane at " << nTimer << " mins" << endl;

				nTimer = elapsedMins + (normalLane->getpHead()->getData()->getServiceTime());

			}


		}

		//print every 10 mins
		if (elapsedMins % 10 == 0 && elapsedMins != 0) { 

			cout << endl;

			cout << "EXPRESS LANE" << endl;
			expressLane->printQueue(epCur);

			cout << endl;

			cout << "NORMAL LANE" << endl;
			normalLane->printQueue(npCur);

			cout << endl;

			epCur = expressLane->getpTail();
			npCur = normalLane->getpTail();

		}

		/*eTimer--;
		nTimer--;*/
		elapsedMins++; // one min has passed

		Sleep(0); // simulating one min
	}

	//cout << "Recent queue:" << endl;

	//cout << "EXPRESS LANE" << endl << endl;
	//expressLane->printQueue(epCur);

	//cout << "NORMAL LANE" << endl << endl;
	//normalLane->printQueue(npCur);


}
