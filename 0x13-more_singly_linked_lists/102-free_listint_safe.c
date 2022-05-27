#include "lists.h"

/**
 * frees_linklistp2 - frees a linked list
 * @head: head of a list.
 *
 * Return: no return.
 */
void frees_linklistp2(listp_t **head)
{
listp_t *temp;
listp_t *curr;

if (head != NULL)
{
curr = *head;
while ((temp = curr) != NULL)
{
curr = curr->next;
free(temp);
}
*head = NULL;
}
}

/**
 * free_listint_safe - frees a linked list.
 * @h: head of a list.
 *
 * Return: size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
size_t nodesnumber = 0;
listp_t *hptr, *new, *add;
listint_t *curr;

hptr = NULL;
while (*h != NULL)
{
new = malloc(sizeof(listp_t));

if (new == NULL)
exit(98);

new->p = (void *)*h;
new->next = hptr;
hptr = new;

add = hptr;

while (add->next != NULL)
{
add = add->next;
if (*h == add->p)
{
*h = NULL;
frees_linklistp2(&hptr);
return (nodesnumber);
}
}

curr = *h;
*h = (*h)->next;
free(curr);
nodesnumber++;
}

*h = NULL;
frees_linklistp2(&hptr);
return (nodesnumber);
}
