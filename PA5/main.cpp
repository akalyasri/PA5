#include "queue.hpp"

Queue *line1;

int main(void) {


	line1 = new Queue;

	line1->enqueue(4, 2, 6);
	line1->enqueue(5, 3, 7);
	line1->enqueue(6, 4, 8);


}
