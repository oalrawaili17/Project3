#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
template <class T>
class LinkedList
{
public:
	class Node
	{
	private:
		T element;
		Node* next = nullptr;
		Node* prev = nullptr;

	public:
		Node(Node* p, Node* n)
		{
			next = n;
			prev = p;
		}
		Node(Node* p, Node* n, T e)
		{
			element = e;
			next = n;
			prev = p;
		}
		Node(const Node& node)
		{
			element = node.element;
			next = node.next;
			prev = node.prev;
		}
		Node& operator=(const Node& node)
		{
			if (this != node)
			{
				element = node.element;
				next = node.next;
				prev = node.prev;
			}
			return *this;
		}
		T getElement()
		{
			return element;
		}
		void setElement(T* e)
		{
			element = e;
		}
		Node* getNext()
		{
			return next;
		}
		void setNext(Node* n)
		{
			next = n;
		}
		Node* getPrev()
		{
			return prev;
		}
		void setPrev(Node* p)
		{
			prev = p;
		}
	};

private:
	Node* header = nullptr;
	Node* trailer = nullptr;
	Node* newNode = nullptr;
	int size;
	void addBetween(Node* prev, Node* next, T elem)
	{
		newNode = new Node(prev, next, elem);
		prev->setNext(newNode);
		next->setPrev(newNode);
		size++;
	}
	T remove(Node* node)
	{
		Node* next = node->getNext();
		Node* prev = node->getPrev();
		next->setPrev(prev);
		prev->setNext(next);
		T elem = node->getElement();
		size--;
		delete node;
		return elem;
	}
	Node* getNodeAt(int index) const
	{
		Node* currNode = header->getNext();
		for (int i = 0; i < index; i++)
		{
			currNode = currNode->getNext();
		}
		return currNode;
	}

public:
	LinkedList()
	{
		header = new Node(nullptr, nullptr);
		trailer = new Node(header, nullptr);
		header->setNext(trailer);
		size = 0;
	}
	//Copy constructors
	LinkedList(const LinkedList& lst)
	{
		header = new Node(nullptr, nullptr);
		trailer = new Node(header, nullptr);
		header->setNext(trailer);
		size = 0;
		for (int i = 0; i < lst.size; i++)
		{
			addBetween(trailer->getPrev(), trailer, lst.elementAt(i));
		}
	}
	LinkedList& operator=(const LinkedList& lst)
	{
		if (this != &lst)
		{
			header = new Node(nullptr, nullptr);
			trailer = new Node(header, nullptr);
			header->setNext(trailer);
			size = 0;
			for (int i = 0; i < lst.size; i++)
			{
				addBetween(trailer->getPrev(), trailer, lst.elementAt(i));
			}
		}
		return *this;
	}
	~LinkedList()
	{
		for (int i = 0; i < size; i++)
		{
			remove(getNodeAt(i));
		}
		delete header;
		delete trailer;
	}

	void addFirst(T elem)
	{
		addBetween(header, header->getNext(), elem);
	}
	void Append(T elem)
	{
		addBetween(trailer->getPrev(), trailer, elem);
	}
	T removeFirst()
	{
		return remove(header->getNext());
	}
	T removeLast()
	{
		return remove(trailer->getPrev());
	}

	T elementAt(int index) const
	{
		return getNodeAt(index)->getElement();
	}
	T First()
	{
		return header->getNext()->getElement();
	}
	T Last()
	{
		return trailer->getPrev()->getElement();
	}
	int getSize()
	{
		return size;
	}
	//Nested List iterator ADT
	class ListIterator
	{

	public:
		ListIterator() : current{ nullptr }
		{
		}

		const T operator*() const
		{
			return retrieve();
		}
		ListIterator& operator++()
		{
			current = current->getNext();
			return *this;
		}
		ListIterator operator++(int)
		{
			ListIterator old = *this;
			++(*this);
			return old;
		}
		bool operator==(const ListIterator& itr) const
		{
			return current == itr.current;
		}
		bool operator!=(const ListIterator& itr) const
		{
			return !(*this == itr);
		}

	protected:
		Node* current;
		T retrieve() const
		{
			return current->getElement();
		}
		ListIterator(Node* p) : current{ p }
		{
		}
		friend class LinkedList<T>;
	};

	class ForwardIterator : public ListIterator
	{
	private:
		bool done;
		int elemsTraversed = 0;

	public:
		ForwardIterator()
		{
		}
		bool Done() { return this->current->getNext() == nullptr ? true : false; }
		T operator*()
		{
			return ListIterator::retrieve();
		}
		const T operator*() const
		{
			return ListIterator::operator*();
		}
		ForwardIterator& operator++()
		{
			this->current = this->current->getNext();
			elemsTraversed += 1;
			return *this;
		}
		ForwardIterator operator++(int)
		{
			ForwardIterator old = *this;
			elemsTraversed += 1;
			++(*this);
			return old;
		}
		ForwardIterator Reset()
		{
			for (int i = 0; i < elemsTraversed; i++)
			{
				this->current = this->current->getPrev();
			}
			elemsTraversed = 0;
			return *this;
		}

	protected:
		ForwardIterator(Node* p) : ListIterator{ p }
		{
			done = true;
		}
		friend class LinkedList<T>;
	};
	class BackwardIterator : public ListIterator
	{
	private:
		int elemsTraversed = 0;

	public:
		BackwardIterator()
		{
		}
		bool Done() { return this->current->getPrev() == nullptr ? true : false; }
		T operator*()
		{
			return ListIterator::retrieve();
		}
		const T operator*() const
		{
			return ListIterator::operator*();
		}
		BackwardIterator& operator++()
		{
			this->current = this->current->getPrev();
			elemsTraversed += 1;
			return *this;
		}
		BackwardIterator operator++(int)
		{
			BackwardIterator old = *this;
			elemsTraversed += 1;
			++(*this);
			return old;
		}
		BackwardIterator Reset()
		{
			for (int i = 0; i < elemsTraversed; i++)
			{
				this->current = this->current->getNext();
			}
			elemsTraversed = 0;
			return *this;
		}

	protected:
		BackwardIterator(Node* p) : ListIterator{ p }
		{
		}
		friend class LinkedList<T>;
	};
	ForwardIterator ForwardBegin()
	{
		return ForwardIterator(header->getNext());
	}
	ForwardIterator ForwardEnd()
	{
		return ForwardIterator(trailer);
	}
	BackwardIterator BackwardBegin()
	{
		return BackwardIterator(trailer->getPrev());
	}
	BackwardIterator BackwardEnd()
	{
		return BackwardIterator(header);
	}
};
#endif