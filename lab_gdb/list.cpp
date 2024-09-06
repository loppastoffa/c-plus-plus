/**
 * @file list.cpp
 * Singly Linked List (lab_gdb).
 *
 * @author Chase Geigle
 * @date (created) Fall 2011
 * @date (modified) Spring 2012, Fall 2012
 *
 * @author Jack Toole
 * @date (modified) Fall 2011
 *
 * @author Veer Dedhia
 * @date (modified) Spring 2014
 */

/**
 * Destroys the current List. This function should ensure that
 * memory does not leak on destruction of a list.
 */
template <class T>
List<T>::~List()
{
    clear();
}

/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <class T>
void List<T>::clear()
{
    ListNode *current = head;
    while (current != nullptr) {
        ListNode *next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    length = 0;
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertFront(T const & ndata) {
  ListNode * newNode = new ListNode(ndata);
  newNode->next = head;
  head = newNode;
  
  length++;
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertBack( const T & ndata )
{
    if (head == nullptr)
    {
        head = new ListNode(ndata);
    }
    else
    {
        ListNode * temp = head;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = new ListNode(ndata);
    }
    length++;
}


/**
 * Reverses the current List.
 */
template <class T>
void List<T>::reverse()
{
    head = reverse(head, NULL, length);
}

/**
 * Helper function to recursively reverse the enitre sequence of
 * linked memory inside a List.
 *
 * @param curr The current node we are reversing
 * @param prev The node that should be placed before the current node in the
 * final reversed list
 * @param len The length of the remaining list to be reversed
 */
template <class T>
typename List<T>::ListNode* List<T>::reverse( ListNode * curr, ListNode * prev, int len )
{
    ListNode * temp;
    if (curr == nullptr || len <= 0)
    {
        return prev;
    }
    else
    {
        temp = curr->next;
        curr->next = prev;

        return reverse(temp, curr, len-1);
    }
}

/**
 * Shuffles the current list by applying a perfect shuffle once. This entails
 * splitting the list in half, then interleaving the two halves.
 * For example:
 * start : < 1, 2, 3, 4, 5 >
 * split : < 1, 2, 3 >    < 4, 5 >
 * final : < 1, 4, 2, 5, 3 >
 */
template <class T>
void List<T>::shuffle()
{
    if (length <= 1)
        return;

    ListNode * one, * two, * prev;
    one = two = prev = head;

    for (int i = 0; i < length/2; i++)
    {
        prev = two;
        two = two->next;
    }
    prev->next = nullptr;

    // interleave
    while (one != nullptr && two != nullptr)
    {
        ListNode* nextFirst = one->next;
        ListNode* nextSecond = two->next;

        one->next = two;
        two->next = nextFirst;
        
        one = nextFirst;
        two = nextSecond;
    }
}


