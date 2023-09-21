Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newnode;