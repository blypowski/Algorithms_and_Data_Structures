#define MAX 10000

class List {
	int t[MAX];
	int last;
	public:
	List();
	void push_front(int x);
	int pop_front();
	void push_back(int x);
	int pop_back();
	int size();
	bool empty();
	void clear();
	int find(int x);
	int erase(int i);
	void insert(int i, int x);
	int remove(int x);
	void traverse();
};

List::List() {
	last = 0;
}

void List::push_front(int x) {
	if(last>=0 && last<MAX){
	for (int i=last; i>0; --i) {
            t[i] = t[i-1];
        }
        t[0] = x;
        last++;
	}
	
	else throw std::out_of_range("overflow");
}

int List::pop_front() {
	if(!empty()) {
	int x;
	x = t[0];
	int i = 0;
	while(i<last) {
		t[i] = t[i+1];
		i++;
	}
	last--;
	return x;
	}
	else throw std::out_of_range("overflow");
}

void List::push_back(int x) {
	if(last<MAX) {
		t[last++]=x;
	}

	else throw std::out_of_range("overflow");
}

int List::pop_back() {
	if(last>0) {
		return t[--last];
	}
	else throw std::out_of_range("underflow");
}

int List::size() {
	return last;
}

bool List::empty() {
	if(last==0)
		return true;
	else
		return false;
}

void List::clear() {
	last = 0;
}

int List::find(int x) {
	for(int i=0;i<last;i++) {
		if(t[i]==x) return i;
	}
	return -1;
}

int List::erase(int i) {
	int x = t[i];
	
	if(i==last) pop_back();
	else {
	for(i;i<last-1;i++) {
		t[i]=t[i+1];
	}
	}
	last--;
	return x;
}

void List::insert(int i, int x) {
	if(i<last) {

		if(i>=0) {
			for(int j=i;j<last-1;j++) {
				t[j]=t[j+1];
			}
			t[i]=x;
			
			last++;
				
		}
		else throw std::out_of_range("underflow");
	}
	else if (i==last) {
		push_back(x);
		last++;
	}
	else throw std::out_of_range("overflow");

}

int List::remove(int x) {
	return -1;
}
