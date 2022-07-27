
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
		//Альтернативное объявление конструктора
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
	
	void Remove(T obj) {
		Node<T>* current = first;
		while (current != nullptr)
		{
			if (current->data == obj)
			{
				if (current == first)
				{		
					first = current->next;
					first->prev = nullptr;
					delete current;
					current = first;
				}
				else if (current == last) {
					last = current->prev;
					last->next = nullptr;
					delete current;
					current = last;
				}
				else {
					//Вариант 1
					Node<T>* temp = current->prev;
					temp->next = current->next;
					current->next->prev = temp;
					delete current;
					current = temp;

					//Вариант 2
					/*current->prev->next = current->next;
					current->next->prev = current->prev;*/
				}
			}
			current = current->next;
		}
		//Вариант 2
		/*delete current;*/
	}

	void RemoveBegin() {
		Node<T>* current = first;
		first = current->next;
		first->prev = nullptr;
		delete current;
	}

	void RemoveEnd() {
		Node<T>* current = last;
		last = current->prev;
		last->prev->next = nullptr;
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
	list.AddNode(3);
	list.AddNode(3);
	list.AddNode(3);
	list.Remove(3);
	list.Print();


}