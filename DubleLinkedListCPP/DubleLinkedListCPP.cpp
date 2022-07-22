
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
	DubleList() : first(nullptr), last(nullptr) {};


	void AddNode(const T data) {
		Node<T>* node = new Node<T>(data);
		node->next = 0;

		node->prev = last;
		if (last != 0)
			last->next = node;

		// Если элемент первый, то он одновременно и голова и хвост
		if (first == node)
			first = last = node;
		else
			// иначе новый элемент - хвостовой
			last = node;

	}


	void Print() {
		Node<T>* current = first;
		while (current != nullptr)
		{
			cout << current << endl;
			current = current->next;
		}
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	DubleList<int> list;
	//DubleList<int> list = DubleList<int>();
	list.AddNode(1);
	list.AddNode(2);
	list.AddNode(3);
	list.AddNode(4);
	list.Print();


}