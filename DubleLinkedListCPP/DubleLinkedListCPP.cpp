
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
	/*void Remove(T obj) {
		Node<T>* current = new Node<T>(obj);
		Node<T>* ptr = nullptr;

		if (current == first)
		{
			RemoveBegin();
		}
		else if (current == last) {
			RemoveEnd();
		}
		else {
			current->next->prev = current->prev;
			current->prev->next = current->next;
			
			delete current;
		}
	}*/
	void Remove(T obj) {
		Node<T>* current = first;
		
		
		while (current != nullptr)
		{
			if (current->data == obj)
			{
				if (current == first)
				{
					RemoveBegin();
					delete current;
					current = first;
				}
				else if (current == last) {
					RemoveEnd();
				}
				else {


					Node<T>* temp = current->prev;
					
					/*current->prev->next = current->next;
					current->next->prev = current->prev;*/

					temp->next = current->next;
					current->next->prev = temp;

					delete current;
					current = temp;
					
				}
				
			}
			current = current->next;
		}
		
		
	}

	Node<T>* RemoveBegin() {
		Node<T>* current = first;
		
		first = current->next;
		first->prev = nullptr;
		return first;
	}

	void RemoveEnd() {
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
	list.AddNode(3);
	list.AddNode(2);
	list.AddNode(4);
	list.AddNode(6);
	list.Remove(3);
	list.Print();


}