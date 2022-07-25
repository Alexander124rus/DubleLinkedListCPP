
#include <iostream>;
using namespace std;

template <typename T>
class DubleList {
private:
	template <class ITEM>
	struct Node {
		ITEM data;
		Node<ITEM>* next;
		Node<ITEM>* prev;
		Node(ITEM data, Node<ITEM>* next = nullptr, Node<ITEM>* prev = nullptr) : data(data), next(next), prev(prev) {}
		/*Node(ITEM data, Node<ITEM>* next = nullptr, Node<ITEM>* prev = nullptr) {
			this.data = data;
			this.next = next;
			this.prev = prev;
		}*/
	};
	Node<T>* first;
	Node<T>* last;
public:
	DubleList() {
		first = nullptr;
		last = nullptr;
	};
	~DubleList() {
		RemoveAll();
	};


	void AddNode(const T data) {
		Node<T>* node = new Node<T>(data);
		if (first == nullptr)
		{
			first = last = node;
		}
		else
		{
			last->next = node; // делаем резервное место под след значение
			node->prev = last;
		}
		last = node;


	}

	void Remove(const T data) {
		Node<T>* current = first;
		
		while (current != nullptr)
		{
			if (current->data == data)
			{
				if (current == first)
				{
					first = current->next;
					delete current;
				}
				else if (current == last) {
					last->prev->next = nullptr;
					last = current->prev;
					delete current;
				}
				else {
					current->prev->next = current->next;
					current->next->prev = current->prev;
					delete current;
				}
				
			}
			current = current->next;
		}		
	}

	void RemoveBegin() {
		Node<T>* current = last;
		last->prev->next = nullptr;
		last = current->prev;
		delete current;
	}

	void RemoveAll() {
		Node<T>* current = first;
		while (current != nullptr)
		{
			first = current->next;
			delete current;
			current = first;
		}
		first = nullptr;
	}


	void Print() {
		Node<T>* current = first;
		while (current != nullptr)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	DubleList<int> list;
	//DubleList<int> list = DubleList<int>();
	list.AddNode(4);
	list.AddNode(2);
	list.AddNode(3);
	list.AddNode(5);
	list.Remove(3);
	list.Print();


}