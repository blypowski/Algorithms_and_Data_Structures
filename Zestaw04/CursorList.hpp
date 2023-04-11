#define MAX 10000

class List {

	struct Node {
		int element;
		int next;
	};
	
	Node arr[MAX];
	int head;
	int lsize;
	int spare;
	
	
	public:
		List();
		void push_front(int x);
		int pop_front();
		void push_back(int x);
		int pop_back();
		int size();
		
		bool empty();
		//void clear();
		int find(int x);
		int erase(int i);
		void insert(int i, int x);
		//int remove(int x);
		void traverse();
};

List::List() {
	head = 0;
	lsize = 0;
	int i;
	for(i=1;i<=MAX-1;i++) {
		arr[i].next=i+1;
	}
	spare=1;
}

int List::size() {
	return lsize;
}

bool List::empty() {
	return lsize==0;
}

/*
void List::clear() {
	
}
*/


void List::push_front(int x) {
	if(lsize>=MAX || lsize<0) throw std::out_of_range("out of range");
	else {
	int tmp = head;
	arr[spare].element=x;
	head=spare;
	spare=arr[head].next;
	arr[head].next = tmp;
	lsize++;
	}
}

int List::pop_front() {
	if(!empty()) {
		int tmp=arr[head].next;
		arr[head].next = spare;
		spare = head;
		int x = arr[spare].element;
		head=tmp;
		lsize--;
		return x;
	}
	else throw std::out_of_range("cannot pop from an empty list");
}

int List::pop_back() {
	if(!empty()) {
		int x;
		if(lsize==1) {
			x = pop_front();
			return x;
		}
		else {
			int prevNode=head;
			int counter =0;
			while(arr[arr[prevNode].next].next!=0) {
				prevNode=arr[prevNode].next;
			}
				int tmp = arr[arr[prevNode].next].next;
				arr[arr[prevNode].next].next=spare;
				spare = arr[prevNode].next;
				x = arr[spare].element;
				arr[prevNode].next=tmp;
				lsize--;
			return x;
		}
	}
	else throw std::out_of_range("cannot pop from an empty list");
}

void List::push_back(int x) {
	if(lsize==MAX-1 ||lsize<0) throw std::out_of_range("poza zakresem");
	else if (lsize==0) push_front(x);
	else {
		int prevNode=head;
		int counter = 0;
		while(arr[prevNode].next!=0) {
			prevNode=arr[prevNode].next;
		}
			int tmp = arr[prevNode].next;
			arr[spare].element=x;
			arr[prevNode].next = spare;
			spare = arr[spare].next;
			arr[arr[prevNode].next].next = tmp;
			lsize++;
	}
	
}


int List::find(int x) {
	if(empty()) return -1;
	if(arr[head].element==x) return 0;
	int counter=0;
	int prevNode=head;
	while(prevNode!=0) {
		if(arr[prevNode].element==x)
			return counter;
		else {
			counter++;
			prevNode = arr[prevNode].next;
		}	
	}
	return -1;
}

int List::erase(int i) {
	if(!empty()) {
		int x;
		if(i==0) {
			x = pop_front();
			return x;
		}
		else {
			int prevNode = head;
			int counter=0;
		
			while(counter<i-1) {
				prevNode = arr[prevNode].next;
				counter++;
			}
			int tmp = arr[arr[prevNode].next].next;
			arr[arr[prevNode].next].next=spare;
			spare = arr[prevNode].next;
			x = arr[spare].element;
			arr[prevNode].next=tmp;
			lsize--;
			
			return x;
		}
	}
	else throw std::out_of_range("poza zakresem");
}

void List::insert(int i, int x) {
	if(i>lsize || i<0) std::out_of_range("poza zakresem");
	else {
		if(i==0) {
			push_front(x);
		}
		else {
			int prevNode = head;
			int counter=0;
			while(counter<i-1) {
		
				prevNode = arr[prevNode].next;
				counter++;
			}
			int tmp = arr[prevNode].next;
			arr[spare].element=x;
			arr[prevNode].next = spare;
			spare = arr[spare].next;
			arr[arr[prevNode].next].next = tmp;
			lsize++;
		}
	}
			
}
/*
int List::remove(int x) {
	/*
	int counter = 0;
	int nextNode = head;
	while(arr[nextNode].next!=-1) {
		if(arr[nextNode].next==x) {
			int tmp = arr[arr[nextNode].next].next;
			
			arr[nextNode].next = tmp;
			counter++;
		}
		nextNode=arr[nextNode].next;
	}
	
	return -1;
	

}
*/
void List::traverse() {
	std::cout << "-------------------------\n";
	std::cout << "head " << head << "\n";
	std::cout << "arr[head].next " << arr[head].next << "\n";
	std::cout << "spare " << spare << "\n";
	std::cout << "size " << lsize <<"\n";
	for(int i =0;i<7;i++) {
		std::cout << i << " " << arr[i].element << " " << arr[i].next << "\n";
	}
	std::cout << "-------------------------\n";
	int tmp;
	tmp = head;
	while (arr[tmp].next!=0) {
		std::cout << arr[tmp].element << " ";
		tmp=arr[tmp].next;
	}
	std::cout << arr[tmp].element;
	std::cout << "\n";
}

