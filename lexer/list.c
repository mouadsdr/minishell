/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:14:38 by msodor            #+#    #+#             */
/*   Updated: 2023/06/02 01:03:37 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/**
 * token_new - function that creates a new token element
 * @content: a pointer to the content string
 * @len: the length of the content
 * @type: the token type
 * @state: the token state
 * Return: a pointer to the newly created token element
 */
t_elems	*token_new(char *content, int len, t_token type, t_state state)
{
	t_elems	*elems;

	elems = malloc(sizeof(t_elems));
	if (!elems)
		return (NULL);
	elems->prev = NULL;
	elems->content = ft_strdup(content);
	elems->len = len;
	elems->type = type;
	elems->state = state;
	elems->next = NULL;
	return (elems);
}

/**
 * token_list_add - function that adds a new token element to a token list
 * @lst: a pointer to the head of the token list
 * @new: a pointer to the new token element
 */
void	token_list_add(t_elems **lst, t_elems *new)
{
	t_elems	*ptr;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		ptr = *lst;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
		new->prev = ptr;
	}
	else
		*lst = new;
}

/**
 * token_del - function that deletes a token element from a token list
 * @head: a pointer to the head of the token list
 * @node: a pointer to the token element to be deleted
 */
void	token_del(t_elems **head, t_elems *node)
{
	if (*head == NULL || node == NULL)
		return ;
	if (*head == node)
		*head = node->next;
	if (node->next != NULL)
		node->next->prev = node->prev;
	if (node->prev != NULL)
		node->prev->next = node->next;
	else
		*head = node->next;
	if (node->content != NULL)
		free(node->content);
	free(node);
}

/**
 * token_list_free - function that frees the memory used by a token list
 * @list: a pointer to the head of the token list
 */
// void	token_list_free(t_elems *list)
// {
// 	t_elems	*tmp;

// 	tmp = list;
// 	while (tmp)
// 	{
// 		free(tmp->content);
// 		free(tmp);
// 		tmp = tmp->next;
// 	}
// 	free(list);
// }
