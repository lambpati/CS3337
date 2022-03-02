// Intstack class - dvb apr17
// note class DOES NOT check array boundaries - will eventually blow up!!
#include <iostream>
using namespace std;
class IntStack {
	private:
		int *stackArray;
		int stackTop = -1;
		// Introduced a new variable of array size to just make it easier.
		int arraySize;
	public:
	    static int countClassInstances;
		IntStack(int n) {
			stackArray = new int [n];
			arraySize = n;
			countClassInstances++;
		}
		IntStack() { IntStack(100); }
		int length() {return stackTop+1;}

		// If stacktop is smaller than the size of the array, add a value, else do nothing
    void push(int value){
			if(stackTop <= arraySize){
				stackArray[++stackTop]=value;
			}
		}


			// Added index checking for pop, returns 0 if out of bounds.
    	int pop() {
				if(stackTop >= 0){
					return stackArray[stackTop--];}
			 	else{
					return 0;
				}}
    	int peek() { return stackArray[stackTop]; }
    	~IntStack() { delete stackArray; }
  };
	// Class which adds a new array when stackArray is overfilled.
	class IntStackAlt {
		private:
			int *stackArray;
			int stackTop = -1;
			int *stackArray2;
			// Introduced a new variable of array size to just make it easier.
			int arraySize;
		public:
		    //static int countClassInstances;
			IntStackAlt(int n) {
				stackArray = new int [n];
				arraySize = n;
				//countClassInstances++;
			}
			IntStackAlt() { IntStack(100); }
			int length() {return stackTop+1;}

			// Creates new array using the new stackTop if out of bounds
	    	void push(int value){
					if(++stackTop > arraySize){
						stackArray2 = new int[2*arraySize];
						std::copy(stackArray, stackArray+length(), stackArray2);
						// delete stackArray;
						// IntStackAlt(2*arraySize);
						// std::copy(stackArray2, stackArray2+length(), stackArray);
						// delete stackArray2;
					}
					stackArray[++stackTop]=value;
				}

				// Added index checking for pop, returns 0 if out of bounds.
	    	int pop() {
					if(stackTop >= 0){
						return stackArray[stackTop--];}
				 	else{
						return 0;
					}}
	    	int peek() { return stackArray[stackTop]; }
	    	~IntStackAlt() { delete stackArray; }
	  };
int IntStack::countClassInstances = 0;  // initialize the static class vairable count outside main or the class
int main () {
	IntStack *s = new IntStack(10);
	cout << "IntStack::countClassInstances " << IntStack::countClassInstances << endl;
		IntStack *s1 = new IntStack(10);
	cout << "IntStack::countClassInstances " << IntStack::countClassInstances << endl;
	s->push(10);
	cout << "stack top: " << s->peek() << endl;
	s->push(20);
	cout << "stack length: " << s->length()  << endl;
	cout << "stack top: " << s->peek() << endl;

	cout << "Fix to stack pop, should return 0 after empty." << endl;
	// Counts down to stack bottom and then used to explodes on the fourth trial
	cout << "stack pop: " << s->pop() << endl;
	cout << "stack pop: " << s->pop() << endl;
	cout << "stack pop: " << s->pop() << endl;
	cout << "stack pop: " << s->pop() << endl;

	cout << "Fix to stack push, should return 12 things to the array and then stay 12." << endl;
	// Adds 12 things  to the s array and then tries to add one more
	for(int i = 10; i <= 21; i++){
		s->push(i);
		cout << "stack top: " << s->peek() << endl;
	}
	cout << "stack length: " << s->length()  << endl;
	s->push(333);
	cout << "stack top: " << s->peek() << endl;
	cout << "stack length: " << s->length()  << endl;

	// Pt 2 of HW, made small array just to test
	IntStackAlt *s2 = new IntStackAlt(10);
	// Adds 12 things  to the s array and then tries to add one more
	for(int i = 10; i <= 21; i++){
		s2->push(i);
		cout << "stack top: " << s2->peek() << endl;
	}
	cout << "stack length: " << s2->length()  << endl;
	s2->push(333);
	cout << "stack top: " << s2->peek() << endl;
	cout << "stack length: " << s2->length()  << endl;

		delete s; delete s1; delete s2;

	return 0;
}
