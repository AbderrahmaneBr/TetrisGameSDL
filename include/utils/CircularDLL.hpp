#ifndef CIRCULARDLL_HPP
#define CIRCULARDLL_HPP

template <typename T>
class NodeDouble {
public:
    T data;
    NodeDouble<T>* next;
    NodeDouble<T>* prev;

    NodeDouble(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class CircularDoublyLinkedList {
public:
    NodeDouble<T>* head;
    CircularDoublyLinkedList() : head(nullptr) {}

    ~CircularDoublyLinkedList() {
        if (head == nullptr) return;

        NodeDouble<T>* current = head;
        do {
            NodeDouble<T>* next = current->next;
            delete current;
            current = next;
        } while (current != head);
    }
    
    void addLeft(T value) {
        NodeDouble<T>* newNode = new NodeDouble<T>(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            NodeDouble<T>* last = head->prev;
            last->next = newNode;
            newNode->prev = last;
            newNode->next = head;
            head->prev = newNode;
            head = newNode; // Update the head to the new node (in order to start displaying from it)
        }
    }

    void addRight(T value) {
        NodeDouble<T>* newNode = new NodeDouble<T>(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            NodeDouble<T>* last = head->prev;
            last->next = newNode;
            newNode->prev = last;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void shift() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        NodeDouble<T>* temp = head;
        do {
            (temp->data).setColor((temp->next->data).getColor());
            temp = temp->next;
        } while (temp != head);
    }


    void display() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        typeid(T);

        NodeDouble<T>* temp = head;
        do {
            int objectColor = (temp->data).getColor();
            int objectShape = (temp->data).getShape();

            std::string buffer;
            switch (objectColor)
            {
            case 0:
                buffer.append(RED_PAINT);
                break;
            case 1:
                buffer.append(GREEN_PAINT);
                break;
            case 2:
                buffer.append(BLUE_PAINT);
                break;
            case 3:
                buffer.append(YELLOW_PAINT);
                break;
            
            default:
                break;
            }

            switch (objectShape)
            {
            case 0: // Rectangle
                buffer.append("■"); // ■
                break;
            case 1: // Circle
                buffer.append("●"); // ●
                break;
            case 2: // Triangle
                buffer.append("▲"); // ▲
                break;
            case 3: // Diamond
                buffer.append("◆"); // ◆
                break;
            
            default:
                break;
            }

            buffer.append(PAINT_END); // Closing Style

            std::cout << buffer << " ";
            temp = temp->next;
        } while (temp != head);

        std::cout << std::endl;
    
        return;

    }
};

#endif // CIRCULARLL_HPP
